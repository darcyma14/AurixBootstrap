/*
 * AppDio.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include "AppIcu.h"
#define PULSE_ROTATION  12.0

int Speed_Count = 0;
float   Speed_RPM = 0.0;

void Init_Speed(void)
{
    Icu_17_GtmCcu6_SetActivationCondition(IcuConf_IcuChannel_IcuChannel_0, ICU_RISING_EDGE);
    Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_IcuChannel_0);

    Gpt_EnableNotification(GptConf_GptChannel_Gpt_100ms);
    Gpt_StartTimer(GptConf_GptChannel_Gpt_100ms, 2441);
}

void Gpt_100ms_Notification(void)
{
    Speed_RPM = Read_Speed();
}

void Edge_Notification(void)
{
    Speed_Count++;
}

float Read_Speed(void)
{
    float Cur_RPM = 0.0;
    float Cur_Count = (float)Speed_Count;

    Speed_Count = 0;
    Cur_RPM = (60.0/0.1) * (Cur_Count/PULSE_ROTATION);

    return Cur_RPM;
}
