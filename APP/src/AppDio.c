/*
 * AppDio.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include "AppDio.h"


Dio_LevelType Dio_Read(Dio_ChannelType channel)
{
	Dio_LevelType RetVal;

	RetVal = Dio_ReadChannel(channel);
	return RetVal;
}

void Dio_Write(Dio_ChannelType channel, Dio_LevelType OnOff)
{
	Dio_WriteChannel(channel, OnOff);
}

void Init_LED(void)
{
	Dio_Write(TS_LED, ON);
	Dio_Write(LED_EN, ON);
	Dio_Write(O_LED_01M, OFF);
	Dio_Write(O_LED_02M, OFF);
	Dio_Write(O_LED_03M, OFF);
}
