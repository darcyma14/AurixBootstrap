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
#define HSD_I0      DioConf_DioChannel_HSD_I0
#define HSD_I1      DioConf_DioChannel_HSD_I1
#define HSD_I2      DioConf_DioChannel_HSD_I2
#define HSD_I3      DioConf_DioChannel_HSD_I3
#define HSD_SEL0    DioConf_DioChannel_HSD_SEL0
#define HSD_SEL1    DioConf_DioChannel_HSD_SEL1
#define HSD_SEL2    DioConf_DioChannel_HSD_SEL2
#define HSD_SEn     DioConf_DioChannel_HSD_SEn
#define HSD_FAULT   DioConf_DioChannel_HSD_FAULT
#define LED1        DioConf_DioChannel_LED1
#define LED2        DioConf_DioChannel_LED2

/* Input Channel */
#define POS_SEN_R   DioConf_DioChannel_POS_SEN_R
#define POS_SEN_L   DioConf_DioChannel_POS_SEN_L
#define PMIC_BIST   DioConf_DioChannel_PMIC_BIST
#define PMIC_DBG    DioConf_DioChannel_PMIC_DBG

extern Dio_LevelType Dio_Read(Dio_ChannelType channel);
extern void Dio_Write(Dio_ChannelType channel, Dio_LevelType OnOff);
extern void Init_LED(void);

#endif /* APPDIO_H_ */
