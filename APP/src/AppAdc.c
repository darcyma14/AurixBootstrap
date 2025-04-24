/*
 * AppAdc.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include <math.h>
#include "AppAdc.h"

// Result buffer declaration
Adc_ValueGroupType 	Adc0_Result_Scan[NUM_OF_CHANNEL_SCAN_ADC0]	= {0};
Adc_ValueGroupType 	Adc1_Result_Scan[NUM_OF_CHANNEL_SCAN_ADC1]	= {0};

// SW counter for notification
ADC_SCAN_NOTIFICATION_COUNTER	Adc_ScanNotification;


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
void Adc0_Initialization(void)
{
	Std_ReturnType 		Adc0_BufferStatus_Scan	= 0;

	// Initialize ADC0 result buffer for each request groups
	Adc0_BufferStatus_Scan = Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc0_AutoScan, &Adc0_Result_Scan[0]);

	if(Adc0_BufferStatus_Scan == E_OK)
	{
		Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc0_AutoScan);
	}

} /* Adc0_Initialization() */

void Adc1_Initialization(void)
{
	Std_ReturnType 		Adc1_BufferStatus_Scan	= 0;

	// Initialize ADC1 result buffer for each request groups
	Adc1_BufferStatus_Scan = Adc_SetupResultBuffer(AdcConf_AdcGroup_Adc1_AutoScan, &Adc1_Result_Scan[0]);

	if(Adc1_BufferStatus_Scan == E_OK)
	{
		Adc_EnableGroupNotification(AdcConf_AdcGroup_Adc1_AutoScan);
	}

} /* Adc1_Initialization() */

void Adc0_AutoScan_Notification(void)
{
	__nop();
	Adc_ScanNotification.ADC0++;
	__nop();

} /* Adc0_AutoScan_Notification */

void Adc1_AutoScan_Notification(void)
{
	__nop();
	Adc_ScanNotification.ADC1++;
	__nop();

} /* Adc1_AutoScan_Notification */

float Adc_Volt(uint16 adcValue)
{
	float Volt = 0.0;

	Volt = ((float)adcValue/4095.0) * VAREF;
	return Volt;
}

//float Temp_MPU(uint16 adcValue)
float Temp_ChgPlugDC(uint16 adcValue)
{
	float volt, Rt, tempC;

	volt = Adc_Volt(adcValue);
	if(volt < 3.3)
		Rt = (10000.0 * volt) / (3.3 - volt);
	else
		return -100.0;		/* ERROR */

	tempC = (ParamB / (log(Rt / 47000.0) + (ParamB / (273.15 + 25.0)))) - 273.15;

	return tempC;
}

//float Temp_Oil(uint16 adcValue)
float Temp_Coolant(uint16 adcValue)
{
	float volt, Rt, tempC;

	volt = Adc_Volt(adcValue);
	if(volt < 5.0)
		Rt = (2200.0 * volt) / (5.0 - volt);
	else
		return -100.0;		/* ERROR */

	tempC = (ParamC / (log(Rt / 2129.0) + (ParamC / (273.15 + 25.0)))) - 273.15;

	return tempC;
}

//float Press(uint16 adcValue)
//{
//	float volt, pre = 0.0;
//
//	volt = Adc_Volt(adcValue);
//	if(volt < 3.3)
//		pre = (volt - 0.4991) / 0.0716;
//	else
//		pre = -100.0;		/* ERROR */
//
//	return pre;
//}

