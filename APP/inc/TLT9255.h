/*
 * TLT9255.h
 *
 *  Created on: 2022. 9. 26.
 *      Author: Elec1
 */

#ifndef SOURCECODE_APP_INC_TLT9255_H_
#define SOURCECODE_APP_INC_TLT9255_H_

#include <stdint.h>
#include "spi.h"


#define CAN1	0
#define CAN2	1

typedef union
{
	struct
	{
		uint16_t rw : 1 ;
		uint16_t addr : 7 ;
		uint16_t data : 8 ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_CAN_16BIT_CTRL ;

typedef union
{
	struct
	{
	    uint8_t status_info ;
	    uint8_t data ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_CAN_16BIT_RESP ;

typedef enum
{
	//	//need not to cleare in cases of bit5,bit0
	//	if( status_info &= 0x90 )	CAN_ADDR_ERR_STAT clr	//bit7,bit4
	//	if( status_info &= 0x44 )	CAN_ADDR_TRANS_STAT clr //bit6,bit2
	//	if( status_info &= 0x08 )	CAN_ADDR_WAKE_STAT clr	//bit3
	//	if( status_info &= 0x02 )	CAN_ADDR_TRANS_UV_STAT clr	//bit1

	CAN_ADDR_MODE_CTRL = 0x01u,
	CAN_ADDR_HW_CTRL = 0x02u,
	CAN_ADDR_TRANS_STAT = 0x18u,
	CAN_ADDR_TRANS_UV_STAT = 0x19u,
	CAN_ADDR_ERR_STAT = 0x1Au,
	CAN_ADDR_WAKE_STAT = 0x1Bu,
} CAN_TLT9255_ADDR ;


extern uint8_t TLT9255_read(uint8_t CANx, uint8_t addr); //, uint8_t *rsp_statinfo); //addr 7bits
extern uint8_t TLT9255_write(uint8_t CANx, uint8_t addr, uint8_t data); //, uint8_t *rsp_statinfo); //addr 7bits, data 8bits

extern void TLT9255_Init(uint8_t CANx);
extern uint8_t TLT9255_ChkStatus(uint8_t CANx); //SLEEP=0001B, STANDBY=0010B, RCVONLY=0100B or NORMAL=1000B return
extern void TLT9255_Chng2NORMAL(uint8_t CANx);
extern void TLT9255_Chng2SLEEP(uint8_t CANx);

#endif /* SOURCECODE_APP_INC_TLT9255_H_ */
