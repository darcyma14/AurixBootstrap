/*
 * SC900719.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include "SC900719.h"
#include "Test_Print.h"

static uint8_t crc8_table[256] = {
0x00,0x2F,0x5E,0x71,0xBC,0x93,0xE2,0xCD,
0x57,0x78,0x09,0x26,0xEB,0xC4,0xB5,0x9A,
0xAE,0x81,0xF0,0xDF,0x12,0x3D,0x4C,0x63,
0xF9,0xD6,0xA7,0x88,0x45,0x6A,0x1B,0x34,
0x73,0x5C,0x2D,0x02,0xCF,0xE0,0x91,0xBE,
0x24,0x0B,0x7A,0x55,0x98,0xB7,0xC6,0xE9,
0xDD,0xF2,0x83,0xAC,0x61,0x4E,0x3F,0x10,
0x8A,0xA5,0xD4,0xFB,0x36,0x19,0x68,0x47,
0xE6,0xC9,0xB8,0x97,0x5A,0x75,0x04,0x2B,
0xB1,0x9E,0xEF,0xC0,0x0D,0x22,0x53,0x7C,
0x48,0x67,0x16,0x39,0xF4,0xDB,0xAA,0x85,
0x1F,0x30,0x41,0x6E,0xA3,0x8C,0xFD,0xD2,
0x95,0xBA,0xCB,0xE4,0x29,0x06,0x77,0x58,
0xC2,0xED,0x9C,0xB3,0x7E,0x51,0x20,0x0F,
0x3B,0x14,0x65,0x4A,0x87,0xA8,0xD9,0xF6,
0x6C,0x43,0x32,0x1D,0xD0,0xFF,0x8E,0xA1,
0xE3,0xCC,0xBD,0x92,0x5F,0x70,0x01,0x2E,
0xB4,0x9B,0xEA,0xC5,0x08,0x27,0x56,0x79,
0x4D,0x62,0x13,0x3C,0xF1,0xDE,0xAF,0x80,
0x1A,0x35,0x44,0x6B,0xA6,0x89,0xF8,0xD7,
0x90,0xBF,0xCE,0xE1,0x2C,0x03,0x72,0x5D,
0xC7,0xE8,0x99,0xB6,0x7B,0x54,0x25,0x0A,
0x3E,0x11,0x60,0x4F,0x82,0xAD,0xDC,0xF3,
0x69,0x46,0x37,0x18,0xD5,0xFA,0x8B,0xA4,
0x05,0x2A,0x5B,0x74,0xB9,0x96,0xE7,0xC8,
0x52,0x7D,0x0C,0x23,0xEE,0xC1,0xB0,0x9F,
0xAB,0x84,0xF5,0xDA,0x17,0x38,0x49,0x66,
0xFC,0xD3,0xA2,0x8D,0x40,0x6F,0x1E,0x31,
0x76,0x59,0x28,0x07,0xCA,0xE5,0x94,0xBB,
0x21,0x0E,0x7F,0x50,0x9D,0xB2,0xC3,0xEC,
0xD8,0xF7,0x86,0xA9,0x64,0x4B,0x3A,0x15,
0x8F,0xA0,0xD1,0xFE,0x33,0x1C,0x6D,0x42,
};

uint8_t Spi_CompleteFlag;
__attribute__ ((__align(32))) PMIC_CTRL ctrl ;
__attribute__ ((__align(32))) PMIC_RESP resp ;

uint8_t CalCrc(uint8_t* buf)
{
    int i;
    uint8_t chksum = 0xFF;

    for (i = 3; i >= 1; i--)
    {
        chksum = crc8_table[(chksum ^ buf[i]) & 0xff];
    }

    chksum ^= XOR_MAGIC;
    return chksum;
}

uint8_t ChkCrc(uint8_t* buf)
{
    int i;
    uint8_t chksum = 0xFF;

    for (i = 3; i >= 1; i--)
    {
        chksum = crc8_table[(chksum ^ buf[i]) & 0xff];
    }

    chksum ^= XOR_MAGIC;
    chksum ^= buf[0];
    return chksum;
}

void SPI_MasterTransfer(uint32_t* ctrl_pk, uint32_t* resp_pk)
{
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_SPI_Ref,(Spi_DataType*)ctrl_pk,(Spi_DataType*)resp_pk,1);
    Spi_AsyncTransmit(SpiConf_SpiChannel_SpiChannel_SPI_Ref);
}

void delay(uint32_t dly)
{
    uint32_t i, j;

    for(i=0;i<dly;i++)
    {
        for(j=0;j<dly;j++)
            __nop();
    }
}

/* Normal : return data, Error : return 0xffff */
uint16_t SC900719_Read(PMIC_NORMAL_ADDR addr)
{
    Spi_CompleteFlag = 0u;
    resp.pkt = 0u;
    ctrl.pkt = 0u;

    ctrl.K.rw = 0u ;
    ctrl.K.addr = addr ;
    ctrl.K.crc8 = CalCrc(&ctrl.msg[0]) ;

    SPI_MasterTransfer(&ctrl.pkt, &resp.pkt);

    while(Spi_CompleteFlag != 1u)   __nop();

    if(ChkCrc(&resp.msg[0]) == 0u)
        return (uint16_t)(((uint16_t)resp.K.dataH << 8) | resp.K.dataL) ;
    else
        return (uint16_t) 0xffff;
}

