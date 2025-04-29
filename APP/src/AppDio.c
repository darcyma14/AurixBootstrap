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
    Dio_Write(LED1, ON);
    Dio_Write(LED2, ON);
}
