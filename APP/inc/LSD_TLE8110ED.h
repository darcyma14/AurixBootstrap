/*
 * LSD_TLE8110ED.h
 *
 *  Created on: 2022. 9. 19.
 *      Author: Elec1
 */

#ifndef SOURCECODE_APP_INC_LSD_TLE8110ED_H_
#define SOURCECODE_APP_INC_LSD_TLE8110ED_H_


#include <stdint.h>
#include "spi.h"


#define LSD1	0
#define LSD2	1



typedef union
{
	struct
	{
		uint16_t rw : 1 ;
		uint16_t addr : 3 ;
		uint16_t data : 12 ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_LSD_16BIT_CTRL ;

typedef union
{
	struct
	{
		uint16_t parity : 1 ;
		uint16_t addr : 3 ;
		uint16_t data : 12 ;
	} K;
	uint8_t msg[2];
	uint16_t pkt;
} T_LSD_16BIT_RESP ;

/*
typedef struct{
	uint16_t rw : 1 ;
	uint16_t addr : 3 ;
	uint16_t data : 12 ;
} T_LSD_16BIT_CTRL ;

typedef struct
{
	uint16_t parity : 1 ;
	uint16_t addr : 3 ;
	uint16_t data : 12 ;
} T_LSD_16BIT_RESP ;
*/

typedef enum
{
	LSD_ADDR_OUTxDATA = 0x02u,
	LSD_ADDR_ISAxDATA = 0x05u,
	LSD_ADDR_ISBxDATA = 0x06u
} LSD_ADDR ;

extern void delay_spi(uint32_t dly);
extern uint16_t TLE8110ED_16bit_read(uint8_t LSDx, uint8_t addr); //addr 3bits //MISO시 parity cal 필요
extern uint16_t TLE8110ED_16bit_write(uint8_t LSDx, uint8_t addr, uint16_t data); //addr 3bits, data 12bits //MISO시 parity cal 필요

extern void LSD_init(uint8_t LSDx); //LSD1=0 or LDS2=1
extern uint16_t LSD_ReadPin(uint8_t LSDx); //LDS1만 사용 //10bits return
extern void LSD_WritePin(uint8_t LSDx, uint16_t PinState); //LDS1만 사용, PinState 10bits


#endif /* SOURCECODE_APP_INC_LSD_TLE8110ED_H_ */
