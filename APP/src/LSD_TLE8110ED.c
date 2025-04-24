/*
 * LSD_TLE8110ED.c
 *
 *  Created on: 2022. 9. 19.
 *      Author: Elec1
 */

#include "LSD_TLE8110ED.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "AppDio.h"
#include "Pwm_17_Gtm.h"


uint8 Spi_LSD1_CompleteFlag, Spi_LSD2_CompleteFlag;

void delay_spi(uint32_t dly)
{
	uint32_t i, j;

	for(i=0;i<dly;i++)
	{
		for(j=0;j<dly;j++)
			__nop();
	}
}

uint16_t TLE8110ED_16bit_read(uint8_t LSDx, uint8_t addr) //addr 3bits //MISO시 parity cal 필요
{
	T_LSD_16BIT_CTRL ctrl ;
	T_LSD_16BIT_RESP resp;
    uint8_t tmp;

	int bit_pos ;
	uint16_t *presp = (uint16_t*)&resp ;
	uint8_t parity_count = 0u ;

    //ctrl.pkt = 0u ;
    //ctrl.K.rw = 1u ;  //read = 1, write = 0
    //ctrl.K.addr = addr ; //bit14~12: addr
    //ctrl.K.data = 0u ;

    ctrl.pkt = 0x8000;  //bit15: read = 1, write = 0
    ctrl.pkt |= (addr<<12)&0x7000; //bit14~12: addr
    ctrl.pkt |= 0u;	//bit11~0: data

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    if(LSDx == LSD1)
    {
    	Spi_LSD1_CompleteFlag = 0u;
    }
    else	//LSD2
    {
    	Spi_LSD2_CompleteFlag = 0u;
    	Dio_Write(DioConf_DioChannel_SPI0_CS3, 0);	//LSDS2_CS active(low)
    }

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	if(LSDx == LSD1)
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_LSD1);
		while(Spi_LSD1_CompleteFlag != 1u) {	__nop(); }
	}
	else	//LSD2
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_LSD2);
		while(Spi_LSD2_CompleteFlag != 1u) {	__nop(); }
		Dio_Write(DioConf_DioChannel_SPI0_CS3, 1);	//LSDS2_CS inactive(high)
	}

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

 	//MISO parity check
    for(bit_pos = 0; bit_pos < 15 ; bit_pos ++)
    {
    	if ( (*presp >> bit_pos) & 0x01u )
    	{
       		parity_count ++ ;
    	}
    }

    if ((parity_count % 2) == 0u)
    {
    	if( !(resp.pkt & 0x8000) ){ return (uint16_t)(resp.pkt & 0x03ff) ; }  //ok
    }
    else
    {
    	if( resp.pkt & 0x8000 ){ return (uint16_t)(resp.pkt & 0x03ff) ; }  //ok
    }

	return (uint16_t)0xffff ; //error
}

uint16_t TLE8110ED_16bit_write(uint8_t LSDx, uint8_t addr, uint16_t data) //addr 3bits, data 12bits //MISO시 parity cal 필요
{
	T_LSD_16BIT_CTRL ctrl ;
	T_LSD_16BIT_RESP resp;
    uint8_t tmp;

    //ctrl.pkt = data ;
    //ctrl.K.rw = 0u ;  //read = 1, write = 0
    //ctrl.K.addr = addr ;
    //ctrl.K.data = data ;

    ctrl.pkt = 0x0000;  //bit15: read = 1, write = 0
    ctrl.pkt |= (addr<<12) & 0x7000; //bit14~12: addr
    ctrl.pkt |= data & 0x0fff;	//bit11~0: data

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;

    if(LSDx == LSD1)
    {
    	Spi_LSD1_CompleteFlag = 0u;
    }
    else	//LSD2
    {
    	Spi_LSD2_CompleteFlag = 0u;
    	Dio_Write(DioConf_DioChannel_SPI0_CS3, 0);	//LSDS2_CS active(low)
    }

	Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt,(Spi_DataType*)&resp.pkt,2);
	if(LSDx == LSD1)
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_LSD1);
		while(Spi_LSD1_CompleteFlag != 1u) {	__nop(); }
	}
	else	//LSD2
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_LSD2);
		while(Spi_LSD2_CompleteFlag != 1u) {	__nop(); }
		Dio_Write(DioConf_DioChannel_SPI0_CS3, 1);	//LSDS2_CS inactive(high)
	}

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

	//need to do additional something in returning


  	return (uint16_t)0u ;	//ok
}

