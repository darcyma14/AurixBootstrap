/*
 * AppDio.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef APPDIO_H_
#define APPDIO_H_ (0)

#include <stdint.h>
#include "Dio.h"

/* Output Channel */
#define LSD1_EN		DioConf_DioChannel_LS2_EN
#define LSD2_EN		DioConf_DioChannel_LS1_EN
#define LSD2_CS		DioConf_DioChannel_SPI0_CS3		// LSD2 CS, GPIO control
#define LSD2_MPS	DioConf_DioChannel_PMIC_MPS
#define LIN1_EN		DioConf_DioChannel_LIN1_EN
#define LIN2_EN		DioConf_DioChannel_LIN2_EN
#define O_SL_09M	DioConf_DioChannel_O_SL_09M
#define TS_LED		DioConf_DioChannel_TS_LED		// for Tsmart status Led
#define O_SH_02M	DioConf_DioChannel_O_SH_02M
#define CAN3_NEN	DioConf_DioChannel_CAN3_NEN
#define LED_EN		DioConf_DioChannel_LED_EN
#define O_LED_01M	DioConf_DioChannel_O_LED_01M
#define O_LED_02M	DioConf_DioChannel_O_LED_02M
#define O_LED_03M	DioConf_DioChannel_O_LED_03M
#define PMIC_ERR	DioConf_DioChannel_PMIC_ERR

/* Input Channel */
#define PMIC_SS1	DioConf_DioChannel_PMIC_SS1
#define PMIC_SS2	DioConf_DioChannel_PMIC_SS2
#define I_SH_02M	DioConf_DioChannel_I_SH_02M
#define I_SH_03M	DioConf_DioChannel_I_SH_03M
#define I_SH_05M	DioConf_DioChannel_I_SH_05M
#define I_SH_06M	DioConf_DioChannel_I_SH_06M
#define LED_ERRN	DioConf_DioChannel_LED_ERRN
#define I_SL_01M	DioConf_DioChannel_I_SL_01M
#define I_SL_02M	DioConf_DioChannel_I_SL_02M
#define I_SL_03M	DioConf_DioChannel_I_SL_03M
#define I_SL_04M	DioConf_DioChannel_I_SL_04M
#define I_SL_06M	DioConf_DioChannel_I_SL_06M
#define I_SL_07M	DioConf_DioChannel_I_SL_07M
#define I_SL_08M	DioConf_DioChannel_I_SL_08M
#define I_SL_09M	DioConf_DioChannel_I_SL_09M
#define I_SL_10M	DioConf_DioChannel_I_SL_10M

extern Dio_LevelType Dio_Read(Dio_ChannelType channel);
extern void Dio_Write(Dio_ChannelType channel, Dio_LevelType OnOff);
extern void Init_LED(void);

#endif /* APPDIO_H_ */
