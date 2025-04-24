/*
 * AppIcu.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef APPICU_H_
#define APPICU_H_ (0)

#include <stdint.h>
#include "Gpt.h"
#include "Icu_17_GtmCcu6.h"

#define ICU_CLOCK_FREQ	10000000u
#define I_PH_02M 	IcuConf_IcuChannel_I_PH_02M
#define I_PH_03M 	IcuConf_IcuChannel_I_PH_03M
#define I_PH_04M 	IcuConf_IcuChannel_I_PH_04M

extern void ICU_Init(void);
extern void CoolingFanSpd_GetDuty(uint16_t *nDutyPecent);
extern void EVCoolingWaterPumpSpd_GetDuty(uint16_t *nDutyPecent);
extern void SbwsOut_GetFreq(uint32_t *freqVal);
extern void ICU_Deinit(void);

//extern int Counter4ChangeUnit;
//
//extern int	Speed_Count_100ms;
//extern int	Speed_Count_500ms;
//extern int	Speed_Count_1s;
//
//extern float	Speed_RPM_100ms;
//extern float	Speed_RPM_500ms;
//extern float	Speed_RPM_1s;
//
//extern float	Speed_RPM;
//
//extern void Init_Speed(void);
//extern float Read_Speed(void);

#endif /* APPICU_H_ */