void LSD1_EndOfCmdSeqNotification(void)
{
	Spi_LSD1_CompleteFlag = 1u;
}

void LSD2_EndOfCmdSeqNotification(void)
{
	Spi_LSD2_CompleteFlag = 1u;
}

void LSD_init(uint8_t LSDx) //LSD1=0 or LDS2=1
{
	uint16_t data;

	if( LSDx == LSD1 )
	{
//		delay_spi(1000);

//		data = 0x5000 ;   //output제어시 SPI사용
//		data = 0x0050 ;   //output제어시 SPI사용
		data = 0x0000 ;   //output제어시 SPI사용
//		TLE8110ED_16bit_write( LSDx, LSD_ADDR_ISAxDATA, data );
		TLE8110ED_16bit_write( LSD1, LSD_ADDR_ISAxDATA, data );

//		data = 0x6000 ;   //output제어시 SPI사용
//		data = 0x0060 ;   //output제어시 SPI사용
		data = 0x0000 ;   //output제어시 SPI사용
//		TLE8110ED_16bit_write( LSDx, LSD_ADDR_ISBxDATA, data );
		TLE8110ED_16bit_write( LSD1, LSD_ADDR_ISBxDATA, data );

		Dio_Write(DioConf_DioChannel_LS2_EN, 1);	//LS2_EN active(high)
	}
	else
	{
//		delay_spi(1000);
		//No spi cmd at here
/*
		data = 0x0000 ;   //output제어시 SPI사용
//		TLE8110ED_16bit_write( LSDx, LSD_ADDR_ISAxDATA, data );
		TLE8110ED_16bit_write( LSD2, LSD_ADDR_ISAxDATA, data );

		data = 0x0000 ;   //output제어시 SPI사용
//		TLE8110ED_16bit_write( LSDx, LSD_ADDR_ISBxDATA, data );
		TLE8110ED_16bit_write( LSD2, LSD_ADDR_ISBxDATA, data );
*/

		Dio_Write(DioConf_DioChannel_LS1_EN, 1);	//LS1_EN active(high)
	}
}

uint16_t LSD_ReadPin(uint8_t LSDx) //LDS1만 사용 //10bits return
{
    uint16_t data;

    //spi send twice... get data at the 2nd response
	data = TLE8110ED_16bit_read( LSDx, LSD_ADDR_OUTxDATA ) ;
	if ( data == 0xffff) { return data; }   //error
	data = TLE8110ED_16bit_read( LSDx, LSD_ADDR_OUTxDATA ) ;
	if ( data == 0xffff) { return data; }   //error

    return (uint16_t)(data & 0x03ff);   //10bits
}

void LSD_WritePin(uint8_t LSDx, uint16_t PinState) //LDS1만 사용, PinState 10bits
{
	if( LSDx == LSD1 )
	{
		TLE8110ED_16bit_write( LSDx, LSD_ADDR_OUTxDATA, (0x0C00 | PinState) );
	}

/*
	if( LSDx == LSD2 )
	{
		//O_SL-17
		if( PinState & 0x0040 ) {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_07M, 20);	}	//50% duty
		else {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_07M, 0x0000);	}	//off = 0% duty
		//O_SL-18
		if( PinState & 0x0080 ) {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_08M, 20);	}	//50% duty
		else {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_08M, 0x0000);	}	//off = 0% duty
		//O_SL-19
		if( PinState & 0x0100 ) {	Dio_Write(DioConf_DioChannel_O_SL_09M, 1);	}	//on
		else {	Dio_Write(DioConf_DioChannel_O_SL_09M, 0);	}	//off
		//O_SL-20
		if( PinState & 0x0200 ) {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_10M, 100);	}	//50% duty
		else {	Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_O_SL_10M, 0x0000);	}	//off = 0% duty
	}
	else	//LSDx == LSD1
	{
		TLE8110ED_16bit_write( LSDx, LSD_ADDR_OUTxDATA, (0x0C00 | PinState) );
	}
*/
}


