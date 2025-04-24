/*
 * PMIC_TLF35584.c
 *
 *  Created on: 2022. 9. 20.
 *      Author: Elec1
 */

#include "PMIC_TLF35584.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "AppDio.h"


//for debug
#include "LSD_TLE8110ED.h"
//

uint8 Spi_PMIC_CompleteFlag;

uint8_t TLF35584_read(uint8_t addr) //addr 6bits //MOSI및 MISO시 parity cal 필요
{
	T_PMIC_CTRL ctrl ;
	T_PMIC_RESP resp ;
    uint8_t tmp;

	int bit_pos ;
	uint16_t *pctrl = (uint16_t*)&ctrl ;
	uint8_t parity_count = 0u ;

    //ctrl.rw = 0u ;  //bit15: read = 0, write = 1
    //ctrl.addr = addr ; //bit14~9: addr
    //ctrl.data = 0u ;	//bit8~1: data
    //ctrl.parity = 0u ;	//bit0: parity

    ctrl.pkt = 0x0000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (((uint16_t)addr)<<9)&0x7E00; //bit14~9: addr
    ctrl.pkt |= (uint16_t)0u;	//bit8~1: data

    for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
    {
    	if ( (*pctrl >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    if ((parity_count % 2) == 0u)
    {
    	ctrl.pkt &= 0xFFFE;	//bit0: parity
    }
    else
    {
    	ctrl.pkt |= 0x0001;	//bit0: parity
    }

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    Spi_PMIC_CompleteFlag = 0u;

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_PMIC);

	while(Spi_PMIC_CompleteFlag != 1u) {	__nop(); }

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

    //MISO parity check
    pctrl = (uint16_t*)&resp ;
	parity_count = 0u ;

    for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
    {
    	if ( (*pctrl >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    //had checked for 16bit => "number of 1" shall be EVEN
    if ((parity_count % 2) == 0u){ return (uint8_t)( (resp.pkt>>1) & 0xff ) ; }  //ok

    //bit14~9: unknown_stat


	return (uint8_t)0xff ; //error - [ error is 0xff.. because data bit2~0 NOT 111 ]
}

uint8_t TLF35584_write(uint8_t addr, uint8_t data) //addr 6bits, data 8bits //MOSI및 MISO시 parity cal 필요
{
	T_PMIC_CTRL ctrl ;
	T_PMIC_RESP resp ;
    uint8_t tmp;

	int bit_pos ;
	uint16_t *pctrl = (uint16_t*)&ctrl ;
	uint8_t parity_count = 0u ;

    //ctrl.rw = 1u ;
    //ctrl.addr = addr ;
    //ctrl.data = data ;
    //ctrl.parity = 0u ;

    ctrl.pkt = 0x8000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (((uint16_t)addr)<<9)&0x7E00; //bit14~9: addr
    ctrl.pkt |= (((uint16_t)data)<<1) & 0x01FE;;	//bit8~1: data

    for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
    {
    	if ( (*pctrl >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    if ((parity_count % 2) == 0u)
    {
    	ctrl.pkt &= 0xFFFE;	//bit0: parity
    }
    else
    {
    	ctrl.pkt |= 0x0001;	//bit0: parity
    }

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    Spi_PMIC_CompleteFlag = 0u;

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_PMIC);

	while(Spi_PMIC_CompleteFlag != 1u) {	__nop(); }

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

  	//return (uint8_t)( ((resp.pkt>>9) & 0x003F) ) ;	 //bit14~9: addr of cmd
  	if( (resp.msg[0] == ctrl.msg[1]) && (resp.msg[1] == ctrl.msg[0]) ){	return 0; }	//ok
  	else{ return 1; } //error
}

uint8_t TLF35584_write_dbg(uint8_t addr, uint8_t data) //addr 6bits, data 8bits //MOSI및 MISO시 parity cal 필요
{
	T_PMIC_CTRL ctrl ;
	T_PMIC_RESP resp ;
    uint8_t tmp;

	int bit_pos ;
	uint16_t *pctrl = (uint16_t*)&ctrl ;
	uint8_t parity_count = 0u ;

    //ctrl.rw = 1u ;
    //ctrl.addr = addr ;
    //ctrl.data = data ;
    //ctrl.parity = 0u ;

    ctrl.pkt = 0x8000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (((uint16_t)addr)<<9)&0x7E00; //bit14~9: addr
    ctrl.pkt |= (((uint16_t)data)<<1) & 0x01FE;;	//bit8~1: data

    for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
    {
    	if ( (*pctrl >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    if ((parity_count % 2) == 0u)
    {
    	ctrl.pkt &= 0xFFFE;	//bit0: parity
    }
    else
    {
    	ctrl.pkt |= 0x0001;	//bit0: parity
    }

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    Spi_PMIC_CompleteFlag = 0u;

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_PMIC);

	while(Spi_PMIC_CompleteFlag != 1u) {	__nop(); }

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

//LSD_WritePin(LSD1, (uint16_t)((resp.pkt>>1) & 0x00FF));

  	//return (uint8_t)( ((resp.pkt>>9) & 0x003F) ) ;	 //bit14~9: addr of cmd
  	if( (resp.msg[0] == ctrl.msg[1]) && (resp.msg[1] == ctrl.msg[0]) ){	LSD_WritePin(LSD1, (uint16_t)((resp.pkt>>1) & 0x00FF)); return 0; }	//ok
  	else{ LSD_WritePin(LSD1, (uint16_t)((resp.pkt>>1) & 0x0000)); return 1; } //error
}

/*
uint8_t TLF35584_write(uint8_t addr, uint8_t data) //addr 6bits, data 8bits //MOSI및 MISO시 parity cal 필요
{
	T_PMIC_CTRL ctrl ;
	T_PMIC_RESP resp ;
    uint8_t tmp;
uint32_t spisenddata, spircvdata;
	int bit_pos ;
	uint16_t *pctrl = (uint16_t*)&ctrl ;
	uint8_t parity_count = 0u ;

    //ctrl.rw = 1u ;
    //ctrl.addr = addr ;
    //ctrl.data = data ;
    //ctrl.parity = 0u ;

    ctrl.pkt = 0x8000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (addr<<9)&0x7E00; //bit14~9: addr
    ctrl.pkt |= (((uint16_t)data)<<1) & 0x01FE;;	//bit8~1: data

    for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
    {
    	if ( (*pctrl >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    if ((parity_count % 2) == 0u)
    {
    	ctrl.pkt &= 0xFFFE;	//bit0: parity
    }
    else
    {
    	ctrl.pkt |= 0x0001;	//bit0: parity
    }

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

spisenddata = (uint32_t)ctrl.pkt;

ctrl.pkt = 0x8000;  //bit15: read = 0, write = 1
ctrl.pkt |= (addr<<9)&0x7E00; //bit14~9: addr
ctrl.pkt |= (((uint16_t)data)<<1) & 0x01FE;;	//bit8~1: data

for(bit_pos = 0; bit_pos < 16 ; bit_pos ++)
{
	if ( (*pctrl >> bit_pos) & 0x01u )
	{
   		parity_count ++ ;
	}
}

if ((parity_count % 2) == 0u)
{
	ctrl.pkt &= 0xFFFE;	//bit0: parity
}
else
{
	ctrl.pkt |= 0x0001;	//bit0: parity
}

//reverse byte-order
tmp = ctrl.msg[0];
ctrl.msg[0] = ctrl.msg[1];
ctrl.msg[1] = tmp;

spisenddata |= ((((uint32_t)ctrl.pkt) << 16) & 0xffff0000);

    resp.pkt = 0u;
    Spi_PMIC_CompleteFlag = 0u;

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&spisenddata, (Spi_DataType*)&spircvdata, 4 );
	Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_PMIC);

	while(Spi_PMIC_CompleteFlag != 1u) {	__nop(); }

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

//LSD_WritePin(LSD1, (uint16_t)((resp.pkt>>1) & 0x00FF));

  	//return (uint8_t)( ((resp.pkt>>9) & 0x003F) ) ;	 //bit14~9:  addr of cmd
  	if( (resp.msg[0] == ctrl.msg[1]) && (resp.msg[1] == ctrl.msg[0]) ){	return 0; }	//ok
  	else{ return 1; } //error
}
*/

void PMIC_EndOfCmdSeqNotification(void)
{
	Spi_PMIC_CompleteFlag = 1u;
}

void PMIC_Watchdog(void)
{
    uint8_t data;

	//WWDSCMD
	data = TLF35584_read(PMIC_ADDR_WWDSCMD) ;
	//if ( data == 0xff ) { LSD_WritePin(LSD1, (uint16_t)data); Dio_Write(DioConf_DioChannel_O_LED_01M, 1); while(1); }
	//LSD_WritePin(LSD1, (uint16_t)data);

	if(data&0x80) { data=0x00; }
	else { data=0x01; }
	TLF35584_write(PMIC_ADDR_WWDSCMD, data) ;
	//for test
	//TLF35584_write_dbg(PMIC_ADDR_WWDSCMD, data) ;
}

uint8_t PMIC_Init(void)
{
    uint8_t data;

    //DEVCFG2
	TLF35584_write(PMIC_ADDR_DEVCFG2, 0x0C);	//QUC current monitoring threshold value 100mA

	//UNLOCK -> WDCFG0변경 -> LOCK
	data = TLF35584_read(PMIC_ADDR_PROSTAT);
	if( data & 0x01 )	//lock상태이면
	{
		//UNLOCK
		TLF35584_write(PMIC_ADDR_PROTCFG, 0xAB);
		data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x10) ) { return 1; };	//error
		TLF35584_write(PMIC_ADDR_PROTCFG, 0xEF);
		data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x20) ) { return 2; };	//error
		TLF35584_write(PMIC_ADDR_PROTCFG, 0x56);
		data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x40) ) { return 3; };	//error
		TLF35584_write(PMIC_ADDR_PROTCFG, 0x12);
		data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( data & 0x01 ) { return 4; };	//error
	}

	//SYSPCFG1변경 (Protected Register 변경)
	TLF35584_write(PMIC_ADDR_SYSPCFG1, 0x00);	//ERR pin monitor disable -> 이거 하니까, 모드 전환됨!!!!!
	data = TLF35584_read(PMIC_ADDR_SYSPCFG1);		if( (data ^ 0x00) != 0xFF ) { return 5; };	//error

	//WDCFG0변경 (Protected Register 변경)
	TLF35584_write(PMIC_ADDR_WDCFG0, 0xF3);	//WWD disable
	data = TLF35584_read(PMIC_ADDR_WDCFG0);		if( (data ^ 0xF3) != 0xFF ) { return 6; };	//error

	//LOCK
	TLF35584_write(PMIC_ADDR_PROTCFG, 0xDF);
	data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x10) ) { return 7; };	//error
	TLF35584_write(PMIC_ADDR_PROTCFG, 0x34);
	data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x20) ) { return 8; };	//error
	TLF35584_write(PMIC_ADDR_PROTCFG, 0xBE);
	data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x40) ) { return 9; };	//error
	TLF35584_write(PMIC_ADDR_PROTCFG, 0xCA);
	data = TLF35584_read(PMIC_ADDR_PROSTAT);	if( !(data & 0x01) ) { return 10; };	//error

	//Note: LOCK이후 60usec경과후에, Protected Register 변경 값이 적용됨

    return 0;
}