/* Normal : return 0, Error : return 1 */
uint8_t SC900719_Write(PMIC_NORMAL_ADDR addr, uint16_t senddata)
{
    Spi_CompleteFlag = 0u;
    resp.pkt = 0u;

    ctrl.K.rw = 1u ;
    ctrl.K.addr = addr ;
    ctrl.K.dataH = (uint8_t)(senddata >> 8) ;
    ctrl.K.dataL = (uint8_t)(senddata & 0x00FF);
    ctrl.K.crc8 = CalCrc(&ctrl.msg[0]) ;

    SPI_MasterTransfer(&ctrl.pkt, &resp.pkt);

    while(Spi_CompleteFlag != 1u)   __nop();

    return (uint8_t)resp.K.err ;
}

void Ref_EndOfCmdSeqNotification(void)
{
    Spi_CompleteFlag = 1u;
}

uint16_t SC900719_Init(void)
{
    uint16_t inData;
    uint16_t Svcfg_data = 0x56FF;
    //uint16_t En_data = 0x2950;    // 2,3,8,9 LSD
    uint16_t En_data = 0x2100;      // 2LSD only
    uint16_t Clk_data = 0x100C;

    SC900719_Read(PMIC_ADDR_CHIPID);
    inData = SC900719_Read(PMIC_ADDR_CHIPID);

    SC900719_Write(PMIC_ADDR_VLVCLK, Clk_data);     // Valve clock freq. & AVD config
    SC900719_Read(PMIC_ADDR_VLVCLK);
    inData = SC900719_Read(PMIC_ADDR_VLVCLK);

    SC900719_Write(PMIC_ADDR_SVCFG_BIST, Svcfg_data);   // Supervision config
    SC900719_Read(PMIC_ADDR_SVCFG_BIST);
    inData = SC900719_Read(PMIC_ADDR_SVCFG_BIST);

    SC900719_Write(PMIC_ADDR_WSCFG1, 0xCCCC);       // Wheel speed sensor config
    SC900719_Read(PMIC_ADDR_WSCFG1);
    inData = SC900719_Read(PMIC_ADDR_WSCFG1);

    SC900719_Write(PMIC_ADDR_PMDCFG, 0xA200);       // Pump Motor driver config
    SC900719_Read(PMIC_ADDR_PMDCFG);
    inData = SC900719_Read(PMIC_ADDR_PMDCFG);

    SC900719_Write(PMIC_ADDR_ABIST_DIS, 0xFFFF);    // Abist disable config
    SC900719_Read(PMIC_ADDR_ABIST_DIS);
    inData = SC900719_Read(PMIC_ADDR_ABIST_DIS);

    SC900719_Write(PMIC_ADDR_WLD12, 0x33FC);        // Warning lamp driver cfg & error flags
    SC900719_Read(PMIC_ADDR_WLD12);
    inData = SC900719_Read(PMIC_ADDR_WLD12);

    SC900719_Write(PMIC_ADDR_ISOKVSO12, 0x1B7A);    // VSO cfg & error flag
    SC900719_Read(PMIC_ADDR_ISOKVSO12);
    inData = SC900719_Read(PMIC_ADDR_ISOKVSO12);

    SC900719_Write(PMIC_ADDR_PMDF, 0xFFFF);         // Flag RESET
    SC900719_Read(PMIC_ADDR_PMDF);
    inData = SC900719_Read(PMIC_ADDR_PMDF);

    SC900719_Write(PMIC_ADDR_SVFLT, 0x2FFF);        // Flag RESET
    SC900719_Read(PMIC_ADDR_SVFLT);
    inData = SC900719_Read(PMIC_ADDR_SVFLT);

    SC900719_Write(PMIC_ADDR_LSD28F, 0xFFFF);       // Flag RESET
    SC900719_Read(PMIC_ADDR_LSD28F);
    inData = SC900719_Read(PMIC_ADDR_LSD28F);

    SC900719_Write(PMIC_ADDR_LSD39F, 0xFFFF);       // Flag RESET
    SC900719_Read(PMIC_ADDR_LSD39F);
    inData = SC900719_Read(PMIC_ADDR_LSD39F);

    SC900719_Write(PMIC_ADDR_VLVEN, En_data);   // Enable HSD, LSD
    SC900719_Read(PMIC_ADDR_VLVEN);
    inData = SC900719_Read(PMIC_ADDR_VLVEN);

    return inData;
}

