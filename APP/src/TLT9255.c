/*
 * TLT9255.c
 *
 *  Created on: 2022. 9. 26.
 *      Author: Elec1
 */

#include "TLT9255.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "AppDio.h"

//for debug
#include "LSD_TLE8110ED.h"
//

uint8 Spi_CAN1_CompleteFlag, Spi_CAN2_CompleteFlag;

uint8_t TLT9255_read(uint8_t CANx, uint8_t addr) //addr 7bits
{
	T_CAN_16BIT_CTRL ctrl ;
	T_CAN_16BIT_RESP resp ;
    uint8_t tmp;

    //ctrl.rw = 0u ;  //bit15: read = 0, write = 1
    //ctrl.addr = addr ; //bit14~8: addr
    //ctrl.data = 0u ;	//bit7~0: data

    ctrl.pkt = 0x0000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (((uint16_t)addr)<<8)&0x7F00; //bit14~8: addr
    ctrl.pkt |= (uint16_t)0u;	//bit7~0: data

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    if(CANx == CAN1)
    {
    	Spi_CAN1_CompleteFlag = 0u;
    }
    else	//CAN2
    {
    	Spi_CAN2_CompleteFlag = 0u;
    }

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	if( CANx == CAN1 )
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_CAN1);
		while(Spi_CAN1_CompleteFlag != 1u) {	__nop(); }
	}
	else
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_CAN2);
		while(Spi_CAN2_CompleteFlag != 1u) {	__nop(); }
	}


    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

    //bit15~8: status information field
//    if ( resp.pkt & 0x8000 ) { return (uint8_t)0xff ; }	//spi error

    //문제 - return값으로 ok와 error가 구분 안됨!!!!!!!!!!!!!!

    return (uint8_t)( resp.pkt & 0xff ) ;  //ok
}

uint8_t TLT9255_write(uint8_t CANx, uint8_t addr, uint8_t data) //addr 7bits, data 8bits
{
	T_CAN_16BIT_CTRL ctrl ;
	T_CAN_16BIT_RESP resp ;
    uint8_t tmp;

    //ctrl.rw = 1u ;
    //ctrl.addr = addr ;
    //ctrl.data = data ;

    ctrl.pkt = 0x8000;  //bit15: read = 0, write = 1
    ctrl.pkt |= (((uint16_t)addr)<<8)&0x7F00; //bit14~8: addr
    ctrl.pkt |= (uint16_t)data;	//bit7~0: data

    //reverse byte-order
    tmp = ctrl.msg[0];
    ctrl.msg[0] = ctrl.msg[1];
    ctrl.msg[1] = tmp;

    resp.pkt = 0u;
    if(CANx == CAN1)
    {
    	Spi_CAN1_CompleteFlag = 0u;
    }
    else	//CAN2
    {
    	Spi_CAN2_CompleteFlag = 0u;
    }

	Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_HSD, (Spi_DataType*)&ctrl.pkt, (Spi_DataType*)&resp.pkt, 2 );
	if( CANx == CAN1 )
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_CAN1);
		while(Spi_CAN1_CompleteFlag != 1u) {	__nop(); }
	}
	else
	{
		Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_CAN2);
		while(Spi_CAN2_CompleteFlag != 1u) {	__nop(); }
	}

    //reverse byte-order
    tmp = resp.msg[0];
    resp.msg[0] = resp.msg[1];
    resp.msg[1] = tmp;

    //bit15~8: status information field
//    if ( resp.pkt & 0x8000 ) { return 1; }	//spi error

    return 0;  //ok
}

void CAN1_EndOfCmdSeqNotification(void)
{
	Spi_CAN1_CompleteFlag = 1u;
}

void CAN2_EndOfCmdSeqNotification(void)
{
	Spi_CAN2_CompleteFlag = 1u;
}

void TLT9255_Init(uint8_t CANx)
{
	uint8_t data;

	data = 0x23;	//0xA3;	//0x01 ;
	TLT9255_write(CANx, CAN_ADDR_HW_CTRL, (uint8_t)(data));	//clear bits

	data = TLT9255_read(CANx, CAN_ADDR_ERR_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_ERR_STAT, (uint8_t)(data));	//clear bits

	data = TLT9255_read(CANx, CAN_ADDR_TRANS_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_TRANS_STAT, (uint8_t)(data));	//clear bits

	data = TLT9255_read(CANx, CAN_ADDR_WAKE_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_WAKE_STAT, (uint8_t)(data));	//clear bits

//#define	CAN1_LED_DISP
//#define	CAN2_LED_DISP
#ifdef CAN1_LED_DISP
	if(CANx==CAN1) {	LSD_WritePin(LSD1, (uint16_t)data | 0x0100); }
	else {	; }	//LSD_WritePin(LSD1, (uint16_t)data | 0x0200); }
	delay_spi(10000);
#endif
#ifdef CAN2_LED_DISP
	if(CANx==CAN2) {	LSD_WritePin(LSD1, (uint16_t)data | 0x0100); }
	delay_spi(10000);
#endif

}

uint8_t TLT9255_ChkStatus(uint8_t CANx) //SLEEP=0001B, STANDBY=0010B, RCVONLY=0100B or NORMAL=1000B return
{
	uint8_t data = 0u ;

	data = TLT9255_read(CANx, CAN_ADDR_MODE_CTRL) ;
//	if ( data == 0xff ) { return data; }   //error

//    return (uint8_t)( data & 0x0f );    //4bits
    return (uint8_t)( data & 0xff );
}

void TLT9255_Chng2NORMAL(uint8_t CANx)
{
    uint8_t data;

	data = 0x08 ;
	TLT9255_write(CANx, CAN_ADDR_MODE_CTRL, data) ;
}

void TLT9255_Chng2SLEEP(uint8_t CANx)
{
    uint8_t data;

    //TLT9255_Init(CANx);
	data = TLT9255_read(CANx, CAN_ADDR_ERR_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_ERR_STAT, (uint8_t)(data));	//clear bits

	data = TLT9255_read(CANx, CAN_ADDR_TRANS_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_TRANS_STAT, (uint8_t)(data));	//clear bits

	data = TLT9255_read(CANx, CAN_ADDR_WAKE_STAT) ;
	TLT9255_write(CANx, CAN_ADDR_WAKE_STAT, (uint8_t)(data));	//clear bits


	data = 0xA3;	//0x01 ;
	TLT9255_write(CANx, CAN_ADDR_HW_CTRL, (uint8_t)(data));	//clear bits

	data = 0x01 ;
	TLT9255_write(CANx, CAN_ADDR_MODE_CTRL, data) ;
}

