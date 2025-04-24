/*
 * AppDio.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include "AppIcu.h"
//#define	PULSE_ROTATION	51.0
//
//int Counter4ChangeUnit = 0;		//to calculate 500ms, 1s speed
//
//int	Speed_Count_100ms = 0;
//int	Speed_Count_500ms = 0;
//int	Speed_Count_1s = 0;
//
//float	Speed_RPM_100ms = 0;
//float	Speed_RPM_500ms = 0;
//float	Speed_RPM_1s = 0;
//
//float	Speed_RPM = 0.0;

void ICU_Init(void)
{
	Icu_17_GtmCcu6_StartSignalMeasurement(I_PH_02M);
	Icu_17_GtmCcu6_StartSignalMeasurement(I_PH_03M);
	Icu_17_GtmCcu6_StartSignalMeasurement(I_PH_04M);
}

void CoolingFanSpd_GetDuty(uint16_t *nDutyPecent)
{
	Icu_17_GtmCcu6_DutyCycleType DutyCycle = {0x0};
	float dutyVal;

	Icu_17_GtmCcu6_GetDutyCycleValues(I_PH_02M,&DutyCycle);
	if(DutyCycle.PeriodTime != 0)
	{
		dutyVal = ((float)DutyCycle.ActiveTime / (float)DutyCycle.PeriodTime)*100.0;
		*nDutyPecent = (uint16_t)dutyVal;
	}
	else
	{
		*nDutyPecent = 0u;
	}
}

void EVCoolingWaterPumpSpd_GetDuty(uint16_t *nDutyPecent)
{
	Icu_17_GtmCcu6_DutyCycleType DutyCycle = {0x0};
	float dutyVal;

	Icu_17_GtmCcu6_GetDutyCycleValues(I_PH_04M,&DutyCycle);
	if(DutyCycle.PeriodTime != 0)
	{
		dutyVal = ((float)DutyCycle.ActiveTime / (float)DutyCycle.PeriodTime)*100.0;
		*nDutyPecent = (uint16_t)dutyVal;
	}
	else
	{
		*nDutyPecent = 0u;
	}
}

void SbwsOut_GetFreq(uint32_t *freqVal)
{
	Icu_17_GtmCcu6_DutyCycleType DutyCycle = {0x0};

	Icu_17_GtmCcu6_GetDutyCycleValues(I_PH_03M,&DutyCycle);
	if(DutyCycle.PeriodTime != 0)
	{
		*freqVal = (uint32_t)(ICU_CLOCK_FREQ / DutyCycle.PeriodTime);

		//david 20220929	10% down
		*freqVal = (*freqVal / 11) * 10;
	}
	else
	{
		*freqVal = 0u;
	}
}

void ICU_Deinit(void)
{
	Icu_17_GtmCcu6_StopSignalMeasurement(I_PH_02M);
	Icu_17_GtmCcu6_StopSignalMeasurement(I_PH_03M);
	Icu_17_GtmCcu6_StopSignalMeasurement(I_PH_04M);
}


//void Init_Speed(void)
//{
//	Icu_17_GtmCcu6_SetActivationCondition(IcuConf_IcuChannel_IcuChannel_0, ICU_RISING_EDGE);
//	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_IcuChannel_0);
//
//	Gpt_EnableNotification(GptConf_GptChannel_Gpt_100ms);
//	Gpt_StartTimer(GptConf_GptChannel_Gpt_100ms, 2441);	//100ms --> 2441
//}

void Gpt_100ms_Notification(void)
{
//	Speed_RPM = Read_Speed();
}

void Edge_Notification(void)
{
//	Speed_Count_100ms++;
//	Speed_Count_500ms++;
//	Speed_Count_1s++;
}

//float Read_Speed(void)
//{
//	Counter4ChangeUnit ++;
//
//	float Cur_RPM_100ms = 0.0;
//	float Cur_Count_100ms = 0.0;
//	static float Cur_RPM_500ms = 0.0;
//	static float Cur_Count_500ms = 0.0;
//	static float Cur_RPM_1s = 0.0;
//	static float Cur_Count_1s = 0.0;
//
//	//100ms
//	Cur_Count_100ms = (float)Speed_Count_100ms;
//	Speed_Count_100ms = 0;
//	Cur_RPM_100ms = (60.0/0.1) * (Cur_Count_100ms/PULSE_ROTATION);
//
//	//500ms
//	if(Counter4ChangeUnit % 5u == 0u)
//	{
//		Cur_Count_500ms = (float)Speed_Count_500ms;
//		Speed_Count_500ms = 0;
//		Cur_RPM_500ms = (60.0/0.5)*(Cur_Count_500ms/PULSE_ROTATION);
//	}
//
//	//1s
//	if(Counter4ChangeUnit % 10u == 0u)
//	{
//		Cur_Count_1s = (float)Speed_Count_1s;
//		Speed_Count_1s = 0;
//		Cur_RPM_1s = (60.0/1.0)*(Cur_Count_1s/PULSE_ROTATION);
//		Counter4ChangeUnit = 0;
//	}
//
//	//variable (return값은 셋 중의 한 값만 보이므로 변수에 대입)
//	Speed_RPM_100ms = Cur_RPM_100ms;
//	Speed_RPM_500ms = Cur_RPM_500ms;
//	Speed_RPM_1s = Cur_RPM_1s;
//
//	if(Cur_Count_100ms > 10.0)
//		return Cur_RPM_100ms;
//
//	else if(Cur_Count_500ms > 10.0)
//		return Cur_RPM_500ms;
//
//	else
//		return Cur_RPM_1s;
//}