uint16_t SC900719_State(void)
{
    PMIC_INT1 sInt1;
    PMIC_PMDF sPmdf;
    PMIC_SVFLT sSvflt;
    PMIC_VREG sVreg;
    PMIC_28F s28f;
    PMIC_39F s39f;
    PMIC_ABISTFAIL  sAbist;

    SC900719_Read(PMIC_ADDR_INT1);
    sInt1.state = SC900719_Read(PMIC_ADDR_PMDF);
    sPmdf.state = SC900719_Read(PMIC_ADDR_SVFLT);
    sSvflt.state = SC900719_Read(PMIC_ADDR_VREG_FLG);
    sVreg.state = SC900719_Read(PMIC_ADDR_LSD28F);
    s28f.state = SC900719_Read(PMIC_ADDR_LSD39F);
    s39f.state = SC900719_Read(PMIC_ADDR_ABISTFAIL);
    sAbist.state = SC900719_Read(PMIC_ADDR_ABISTFAIL);

    printf("Int:0x%X, Pmdf:0x%X, Svflt:0x%X, sVreg:0x%X, 28f:0x%X, 39f:0x%X, bist:0x%X \r\n",
            sInt1.state, sPmdf.state, sSvflt.state, sVreg.state, s28f.state, s39f.state, sAbist.state);

    return sInt1.state;
}

/* Current : 0 ~ 2.25 A */
uint8_t Ctr_SolValve(SOL_VALVE select, float Ivalue)
{
    uint16 Idata = 0u;
    
    Idata = (uint16)((1023.0 * Ivalue) / 2.25);
    
    //if(Idata <= 0x03ff)   // 2.25A
    if(Idata <= 0x02AA)     // 1.5A
    {
        SC900719_Write((PMIC_NORMAL_ADDR)select, Idata);
        return SC900719_OK;
    }
    else
        return SC900719_ERR;
}

void PwSBC_GotoLPOFF(void)
{
    uint16 Odata = 0x0003;

    SC900719_Write(PMIC_ADDR_INT1, Odata);
}