uint8_t PMIC_ChkStatus(void) //INIT=1,NORMAL=2 or STANDBY=4 return
{
	uint8_t data = 0u ;

	data = TLF35584_read(PMIC_ADDR_DEVSTAT) ;
	if ( data == 0xff ) { return data; }   //error - [ error is 0xff.. because data bit2~0 NOT 111 ]

    return (uint8_t)( data & 0x07 );    //3bits
}

void PMIC_ChngINIT2NORMAL(void)
{
    uint8_t data;

    //Mode전환 위해서는, 2개의 register를 연속해서 write해야함.

	data = 0xEA ;
	TLF35584_write(PMIC_ADDR_DEVCTRL, data) ;

	//PMIC 내부 처리시간 확보 위해서, 여기에 delay추가 해야 하나??? -> delay없어도 됨

	data = 0x15 ;   //0x05로 해야 하나? 둘다 사용가능
	TLF35584_write(PMIC_ADDR_DEVCTRLN, data) ;
}

void PMIC_ChngNORMAL2STANDBY(void)
{
    uint8_t data;

    //Mode전환 위해서는, 2개의 register를 연속해서 write해야함.

	data = 0xEC ;
	TLF35584_write(PMIC_ADDR_DEVCTRL, data) ;

	//PMIC 내부 처리시간 확보 위해서, 여기에 delay추가 해야 하나??? -> delay없어도 됨

	data = 0x13 ;   //0x03로 해야 하나? 둘다 사용가능
	TLF35584_write(PMIC_ADDR_DEVCTRLN, data) ;
}

uint8_t PMIC_GetMonitorStatus(void)
{
	uint8_t data = 0u ;

	data = TLF35584_read(PMIC_ADDR_VMONSTAT) ;
	if ( data == 0xff ) { return data; }   //error - [ error is 0xff.. because data bit1~0 NOT 11 ]

    return (uint8_t)( data & 0xfc );    //msb 6bits
}
