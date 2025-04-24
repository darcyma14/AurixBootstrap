/*
 * AppCan.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef APPCAN_H_
#define APPCAN_H_ (0)

#include "Can_17_MCanP.h"
#include "ComStack_Types.h"

#define MO_ESCS	Can_17_MCanPConf_CanHardwareObject_MO_ESCS
#define MO_MCU	Can_17_MCanPConf_CanHardwareObject_MO_MCU
#define MO_CRM	Can_17_MCanPConf_CanHardwareObject_MO_CRM
#define MO_ESCC	Can_17_MCanPConf_CanHardwareObject_MO_ESCC
#define MO_DTO	Can_17_MCanPConf_CanHardwareObject_MO_DTO
#define MO_DTM	Can_17_MCanPConf_CanHardwareObject_MO_DTM

#define MO_VEH		Can_17_MCanPConf_CanHardwareObject_MO_VEH
#define MO_DEBUG1	Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1
#define MO_DEBUG2	Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2
#define MO_DEBUG3	Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3

// -- added by KMS 2022.09.27 ----------
#define MO1_6B0H	Can_17_MCanPConf_CanHardwareObject_MO1_6B0h		// Rx
#define MO1_100H	Can_17_MCanPConf_CanHardwareObject_MO1_100h
#define MO1_101H	Can_17_MCanPConf_CanHardwareObject_MO1_101h
#define MO1_6C0H	Can_17_MCanPConf_CanHardwareObject_MO1_6C0h

#define MO2_6B0H	Can_17_MCanPConf_CanHardwareObject_MO2_6B0h		// Rx
#define MO2_100H	Can_17_MCanPConf_CanHardwareObject_MO2_100h
#define MO2_101H	Can_17_MCanPConf_CanHardwareObject_MO2_101h
#define MO2_6C0H	Can_17_MCanPConf_CanHardwareObject_MO2_6C0h

// -------------------------------------

/* extern uint8 Test_RxConfirmCount; */
extern uint8 ESCC_TxConfirmCount, DEBUG1_TxConfirmCount, DEBUG2_TxConfirmCount, DEBUG3_TxConfirmCount;
extern uint8 DTO_TxConfirmCount, DTM_TxConfirmCount;

extern void AppCAN_Init(void);
extern void AppCAN_Send (Can_HwHandleType Hth, Can_PduType *Can_MsgBox);

#endif /* APPCAN_H_ */
