/*
 * PMIC_TLF35584.h
 *
 *  Created on: 2022. 9. 20.
 *      Author: Elec1
 */

#ifndef SOURCECODE_APP_INC_PMIC_TLF35584_H_
#define SOURCECODE_APP_INC_PMIC_TLF35584_H_

#include <stdint.h>
#include "spi.h"

typedef union
{
	struct
	{
		uint16_t rw : 1 ;
		uint16_t addr : 6 ;
		uint16_t data : 8 ;
		uint16_t parity : 1 ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_PMIC_CTRL ;

typedef union
{
	struct
	{
	    uint16_t fixed_1 : 1 ;
	    uint16_t unknown_stat : 6 ;	//when read		//this field is addr in case of write
	    uint16_t data : 8 ;
		uint16_t parity : 1 ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_PMIC_RESP ;

typedef enum
{
	PMIC_ADDR_DEVCFG2 = 0x02u,
	PMIC_ADDR_PROTCFG = 0x03u,
	PMIC_ADDR_SYSPCFG1 = 0x05u,
	PMIC_ADDR_WDCFG0 = 0x06u,
	PMIC_ADDR_DEVCTRL = 0x15u,
	PMIC_ADDR_DEVCTRLN = 0x16u,
	PMIC_ADDR_WWDSCMD = 0x17u,
	PMIC_ADDR_SYSSF = 0x1D,
	PMIC_ADDR_VMONSTAT = 0x26,
	PMIC_ADDR_DEVSTAT = 0x27u,
	PMIC_ADDR_PROSTAT = 0x28u,	//protected register lock status
	PMIC_ADDR_WWDSTAT = 0x29	//window watchdog error counter
} PMIC_TLF35584_NORMAL_ADDR ;


extern uint8_t TLF35584_read(uint8_t addr); //addr 6bits //MOSI및 MISO시 parity cal 필요
extern uint8_t TLF35584_write(uint8_t addr, uint8_t data); //addr 6bits, data 8bits //MOSI및 MISO시 parity cal 필요

extern void PMIC_Watchdog(void);
extern uint8_t PMIC_Init(void);
extern uint8_t PMIC_ChkStatus(void); //INIT=1,NORMAL=2 or STANDBY=4 return
extern void PMIC_ChngINIT2NORMAL(void);
extern void PMIC_ChngNORMAL2STANDBY(void);
extern uint8_t PMIC_GetMonitorStatus(void);

#endif /* SOURCECODE_APP_INC_PMIC_TLF35584_H_ */
