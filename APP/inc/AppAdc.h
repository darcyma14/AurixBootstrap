/*
 * AppAdc.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef APPADC_H_
#define APPADC_H_

#include <stdint.h>
#include "Adc.h"

typedef enum
{
	I_AH_T5M,
	I_AL_APS2M,
	IGN_AI,
	I_AH_T1M
} MyADC0;

typedef enum
{
	I_AX_CRZM,
	I_AL_APS1M,
	ACC_AI,
	VSUP_AI
} MyADC1;

typedef struct
{
	uint16	ADC0;
	uint16	ADC1;
} ADC_SCAN_NOTIFICATION_COUNTER;

#define NUM_OF_CHANNEL_SCAN_ADC0	(4)
#define NUM_OF_CHANNEL_SCAN_ADC1	(4)
#define VAREF						(5.0)
#define ParamB						(4131.0)
#define ParamC						(3541.0)

extern ADC_SCAN_NOTIFICATION_COUNTER	Adc_ScanNotification;
extern Adc_ValueGroupType 	Adc0_Result_Scan[NUM_OF_CHANNEL_SCAN_ADC0];
extern Adc_ValueGroupType 	Adc1_Result_Scan[NUM_OF_CHANNEL_SCAN_ADC1];

extern void Adc0_Initialization(void);
extern void Adc1_Initialization(void);
extern void Adc0_AutoScan_Notification(void);
extern void Adc1_AutoScan_Notification(void);
extern float Adc_Volt(uint16 adcValue);
extern float Temp_ChgPlugDC(uint16 adcValue);
extern float Temp_Coolant(uint16 adcValue);
//extern float Press(uint16 adcValue);

#endif /* APPADC_H_ */
