/*
 * E110_Variables.h
 *
 *  Created on: 2018. 3. 21.
 *      Author: jinwo
 */

#ifndef E110_VARIABLES_H_
#define E110_VARIABLES_H_ (0)


#include <stdint.h>
#include "AppCan.h"
#include "E110_CanMsg_Defines.h"
#include "E110_variables.h"
#include "E110_Struct_Defines.h"
#include "E110_Enum_Defines.h"

//#include "EAXEL_CanMsg_Define.h"
//#include "EAXLE_control.h"

extern uint32_t __far VfCALIB_PageIndex ;
extern Can_PduType VSCANN_CCPCRM_MsgBox ;
extern Can_PduType VSCANN_CCPDTO_MsgBox ;
extern Can_PduType VSCANN_CCPDTM_MsgBox ;

extern uint32_t __far VbCALB_CCPCRM_Received ;
extern uint8_t __far VaCALB_CCPCRM_Data[] ;

//Torque
extern float __far VfVIOS_Torque ;

//Spd
extern float __far VfVIOS_Speed_RPM ;
extern float __far VfVIOS_VehSpeed ;
extern float __far VfVIOS_MotSpeed ;

//TCU -> EOP Controller(ESCC)
extern Can_PduType VSCANN_ESCC_MsgBox ;
extern TxTCU_ESCC __far VSCANN_ESCC ;

//TCU -> EOP Controller(DEBUG1)		// by KMS
extern Can_PduType VSCANN_DEBUG1_MsgBox ;
extern TxTCU_debug1 __far VSCANN_DEBUG1 ;

//TCU -> EOP Controller(DEBUG2)		// by KMS
extern Can_PduType VSCANN_DEBUG2_MsgBox ;
extern TxTCU_debug2 __far VSCANN_DEBUG2 ;

//TCU -> EOP Controller(DEBUG3)		// by KMS
extern Can_PduType VSCANN_DEBUG3_MsgBox ;
extern TxTCU_debug3 __far VSCANN_DEBUG3 ;

// -- added by KMS 2022.09.27 ----------
//CAN1 : TxVCU_100H
extern Can_PduType VSCANN1_100H_MsgBox ;
extern TxVCU_100H __far VSCANN1_100H ;
//CAN1 : TxVCU_101H
extern Can_PduType VSCANN1_101H_MsgBox ;
extern TxVCU_101H __far VSCANN1_101H ;
//CAN1 : TxVCU_6C0H
extern Can_PduType VSCANN1_6C0H_MsgBox ;
extern TxVCU_6C0H __far VSCANN1_6C0H ;

//CAN2 : TxVCU_100H
extern Can_PduType VSCANN2_100H_MsgBox ;
extern TxVCU_100H __far VSCANN2_100H ;
//CAN2 : TxVCU_101H
extern Can_PduType VSCANN2_101H_MsgBox ;
extern TxVCU_101H __far VSCANN2_101H ;
//CAN2 : TxVCU_6C0H
extern Can_PduType VSCANN2_6C0H_MsgBox ;
extern TxVCU_6C0H __far VSCANN2_6C0H ;

//CAN1 : RxVCU_6B0H
extern Can_PduType VSCANN1_6B0H_MsgBox ;
extern uint32_t __far VSCANN1_6B0H_Received ;
extern uint8_t __far VSCANN1_6B0H_Data[] ;
//CAN2 : RxVCU_6B0H
extern Can_PduType VSCANN2_6B0H_MsgBox ;
extern uint32_t __far VSCANN2_6B0H_Received ;
extern uint8_t __far VSCANN2_6B0H_Data[] ;
//--------------------------------------

//EOP Controller -> TCU (ESCS)
extern Can_PduType VSCANN_ESCS_MsgBox ;
extern uint32_t __far VbCALB_ESCS_Received ;
extern uint8_t __far VaCALB_ESCS_Data[] ;
extern RxTCU_ESCS __far VSCANN_ESCS ;

//MCU by KMS
extern Can_PduType VSCANN_MCU_MsgBox ;
extern uint32_t __far VbCALB_MCU_Received ;
extern uint8_t __far VaCALB_MCU_Data[] ;
extern RxTCU_MCU __far VSCANN_MCU ;

//VEH by KMS
extern Can_PduType VSCANN_VEH_MsgBox ;
extern uint32_t __far VbCALB_VEH_Received ;
extern uint8_t __far VaCALB_VEH_Data[] ;
extern RxTCU_VEH __far VSCANN_VEH ;

//ADC
extern uint16_t __far VcADC_SIG_G1 ;
extern float __far VfVIOS_u_SIG_G1_Voltage ;

extern uint16_t __far VcADC_SIG_G2 ;
extern float __far VfVIOS_u_SIG_G2_Voltage ;

extern uint16_t __far VcADC_SIG_TQ_L ;
extern float __far VfVIOS_u_SIG_TQ_L_Voltage ;

extern uint16_t __far VcADC_SIG_TQ_R ;
extern float __far VfVIOS_u_SIG_TQ_R_Voltage ;

extern uint16_t __far VcADC_SIG_TOTAL ;
extern float __far VfVIOS_u_SIG_TOTAL_Voltage ;

extern float __far VfVIOS_bar_SIG_PRES_G1;
extern float __far VfVIOS_bar_SIG_PRES_G2;
extern float __far VfVIOS_bar_SIG_PRES_TQ_L;
extern float __far VfVIOS_bar_SIG_PRES_TQ_R;
extern float __far VfVIOS_bar_SIG_PRES_MAIN;

extern uint16_t __far VcADC_SIG_TMP_OIL ;
extern float __far VfVIOS_SIG_TMP_OIL ;

extern uint16_t __far VcADC_SIG_PRES_TMP_SPR ;

extern uint8_t __far VbDI_EPRK_R ;
extern uint8_t __far VbDI_EPRK_L ;

extern float __far VfVIOS_Tq_Command ;
extern float __far VfVIOS_EOP_Ctrl_Value_Main_rpm;
extern float __far VfVIOS_Sol_Ctrl_Value_G1_A;
extern float __far VfVIOS_Sol_Ctrl_Value_G2_A;
extern float __far VfVIOS_Sol_Ctrl_Value_TV_R_A;
extern float __far VfVIOS_Sol_Ctrl_Value_TV_L_A;

extern float __far VfVIOS_Final_Tq_Command;
extern float __far VfVIOS_Final_EOP_Ctrl_Value_Main_rpm;
extern float __far VfVIOS_Final_Sol_Ctrl_Value_G1_A;
extern float __far VfVIOS_Final_Sol_Ctrl_Value_G2_A;
extern float __far VfVIOS_Final_Sol_Ctrl_Value_TV_R_A;
extern float __far VfVIOS_Final_Sol_Ctrl_Value_TV_L_A;

extern uint8_t __far VeVIOS_Gear_State;
extern uint8_t __far VeVIOS_DNR_State ;

extern float __far VfVIOS_DelayTime_1To2_G1;
extern float __far VfVIOS_DelayTime_1To2_G2;
extern float __far VfVIOS_DelayTime_2To1_G1;
extern float __far VfVIOS_DelayTime_2To1_G2;

void EMC_variables_init(void);




// KY 20220924 add 3 lines
#define can_message_t 	Can_PduType

#ifdef _E110_DUP
// global var -> extern
// Rx MsgBox flag & Data[8] --> extern
// Tx MsgBox var

extern uint32_t __far VfCALIB_PageIndex ;
extern Can_PduType VSCANN_CCPCRM_MsgBox ;
extern Can_PduType VSCANN_CCPDTO_MsgBox ;
extern Can_PduType VSCANN_CCPDTM_MsgBox ;

extern uint32_t __far VbCALB_CCPCRM_Received ;
extern uint8_t __far VaCALB_CCPCRM_Data[] ;

#endif


#define SCHEDCHRG_START 			0
#define SCHEDCHRG_START_FAIL 		1
#define SCHEDCHRG_STOP 				2
#define SCHEDCHRG_STOP_FAIL 		3

//1D6H_CHRGSTART_FAIL_REAS
#define CHRGSTART_FAIL_NOTREADY2CHRG 0
#define CHRGSTART_FAIL_INCHRGING 	 1
#define CHRGSTART_FAIL_ALREADYCHRGED 2
#define CHRGSTART_FAIL_EVSEFAULT 	 3
#define CHRGSTART_FAIL_VEHPROBLEM 	240
#define CHRGSTART_FAIL_NOFAIL		255

//1D6H_CHRGSTOP_FAIL_REAS
#define CHRGSTOP_FAIL_ALREADYSTOPPED 0
#define CHRGSTOP_FAIL_VEHPROBLEM     240
#define CHRGSTOP_FAIL_NOFAIL		 255

//1D7H_CHRGFINISH
#define CHRGFINISH_BYSCHED						0
#define CHRGFINISH_BYIMMEDIATEOFCCU				1
#define CHRGFINISH_STOPDURINGSCHED				2
#define CHRGFINISH_STOPDURINGIMMEDIATEOFCCU		3

//1D7H_CHRGSTOPREAS
#define CHRGSTOP_GUNDISCONNECTED				2
#define CHRGSTOP_EVSEFAULT						3
#define CHRGSTOP_REQBYFOBKEY					4
#define CHRGSTOP_REQBYAVNCMD					5
#define CHRGSTOP_EVSEnEMERGENCYSTOP				7
#define CHRGSTOP_VEHPROBLEM						240
#define CHRGSTOP_NOFAIL							255

//1C5H_CHRGSCHEDULECHECK
#define CHRGSCHEDULECHECK_NOACTIVATION			0
#define CHRGSCHEDULECHECK_ACTIVATION			1
#define CHRGSCHEDULECHECK_INVALID				2

//1CCH_IMMECHRGREAS
#define IMMECHRGRES_START						0
#define IMMECHRGRES_START_FAIL					1
#define IMMECHRGRES_STOP						2
#define IMMECHRGRES_STOP_FAIL					3

//1CCH_IMMECHRGSTARTFAILREAS
#define IMMECHRGSTARTFAILRES_NOTREADY2CHRG		0
#define IMMECHRGSTARTFAILRES_INCHRGING			1
#define IMMECHRGSTARTFAILRES_ALREADYCHRGED		2
#define IMMECHRGSTARTFAILRES_EVSEFAULT			3
#define IMMECHRGSTARTFAILRES_VEHPROBLEM			240
#define IMMECHRGSTARTFAILRES_NOFAIL				255

//1CCH_IMMECHRGSTOPFAILREAS
#define IMMECHRGSTOPFAILREAS_ALREADYSTOPPEDCHRG 0
#define IMMECHRGSTOPFAILREAS_VEHPROBLEM 240
#define IMMECHRGSTOPFAILREAS_NOFAIL 255


////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************TaskCounter********************************/
//�� Task�� ���� �ִ����� Ȯ���ϱ� ���� ����
extern uint8_t __far VcCount_Main_Task ;
extern uint8_t __far VcCount_Charge_Task ;
extern uint8_t __far VcCount_Drive_Task ;
extern uint8_t __far VcCount_CANMng_Task ;
extern uint8_t __far VcCount_APSLearn_Task ;
extern uint8_t __far VcCount_Diag_Task ;

#ifdef _E110

// CAN1
// TX = 3+3+12 = 18
extern uint8_t __far dataVSCANN_VCU_ECAN_1D4h[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_1D5h[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_3AEh[8];

extern uint8_t __far dataVSCANN_VCU_ECAN_3ABh[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_3ACh[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_3ADh[8];

extern uint8_t __far dataVSCANN_VCU_ECAN_DV1[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV2[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV3[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV4[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV5[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV6[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV7[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV8[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV9[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV10[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV11[8];
extern uint8_t __far dataVSCANN_VCU_ECAN_DV12[8];


extern T_VCU_1D4H __far VSCANN_VCU_ECAN_1D4h ;
extern T_VCU_1D5H __far VSCANN_VCU_ECAN_1D5h ;
extern T_VCU_3AEH __far VSCANN_VCU_ECAN_3AEh ;

extern T_VCU2EVCC_3ABH __far VSCANN_VCU_ECAN_3ABh 	;
extern T_VCU2EVCC_3ACH __far VSCANN_VCU_ECAN_3ACh	;
extern T_VCU2EVCC_3ADH __far VSCANN_VCU_ECAN_3ADh	;
//extern T_VCU_506H VSCANN_VCU_ECAN_506h	;


extern T_VCU_DBG1 __far VSCANN_VCU_ECAN_DV1		;
extern T_VCU_DBG2 __far VSCANN_VCU_ECAN_DV2		;
extern T_VCU_DBG3 __far VSCANN_VCU_ECAN_DV3		;
extern T_VCU_DBG4 __far VSCANN_VCU_ECAN_DV4		;
extern T_VCU_DBG5 __far VSCANN_VCU_ECAN_DV5		;
extern T_VCU_DBG6 __far VSCANN_VCU_ECAN_DV6		;
extern T_VCU_DBG7 __far VSCANN_VCU_ECAN_DV7		;
extern T_VCU_DBG8 __far VSCANN_VCU_ECAN_DV8		;
extern T_VCU_DBG9 __far VSCANN_VCU_ECAN_DV9		;
extern T_VCU_DBG10 __far VSCANN_VCU_ECAN_DV10	;
extern T_VCU_DBG11 __far VSCANN_VCU_ECAN_DV11	;
extern T_VCU_DBG12 __far VSCANN_VCU_ECAN_DV12	;

// RX = 6 + 7 +4 = 17

extern uint8_t __far dataVSCANN_RxBMS_ECAN_1D9h[8];
extern uint8_t __far dataVSCANN_RxBMS_ECAN_321h[8];
extern uint8_t __far dataVSCANN_RxBMS_ECAN_322h[8];
extern uint8_t __far dataVSCANN_RxBMS_ECAN_323h[8];
extern uint8_t __far dataVSCANN_RxBMS_ECAN_324h[8];
extern uint8_t __far dataVSCANN_RxBMS_ECAN_325h[8];

extern uint8_t __far dataVSCANN_RxMCU_ECAN_1E1h[8];
extern uint8_t __far dataVSCANN_RxMCU_ECAN_1E2h[8];
extern uint8_t __far dataVSCANN_RxMCU_ECAN_3A3h[8];
extern uint8_t __far dataVSCANN_RxMCU_ECAN_3A4h[8];
//extern uint8_t __far dataVSCANN_RxMCU_ECAN_3A5h[8];
extern uint8_t __far dataVSCANN_RxMCU_ECAN_3A6h[8];
extern uint8_t __far dataVSCANN_RxMCU_ECAN_3A7h[8];

extern uint8_t __far dataVSCANN_RxEVCC_ECAN_341h[8];
extern uint8_t __far dataVSCANN_RxEVCC_ECAN_342h[8];
extern uint8_t __far dataVSCANN_RxEVCC_ECAN_343h[8];
extern uint8_t __far dataVSCANN_RxEVCC_ECAN_513h[8];

extern T_BMS_1D9H __far VSCANN_RxBMS_ECAN_1D9h ;
extern T_BMS_321H __far VSCANN_RxBMS_ECAN_321h ;
extern T_BMS_322H __far VSCANN_RxBMS_ECAN_322h ;
extern T_BMS_323H __far VSCANN_RxBMS_ECAN_323h ;
extern T_BMS_324H __far VSCANN_RxBMS_ECAN_324h ;
extern T_BMS_325H __far VSCANN_RxBMS_ECAN_325h ;

extern T_MCU_1E1H __far VSCANN_RxMCU_ECAN_1E1h ;
extern T_MCU_1E2H __far VSCANN_RxMCU_ECAN_1E2h ;
extern T_MCU_3A3H __far VSCANN_RxMCU_ECAN_3A3h ;
extern T_MCU_3A4H __far VSCANN_RxMCU_ECAN_3A4h ;
//extern T_MCU_3A5H __far VSCANN_RxMCU_ECAN_3A5h ;
extern T_MCU_3A6H __far VSCANN_RxMCU_ECAN_3A6h ;
extern T_MCU_3A7H __far VSCANN_RxMCU_ECAN_3A7h ;

extern T_EVCC_341H __far VSCANN_RxEVCC_ECAN_341h	;
extern T_EVCC_342H __far VSCANN_RxEVCC_ECAN_342h	;
extern T_EVCC_343H __far VSCANN_RxEVCC_ECAN_343h	;
extern T_EVCC_513H __far VSCANN_RxEVCC_ECAN_513h	;

#else
/*******************************ECAN********************************/
extern T_VCU_1D4H VSCANN_VCU_ECAN_1D4h ;
extern T_VCU_1D5H VSCANN_VCU_ECAN_1D5h ;
extern T_VCU_3AEH VSCANN_VCU_ECAN_3AEh ;

extern T_BMS_1D9H VSCANN_RxBMS_ECAN_1D9h ;
extern T_BMS_321H VSCANN_RxBMS_ECAN_321h ;
extern T_BMS_322H VSCANN_RxBMS_ECAN_322h ;
extern T_BMS_323H VSCANN_RxBMS_ECAN_323h ;
extern T_BMS_324H VSCANN_RxBMS_ECAN_324h ;
extern T_BMS_325H VSCANN_RxBMS_ECAN_325h ;
//extern T_BMS_326H VSCANN_RxBMS_ECAN_326h ;
//extern T_BMS_581H VSCANN_RxBMS_ECAN_581h ;
//extern T_BMS_582H VSCANN_RxBMS_ECAN_582h ;
//extern T_BMS_583H VSCANN_RxBMS_ECAN_583h ;

extern T_MCU_1E1H VSCANN_RxMCU_ECAN_1E1h ;
extern T_MCU_1E2H VSCANN_RxMCU_ECAN_1E2h ;
extern T_MCU_3A3H VSCANN_RxMCU_ECAN_3A3h ;
extern T_MCU_3A4H VSCANN_RxMCU_ECAN_3A4h ;
extern T_MCU_3A6H VSCANN_RxMCU_ECAN_3A6h ;
extern T_MCU_3A7H VSCANN_RxMCU_ECAN_3A7h ;

extern T_VCU2EVCC_3ABH VSCANN_VCU_ECAN_3ABh 	;
extern T_VCU2EVCC_3ACH VSCANN_VCU_ECAN_3ACh	;
extern T_VCU2EVCC_3ADH VSCANN_VCU_ECAN_3ADh	;
//extern T_VCU_506H VSCANN_VCU_ECAN_506h	;
extern T_EVCC_341H VSCANN_RxEVCC_ECAN_341h	;
extern T_EVCC_342H VSCANN_RxEVCC_ECAN_342h	;
extern T_EVCC_343H VSCANN_RxEVCC_ECAN_343h	;
extern T_EVCC_513H VSCANN_RxEVCC_ECAN_513h	;

extern T_VCU_DBG1 VSCANN_VCU_ECAN_DV1		;
extern T_VCU_DBG2 VSCANN_VCU_ECAN_DV2		;
extern T_VCU_DBG3 VSCANN_VCU_ECAN_DV3		;
extern T_VCU_DBG4 VSCANN_VCU_ECAN_DV4		;
extern T_VCU_DBG5 VSCANN_VCU_ECAN_DV5		;
extern T_VCU_DBG6 VSCANN_VCU_ECAN_DV6		;
extern T_VCU_DBG7 VSCANN_VCU_ECAN_DV7		;
extern T_VCU_DBG8 VSCANN_VCU_ECAN_DV8		;
extern T_VCU_DBG9 VSCANN_VCU_ECAN_DV9		;
extern T_VCU_DBG10 VSCANN_VCU_ECAN_DV10	;
extern T_VCU_DBG11 VSCANN_VCU_ECAN_DV11	;
extern T_VCU_DBG12 VSCANN_VCU_ECAN_DV12	;
#endif



#ifdef _E110
/*******************************PCAN********************************/
/* PCAN Msg Definitions */

//Tx = 11 + 7 + 6 = 24
extern uint8_t __far dataVSCANN_VCU_PCAN_1D1h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_1D2h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_1D3h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_211h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_245h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_351h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_3ACh[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_3ADh[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_510h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_512h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_514h[8];

extern uint8_t __far dataVSCANN_VCU_PCAN_105h[8];
extern uint8_t __far dataVSCANN_VCU_PCAN_116h[8];
extern uint8_t __far dataVSCANN_VCU_ChargingCheckMsg_PCAN_1C5h[8];
extern uint8_t __far dataVSCANN_VCU_ImmediateChargingPushMsg_PCAN_1CCh[8];
extern uint8_t __far dataVSCANN_VCU_ScheduledChargingPushMsg_PCAN_1D6h[8];
extern uint8_t __far dataVSCANN_VCU_ChargingStopResult_PCAN_1D7h[8];
extern uint8_t __far dataVSCANN_VCU_ChargingSetSts_PCAN_3AFh[8];

extern uint8_t __far dataVSCANN_VCU_NM_PCAN_414h[8];
extern uint8_t __far dataVSCANN_VCU_CAL_PCAN_631h[8];
extern uint8_t __far dataVSCANN_VCU_CAL_PCAN_632h[8];
extern uint8_t __far dataVSCANN_VCU_CAL_PCAN_633h[8];
extern uint8_t __far dataVSCANN_VCU_CAL_PCAN_634h[8];
extern uint8_t __far dataVSCANN_VCU_DGN_RESP_PCAN_7E8h[8];

extern T_VCU_1D1H __far VSCANN_VCU_PCAN_1D1h ;
extern T_VCU_1D2H __far VSCANN_VCU_PCAN_1D2h ;
extern T_VCU_1D3H __far VSCANN_VCU_PCAN_1D3h ;
extern T_VCU_211H __far VSCANN_VCU_PCAN_211h ;
extern T_VCU_245H __far VSCANN_VCU_PCAN_245h ;
extern T_VCU_351H __far VSCANN_VCU_PCAN_351h ;
extern T_VCU_3ACH __far VSCANN_VCU_PCAN_3ACh ;
extern T_VCU_3ADH __far VSCANN_VCU_PCAN_3ADh ;
extern T_VCU_510H __far VSCANN_VCU_PCAN_510h ;
extern T_VCU_512H __far VSCANN_VCU_PCAN_512h ;
extern T_VCU_514H __far VSCANN_VCU_ECAN_514h ;

extern T_VCU_105H __far  VSCANN_VCU_PCAN_105h ;
extern T_VCU_116H __far  VSCANN_VCU_PCAN_116h ;
extern T_VCU_1C5H __far  VSCANN_VCU_ChargingCheckMsg_PCAN_1C5h ;
extern T_VCU_1CCH __far VSCANN_VCU_ImmediateChargingPushMsg_PCAN_1CCh ;
extern T_VCU_1D6H __far  VSCANN_VCU_ScheduledChargingPushMsg_PCAN_1D6h ;
extern T_VCU_1D7H __far VSCANN_VCU_ChargingStopResult_PCAN_1D7h ;
extern T_VCU_3AFH __far  VSCANN_VCU_ChargingSetSts_PCAN_3AFh ;

extern T_VCU_414H __far VSCANN_VCU_NM_PCAN_414h ;
extern T_VCU_631H __far VSCANN_VCU_CAL_PCAN_631h ;
extern T_VCU_632H __far VSCANN_VCU_CAL_PCAN_632h ;
extern T_VCU_633H __far VSCANN_VCU_CAL_PCAN_633h ;
extern T_VCU_634H __far VSCANN_VCU_CAL_PCAN_634h ;
extern T_VCU_7E8H __far VSCANN_VCU_DGN_RESP_PCAN_7E8h ;


//RX = 27 + 7 + 12 = 46
extern uint8_t __far dataVSCANN_RxYRS_PCAN_130h[8];
extern uint8_t __far dataVSCANN_RxYRS_PCAN_140h[8];
extern uint8_t __far dataVSCANN_RxACU_PCAN_135h[8];
extern uint8_t __far dataVSCANN_RxBCM_PCAN_511h[8];
extern uint8_t __far dataVSCANN_RxBMS_PCAN_352h[8];
extern uint8_t __far dataVSCANN_RxCGW_PCAN_STPM_APPL01[8];
extern uint8_t __far dataVSCANN_RxICM_PCAN_303h[8];
extern uint8_t __far dataVSCANN_RxICM_PCAN_304h[8];
extern uint8_t __far dataVSCANN_RxFRM_PCAN_259h[8];
extern uint8_t __far dataVSCANN_RxCGW_PCAN_372h[8];
extern uint8_t __far dataVSCANN_RxEPB_PCAN_340h[8];
extern uint8_t __far dataVSCANN_RxAVH_PCAN_360h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_200h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_207h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_208h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_20Ah[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_300h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_330h[8];
extern uint8_t __far dataVSCANN_RxEBU_PCAN_331h[8];
extern uint8_t __far dataVSCANN_RxEGP_PCAN_1E8h[8];
extern uint8_t __far dataVSCANN_RxEHVC_PCAN_1EBh[8];
extern uint8_t __far dataVSCANN_RxEHVC_PCAN_33Eh[8];
extern uint8_t __far dataVSCANN_RxEHVC_PCAN_33Fh[8];
extern uint8_t __far dataVSCANN_RxHVAC_PCAN_235h[8];
extern uint8_t __far dataVSCANN_RxHVAC_PCAN_355h[8];
extern uint8_t __far dataVSCANN_RxLDC_PCAN_3A0h[8];
extern uint8_t __far dataVSCANN_RxLDC_PCAN_3A1h[8];

extern uint8_t __far dataVSCANN_RxMCU_PCAN_327h[8];
extern uint8_t __far dataVSCANN_RxOBC_PCAN_3A8h[8];
extern uint8_t __far dataVSCANN_RxOBC_PCAN_3A9h[8];
extern uint8_t __far dataVSCANN_RxSBWS_PCAN_1E7h[8];
extern uint8_t __far dataVSCANN_RxSKM_PCAN_110h[8];
extern uint8_t __far dataVSCANN_RxSKM_PCAN_115h[8];
extern uint8_t __far dataVSCANN_RxSKM_PCAN_248h[8];

extern uint8_t __far dataVSCANN_RxEPS_PCAN_231h[8];
extern uint8_t __far dataVSCANN_RxSKM_PCAN_076h[8];
extern uint8_t __far dataVSCANN_RxSKM_PCAN_111h[8];
extern uint8_t __far dataVSCANN_RxICM_PCAN_152h[8];
extern uint8_t __far dataVSCANN_RxAVN_PCAN_15Ah[8];
extern uint8_t __far dataVSCANN_RxICM_PCAN_160h[8];
extern uint8_t __far dataVSCANN_RxCCU_PCAN_1C4h[8];
extern uint8_t __far dataVSCANN_RxAVN_PCAN_1CDh[8];
extern uint8_t __far dataVSCANN_RxCGW_NM_P_PCAN_448h[8];
extern uint8_t __far dataVSCANN_RxVCU_CAL_PCAN_630h[8];
extern uint8_t __far dataVSCANN_RxDIAG_FUNC_REQ_PCAN_700h[8];
extern uint8_t __far dataVSCANN_RxVCU_DGN_REQ_PCAN_7E0h[8];

extern T_ACU_130H __far VSCANN_RxYRS_PCAN_130h ;
extern T_ACU_140H __far VSCANN_RxYRS_PCAN_140h ;
extern T_ACU_135H __far VSCANN_RxACU_PCAN_135h ;
extern T_BCM_511H __far VSCANN_RxBCM_PCAN_511h ;
extern T_BMS_352H __far VSCANN_RxBMS_PCAN_352h ;
extern T_CGW_161H __far VSCANN_RxCGW_PCAN_STPM_APPL01 ;
extern T_CGW_303H __far VSCANN_RxICM_PCAN_303h ;
extern T_CGW_304H __far VSCANN_RxICM_PCAN_304h ;
extern T_CGW_259H __far VSCANN_RxFRM_PCAN_259h ;
extern T_CGW_372H __far VSCANN_RxCGW_PCAN_372h ;
extern T_CGW_340H __far VSCANN_RxEPB_PCAN_340h ;
extern T_CGW_360H __far VSCANN_RxAVH_PCAN_360h ;
extern T_EBU_200H __far VSCANN_RxEBU_PCAN_200h ;
extern T_EBU_207H __far VSCANN_RxEBU_PCAN_207h ;
extern T_EBU_208H __far VSCANN_RxEBU_PCAN_208h ;
extern T_EBU_20AH __far VSCANN_RxEBU_PCAN_20Ah ;
extern T_EBU_300H __far VSCANN_RxEBU_PCAN_300h ;
extern T_EBU_330H __far VSCANN_RxEBU_PCAN_330h ;
extern T_EBU_331H __far VSCANN_RxEBU_PCAN_331h ;
extern T_EGP_1E8H __far VSCANN_RxEGP_PCAN_1E8h ;
extern T_EHVC_1EBH __far VSCANN_RxEHVC_PCAN_1EBh ;
extern T_EHVC_33EH __far VSCANN_RxEHVC_PCAN_33Eh ;
extern T_EHVC_33FH __far VSCANN_RxEHVC_PCAN_33Fh ;
extern T_HVAC_235H __far VSCANN_RxHVAC_PCAN_235h ;
extern T_HVAC_355H __far VSCANN_RxHVAC_PCAN_355h ;
extern T_LDC_3A0H __far VSCANN_RxLDC_PCAN_3A0h ;
extern T_LDC_3A1H __far VSCANN_RxLDC_PCAN_3A1h ;

extern T_MCU_327H __far VSCANN_RxMCU_PCAN_327h ;
extern T_OBC_3A8H __far VSCANN_RxOBC_PCAN_3A8h ;
extern T_OBC_3A9H __far VSCANN_RxOBC_PCAN_3A9h ;
extern T_SBWS_1E7H __far VSCANN_RxSBWS_PCAN_1E7h ;
extern T_SKM_110H __far VSCANN_RxSKM_PCAN_110h ;
extern T_SKM_115H __far VSCANN_RxSKM_PCAN_115h ;
extern T_SKM_248H __far VSCANN_RxSKM_PCAN_248h ;

extern T_EPS_231H __far VSCANN_RxEPS_PCAN_231h ;
extern T_SKM_076H __far VSCANN_RxSKM_PCAN_076h ;
extern T_SKM_111H __far VSCANN_RxSKM_PCAN_111h ;
extern T_CGW_152H __far VSCANN_RxICM_PCAN_152h ;
extern T_CGW_15AH __far VSCANN_RxAVN_PCAN_15Ah ;
extern T_CGW_160H __far VSCANN_RxICM_PCAN_160h ;
extern T_CGW_1C4H __far VSCANN_RxCCU_PCAN_1C4h ;
extern T_CGW_1CDH __far VSCANN_RxAVN_PCAN_1CDh ;
extern T_CGW_448H __far VSCANN_RxCGW_NM_P_PCAN_448h ;
extern T_CGW_630H __far VSCANN_RxVCU_CAL_PCAN_630h ;
extern T_CGW_700H __far VSCANN_RxDIAG_FUNC_REQ_PCAN_700h ;
extern T_CGW_7E0H __far VSCANN_RxVCU_DGN_REQ_PCAN_7E0h ;

#else
/*******************************PCAN********************************/
extern T_VCU_1D1H VSCANN_VCU_PCAN_1D1h ;
extern T_VCU_1D2H VSCANN_VCU_PCAN_1D2h ;
extern T_VCU_1D3H VSCANN_VCU_PCAN_1D3h ;
extern T_VCU_211H VSCANN_VCU_PCAN_211h ;
extern T_VCU_245H VSCANN_VCU_PCAN_245h ;
extern T_VCU_351H VSCANN_VCU_PCAN_351h ;
extern T_VCU_3ACH VSCANN_VCU_PCAN_3ACh ;
extern T_VCU_3ADH VSCANN_VCU_PCAN_3ADh ;
extern T_VCU_510H VSCANN_VCU_PCAN_510h ;
extern T_VCU_512H VSCANN_VCU_PCAN_512h ;
extern T_VCU_514H VSCANN_VCU_ECAN_514h ;	//220703

extern T_VCU_105H  VSCANN_VCU_PCAN_105h ; // NONE
extern T_VCU_116H  VSCANN_VCU_PCAN_116h ; // NONE
extern T_VCU_1C5H  VSCANN_VCU_ChargingCheckMsg_PCAN_1C5h ; // NONE
extern T_VCU_1CCH VSCANN_VCU_ImmediateChargingPushMsg_PCAN_1CCh ; // NONE
extern T_VCU_1D6H  VSCANN_VCU_ScheduledChargingPushMsg_PCAN_1D6h ; // NONE
extern T_VCU_1D7H VSCANN_VCU_ChargingStopResult_PCAN_1D7h ; // NONE
extern T_VCU_3AFH  VSCANN_VCU_ChargingSetSts_PCAN_3AFh ; // 200ms
extern T_VCU_414H VSCANN_VCU_NM_PCAN_414h ; // NONE
extern T_VCU_631H VSCANN_VCU_CAL_PCAN_631h ; // NONE
extern T_VCU_632H VSCANN_VCU_CAL_PCAN_632h ; // NONE
extern T_VCU_633H VSCANN_VCU_CAL_PCAN_633h ; // NONE
extern T_VCU_634H VSCANN_VCU_CAL_PCAN_634h ; // NONE
extern T_VCU_7E8H VSCANN_VCU_DGN_RESP_PCAN_7E8h ; // NONE

extern T_ACU_130H VSCANN_RxYRS_PCAN_130h ;
extern T_ACU_140H VSCANN_RxYRS_PCAN_140h ;
extern T_ACU_135H VSCANN_RxACU_PCAN_135h ;
extern T_BCM_511H VSCANN_RxBCM_PCAN_511h ;
extern T_BMS_352H VSCANN_RxBMS_PCAN_352h ;
extern T_CGW_161H VSCANN_RxCGW_PCAN_STPM_APPL01 ;
extern T_CGW_303H VSCANN_RxICM_PCAN_303h ;
extern T_CGW_304H VSCANN_RxICM_PCAN_304h ;
extern T_CGW_259H VSCANN_RxFRM_PCAN_259h ;
extern T_CGW_372H VSCANN_RxCGW_PCAN_372h ;
extern T_CGW_340H VSCANN_RxEPB_PCAN_340h ;
extern T_CGW_360H VSCANN_RxAVH_PCAN_360h ;
extern T_EBU_200H VSCANN_RxEBU_PCAN_200h ;
extern T_EBU_207H VSCANN_RxEBU_PCAN_207h ;
extern T_EBU_208H VSCANN_RxEBU_PCAN_208h ;
extern T_EBU_20AH VSCANN_RxEBU_PCAN_20Ah ;
extern T_EBU_300H VSCANN_RxEBU_PCAN_300h ;
extern T_EBU_330H VSCANN_RxEBU_PCAN_330h ;
extern T_EBU_331H VSCANN_RxEBU_PCAN_331h ;
extern T_EGP_1E8H VSCANN_RxEGP_PCAN_1E8h ;
extern T_EHVC_1EBH VSCANN_RxEHVC_PCAN_1EBh ;
extern T_EHVC_33EH VSCANN_RxEHVC_PCAN_33Eh ;
extern T_EHVC_33FH VSCANN_RxEHVC_PCAN_33Fh ;
extern T_HVAC_235H VSCANN_RxHVAC_PCAN_235h ;
extern T_HVAC_355H VSCANN_RxHVAC_PCAN_355h ;
extern T_LDC_3A0H VSCANN_RxLDC_PCAN_3A0h ;
extern T_LDC_3A1H VSCANN_RxLDC_PCAN_3A1h ;
//extern T_MCU_1E1H VSCANN_RxMCU_PCAN_1E1h ;
extern T_MCU_327H VSCANN_RxMCU_PCAN_327h ;
extern T_OBC_3A8H VSCANN_RxOBC_PCAN_3A8h ;
extern T_OBC_3A9H VSCANN_RxOBC_PCAN_3A9h ;
extern T_SBWS_1E7H VSCANN_RxSBWS_PCAN_1E7h ;
extern T_SKM_110H VSCANN_RxSKM_PCAN_110h ;
extern T_SKM_115H VSCANN_RxSKM_PCAN_115h ;
extern T_SKM_248H VSCANN_RxSKM_PCAN_248h ;
extern T_EPS_231H VSCANN_RxEPS_PCAN_231h ;

extern T_SKM_076H VSCANN_RxSKM_PCAN_076h ;
extern T_SKM_111H VSCANN_RxSKM_PCAN_111h ;
extern T_CGW_152H VSCANN_RxICM_PCAN_152h ;
extern T_CGW_15AH VSCANN_RxAVN_PCAN_15Ah ;
extern T_CGW_160H VSCANN_RxICM_PCAN_160h ;
extern T_CGW_1C4H VSCANN_RxCCU_PCAN_1C4h ;
extern T_CGW_1CDH VSCANN_RxAVN_PCAN_1CDh ;
extern T_CGW_448H VSCANN_RxCGW_NM_P_PCAN_448h ;
extern T_CGW_630H VSCANN_RxVCU_CAL_PCAN_630h ;
extern T_CGW_700H VSCANN_RxDIAG_FUNC_REQ_PCAN_700h ;
extern T_CGW_7E0H VSCANN_RxVCU_DGN_REQ_PCAN_7E0h ;
#endif

#ifdef _E110
/**************************ECANMsgBox********************************/
//TX  3 + 3 + 12 = 18
extern can_message_t VSCANN_VCU_ECAN_1D4h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_1D5h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_3AEh_MsgBox ;

extern  can_message_t VSCANN_VCU_ECAN_3ABh_MsgBox ;
extern  can_message_t VSCANN_VCU_ECAN_3ACh_MsgBox ;
extern  can_message_t VSCANN_VCU_ECAN_3ADh_MsgBox ;

extern  can_message_t VSCANN_VCU_ECAN_DV1_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV2_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV3_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV4_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV5_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV6_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV7_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV8_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV9_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV10_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV11_MsgBox	;
extern  can_message_t VSCANN_VCU_ECAN_DV12_MsgBox	;


//RX
extern can_message_t VSCANN_RxBMS_ECAN_1D9h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_1D9h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_1D9h_Data[8u] ;

extern can_message_t VSCANN_RxBMS_ECAN_321h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_321h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_321h_Data[8u] ;


extern can_message_t VSCANN_RxBMS_ECAN_322h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_322h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_322h_Data[8u] ;

extern can_message_t VSCANN_RxBMS_ECAN_323h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_323h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_323h_Data[8u] ;

extern can_message_t VSCANN_RxBMS_ECAN_324h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_324h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_324h_Data[8u] ;

extern can_message_t VSCANN_RxBMS_ECAN_325h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_325h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_325h_Data[8u] ;


extern can_message_t VSCANN_RxMCU_ECAN_1E1h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_1E1h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_1E1h_Data[8u] ;

extern can_message_t VSCANN_RxMCU_ECAN_1E2h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_1E2h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_1E2h_Data[8u] ;

extern can_message_t VSCANN_RxMCU_ECAN_3A3h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_3A3h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_3A3h_Data[8u] ;

extern can_message_t VSCANN_RxMCU_ECAN_3A4h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_3A4h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_3A4h_Data[8u] ;

//extern can_message_t VSCANN_RxMCU_ECAN_3A5h_MsgBox ;
//extern uint32_t __far VbCALB_RxMCU_ECAN_3A5h ;
//extern uint8_t __far VaCALB_RxMCU_ECAN_3A5h_Data[8u] ;


extern can_message_t VSCANN_RxMCU_ECAN_3A6h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_3A6h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_3A6h_Data[8u] ;

extern can_message_t VSCANN_RxMCU_ECAN_3A7h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_ECAN_3A7h ;
extern uint8_t __far VaCALB_RxMCU_ECAN_3A7h_Data[8u] ;

extern  can_message_t VSCANN_RxEVCC_ECAN_341h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_341h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_341h_Data[8u] ;

extern  can_message_t VSCANN_RxEVCC_ECAN_342h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_342h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_342h_Data[8u] ;

extern  can_message_t VSCANN_RxEVCC_ECAN_343h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_343h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_343h_Data[8u] ;

extern  can_message_t VSCANN_RxEVCC_ECAN_513h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_ECAN_513h ;
extern uint8_t __far VaCALB_RxBMS_ECAN_513h_Data[8u] ;

#else
/**************************ECANMsgBox********************************/
extern can_message_t VSCANN_VCU_ECAN_1D4h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_1D5h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_3AEh_MsgBox ;

extern can_message_t VSCANN_RxBMS_ECAN_1D9h_MsgBox ;
extern can_message_t VSCANN_RxBMS_ECAN_321h_MsgBox ;
extern can_message_t VSCANN_RxBMS_ECAN_322h_MsgBox ;
extern can_message_t VSCANN_RxBMS_ECAN_323h_MsgBox ;
extern can_message_t VSCANN_RxBMS_ECAN_324h_MsgBox ;
extern can_message_t VSCANN_RxBMS_ECAN_325h_MsgBox ;

extern can_message_t VSCANN_RxMCU_ECAN_1E1h_MsgBox ;
extern can_message_t VSCANN_RxMCU_ECAN_1E2h_MsgBox ;
extern can_message_t VSCANN_RxMCU_ECAN_3A3h_MsgBox ;
extern can_message_t VSCANN_RxMCU_ECAN_3A4h_MsgBox ;
extern can_message_t VSCANN_RxMCU_ECAN_3A6h_MsgBox ;
extern can_message_t VSCANN_RxMCU_ECAN_3A7h_MsgBox ;

extern can_message_t VSCANN_VCU_ECAN_3ABh_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_3ACh_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_3ADh_MsgBox ;
//extern can_message_t VSCANN_VCU_ECAN_506h_MsgBox ;
extern can_message_t VSCANN_RxEVCC_ECAN_341h_MsgBox ;
extern can_message_t VSCANN_RxEVCC_ECAN_342h_MsgBox ;
extern can_message_t VSCANN_RxEVCC_ECAN_343h_MsgBox ;
extern can_message_t VSCANN_RxEVCC_ECAN_513h_MsgBox ;

extern can_message_t VSCANN_VCU_ECAN_DV1_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV2_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV3_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV4_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV5_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV6_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV7_MsgBox		;
extern can_message_t VSCANN_VCU_ECAN_DV8_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV9_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV10_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV11_MsgBox 	;
extern can_message_t VSCANN_VCU_ECAN_DV12_MsgBox 	;


#endif


#ifdef _E110
/*******************************PCAN********************************/
//Tx = 11 + 7 + 6 = 24
extern can_message_t VSCANN_VCU_PCAN_1D1h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_1D2h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_1D3h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_211h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_245h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_351h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_3ACh_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_3ADh_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_510h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_512h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_514h_MsgBox ;

extern can_message_t VSCANN_VCU_PCAN_105h_MsgBox 	;
extern can_message_t VSCANN_VCU_PCAN_116h_MsgBox 	;
extern can_message_t VSCANN_VCU_ChargingCheckMsg_PCAN_1C5h_MsgBox 	;
extern can_message_t VSCANN_VCU_ImmediateChargingPushMsg_PCAN_1CCh_MsgBox 	;
extern can_message_t VSCANN_VCU_ScheduledChargingPushMsg_PCAN_1D6h_MsgBox 	;
extern can_message_t VSCANN_VCU_ChargingStopResult_PCAN_1D7h_MsgBox 		;
extern can_message_t VSCANN_VCU_ChargingSetSts_PCAN_3AFh_MsgBox 			;

extern can_message_t VSCANN_VCU_NM_PCAN_414h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_631h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_632h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_633h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_634h_MsgBox 	;
extern can_message_t VSCANN_VCU_DGN_RESP_PCAN_7E8h_MsgBox 	;


//RX = 27 + 7 + 12 = 46
extern  can_message_t VSCANN_RxYRS_PCAN_130h_MsgBox ;
extern uint32_t __far VbCALB_RxYRS_PCAN_130h ;
extern uint8_t __far VaCALB_RxYRS_PCAN_130h_Data[8u] ;

extern  can_message_t VSCANN_RxYRS_PCAN_140h_MsgBox ;
extern uint32_t __far VbCALB_RxYRS_PCAN_140h ;
extern uint8_t __far VaCALB_RxYRS_PCAN_140h_Data[8u] ;

extern  can_message_t VSCANN_RxACU_PCAN_135h_MsgBox ;
extern uint32_t __far VbCALB_RxACU_PCAN_135h ;
extern uint8_t __far VaCALB_RxACU_PCAN_135h_Data[8u] ;

extern  can_message_t VSCANN_RxBCM_PCAN_511h_MsgBox ;
extern uint32_t __far VbCALB_RxBCM_PCAN_511h ;
extern uint8_t __far VaCALB_RxBCM_PCAN_511h_Data[8u] ;

extern  can_message_t VSCANN_RxBMS_PCAN_352h_MsgBox ;
extern uint32_t __far VbCALB_RxBMS_PCAN_352h ;
extern uint8_t __far VaCALB_RxBMS_PCAN_352h_Data[8u] ;

extern  can_message_t VSCANN_RxCGW_PCAN_STPM_APPL01_MsgBox ;
extern uint32_t __far VbCALB_RxCGW_PCAN_STPM_APPL01 ;
extern uint8_t __far VaCALB_RxCGW_PCAN_STPM_APPL01_Data[8u] ;

extern  can_message_t VSCANN_RxICM_PCAN_303h_MsgBox ;
extern uint32_t __far VbCALB_RxICM_PCAN_303h ;
extern uint8_t __far VaCALB_RxICM_PCAN_303h_Data[8u] ;

extern  can_message_t VSCANN_RxICM_PCAN_304h_MsgBox ;
extern uint32_t __far VbCALB_RxICM_PCAN_304h ;
extern uint8_t __far VaCALB_RxICM_PCAN_304h_Data[8u] ;

extern  can_message_t VSCANN_RxFRM_PCAN_259h_MsgBox ;
extern uint32_t __far VbCALB_RxFRM_PCAN_259h ;
extern uint8_t __far VaCALB_RxFRM_PCAN_259h_Data[8u] ;

extern  can_message_t VSCANN_RxCGW_PCAN_372h_MsgBox ;
extern uint32_t __far VbCALB_RxCGW_PCAN_372h ;
extern uint8_t __far VaCALB_RxCGW_PCAN_372h_Data[8u] ;

extern  can_message_t VSCANN_RxEPB_PCAN_340h_MsgBox ;
extern uint32_t __far VbCALB_RxEPB_PCAN_340h ;
extern uint8_t __far VaCALB_RxEPB_PCAN_340h_Data[8u] ;

extern  can_message_t VSCANN_RxAVH_PCAN_360h_MsgBox ;
extern uint32_t __far VbCALB_RxAVH_PCAN_360h ;
extern uint8_t __far VaCALB_RxAVH_PCAN_360h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_200h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_200h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_200h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_207h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_207h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_207h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_208h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_208h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_208h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_20Ah_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_20Ah ;
extern uint8_t __far VaCALB_RxEBU_PCAN_20Ah_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_300h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_300h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_300h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_330h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_330h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_330h_Data[8u] ;

extern  can_message_t VSCANN_RxEBU_PCAN_331h_MsgBox ;
extern uint32_t __far VbCALB_RxEBU_PCAN_331h ;
extern uint8_t __far VaCALB_RxEBU_PCAN_331h_Data[8u] ;

extern  can_message_t VSCANN_RxEGP_PCAN_1E8h_MsgBox ;
extern uint32_t __far VbCALB_RxEGP_PCAN_1E8h ;
extern uint8_t __far VaCALB_RxEGP_PCAN_1E8h_Data[8u] ;

extern  can_message_t VSCANN_RxEHVC_PCAN_1EBh_MsgBox ;
extern uint32_t __far VbCALB_RxEHVC_PCAN_1EBh ;
extern uint8_t __far VaCALB_RxEHVC_PCAN_1EBh_Data[8u] ;

extern  can_message_t VSCANN_RxEHVC_PCAN_33Eh_MsgBox ;
extern uint32_t __far VbCALB_RxEHVC_PCAN_33Eh ;
extern uint8_t __far VaCALB_RxEHVC_PCAN_33Eh_Data[8u] ;

extern  can_message_t VSCANN_RxEHVC_PCAN_33Fh_MsgBox ;
extern uint32_t __far VbCALB_RxEHVC_PCAN_33Fh ;
extern uint8_t __far VaCALB_RxEHVC_PCAN_33Fh_Data[8u] ;

extern  can_message_t VSCANN_RxHVAC_PCAN_235h_MsgBox ;
extern uint32_t __far VbCALB_RxHVAC_PCAN_235h ;
extern uint8_t __far VaCALB_RxHVAC_PCAN_235h_Data[8u] ;

extern  can_message_t VSCANN_RxHVAC_PCAN_355h_MsgBox ;
extern uint32_t __far VbCALB_RxHVAC_PCAN_355h ;
extern uint8_t __far VaCALB_RxHVAC_PCAN_355h_Data[8u] ;

extern  can_message_t VSCANN_RxLDC_PCAN_3A0h_MsgBox ;
extern uint32_t __far VbCALB_RxLDC_PCAN_3A0h ;
extern uint8_t __far VaCALB_RxLDC_PCAN_3A0h_Data[8u] ;

extern  can_message_t VSCANN_RxLDC_PCAN_3A1h_MsgBox ;
extern uint32_t __far VbCALB_RxLDC_PCAN_3A1h ;
extern uint8_t __far VaCALB_RxLDC_PCAN_3A1h_Data[8u] ;



extern  can_message_t VSCANN_RxMCU_PCAN_327h_MsgBox ;
extern uint32_t __far VbCALB_RxMCU_PCAN_327h ;
extern uint8_t __far VaCALB_RxMCU_PCAN_327h_Data[8u] ;

extern  can_message_t VSCANN_RxOBC_PCAN_3A8h_MsgBox ;
extern uint32_t __far VbCALB_RxOBC_PCAN_3A8h ;
extern uint8_t __far VaCALB_RxOBC_PCAN_3A8h_Data[8u] ;

extern  can_message_t VSCANN_RxOBC_PCAN_3A9h_MsgBox ;
extern uint32_t __far VbCALB_RxOBC_PCAN_3A9h ;
extern uint8_t __far VaCALB_RxOBC_PCAN_3A9h_Data[8u] ;

extern  can_message_t VSCANN_RxSBWS_PCAN_1E7h_MsgBox ;
extern uint32_t __far VbCALB_RxSBWS_PCAN_1E7h ;
extern uint8_t __far VaCALB_RxSBWS_PCAN_1E7h_Data[8u] ;

extern  can_message_t VSCANN_RxSKM_PCAN_110h_MsgBox ;
extern uint32_t __far VbCALB_RxSKM_PCAN_110h ;
extern uint8_t __far VaCALB_RxSKM_PCAN_110h_Data[8u] ;

extern  can_message_t VSCANN_RxSKM_PCAN_115h_MsgBox ;
extern uint32_t __far VbCALB_RxSKM_PCAN_115h ;
extern uint8_t __far VaCALB_RxSKM_PCAN_115h_Data[8u] ;

extern  can_message_t VSCANN_RxSKM_PCAN_248h_MsgBox ;
extern uint32_t __far VbCALB_RxSKM_PCAN_248h ;
extern uint8_t __far VaCALB_RxSKM_PCAN_248h_Data[8u] ;



extern can_message_t VSCANN_RxEPS_PCAN_231h_MsgBox ;
extern uint32_t __far VbCALB_RxEPS_PCAN_231h ;
extern uint8_t __far VaCALB_RxEPS_PCAN_231h_Data[8u] ;

extern can_message_t VSCANN_RxSKM_PCAN_076h_MsgBox ;
extern uint32_t __far VbCALB_RxSKM_PCAN_076h ;
extern uint8_t __far VaCALB_RxSKM_PCAN_076h_Data[8u] ;

extern can_message_t VSCANN_RxSKM_PCAN_111h_MsgBox ;
extern uint32_t __far VbCALB_RxSKM_PCAN_111h ;
extern uint8_t __far VaCALB_RxSKM_PCAN_111h_Data[8u] ;

extern can_message_t VSCANN_RxICM_PCAN_152h_MsgBox ;
extern uint32_t __far VbCALB_RxICM_PCAN_152h ;
extern uint8_t __far VaCALB_RxICM_PCAN_152h_Data[8u] ;

extern can_message_t VSCANN_RxAVN_PCAN_15Ah_MsgBox ;
extern uint32_t __far VbCALB_RxAVN_PCAN_15Ah ;
extern uint8_t __far VaCALB_RxAVN_PCAN_15Ah_Data[8u] ;

extern  can_message_t VSCANN_RxICM_PCAN_160h_MsgBox ;
extern uint32_t __far VbCALB_RxICM_PCAN_160h ;
extern uint8_t __far VaCALB_RxICM_PCAN_160h_Data[8u] ;

extern  can_message_t VSCANN_RxCCU_PCAN_1C4h_MsgBox ;
extern uint32_t __far VbCALB_RxCCU_PCAN_1C4h ;
extern uint8_t __far VaCALB_RxCCU_PCAN_1C4h_Data[8u] ;

extern  can_message_t VSCANN_RxAVN_PCAN_1CDh_MsgBox ;
extern uint32_t __far VbCALB_RxAVN_PCAN_1CDh ;
extern uint8_t __far VaCALB_RxAVN_PCAN_1CDh_Data[8u] ;

extern  can_message_t VSCANN_RxCGW_NM_P_PCAN_448h_MsgBox ;
extern uint32_t __far VbCALB_RxCGW_NM_P_PCAN_448h ;
extern uint8_t __far VaCALB_RxCGW_NM_P_PCAN_448h_Data[8u] ;

extern  can_message_t VSCANN_RxVCU_CAL_PCAN_630h_MsgBox ;
extern uint32_t __far VbCALB_RxVCU_CAL_PCAN_630h ;
extern uint8_t __far VaCALB_RxVCU_CAL_PCAN_630h_Data[8u] ;

extern  can_message_t VSCANN_RxDIAG_FUNC_REQ_PCAN_700h_MsgBox ;
extern uint32_t __far VbCALB_RxDIAG_FUNC_REQ_PCAN_700h ;
extern uint8_t __far VaCALB_RxDIAG_FUNC_REQ_PCAN_700h_Data[8u] ;

extern  can_message_t VSCANN_RxVCU_DGN_REQ_PCAN_7E0h_MsgBox ;
extern uint32_t __far VbCALB_RxVCU_DGN_REQ_PCAN_7E0h ;
extern uint8_t __far VaCALB_RxVCU_DGN_REQ_PCAN_7E0h_Data[8u] ;

#else
/**************************PCANMsgBox********************************/
extern can_message_t VSCANN_VCU_PCAN_1D1h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_1D2h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_1D3h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_211h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_245h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_351h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_3ACh_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_3ADh_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_510h_MsgBox ;
extern can_message_t VSCANN_VCU_PCAN_512h_MsgBox ;
extern can_message_t VSCANN_VCU_ECAN_514h_MsgBox ;

extern can_message_t VSCANN_VCU_PCAN_105h_MsgBox 	;
extern can_message_t VSCANN_VCU_PCAN_116h_MsgBox 	;
extern can_message_t VSCANN_VCU_ChargingCheckMsg_PCAN_1C5h_MsgBox 	;
extern can_message_t VSCANN_VCU_ImmediateChargingPushMsg_PCAN_1CCh_MsgBox 	;
extern can_message_t VSCANN_VCU_ScheduledChargingPushMsg_PCAN_1D6h_MsgBox 	;
extern can_message_t VSCANN_VCU_ChargingStopResult_PCAN_1D7h_MsgBox 		;
extern can_message_t VSCANN_VCU_ChargingSetSts_PCAN_3AFh_MsgBox 			;
extern can_message_t VSCANN_VCU_NM_PCAN_414h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_631h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_632h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_633h_MsgBox 	;
extern can_message_t VSCANN_VCU_CAL_PCAN_634h_MsgBox 	;
extern can_message_t VSCANN_VCU_DGN_RESP_PCAN_7E8h_MsgBox 	;
//
//
//extern can_message_t VSCANN_RxYRS_PCAN_130h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxYRS_PCAN_140h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxACU_PCAN_135h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxBCM_PCAN_511h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxBMS_PCAN_352h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxCGW_PCAN_STPM_APPL01_MsgBox ;   // Not use
//extern can_message_t VSCANN_RxICM_PCAN_303h_MsgBox ;          // 6
//extern can_message_t VSCANN_RxICM_PCAN_304h_MsgBox ;          // 7
//extern can_message_t VSCANN_RxFRM_PCAN_259h_MsgBox ;          // 8
//extern can_message_t VSCANN_RxCGW_PCAN_372h_MsgBox ;          // 9
//extern can_message_t VSCANN_RxEPB_PCAN_340h_MsgBox ;          // 10
//extern can_message_t VSCANN_RxEBU_PCAN_200h_MsgBox ;          // 11
//extern can_message_t VSCANN_RxEBU_PCAN_207h_MsgBox ;          // 12
//extern can_message_t VSCANN_RxEBU_PCAN_208h_MsgBox ;          // 13
//extern can_message_t VSCANN_RxEBU_PCAN_20Ah_MsgBox ;          // 14
//extern can_message_t VSCANN_RxEBU_PCAN_300h_MsgBox ;          // 15
//extern can_message_t VSCANN_RxEBU_PCAN_330h_MsgBox ;          // 16
//extern can_message_t VSCANN_RxEBU_PCAN_331h_MsgBox ;          // 17
//extern can_message_t VSCANN_RxEGP_PCAN_1E8h_MsgBox ;          // 18
//extern can_message_t VSCANN_RxEHVC_PCAN_1EBh_MsgBox ;         // 19
//extern can_message_t VSCANN_RxEHVC_PCAN_33Eh_MsgBox ;         // 20
//extern can_message_t VSCANN_RxEHVC_PCAN_33Fh_MsgBox ;         // 21
//extern can_message_t VSCANN_RxHVAC_PCAN_235h_MsgBox ;         // 22
//extern can_message_t VSCANN_RxHVAC_PCAN_355h_MsgBox ;         // 23
//extern can_message_t VSCANN_RxLDC_PCAN_3A0h_MsgBox ;          // 24
//extern can_message_t VSCANN_RxLDC_PCAN_3A1h_MsgBox ;          // 25
//extern can_message_t VSCANN_RxMCU_PCAN_1E1h_MsgBox ;
//extern can_message_t VSCANN_RxMCU_PCAN_327h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxOBC_PCAN_3A8h_MsgBox ;          // 26
//extern can_message_t VSCANN_RxOBC_PCAN_3A9h_MsgBox ;          // 27
//extern can_message_t VSCANN_RxSBWS_PCAN_1E7h_MsgBox ;         // 28
//extern can_message_t VSCANN_RxSKM_PCAN_110h_MsgBox ;          // 29
//extern can_message_t VSCANN_RxSKM_PCAN_115h_MsgBox ;          // Not use
//extern can_message_t VSCANN_RxSKM_PCAN_248h_MsgBox ;          // 30

extern can_message_t VSCANN_RxEPS_PCAN_231h_MsgBox	;
extern can_message_t VSCANN_RxSKM_PCAN_076h_MsgBox	;
extern can_message_t VSCANN_RxSKM_PCAN_111h_MsgBox	;
extern can_message_t VSCANN_RxICM_PCAN_152h_MsgBox	;
extern can_message_t VSCANN_RxAVN_PCAN_15Ah_MsgBox	;
//extern can_message_t VSCANN_RxICM_PCAN_160h_MsgBox	;
extern can_message_t VSCANN_RxCCU_PCAN_1C4h_MsgBox	;
extern can_message_t VSCANN_RxAVN_PCAN_1CDh_MsgBox	;
extern can_message_t VSCANN_RxCGW_NM_P_PCAN_448h_MsgBox	;
extern can_message_t VSCANN_RxVCU_CAL_PCAN_630h_MsgBox	;
extern can_message_t VSCANN_RxDIAG_FUNC_REQ_PCAN_700h_MsgBox	;
extern can_message_t VSCANN_RxVCU_DGN_REQ_PCAN_7E0h_MsgBox		;

#endif



////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _E110 //NOT
// KY 20220924 duplication
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPCRM_MsgBox ;
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPDTO_MsgBox ;
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPDTM_MsgBox ;

// KY 20220924 duplication
extern uint8_t __far VbCALB_CCPCRM_Received ;
extern uint8_t __far VaCALB_CCPCRM_Data[8u] ;
#endif


#ifdef _E110
extern uint32_t __far VfCALB_PageIndex ;
extern uint8_t __far VbVIOS_AdcConvDone ;
extern uint8_t __far VeVIOS_VCU_MainContactorControl ;

//NM 414, 448 Msg
extern uint8_t __far Vb_CanRx_448h_Flag ;
extern uint8_t __far Vb_414h_SleepFlag ;

extern uint8_t __far VfVIOS_FI_CoolFan_DutyFb ;
extern uint8_t __far VfVIOS_FI_WaterPump_DutyFb ;
//extern uint8_t __far VbVIOS_IGN3CtrlSts ;
extern uint8_t __far VbDIH_IGN3Fb ;
//extern uint8_t __far VbVIOS_IGN4CtrlSts ;
extern uint8_t __far VbDIH_IGN4Fb ;
extern float __far VfVIOS_T_EPTCoolantTemp ;
extern float __far VfVIOS_T_DCTS ;
extern uint8_t __far VfVIOS_T_CharInletTemp ;
extern uint8_t __far VbVIOS_CharPlugAtLockSwIndSts ;
extern uint8_t __far VbVIOS_CharPlugLockCtrlSts ;
extern uint8_t __far VbDIH_ChargDoorLockFb ;
extern uint8_t __far VbVIOS_CharDrCtrlSts ;
extern uint8_t __far VbDIL_ChargDoorOpCld ;

extern uint8_t __far VfVIOS_Pct_CharIndRedCtrlSts ;
extern uint8_t __far VfVIOS_Pct_CharIndGrCtrlSts ;
extern uint8_t __far VfVIOS_Pct_CharIndBlueCtrlSts ;
extern uint8_t __far VbVIOS_IGN2Sts ;
extern uint8_t __far VbDIH_IGN1 ;
extern uint8_t __far VbVIOS_AccSts ;


extern uint8_t __far VbVIOS_CharDrOpSw_RawVal ;
extern uint8_t __far VbVIOS_SchedCharCancelSw_RawVal ;
extern uint8_t __far VbDIL_DriveModeSwitch ;
extern uint8_t __far VbVIOS_CharPlugAtLockSw_RawVal ;
extern uint8_t __far VbDIH_BrakeSwitchCruise ;
extern uint8_t __far VbDIH_BrakeLampSw ;


extern uint8_t __far VbVIOS_QkCharPosRlyFblSts ;
extern uint8_t __far VbVIOS_QkCharNegRlyFblSts ;

extern uint8_t __far VeVIOS_CruiseSwSts ;
//extern uint8_t __far VfVIOS_U_CruiseSw_RawVal ;

extern uint8_t __far VfVIOS_SBWS_FO_FreqCtrl ;
extern uint8_t __far VfVIOS_FI_SBWS_Freq ;
extern uint8_t __far VfVIOS_U_CharCP_RawVal ;
extern uint8_t __far VfVIOS_U_CharPD_RawVal ;
extern uint8_t __far VfVIOS_Pct_MCU_Bu_RawVal ;
extern uint8_t __far VfVIOS_U_MCU_BuFb_RawVal ;

extern uint8_t __far VbVIOS_CoolFanRlyCtrlSts ;
extern uint8_t __far VbVIOS_PumpRlyCtrlSts ;

extern uint8_t __far VbVIOS_DO_Main_Rly ;
extern uint8_t __far VbDIH_MainRlyFb ;

extern uint8_t __far VbDIL_Sched_Chg_Wakeup ;

extern float __far VfVIOS_Pct_APS1NormPctVoltage ;
extern float __far VfVIOS_Pct_APS2NormPctVoltage ;

extern uint16_t __far VcADC_AccelPosition1 ;
extern uint16_t __far VcADC_AccelPosition2 ;
//extern uint16_t __far VcADC_ACC;
extern uint16_t __far VcADC_IGN2;
extern uint16_t __far VcADC_12VBAT ;
extern uint16_t __far VcADC_Temp1;
extern uint16_t __far VcADC_Temp2;
extern uint16_t __far VcAdc_CruiseControlSW ;

extern float __far VfVIOS_U_APS1FiltedVoltage ;
extern float __far VfVIOS_U_APS2FiltedVoltage ;

extern float __far VfVIOS_Pct_FinalAPSPosition ;

extern T_DIAG_OUT __far VSVIOS_APS1RngLmtHiDiag ;
extern T_DIAG_OUT __far VSVIOS_APS1RngLmtLoDiag ;

extern T_DIAG_OUT __far VSVIOS_APS2RngLmtHiDiag ;
extern T_DIAG_OUT __far VSVIOS_APS2RngLmtLoDiag ;

extern T_DIAG_OUT __far VSVIOS_APS12CorrDiag ;
extern T_DIAG_OUT __far VSVIOS_APS12MinCorrDiag ;

extern T_DIAG_OUT __far VSVIOS_SBWSLvrDiag ;

extern T_LEARN_OUT __far VSVIOS_APS1MinLearnOut ;
extern T_LEARN_OUT __far VSVIOS_APS2MinLearnOut ;

extern float __far VfVIOS_k_APS1WeightFactor ;
extern float __far VfVIOS_k_APS2WeightFactor ;

extern float __far VfVIOS_Pct_APS1LearnedMin ;
extern float __far VfVIOS_Pct_APS2LearnedMin ;

extern float __far VfVIOS_U_12VBatteryVoltage ;
extern float __far VfVIOS_U_IgnitionVoltage ;

extern float __far VfVIOS_U_CruiseSWPctVoltage;
extern float __far VfVIOS_U_CruiseSWRawVoltage;

extern uint8_t __far VbVIOS_AccelPedalApplied ;

extern float __far VfVIOS_Pct_APS1PctVoltage ;
extern float __far VfVIOS_Pct_APS2PctVoltage ;

extern float __far VfVIOS_U_APS1RawVoltage ;
extern float __far VfVIOS_U_APS2RawVoltage ;

extern float __far VfVIOS_Pct_APS1IndPosition ;
extern float __far VfVIOS_Pct_APS2IndPosition ;

extern uint8_t __far VbCANN_ECAN_Tx_Busy ;
extern uint8_t __far VbCANN_PCAN_Tx_Busy ;

// ECAN VCU 0x1D4
extern uint8_t __far VeBMSC_MainContactorControl ;

// ECAN VCU 0x1D5
//extern float VfTORQ_M_CANSend_EVDemandTorque ;
extern uint8_t __far VeMCUC_OperationalModeCmd ;
extern uint8_t __far VeMCUC_CommandModeVCU ;
extern uint8_t __far VeMCU_ACTV_Discharge_REQ;

// ECAN VCU 0x3AE

extern float __far VfMCUC_U_MaxBatteryVoltage ;
extern float __far VfMCUC_U_MinBatteryVoltage ;

extern float __far VfMCUC_A_MaxDischargeCurrent ;
extern float __far VfMCUC_A_MaxChargeCurrent ;

extern uint8_t __far VeMCUC_ActiveDampingDisableCommand ;
extern uint8_t __far VeMCUC_OperationRequest ;

extern uint8_t __far VbLDCC_LDC_Enable ;
extern uint8_t __far VeVIOS_VCU_Ready ;


extern uint8_t __far VfCANN_VCU_ECAN_3AEh_Counter ;

extern float __far VfTORQ_n_MotSpd_Vector_MCU ;
extern float __far VfTORQ_v_VehSpd_Vector_MCU ;
extern float __far VfTORQ_n_Filtered_MotSpd_Scalar_MCU ;

extern float __far VfTORQ_v_Filtered_VehSpd_Vector_MCU ;
extern float __far VfTORQ_n_Filtered_MotSpd_Vector_MCU ;

extern T_DIAG_OUT __far VSVIOS_BPSDiag ;
extern uint8_t __far VbVIOS_BrakePedalApplied ;

extern E_GEAR_POSITION __far VeSBWS_Lever_Position ;
extern E_STEP2GEARCHANGE __far VeVIOS_Step2GearChange ;
extern uint8_t __far VbVIOS_P2N_ByReleaseSW_flag ;
extern E_GEAR_POSITION __far VeSBWS_GearState4TqCtrl ;
extern uint8_t __far VbTORQ_GearReverese ;
extern uint8_t __far VfTORQ_RegenLevel ;
extern uint8_t __far VbTORQ_DriveFlag_PorN ;

extern uint8_t __far Vb_Charge_Reservation_Cancel_Flag ;
extern E_AUTOLOCK_STS __far Vb_AutoLockSts;
extern E_AUTOLOCK_STS __far Vb_Prev_KeyCycle_AutoLockSts ;

//extern float VfTORQ_M_RegenAvailableTorque	;
//extern float vfTORQ_M_BMSRegenAvailableTorque	;
//extern float VfTORQ_M_MCUMotorAvailableTorque	;
extern float __far VfTORQ_M_EVDemandTorque	;
extern float __far VfTORQ_M_EVFianlDemandTorque ;
extern float __far VfTORQ_M_CANSend_EVDemandTorque ;
extern float __far VfTORQ_M_Motoring_MaxTq	;
//extern float VfTORQ_M_LimitGenTq ;
//extern float VfTORQ_M_LimitMotTq ;
extern float __far VfTORQ_M_Generating_MaxTq ;
extern float __far VfTORQ_M_DriverMotorTorque ;
extern float __far VfTORQ_M_DriverGenTorque ;
extern float __far VfTORQ_M_DriverDemandTorque	;
extern float __far VfTORQ_v_LmtSpdbyDriveMode ;
extern float __far VfTORQ_v_LmtSpdbySwitch ;
extern float __far VfVIOS_CruiseTargetKPH ;
extern float __far VfTORQ_v_LimitSpeed ;
extern float __far VfTORQ_M_EVCommandTorque ;
extern E_ECO_ENERGY_FLOW __far VeTORQ_M_ECOEnergyFlowIND ;
extern E_ECO_GUIDE_Level_IND __far VeTORQ_M_ECO_Guide_Level_IND ;
extern float __far VfTORQ_v_LMTSpd4OverspeedMode ;
extern uint8_t __far VbTORQ_v_LMTSpdOverspeedMode_Flag ;

// 0908 JE
extern float __far Vf_MCU_PowerConsumption ;
extern uint8_t __far VeTORQ_M_PwrLevel  ;
extern uint8_t __far VeTORQ_M_ChagLevel ;

extern uint8_t __far VbTORQ_REGN_AVAL_STS_EPT ;

extern E_IO_STATE __far VbDIL_ChargDoorOpCldFilted ;
extern E_IO_STATE __far VbVIOS_prev_CharOpCldStsFilted ;

extern int32_t __far VfVIOS_CharDoorOpenRequestTimer ;
extern int32_t __far VfVIOS_CharDoorCtrlTimer ;

extern E_GEAR_POSITION __far VeSBWS_GearState4MCUCtrl ;

//DO(50msTimer)	//Ctrl
extern E_IO_STATE __far VbLSD_MainRlyCtrl;
extern E_IO_STATE __far VbLSD_IGN3Ctrl;
extern E_IO_STATE __far VbLSD_IGN4Ctrl;
extern E_IO_STATE __far VbLSD_FanRlyCtrl;
extern E_IO_STATE __far VbLSD_WaterPumpRlyCtrl;
extern E_IO_STATE __far VbLSD_QckChrgPosiRlyCtrl;
extern E_IO_STATE __far VbLSD_QckChrgNegaRlyCtrl;
extern E_IO_STATE __far VbHSD_ChrgPlugAutoLockIndicatorCtrl;
extern E_IO_STATE __far VbHSD_ChrgLED_R_Ctrl;
extern E_IO_STATE __far VbHSD_ChrgLED_G_Ctrl;
extern E_IO_STATE __far VbHSD_ChrgLED_B_Ctrl;
extern E_IO_STATE __far VbLSD_ChrgLED_Ctrl;
extern E_IO_STATE __far VbLSD_EVCCEnableCtrl;
extern uint8_t __far VbCharg_VCU_ISOLT_MTR_STP_REQ ;

extern E_IO_STATE __far VbLSD_ChargDoorRlyCtrl;

//DO(50msTimer)	//Cmd
extern E_IO_STATE __far VbLSD_MainRlyCmd;
extern E_IO_STATE __far VbLSD_IGN3Cmd;
extern E_IO_STATE __far VbLSD_IGN4Cmd;
extern E_IO_STATE __far VbLSD_FanRlyCmd;
extern E_IO_STATE __far VbLSD_WaterPumpRlyCmd;
extern E_IO_STATE __far VbLSD_QckChrgPosiRlyCmd;
extern E_IO_STATE __far VbLSD_QckChrgNegaRlyCmd;
extern E_IO_STATE __far VbHSD_ChrgPlugAutoLockIndCmd;
extern E_IO_STATE __far VbHSD_ChrgLED_R_Cmd;
extern E_IO_STATE __far VbHSD_ChrgLED_G_Cmd;
extern E_IO_STATE __far VbHSD_ChrgLED_B_Cmd;
extern E_IO_STATE __far VbLSD_ChrgLED_Cmd;
extern E_IO_STATE __far VbHSD_EVCCEnableCmd;

extern E_IO_STATE __far VbLSD_ChargDoorRlyCmd;

//FO(100msTimer)	//Ctrl&Cmd
extern float __far VfVIOS_FO_SBWS_PeriodCtrl;
extern float __far VfVIOS_FO_SBWS_PeriodCmd;
extern float __far VfVIOS_FO_SBWS_DutyCtrl;
extern float __far VfVIOS_FO_SBWS_DutyCmd;
extern float __far VfVIOS_FO_CoolFan_DutyCtrl;
extern float __far VfVIOS_FO_CoolFan_DutyCmd;
extern float __far VfVIOS_FO_WaterPump_DutyCtrl;
extern float __far VfVIOS_FO_WaterPump_DutyCmd;

extern uint8_t __far VbTORQ_LaunchActive ;
extern uint8_t __far VbTORQ_LaunchEnable ;
extern uint8_t __far VbTORQ_CreepActive ;
extern uint8_t __far VbTORQ_OverTemp[3] ;
extern uint8_t __far VbTORQ_VehStopped ;
extern uint8_t __far VbTORQ_DoorHoodAjarFlag ;
extern float __far VfTORQ_M_SpeedGoverningTq_Pterm ;
extern float __far VfTORQ_M_SpeedGoverningTq_Iterm ;
extern float __far VfTORQ_M_SpeedGoverningTq_Diff ;
extern float __far VfTQ_N_CreepTq_pterm ;
extern float __far VfTQ_N_CreepTq_iterm ;

//GetTqLimit �Լ� ���� ���Ͽ�
extern T_BMS_610H __far VSCAN_DCAN_BMS1_610h ;
extern can_message_t VSCAN_DCAN_BMS1_610h_MsgBox ;

//Drive �Լ� local->global
extern uint8_t __far VbTORQ_ActiveDecelCruise;
extern uint8_t __far VbTORQ_DecelCruisePIDReset ;

extern float __far VfMCUB_T_IGBT_Temp ;
extern float __far VfMCUB_T_MOT_Temp ;
extern float __far VfMCUB_T_Board_Temp ;
extern float __far VfTORQ_M_DecelCruiseSetTq ;
extern float __far VfTORQ_M_CreepTq ;
extern float __far VfTORQ_M_DecelCruiseGenTq ;
extern float __far VfTORQ_M_DecelCruiseTq ;
extern float __far VfTORQ_M_CoastRegenTq ;
extern float __far VfTORQ_M_CoastRegenTq4CANTx ;
extern float __far VfTorq_EBURegenREQTq	;
extern float __far VfTORQ_M_Motoring_LaunchAssist ;
extern float __far VfTORQ_M_Motoring_Tq_APS ;
extern float __far VfTORQ_v_DecelCruiseTargetSpeedOffset ;
extern float __far VfVIOS_Pct_FinalBPSPosition ;
extern float __far VfTORQ_M_BMSMotorAvailableTorque ;
extern float __far VfTORQ_M_MCUMotorAvailableTorque ;
extern float __far VfTORQ_M_MotorAvailableTorque ;
extern float __far VfTORQ_M_BMSRegenAvailableTorque ;
extern float __far VfTORQ_M_MCURegenAvailableTorque ;
extern float __far VfTORQ_M_RegenAvailableTorque ;

extern E_DRIVE_MODE __far VeTORQ_DriveMode	;
extern uint8_t __far VbDriveMode_ModeChangeActive	;
extern uint8_t __far VbDriveMode_EcoPlusModeEnable ;
extern uint8_t __far VcDriveMode_Count ;

extern E_DRIVE_MODE __far VeTORQ_PrevDriveMode ;

//extern uint8_t __far Vb_TorqCtrlDisabledCondMet	;
extern uint8_t __far VbRegenInhibition	;

extern float VfTORQ_k_rpm2kphCoeff ;

extern float __far VfTORQ_v_Filtered_VehSpd_Scalar_MCU	;

extern float __far VfTORQ_v_VehSpd_WSSFL	;
extern float __far VfTORQ_v_VehSpd_WSSFR	;
extern float __far VfTORQ_v_VehSpd_WSSRL	;
extern float __far VfTORQ_v_VehSpd_WSSRR	;
extern float __far VfTORQ_v_VehSpd_WSSFA	;
extern float __far VfTORQ_v_VehSpd_WSSRA	;
extern float __far VfTORQ_v_VehSpd_WSS	;

extern float __far VfFAN_Pct_Spd_CLT					;
extern float __far VfFAN_Pct_Spd_EPT					;
extern float __far VfFAN_Pct_Spd_eComp_Pressure		;
extern float __far VfFAN_Pct_Spd_eComp_RPM			;

extern float __far VfEWP_Pct_Spd_MotCoolFlow			;
extern float __far VfEWP_Pct_Spd_MCUCoolFlow			;
extern float __far VfEWP_Pct_Spd_HVACCoolFlow		;

extern float __far VfVIOS_T_ActualEPTCoolantFlow		;

extern E_IO_STATE __far VbDIL_Auto_Lock_SW				;
extern E_IO_STATE __far VbDIH_Qck_Chrg_NegaRly_Fb		;
extern E_IO_STATE __far VbDIH_Qck_Chrg_PosiRly_Fb		;
extern E_IO_STATE __far VbDIL_Scheduled_Chrg_Cancel_SW	;
extern E_IO_STATE __far VbDIL_EVCC_Wku	;

extern E_EGP_PARKINGREQ __far VeVIOS_EGP_Parking_Req	;

extern E_ACC_STATE __far VeVIOS_ACC_State	;
extern E_MAIN_STATE __far VeVIOS_Main_State ;
extern E_MAIN_STATE __far VeVIOS_Main_Prev_State ;

extern uint8_t __far VcSKM_ST_REQ	;
extern uint8_t __far VeVIOS_Start	;

extern uint8_t __far VbMain_MainContactorOffFault ;
extern E_EV_READY_STATE __far VeMain_EV_READY_STATE	;
extern uint8_t __far Vb_MCANWkuCmd ;
extern uint8_t __far Vb_CCANWkuCmd ;
extern uint8_t __far Vb_ICANWkuCmd ;
extern uint8_t __far Vb_NM_MCANWkuCmd ;
extern uint8_t __far Vb_NM_CCANWkuCmd ;
extern uint8_t __far Vb_NM_ICANWkuCmd ;

extern uint8_t __far Vb_CAN1C5Send_Flag ;
extern E_CHRG_SCHEDULE_CHECK __far Ve_ChrgScheduleCheck;

extern uint8_t __far VbCharg_ChargFinished ;

extern E_CHRG_STATE __far VeCharge_State ;

extern uint8_t __far VeCharge_VCU_EVstat ;
extern uint8_t __far VbCharge_VCU_PDU_ContactorState ;
extern float __far VfCharge_VCU_EVSOC ;
extern float __far VfCharge_VCU_TargetVolt ;
extern float __far VfCharge_VCU_PresentVolt ;
extern uint8_t __far VbCharge_VCU_S2_OnReqACDC ;
extern float __far VfCharge_VCU_DC_EVMaxCurrent ;
extern float __far VfCharge_VCU_DC_EVMaxVoltage ;
extern float __far VfCharge_VCU_DC_EVTargetCurrent ;
extern float __far VfCharge_VCU_DC_EVTargetVoltage ;
extern float __far VfCharge_VCU_FullSOCRemainTime ;
extern uint8_t __far VbCharge_VCU_Command_En_OBC ;
extern E_CP_STATE __far VeCharge_VCU_CMDChargeCP ;
extern E_PD_STATE __far VeCharge_VCU_CMDChargePD ;
extern uint8_t __far VeCharge_VCU_CMDChargePWM ;
extern uint8_t __far VeCharge_VCU_CMDACChageStartReq ;
extern uint8_t __far VeCharge_VCU_AC_ChargingReady ;

extern uint8_t __far VeCharge_VCU_OBC_STS_Ready ;
extern uint8_t __far VeCharge_VCU_OBC_STS_CONTRAB ;
extern E_CHRG_FINISH_REASON __far VeCharge_VCU_ChgFinished ;
extern uint8_t __far VbCharg_NormalChargFinished ;
extern uint8_t __far VbCharg_AbnormalChargFinished ;
extern uint8_t __far VeCharge_VCU_BMS_ContactorState ;

extern uint8_t __far VeCharge_VCU_AC_Cmd_Char_CP ;
extern uint8_t __far VeCharge_VCU_AC_Cmd_Char_PD ;
//extern uint8_t __far VeCharge_VCU_AC_Cmd_Char_St_Req ;
extern float __far VfCharge_VCU_AC_Cmd_Char_PWM ;
extern uint8_t __far VbCharge_VCU_AC_ChargingReady ;
extern uint8_t __far VbCharge_VCU_AC_Cmd_En_OBC ;
//extern uint8_t __far VbCharge_VCU_S2_OnReqACDC ;
extern float __far VfCharge_VCU_AC_EVTargetCurrent ;
extern float __far VfCharge_VCU_AC_EVTargetVoltage ;
extern uint8_t __far VbCharge_VCU_AC1_CHARGE_CRT_Status ;
extern uint8_t __far VbCharge_VCU_AC2_CHARGE_CRT_Status ;
extern uint8_t __far VeCharge_VCU_AC_Cmd_Char_St_Req ;
extern uint8_t __far VeCharge_VCU_ChargeConnectionStatus ;

extern float __far VfCharge_PrecharVolStableDelay ;

extern uint32_t __far VcActiveCreep_count0	;
extern uint8_t __far  VeCreepState			;

extern float __far VfTORQ_M_LmtSpdTorque		;
extern float __far VfTORQ_M_EVSystemAvailableTorque ;

extern uint8_t __far VbTORQ_LimitSpdCtrlEnabled ;
extern float __far VfTORQ_M_BMSMotorAvailablePower ;
extern float __far VfTORQ_M_BMSRegenAvailablePower ;
extern float __far VfTORQ_BMS_PowerAvailable2sMot		;
extern float __far VfTORQ_BMS_PowerAvailable10sMot		;
extern float __far VfTORQ_BMS_PowerAvailable2sReg		;
extern float __far VfTORQ_BMS_PowerAvailable10sReg  	;

extern float __far VfTorq_LA_Speed ;

extern E_SMC_E_S __far VeComm_P211h_SMC_E_S ;

extern uint8_t __far VcWakeUp_SPIMODE ;
extern uint8_t __far VcWakeUp_WakeUpStat  ;

extern E_CHRG_DOOR_STATE __far VeChgDr_State ;
extern uint16_t __far VcChgDr_Open_Count ;
extern uint16_t __far VcChgDr_Close_Count ;
extern uint16_t __far VcChgDr_RlyOn_Count ;

extern uint8_t __far VbChgDr_OpenDemandFlag ;
extern E_IO_STATE __far VbLSD_ChargDoorRlyCtrl_Func ;

extern float __far VfDTE_EWMA_AC_Power  ;
extern float __far VfDTE_EWMA_HTR_Power ;
extern float __far VfDTE_VehSOE		   ;
extern float __far VfDTE_VCU_STS_ESTM_DRV_Range_SOC ;
extern float __far VfDTE_VCU_STS_ESTM_DRV_Range_SOE ;
extern uint8_t __far Vb_Flag4Soc ;
extern float __far VfDTE_VCU_STS_ESTM_DRV_Range ;
extern float __far VfDTE_VCU_STS_ESTM_DRV_Range_FinalVal ;

extern uint8_t __far VbGrad_APSAct_GradCalStop_Flag  ;
extern uint16_t __far VfGrad_APSAct_GradCalStop_Timer ;
extern uint8_t __far VbGrad_BPSAct_GradCalStop_Flag  ;
extern float __far VfGrad_LongAc_Filt ;
extern float __far VfGrad_VehAc_Filt ;
extern float __far VfTORQ_phi_Grad ;

extern float __far VfVIOS_ACC_Engine_Torque ;
extern float __far VfVIOS_ACC_Engine_Torque_Pct ;
extern float __far VfVIOS_Virtual_APSPosition ;

extern uint8_t __far VfVIOS_PW ;
extern uint8_t __far VeVIOS_PW_Virtual_Flag ;
extern uint8_t __far VbVIOS_CAN_Driver_Accel_Override ;

extern E_SPD_LIM_STATE __far VeVIOS_Spd_Lim_State ;
extern uint8_t __far VbTORQ_KickDownEn ;
extern uint8_t __far VbTORQ_OverspeedFlag_KickDown ;
extern uint8_t __far VbTORQ_OverspeedFlag ;

extern uint8_t __far VbVIOS_AccelPedalApplied_PW ;
extern uint8_t __far VbTORQ_TipInActive ;
extern uint8_t __far VbTORQ_TipOutActive ;
extern uint16_t __far VeTORQ_period ;

extern float __far VfTORQ_TipIn_LowZoneStepUp ;
extern float __far VfTORQ_TipIn_MidZoneStepUp ;
extern float __far VfTORQ_TipIn_HighZoneStepUp ;
extern float __far VfTORQ_TipIn_FilterCoefficientUp ;

extern float __far VfTORQ_HighZoneStepDown ;
extern float __far VfTORQ_MidZoneStepDown ;
extern float __far VfTORQ_LowZoneStepDown ;

extern uint16_t __far VeTORQ_TipIn_MiddleZoneLoTq_Th ;
extern uint16_t __far VeTORQ_TipIn_MiddleZoneHiTq_Th ;

extern float __far VfTORQ_TipOut_HighP_Th ;
extern float __far VfTORQ_TipOut_MidP_Th ;

extern uint8_t __far Vb_ExtTqReqExit_Flag ;

extern uint8_t __far VeSBWS_Lever_Position_Fault ;

//DGDM Test
extern T_DIAG_OUT __far VSVIOS_DGDMTestDiagOut ;
extern T_DIAG_HISTORY __far VSVIOS_DGDMTestDiagHistory ;
extern T_DIAG_FREEZEFRAME __far VSVIOS_DGDMTestFreezeFrame ;

extern uint8_t __far VeCOMM_P1D2h_VCU_REQ_EN_ACOMP ;
extern uint8_t __far VeCOMM_P1D2h_VCU_REQ_EN_Heater ;
extern uint8_t __far Vb_VCU_REQ_LMT_ACCOMP_PWR ;
extern uint8_t __far Vb_VCU_REQ_LMT_Blower_Step ;
extern uint8_t __far Vb_VCU_REQ_LMT_CABN_Heater_PWR ;

extern uint8_t __far VbSBWS_GearChangeTransition ;
extern uint8_t __far VbVIOS_DrivDoorAjarOpenFlag ;
extern uint8_t __far VbSBWS_LowSpdGearChangeTransition ;
extern uint8_t __far Vb_ExtECUIntervention_Active ;
extern uint8_t __far Vb_TorqCtrlDisabledCondMet ;

extern float __far VfODO_ThisKeyCycle ;
extern float __far VfODD_SinceCodeClear ;

extern float __far VfSPD_SpeedPer1km ;
extern uint32_t __far VcSPD_VehStopCounterPer1km ;
extern uint32_t __far VcSPD_VehMovingCounterPer1km ;
extern uint32_t __far VcSPD_VehStopCounterPer5km  ;
extern T_VALPER5KM_INT __far VSSPD_VehStopCounterPer5km ;
extern uint32_t __far VcSPD_VehMovingCounterPer5km ;
extern T_VALPER5KM_INT __far VSSPD_VehMovingCounterPer5km ;
extern T_VALPER5KM_FLOAT __far VSSPD_AvgSpeedPer5km ;

extern float __far VfDTE_VehSpd_MovingAvg ;

extern uint8_t __far VbODO_ResetFlag1km ;
extern float __far VfODO_1000m ;
extern float __far VfODO_5000m ;
extern T_VALPER5KM_FLOAT __far VSODO_5000m ;

extern uint8_t __far VcChargeComplt_Min_DC ;
extern uint16_t __far VcChargeComplt_Min_AC_UnPortable ;
extern uint16_t __far VcChargeComplt_Min_AC_Portable ;
extern uint16_t __far VcChargeComplt_Min ;
extern uint16_t __far VcChargeComplt_Min_SOC80 ;

extern uint8_t __far Ve_VCU_CHAR_INLT_STS_WRN_MSG ;
extern uint8_t __far Vb_Service_Wrn_Ind ;
extern uint8_t __far Ve_Service_Wrn_Msg ;
extern uint8_t __far Vb_Chrging_Sts_Wrn_Msg ;
extern uint8_t __far Vb_VCU_LV_System_WRN_IND ;
extern uint8_t __far Ve_VCU_LV_System_WRN_MSG ;
extern uint8_t __far Vb_VCU_HV_ACT_IND ;

extern uint8_t __far Vb_STPM_Mode_Flag ;
extern uint8_t __far Vb_STPM_HVAC_Mode_Flag ;

extern E_REMOTE_RESPONSE __far Ve_VCU_Remote_Response ;

extern float __far VfCHAG_TotalChargePwr ;

extern uint8_t __far VeVIOS_Charging_Sts_IND ;

extern uint8_t __far VeVIOS_Check_Variable ;

extern uint8_t __far Vb_EVCCWakeupCmdbyVCU ;
extern uint8_t __far Vb_EVCCStandbyCmdbyVCU ;

extern E_CHRG_INHIBITION_REASON __far VeChrg_ChrgInhibitition ;

extern float __far VfCharge_VCU_DC_EVTargetCurrent_Pct ;
extern float __far VfCharge_VCU_DC_EVTargetCurrent_CalculatedVal ;

extern float __far VfEVCC_Evse_LimitCurr_A ;
extern float __far VfECAN_RxEVCC_511h_EVSEMaxA ;

extern E_VCU_HV_PWR_STATE __far Ve_HV_Pwr_State ;
extern uint8_t __far Vb_VCU_HV_Low_SOC_WRN_IND ;
extern E_VCU_HV_PWR_LMT_WRN_MSG __far Ve_VCU_HV_PwrLmtWrnMsg ;

extern E_VCU_EVPWRDNWRN_IND_STATE __far Ve_VCU_EvPwrDnWrn_Ind_Sts ;
extern uint8_t __far Vb_VCU_EV_Power_Down_Wrn_Ind ;

extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_RSOC;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_DERATING;
//extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_BMS;
//extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Inverter;
//extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Motor;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_TmpHigh_COOLTS ;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_TqLmt;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_HVDCLinkVLow;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_EPTnBMSPwrLow;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_2;
extern uint8_t __far Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_10;

extern int32_t __far V_LVBatt_Volt ;
extern int32_t __far V_LVBatt_Temp ;
extern int32_t __far V_LVBatt_Curr ;
extern int32_t __far V_LVBatt_SOC ;
extern int32_t __far V_LVBatt_SOH ;
extern int32_t __far V_LVBatt_OCV ;
extern int32_t __far V_LVBatt_CNOM ;

extern uint8_t __far Vb_LIN1Rx_Flag ;
extern uint8_t __far Vb_LIN2Rx_Flag ;

extern T_LVAUTOCHRG_DISREASON __far Vs_LVAutoChrg_DisReason ;
extern uint8_t __far Vb_LVAutoChrgEn_Flag ;

extern uint8_t __far V_Flag_110Rx ;
extern uint8_t __far V_Flag_115Rx ;
extern uint64_t __far V_ECU_Immo ;

extern uint8_t __far V_NM_IGN3_STS_VCU ;
extern uint8_t __far V_NM_Ignition1Sts_VCU ;

extern uint8_t __far V_RxCGW_15Ah_ACChargingTargetSetCmd;
extern uint8_t __far V_RxCGW_15Ah_DCChargingTargetSetCmd;

extern uint8_t __far Vb_HVBattLowVolt_Condition_Flag ;

extern E_GEAR_POSITION __far Ve_Prev_KeyCycle_Gear_Position ;

extern E_VCU_SHIFT_UNMATCH_WRN __far Ve_VCU_Shift_COND_Unmatch_WRN_MSG ;
extern uint8_t __far Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_SPDCOND_1u ;
extern uint8_t __far Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOBRAKE_CHANGE_2u ;
extern uint8_t __far Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOSTOP_P_3u ;
extern uint8_t __far Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOBRAKE_PRELEASE_4u ;

extern E_VCU_SHIFTCTRLSTS_WRN_MSG __far Ve_VCU_ShiftCtrl_WRN_MSG ;
extern uint8_t __far Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_P_Engaged_1u ;
extern uint8_t __far Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_N_Engaged_2u ;
extern uint8_t __far Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_P_Malfunction_3u ;
extern uint8_t __far Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_CheckSystem_4u ;

//extern uint8_t __far VcCount4Check_RomData_AutoLockSts ;		//�� loop���� +1��

extern uint8_t __far VcCount_DCCharge ;
extern uint8_t __far Vb_VoltDiffErr_Flag ;

extern E_TIPIN_STATE __far Ve_TipInState ;
extern E_TIPOUT_STATE __far Ve_TipOutState ;

extern uint8_t __far Vb_VCU_PAD_COND_WRN_MSG ;

extern float __far VfTORQ_v_CreepTargetSpd ;

//CAN Copy

//ACU_135 RAW
extern uint8_t __far ACU_Crashout_ACU_135h_RAW ;
//AVN_1CD RAW
extern uint8_t __far ChargingStopCmdbyAVN_AVN_1CD_RAW ;
extern uint8_t __far RespChargingScheduleSts_AVN_1CD_RAW ;
extern uint8_t __far ScheduledChargingCmd_AVN_1CD_RAW ;
//
extern uint8_t __far FixedTypeChargeCurrentSetCmd_AVN_15Ah_RAW ;
extern uint8_t __far PortableTypeChargeCurrentSetCmd_AVN_15Ah_RAW ;
extern uint8_t __far AcChargingTartgetSetCmd_AVN_15Ah_RAW ;
extern uint8_t __far DcChargingTartgetSetCmd_AVN_15Ah_RAW ;

extern uint8_t __far HoodAjarSts4p_BCM_511h_RAW ;
extern uint8_t __far RearDefoggerActSts_BCM_511h_RAW ;
extern uint8_t __far FrontWiperMotorSts4P_BCM_511h_RAW ;
extern uint8_t __far HeadLightOnOff4P_BCM_511h_RAW ;
extern uint8_t __far DRLSts_BCM_511h_RAW ;
extern uint8_t __far DrivSeatBeltSts_BCM_511h_RAW ;

extern uint8_t __far BLS_PA_BS_200h_P_RAW ;
extern uint8_t __far BLS_BS_200h_P_RAW ;
extern uint8_t __far BZ200h_BS_200h_P_RAW ;
extern uint16_t __far DVL_BS_200h_P_RAW ;
extern uint16_t __far DVR_BS_200h_P_RAW ;
extern uint16_t __far TM_DL_BS_200h_P_RAW ;

extern uint8_t __far REGEN_ENABLE_STS_BS_207h_P_RAW ;
extern uint8_t __far PTS_SNS_FAIL_BS_207h_P_RAW ;
extern uint8_t __far RBC_DEF_BS_207h_P_RAW ;
extern uint8_t __far REQ_COAST_REGEN_EXIT_BS_207h_P_RAW ;
extern uint8_t __far Counter_207h_BS_207h_P_RAW ;
extern uint8_t __far REGEN_EXIT_MONITORING_BS_207h_P_RAW ;
extern uint8_t __far EBU_PW_BS_207h_P_RAW ;
extern uint8_t __far Checksum_207h_BS_207h_P_RAW ;
extern uint16_t __far REGEN_REQ_TQ_BS_207h_P_RAW ;
extern uint16_t __far DRIVER_REQ_PRESSURE_BS_207h_P_RAW ;

extern uint8_t __far TM_AUS_BS_208h_P_RAW ;
extern uint16_t __far DHR_BS_208h_P_RAW ;
extern uint16_t __far DHL_BS_208h_P_RAW ;

extern uint8_t __far HSA_DEF_FLG_BS_20Ah_P_RAW ;
extern uint8_t __far HSA_CTR_FLAG_BS_20Ah_P_RAW ;
extern uint8_t __far Counter_20Ah_BS_20Ah_P_RAW ;
extern uint8_t __far Checksum_20Ah_BS_20Ah_P_RAW ;
extern uint16_t __far ACC_Engine_Torque_Value_BS_20Ah_P_RAW ;

extern uint8_t __far MMOTSE_PA_BS_300h_P_RAW ;
extern uint8_t __far MMOTSR_PA_BS_300h_P_RAW ;
extern uint8_t __far MPAR_ESP_BS_300h_P_RAW ;
extern uint8_t __far TOGGLE_BS_300h_P_RAW ;
extern uint8_t __far MMAX_ESP_BS_300h_P_RAW ;
extern uint8_t __far MMIN_ESP_BS_300h_P_RAW ;
extern uint8_t __far MTGL_ESP_BS_300h_P_RAW ;
extern uint8_t __far Counter_300h_BS_300h_P_RAW ;
extern uint8_t __far BZ300h_BS_300h_P_RAW ;
extern uint8_t __far Checksum_300h_BS_300h_P_RAW ;
extern uint16_t __far M_ESP_BS_300h_P_RAW ;

extern uint8_t __far EBS_STATUS_BS_330h_P_RAW ;
extern uint8_t __far Counter_330h_BS_330h_P_RAW ;
extern uint8_t __far Checksum_330h_BS_330h_P_RAW ;
extern uint16_t __far EST_REF_VELOCITY_BS_330h_P_RAW ;

extern uint16_t __far PS_MEANVAL_BS_331h_P_RAW ;

extern uint8_t __far EPB_RBLRQ_BS_340h_EPB_RAW ;
extern uint8_t __far EPB_Status_BS_340h_EPB_RAW ;
extern uint8_t __far Counter_340h_BS_340h_EPB_RAW ;
extern uint8_t __far Checksum_340h_BS_340h_EPB_RAW ;

extern uint8_t __far AVH_LAMP_INFO_360h_AVH_RAW ;

extern uint8_t __far CCU_ChargingStopReq_CCU_1C4h_RAW ;
extern uint8_t __far CCU_ImmediateChargingReq_CCU_1C4h_RAW ;

extern uint8_t __far HeadLampHighSts_CGW_372h_RAW ;
extern uint8_t __far HazardSw_CGW_372h_RAW ;
extern uint8_t __far DrivDoorLockUnSts_CGW_372h_RAW ;
extern uint8_t __far DrivDoorAjarSts_CGW_372h_RAW ;
extern uint8_t __far BatteryCheckReqCmdbyCCU_CGW_372h_RAW ;

extern uint8_t __far NM_SleepFlag_CGW_CGW_448h_RAW ;
extern uint8_t __far NM_CommandCode_CGW_448h_RAW ;
extern uint8_t __far NM_Destination_CGW_448h_RAW ;

extern uint64_t __far DIAG_REQ_FUNC_700h_RAW ;

extern uint8_t __far Pmotor_Position_Failure_EGP_1E8h_RAW ;
extern uint8_t __far Shifting_In_Progress_EGP_1E8h_RAW ;
extern uint8_t __far EGP_Service_WRN_IND_EGP_1E8h_RAW ;
extern uint8_t __far Pmotor_Position_Status_EGP_1E8h_RAW ;
extern uint8_t __far EGP_OperationMode_EGP_1E8h_RAW ;
extern uint8_t __far Counter_1E8h_EGP_1E8h_RAW ;
extern uint8_t __far Pmotor_Error_Level_EGP_1E8h_RAW ;
extern uint8_t __far Checksum_1E8h_EGP_1E8h_RAW ;

extern uint16_t __far AC_REF_High_Pressure_EHVC_1EBh_RAW ;
extern uint16_t __far Cabin_HTR_Power_EHVC_1EBh_RAW ;

extern uint8_t __far eComp_Phase_Current_EHVC_33Eh_RAW ;
extern uint8_t __far eComp_Inverter_Temp_EHVC_33Eh_RAW ;
extern uint8_t __far eComp_Battery_Voltage_EHVC_33Eh_RAW ;
extern uint16_t __far eComp_Power_EHVC_33Eh_RAW ;
extern uint16_t __far eComp_Drive_RPM_EHVC_33Eh_RAW ;

extern uint8_t __far DATC_STS_CHILLER_EHVC_33Fh_RAW ;
extern uint8_t __far Cabin_HTR_Current_EHVC_33Fh_RAW ;

extern uint8_t __far ACC_SystemState_FRM_259h_RAW ;
extern uint8_t __far ACC_Mode_FRM_259h_RAW ;
extern uint8_t __far Counter_259h_FRM_259h_RAW ;
extern uint8_t __far Checksum_259h_FRM_259h_RAW ;

extern uint8_t __far FAN_Status_HVAC_235h_RAW ;
extern uint8_t __far HVAC_TEMP_Status_HVAC_235h_RAW ;
extern uint8_t __far HVAC_Mode_Status_HVAC_235h_RAW ;
extern uint8_t __far RearDefoggerSwSts_HVAC_235h_RAW ;
extern uint8_t __far Incar_Temp_HVAC_235h_RAW ;

extern uint8_t __far HVAC_Cooling_STS_HVAC_355h_RAW ;
extern uint8_t __far HVAC_Heating_STS_HVAC_355h_RAW ;
extern uint8_t __far HVAC_HEX_ICING_STS_HVAC_355h_RAW ;
extern uint8_t __far HVAC_DEF_STS_HVAC_355h_RAW ;
extern uint8_t __far HVAC_Temp_Act_STS_L_HVAC_355h_RAW ;
extern uint8_t __far HVAC_Temp_Act_STS_R_HVAC_355h_RAW ;

extern uint8_t __far DrvMode1_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t __far DrvMode2_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t __far DrvMode3_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t __far DrvMode4_RegenLevelSetCmd_ICM_152h_RAW ;

extern uint8_t __far ACC_SW_ICM_160h_RAW ;
extern uint8_t __far ACC_Accel_RES_SW_ICM_160h_RAW ;
extern uint8_t __far ACC_Decel_SET_SW_ICM_160h_RAW ;
extern uint8_t __far ACC_DistanceSW_ICM_160h_RAW ;
extern uint8_t __far SpeedLimitSW_ICM_160h_RAW ;
extern uint8_t __far RegenUpSW_ICM_160h_RAW ;
extern uint8_t __far RegenDownSW_ICM_160h_RAW ;
extern uint8_t __far Counter_160h_ICM_160h_RAW ;
extern uint8_t __far Checksum_160h_ICM_160h_RAW ;

extern uint8_t __far V_MPH_ICM_303h_RAW ;
extern uint8_t __far Counter_303h_ICM_303h_RAW ;
extern uint8_t __far T_Outside_ICM_303h_RAW ;
extern uint8_t __far Checksum_303h_ICM_303h_RAW ;
extern uint16_t __far Speed_Combi_ICM_303h_RAW ;
extern uint16_t __far V_ANZ_ICM_303h_RAW ;

extern uint8_t __far OM_High_ICM_304h_RAW ;
extern uint16_t __far KM16_ICM_304h_RAW ;

extern uint8_t __far LDC_Out_Emergency_LDC_3A0h_RAW ;
extern uint8_t __far LDC_Service_WRN_IND_LDC_3A0h_RAW ;
extern uint8_t __far LDC_STS_Ready_LDC_3A0h_RAW ;
extern uint8_t __far LDC_Out_Mode_LDC_3A0h_RAW ;
extern uint8_t __far LDC_STS_MODE_LDC_3A0h_RAW ;
extern uint8_t __far Counter_3A0h_LDC_3A0h_RAW ;
extern uint8_t __far LDC_STS_TEMP_LDC_3A0h_RAW ;
extern uint8_t __far Checksum_3A0h_LDC_3A0h_RAW ;
extern uint16_t __far LDC_STS_Power_OUT_LDC_3A0h_RAW ;

extern uint8_t __far LDC_STS_VOLT_OUT_LDC_3A1h_RAW ;
extern uint8_t __far LDC_STS_CURR_IN_LDC_3A1h_RAW ;
extern uint16_t __far LDC_STS_VOLT_IN_LDC_3A1h_RAW ;
extern uint16_t __far LDC_STS_CURR_OUT_LDC_3A1h_RAW ;

extern uint8_t __far MCU_Service_WRN_IND_MCU_327h_RAW ;
extern uint16_t __far MCU_PowerConsumption_MCU_327h_RAW ;

extern uint8_t __far OBC_STS_Ready_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_CONTRAB_OBC_3A8h_RAW ;
extern uint8_t __far OBC_CMD_Chg_Finished_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_AC_DETECT_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_Temporary_Stop_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_SC_State_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_PC_State_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_CHECK_GROUP_OBC_3A8h_RAW ;
extern uint8_t __far OBC_STS_TEMP_OBC_3A8h_RAW ;

extern uint16_t __far OBC_AC_V_rms_OBC_3A9h_RAW ;
extern uint16_t __far OBC_AC_I_rms_OBC_3A9h_RAW ;
extern uint16_t __far OBC_DC_Output_V_OBC_3A9h_RAW ;
extern uint16_t __far OBC_DC_Output_I_OBC_3A9h_RAW ;

extern uint8_t __far SBWS_STS_Parking_Release_SW_SBWS_1E7h_RAW ;
extern uint8_t __far SBW_STS_SBWS_1E7h_RAW ;
extern uint8_t __far SBW_ShutDown_Timer_SBWS_1E7h_RAW ;
extern uint8_t __far SBWS_Lever_SBWS_1E7h_RAW ;
extern uint8_t __far SBW_WRN_MSG_SBWS_1E7h_RAW ;
extern uint8_t __far Counter_1E7h_SBWS_1E7h_RAW ;
extern uint8_t __far Checksum_1E7h_SBWS_1E7h_RAW ;

extern uint8_t __far REKESChargingStopCmd_SKM_076h_RAW ;

extern uint8_t __far ST_REQ_SKM_110h_RAW ;

extern uint8_t __far HighVoltageRelayOnOffReqCmd_SKM_111h_RAW ;

extern uint64_t __far SKM_Immo_SKM_115h_RAW ;

extern uint8_t __far BatteryCheckReqCmdbySTPM_STPM_APPL01_161h_RAW ;

extern uint64_t __far VCU_Calibration_630h_RAW ;

extern uint64_t __far DGN_REQ_VCU_7E0h_RAW ;

extern uint8_t __far CF_Yrs_Yr_Fail_YRS_130h_RAW ;
extern uint8_t __far CF_Yrs_Yr_Init_YRS_130h_RAW ;
extern uint8_t __far CF_Yrs_LatAc_Fail_YRS_130h_RAW ;
extern uint8_t __far CF_Yrs_LatAc_Init_YRS_130h_RAW ;
extern uint8_t __far CR_Yrs_Crc1_YRS_130h_RAW ;
extern uint16_t __far CR_Yrs_Yr_YRS_130h_RAW ;
extern uint16_t __far CR_Yrs_LatAc_YRS_130h_RAW ;

extern uint8_t __far CR_Yrs_LongAc_Fail_YRS_140h_RAW ;
extern uint8_t __far CR_Yrs_LongAc_Init_YRS_140h_RAW ;
extern uint8_t __far CR_Yrs_MsgCnt2_YRS_140h_RAW ;
extern uint8_t __far CR_Yrs_Crc2_YRS_140h_RAW ;
extern uint16_t __far CR_Yrs_LongAc_YRS_140h_RAW ;

extern uint64_t __far ECU_Immo_VCU_105h_RAW ;

extern uint8_t __far HighVoltageRelayOnReqFb_VCU_116h_RAW ;

extern uint64_t __far VCU_Calibration_631h_Signal_VCU_631h_RAW ;
extern uint64_t __far VCU_Calibration_632h_Signal_VCU_632h_RAW ;
extern uint64_t __far VCU_Calibration_633h_Signal_VCU_633h_RAW ;
extern uint64_t __far VCU_Calibration_634h_Signal_VCU_634h_RAW ;

extern uint8_t __far ChargingScheduleCheck_VCU_1C5h_RAW ;

extern uint8_t __far FixedTypeChargeCurrentSetSts_VCU_3AFh_RAW ;
extern uint8_t __far PortableTypeChargeCurrentSetSts_VCU_3AFh_RAW ;
extern uint8_t __far DcChargingTartgetSetSts_VCU_3AFh_RAW ;
extern uint8_t __far AcChargingTartgetSetSts_VCU_3AFh_RAW ;

extern uint8_t __far ChargingFinish_VCU_1D7h_RAW ;
extern uint8_t __far ChargingStopReason_VCU_1D7h_RAW ;

extern uint64_t __far DGN_RESP_VCU_7E8h_RAW ;

extern uint8_t __far ImmediateChargingResult_VCU_1CCh_RAW ;
extern uint8_t __far ImmeChargingStartFailReason_VCU_1CCh_RAW ;
extern uint8_t __far ImmeChargingStopFailReason_VCU_1CCh_RAW ;

extern uint8_t __far NM_McanWakeupCmd_VCU_414h_RAW ;
extern uint8_t __far NM_IcanWakeupCmd_VCU_414h_RAW ;
extern uint8_t __far NM_CcanWakeupCmd_VCU_414h_RAW ;
extern uint8_t __far NM_SleepFlag_VCU_414h_RAW ;
extern uint8_t __far NM_CommandCode_VCU_414h_RAW ;
extern uint8_t __far NM_WakeupReason_VCU_414h_RAW ;
extern uint8_t __far NM_FormerState_VCU_414h_RAW ;
extern uint8_t __far NM_Destination_VCU_414h_RAW ;
extern uint16_t __far NM_Reserved_VCU_414h_RAW ;

extern uint8_t __far ScheduledChargingResult_VCU_1D6h_RAW ;
extern uint8_t __far ScheChargingStartFailReason_VCU_1D6h_RAW ;
extern uint8_t __far ScheChargingStopFailReason_VCU_1D6h_RAW ;

extern can_message_t ECAN_RX0_Message_Buffer[2];
extern can_message_t ECAN_RX1_Message_Buffer[2];
extern can_message_t ECAN_RX2_Message_Buffer[2];
extern can_message_t ECAN_RX3_Message_Buffer[2];
extern can_message_t ECAN_RX4_Message_Buffer[2];
extern can_message_t ECAN_RX5_Message_Buffer[2];
extern can_message_t ECAN_RX6_Message_Buffer[2];
extern can_message_t ECAN_RX7_Message_Buffer[2];

extern  uint32_t __far ECAN_RX0_BufferIndex ;
extern  uint32_t __far ECAN_RX1_BufferIndex ;
extern  uint32_t __far ECAN_RX2_BufferIndex ;
extern  uint32_t __far ECAN_RX3_BufferIndex ;
extern  uint32_t __far ECAN_RX4_BufferIndex ;
extern  uint32_t __far ECAN_RX5_BufferIndex ;
extern  uint32_t __far ECAN_RX6_BufferIndex ;
extern  uint32_t __far ECAN_RX7_BufferIndex ;

extern can_message_t PCAN_RX0_Message_Buffer[2];
extern can_message_t PCAN_RX1_Message_Buffer[2];
extern can_message_t PCAN_RX2_Message_Buffer[2];
extern can_message_t PCAN_RX3_Message_Buffer[2];
extern can_message_t PCAN_RX4_Message_Buffer[2];
extern can_message_t PCAN_RX5_Message_Buffer[2];
extern can_message_t PCAN_RX6_Message_Buffer[2];
extern can_message_t PCAN_RX7_Message_Buffer[2];

extern  uint32_t __far PCAN_RX0_BufferIndex ;
extern  uint32_t __far PCAN_RX1_BufferIndex ;
extern  uint32_t __far PCAN_RX2_BufferIndex ;
extern  uint32_t __far PCAN_RX3_BufferIndex ;
extern  uint32_t __far PCAN_RX4_BufferIndex ;
extern  uint32_t __far PCAN_RX5_BufferIndex ;
extern  uint32_t __far PCAN_RX6_BufferIndex ;
extern  uint32_t __far PCAN_RX7_BufferIndex ;

#else
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPCRM_MsgBox ;
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPDTO_MsgBox ;
extern can_message_t VSCANN_VCU_DEBUG_CAN_CCPDTM_MsgBox ;

extern uint8_t VbCALB_CCPCRM_Received ;
extern uint8_t VaCALB_CCPCRM_Data[] ;

extern uint32_t VfCALB_PageIndex ;
extern uint8_t VbVIOS_AdcConvDone ;
extern uint8_t VeVIOS_VCU_MainContactorControl ;

extern uint8_t Vb_CanRx_448h_Flag ;
extern uint8_t Vb_414h_SleepFlag ;

extern uint8_t VfVIOS_FI_CoolFan_DutyFb ;
extern uint8_t VfVIOS_FI_WaterPump_DutyFb ;
//extern uint8_t VbVIOS_IGN3CtrlSts ;
extern uint8_t VbDIH_IGN3Fb ;
//extern uint8_t VbVIOS_IGN4CtrlSts ;
extern uint8_t VbDIH_IGN4Fb ;
extern float VfVIOS_T_EPTCoolantTemp ;
extern float VfVIOS_T_DCTS ;
extern uint8_t VfVIOS_T_CharInletTemp ;
extern uint8_t VbVIOS_CharPlugAtLockSwIndSts ;
extern uint8_t VbVIOS_CharPlugLockCtrlSts ;
extern uint8_t VbDIH_ChargDoorLockFb ;
extern uint8_t VbVIOS_CharDrCtrlSts ;
extern uint8_t VbDIL_ChargDoorOpCld ;

extern uint8_t VfVIOS_Pct_CharIndRedCtrlSts ;
extern uint8_t VfVIOS_Pct_CharIndGrCtrlSts ;
extern uint8_t VfVIOS_Pct_CharIndBlueCtrlSts ;
extern uint8_t VbVIOS_IGN2Sts ;
extern uint8_t VbDIH_IGN1 ;
extern uint8_t VbVIOS_AccSts ;

extern uint8_t VbVIOS_CharDrOpSw_RawVal ;
extern uint8_t VbVIOS_SchedCharCancelSw_RawVal ;
extern uint8_t VbDIL_DriveModeSwitch ;
extern uint8_t VbVIOS_CharPlugAtLockSw_RawVal ;
extern uint8_t VbDIH_BrakeSwitchCruise ;
extern uint8_t VbDIH_BrakeLampSw ;


extern uint8_t VbVIOS_QkCharPosRlyFblSts ;
extern uint8_t VbVIOS_QkCharNegRlyFblSts ;

extern uint8_t VeVIOS_CruiseSwSts ;
//extern uint8_t VfVIOS_U_CruiseSw_RawVal ;

extern uint8_t VfVIOS_SBWS_FO_FreqCtrl ;
extern uint8_t VfVIOS_FI_SBWS_Freq ;
extern uint8_t VfVIOS_U_CharCP_RawVal ;
extern uint8_t VfVIOS_U_CharPD_RawVal ;
extern uint8_t VfVIOS_Pct_MCU_Bu_RawVal ;
extern uint8_t VfVIOS_U_MCU_BuFb_RawVal ;

extern uint8_t VbVIOS_CoolFanRlyCtrlSts ;
extern uint8_t VbVIOS_PumpRlyCtrlSts ;

extern uint8_t VbVIOS_DO_Main_Rly ;
extern uint8_t VbDIH_MainRlyFb ;

extern uint8_t VbDIL_Sched_Chg_Wakeup ;

extern float VfVIOS_Pct_APS1NormPctVoltage ;
extern float VfVIOS_Pct_APS2NormPctVoltage ;

extern uint16_t VcADC_AccelPosition1 ;
extern uint16_t VcADC_AccelPosition2 ;
//extern uint16_t VcADC_ACC;
extern uint16_t VcADC_IGN2;
extern uint16_t VcADC_12VBAT ;
extern uint16_t VcADC_Temp1;
extern uint16_t VcADC_Temp2;
extern uint16_t VcAdc_CruiseControlSW;

extern float VfVIOS_U_APS1FiltedVoltage ;
extern float VfVIOS_U_APS2FiltedVoltage ;

extern float VfVIOS_Pct_FinalAPSPosition ;

extern T_DIAG_OUT VSVIOS_APS1RngLmtHiDiag ;
extern T_DIAG_OUT VSVIOS_APS1RngLmtLoDiag ;

extern T_DIAG_OUT VSVIOS_APS2RngLmtHiDiag ;
extern T_DIAG_OUT VSVIOS_APS2RngLmtLoDiag ;

extern T_DIAG_OUT VSVIOS_APS12CorrDiag ;
extern T_DIAG_OUT VSVIOS_APS12MinCorrDiag ;

extern T_DIAG_OUT VSVIOS_SBWSLvrDiag ;

extern T_LEARN_OUT VSVIOS_APS1MinLearnOut ;
extern T_LEARN_OUT VSVIOS_APS2MinLearnOut ;

extern float VfVIOS_k_APS1WeightFactor ;
extern float VfVIOS_k_APS2WeightFactor ;

extern float VfVIOS_Pct_APS1LearnedMin ;
extern float VfVIOS_Pct_APS2LearnedMin ;

extern float VfVIOS_U_12VBatteryVoltage ;
extern float VfVIOS_U_IgnitionVoltage ;

extern float VfVIOS_U_CruiseSWPctVoltage;
extern float VfVIOS_U_CruiseSWRawVoltage;

extern uint8_t VbVIOS_AccelPedalApplied ;

extern float VfVIOS_Pct_APS1PctVoltage ;
extern float VfVIOS_Pct_APS2PctVoltage ;

extern float VfVIOS_U_APS1RawVoltage ;
extern float VfVIOS_U_APS2RawVoltage ;

extern float VfVIOS_Pct_APS1IndPosition ;
extern float VfVIOS_Pct_APS2IndPosition ;

extern uint8_t VbCANN_ECAN_Tx_Busy ;
extern uint8_t VbCANN_PCAN_Tx_Busy ;

// ECAN VCU 0x1D4
extern uint8_t VeBMSC_MainContactorControl ;

// ECAN VCU 0x1D5
//extern float VfTORQ_M_CANSend_EVDemandTorque ;
extern uint8_t VeMCUC_OperationalModeCmd ;
extern uint8_t VeMCU_ACTV_Discharge_REQ;
extern uint8_t VeMCUC_CommandModeVCU ;

// ECAN VCU 0x3AE

extern float VfMCUC_U_MaxBatteryVoltage ;
extern float VfMCUC_U_MinBatteryVoltage ;

extern float VfMCUC_A_MaxDischargeCurrent ;
extern float VfMCUC_A_MaxChargeCurrent ;

extern uint8_t VeMCUC_ActiveDampingDisableCommand ;
extern uint8_t VeMCUC_OperationRequest ;

extern uint8_t VbLDCC_LDC_Enable ;
extern uint8_t VeVIOS_VCU_Ready ;

extern uint8_t VfCANN_VCU_ECAN_3AEh_Counter ;

extern float VfTORQ_n_MotSpd_Vector_MCU	;
extern float VfTORQ_v_VehSpd_Vector_MCU ;
extern float VfTORQ_n_Filtered_MotSpd_Scalar_MCU	;

extern float VfTORQ_v_Filtered_VehSpd_Vector_MCU ;
extern float VfTORQ_n_Filtered_MotSpd_Vector_MCU ;

extern T_DIAG_OUT VSVIOS_BPSDiag ;
extern uint8_t VbVIOS_BrakePedalApplied ;

extern E_GEAR_POSITION VeSBWS_Lever_Position ;
extern E_STEP2GEARCHANGE VeVIOS_Step2GearChange ;
extern uint8_t VbVIOS_P2N_ByReleaseSW_flag ;
extern E_GEAR_POSITION VeSBWS_GearState4TqCtrl ;
extern uint8_t VbTORQ_GearReverese ;
extern uint8_t VfTORQ_RegenLevel ;
extern uint8_t VbTORQ_DriveFlag_PorN ;

extern uint8_t Vb_Charge_Reservation_Cancel_Flag ;
extern E_AUTOLOCK_STS Vb_AutoLockSts;
extern E_AUTOLOCK_STS Vb_Prev_KeyCycle_AutoLockSts ;

//extern float VfTORQ_M_RegenAvailableTorque	;
//extern float vfTORQ_M_BMSRegenAvailableTorque	;
//extern float VfTORQ_M_MCUMotorAvailableTorque	;
extern float VfTORQ_M_EVDemandTorque	;
extern float VfTORQ_M_EVFianlDemandTorque ;
extern float VfTORQ_M_CANSend_EVDemandTorque ;
extern float VfTORQ_M_Motoring_MaxTq ;
//extern float VfTORQ_M_LimitGenTq ;
//extern float VfTORQ_M_LimitMotTq ;
extern float VfTORQ_M_Generating_MaxTq ;
extern float VfTORQ_M_DriverMotorTorque ;
extern float VfTORQ_M_DriverGenTorque ;
extern float VfTORQ_M_DriverDemandTorque	;
extern float VfTORQ_v_LmtSpdbyDriveMode ;
extern float VfTORQ_v_LmtSpdbySwitch ;
extern float VfVIOS_CruiseTargetKPH ;
extern float VfTORQ_v_LimitSpeed ;
extern float VfTORQ_M_EVCommandTorque ;
extern E_ECO_ENERGY_FLOW VeTORQ_M_ECOEnergyFlowIND ;
extern E_ECO_GUIDE_Level_IND VeTORQ_M_ECO_Guide_Level_IND ;
extern float VfTORQ_v_LMTSpd4OverspeedMode ;
extern uint8_t VbTORQ_v_LMTSpdOverspeedMode_Flag ;

//0908 JE
extern float Vf_MCU_PowerConsumption ;
extern uint8_t VeTORQ_M_PwrLevel  ;
extern uint8_t VeTORQ_M_ChagLevel ;

extern uint8_t VbTORQ_REGN_AVAL_STS_EPT ;

extern E_IO_STATE VbDIL_ChargDoorOpCldFilted ;
extern E_IO_STATE VbVIOS_prev_CharOpCldStsFilted ;

extern int32_t VfVIOS_CharDoorOpenRequestTimer ;
extern int32_t VfVIOS_CharDoorCtrlTimer ;

extern E_GEAR_POSITION VeSBWS_GearState4MCUCtrl ;

//Ctrl
extern E_IO_STATE VbLSD_MainRlyCtrl;
extern E_IO_STATE VbLSD_IGN3Ctrl;
extern E_IO_STATE VbLSD_IGN4Ctrl;
extern E_IO_STATE VbLSD_FanRlyCtrl;
extern E_IO_STATE VbLSD_WaterPumpRlyCtrl;
extern E_IO_STATE VbLSD_QckChrgPosiRlyCtrl;
extern E_IO_STATE VbLSD_QckChrgNegaRlyCtrl;
extern E_IO_STATE VbHSD_ChrgPlugAutoLockIndicatorCtrl;
extern E_IO_STATE VbHSD_ChrgLED_R_Ctrl;
extern E_IO_STATE VbHSD_ChrgLED_G_Ctrl;
extern E_IO_STATE VbHSD_ChrgLED_B_Ctrl;
extern E_IO_STATE VbLSD_ChrgLED_Ctrl;
extern E_IO_STATE VbLSD_EVCCEnableCtrl;

extern uint8_t VbCharg_VCU_ISOLT_MTR_STP_REQ ;

extern E_IO_STATE VbLSD_ChargDoorRlyCtrl;

//Cmd
extern E_IO_STATE VbLSD_MainRlyCmd;
extern E_IO_STATE VbLSD_IGN3Cmd;
extern E_IO_STATE VbLSD_IGN4Cmd;
extern E_IO_STATE VbLSD_FanRlyCmd;
extern E_IO_STATE VbLSD_WaterPumpRlyCmd;
extern E_IO_STATE VbLSD_QckChrgPosiRlyCmd;
extern E_IO_STATE VbLSD_QckChrgNegaRlyCmd;
extern E_IO_STATE VbHSD_ChrgPlugAutoLockIndCmd;
extern E_IO_STATE VbHSD_ChrgLED_R_Cmd;
extern E_IO_STATE VbHSD_ChrgLED_G_Cmd;
extern E_IO_STATE VbHSD_ChrgLED_B_Cmd;
extern E_IO_STATE VbLSD_ChrgLED_Cmd;
extern E_IO_STATE VbHSD_EVCCEnableCmd;

extern E_IO_STATE VbLSD_ChargDoorRlyCmd;

extern float VfVIOS_FO_SBWS_PeriodCtrl;
extern float VfVIOS_FO_SBWS_PeriodCmd;
extern float VfVIOS_FO_SBWS_DutyCtrl;
extern float VfVIOS_FO_SBWS_DutyCmd;
extern float VfVIOS_FO_CoolFan_DutyCtrl;
extern float VfVIOS_FO_CoolFan_DutyCmd;
extern float VfVIOS_FO_WaterPump_DutyCtrl;
extern float VfVIOS_FO_WaterPump_DutyCmd;

extern uint8_t VbTORQ_LaunchActive ;
extern uint8_t VbTORQ_LaunchEnable ;
extern uint8_t VbTORQ_CreepActive ;
extern uint8_t VbTORQ_OverTemp[] ;
extern uint8_t VbTORQ_VehStopped ;
extern uint8_t VbTORQ_DoorHoodAjarFlag ;
extern float VfTORQ_M_SpeedGoverningTq_Pterm ;
extern float VfTORQ_M_SpeedGoverningTq_Iterm ;
extern float VfTORQ_M_SpeedGoverningTq_Diff ;
extern float VfTQ_N_CreepTq_pterm ;
extern float VfTQ_N_CreepTq_iterm ;

extern T_BMS_610H VSCAN_DCAN_BMS1_610h ;
extern can_message_t VSCAN_DCAN_BMS1_610h_MsgBox ;

extern uint8_t VbTORQ_ActiveDecelCruise ;
extern uint8_t VbTORQ_DecelCruisePIDReset ;

extern float VfMCUB_T_IGBT_Temp ;
extern float VfMCUB_T_MOT_Temp ;
extern float VfMCUB_T_Board_Temp ;
extern float VfTORQ_M_DecelCruiseSetTq ;
extern float VfTORQ_M_CreepTq ;
extern float VfTORQ_M_DecelCruiseGenTq ;
extern float VfTORQ_M_DecelCruiseTq ;
extern float VfTORQ_M_CoastRegenTq ;
extern float VfTORQ_M_CoastRegenTq4CANTx ;
extern float  VfTorq_EBURegenREQTq ;
extern float VfTORQ_M_Motoring_LaunchAssist ;
extern float VfTORQ_M_Motoring_Tq_APS ;
extern float VfTORQ_v_DecelCruiseTargetSpeedOffset ;
extern float VfVIOS_Pct_FinalBPSPosition ;
extern float VfTORQ_M_BMSMotorAvailableTorque	;
extern float VfTORQ_M_MCUMotorAvailableTorque	;
extern float VfTORQ_M_MotorAvailableTorque	;
extern float VfTORQ_M_BMSRegenAvailableTorque	;
extern float VfTORQ_M_MCURegenAvailableTorque	;
extern float VfTORQ_M_RegenAvailableTorque	;

extern E_DRIVE_MODE VeTORQ_DriveMode ;
extern uint8_t VbDriveMode_ModeChangeActive	;
extern uint8_t VbDriveMode_EcoPlusModeEnable;
extern uint8_t VcDriveMode_Count	;

extern E_DRIVE_MODE VeTORQ_PrevDriveMode ;

//extern uint8_t Vb_TorqCtrlDisabledCondMet	;
extern uint8_t VbRegenInhibition	;

extern float VfTORQ_k_rpm2kphCoeff	;

extern float VfTORQ_v_Filtered_VehSpd_Scalar_MCU	;

extern float VfTORQ_v_VehSpd_WSSFL	;
extern float VfTORQ_v_VehSpd_WSSFR	;
extern float VfTORQ_v_VehSpd_WSSRL	;
extern float VfTORQ_v_VehSpd_WSSRR	;
extern float VfTORQ_v_VehSpd_WSSFA	;
extern float VfTORQ_v_VehSpd_WSSRA	;
extern float VfTORQ_v_VehSpd_WSS	;

extern float VfFAN_Pct_Spd_CLT	;
extern float VfFAN_Pct_Spd_EPT	;
extern float VfFAN_Pct_Spd_eComp_Pressure	;
extern float VfFAN_Pct_Spd_eComp_RPM		;

extern float VfEWP_Pct_Spd_MotCoolFlow		;
extern float VfEWP_Pct_Spd_MCUCoolFlow		;
extern float VfEWP_Pct_Spd_HVACCoolFlow		;

extern float VfVIOS_T_ActualEPTCoolantFlow  ;

extern E_IO_STATE VbDIL_Auto_Lock_SW					;
extern E_IO_STATE VbDIH_Qck_Chrg_NegaRly_Fb			;
extern E_IO_STATE VbDIH_Qck_Chrg_PosiRly_Fb			;
extern E_IO_STATE VbDIL_Scheduled_Chrg_Cancel_SW		;
extern E_IO_STATE VbDIL_EVCC_Wku						;

extern E_EGP_PARKINGREQ VeVIOS_EGP_Parking_Req		;

extern E_ACC_STATE VeVIOS_ACC_State	;
extern E_MAIN_STATE VeVIOS_Main_State	;
extern E_MAIN_STATE VeVIOS_Main_Prev_State	;

extern uint8_t VcSKM_ST_REQ	;
extern uint8_t VeVIOS_Start	;

extern uint8_t VbMain_MainContactorOffFault ;
extern E_EV_READY_STATE VeMain_EV_READY_STATE ;
extern uint8_t Vb_MCANWkuCmd ;
extern uint8_t Vb_CCANWkuCmd ;
extern uint8_t Vb_ICANWkuCmd ;
extern uint8_t Vb_NM_MCANWkuCmd ;
extern uint8_t Vb_NM_CCANWkuCmd ;
extern uint8_t Vb_NM_ICANWkuCmd ;

extern uint8_t Vb_CAN1C5Send_Flag ;
extern E_CHRG_SCHEDULE_CHECK Ve_ChrgScheduleCheck;

extern uint8_t VbCharg_ChargFinished ;

extern E_CHRG_STATE VeCharge_State ;

extern uint8_t VeCharge_VCU_EVstat ;
extern uint8_t VbCharge_VCU_PDU_ContactorState ;
extern float VfCharge_VCU_EVSOC ;
extern float VfCharge_VCU_TargetVolt ;
extern float VfCharge_VCU_PresentVolt ;
extern uint8_t VbCharge_VCU_S2_OnReqACDC ;
extern float VfCharge_VCU_DC_EVMaxCurrent ;
extern float VfCharge_VCU_DC_EVMaxVoltage ;
extern float VfCharge_VCU_DC_EVTargetCurrent ;
extern float VfCharge_VCU_DC_EVTargetVoltage ;
extern float VfCharge_VCU_FullSOCRemainTime ;
extern uint8_t VbCharge_VCU_Command_En_OBC ;
extern E_CP_STATE VeCharge_VCU_CMDChargeCP ;
extern E_PD_STATE VeCharge_VCU_CMDChargePD ;
extern uint8_t VeCharge_VCU_CMDChargePWM ;
extern uint8_t VeCharge_VCU_CMDACChageStartReq ;
extern uint8_t VeCharge_VCU_AC_ChargingReady ;

extern uint8_t VeCharge_VCU_OBC_STS_Ready ;
extern uint8_t VeCharge_VCU_OBC_STS_CONTRAB ;
extern E_CHRG_FINISH_REASON VeCharge_VCU_ChgFinished ;
extern uint8_t VbCharg_NormalChargFinished ;
extern uint8_t VbCharg_AbnormalChargFinished ;
extern uint8_t VeCharge_VCU_BMS_ContactorState ;

extern uint8_t VeCharge_VCU_AC_Cmd_Char_CP ;
extern uint8_t VeCharge_VCU_AC_Cmd_Char_PD ;
//extern uint8_t VeCharge_VCU_AC_Cmd_Char_St_Req ;
extern float VfCharge_VCU_AC_Cmd_Char_PWM ;
extern uint8_t VbCharge_VCU_AC_ChargingReady ;
extern uint8_t VbCharge_VCU_AC_Cmd_En_OBC ;
//extern uint8_t VbCharge_VCU_S2_OnReqACDC ;
extern float VfCharge_VCU_AC_EVTargetCurrent ;
extern float VfCharge_VCU_AC_EVTargetVoltage ;
extern uint8_t VbCharge_VCU_AC1_CHARGE_CRT_Status ;
extern uint8_t VbCharge_VCU_AC2_CHARGE_CRT_Status ;
extern uint8_t VeCharge_VCU_AC_Cmd_Char_St_Req ;
extern uint8_t VeCharge_VCU_ChargeConnectionStatus ;

extern float VfCharge_PrecharVolStableDelay ;

extern uint32_t VcActiveCreep_count0	;
extern uint8_t VeCreepState	;

extern float VfTORQ_M_LmtSpdTorque		;
extern float VfTORQ_M_EVSystemAvailableTorque	;

extern uint8_t VbTORQ_LimitSpdCtrlEnabled	;
extern float VfTORQ_M_BMSMotorAvailablePower	;
extern float VfTORQ_M_BMSRegenAvailablePower	;
extern float VfTORQ_BMS_PowerAvailable2sMot  ;
extern float VfTORQ_BMS_PowerAvailable10sMot ;
extern float VfTORQ_BMS_PowerAvailable2sReg  ;
extern float VfTORQ_BMS_PowerAvailable10sReg ;

extern float VfTorq_LA_Speed ;
extern E_SMC_E_S VeComm_P211h_SMC_E_S ;
extern uint8_t VcWakeUp_SPIMODE ;
extern uint8_t VcWakeUp_WakeUpStat ;

extern E_CHRG_DOOR_STATE VeChgDr_State ;
extern uint16_t VcChgDr_Open_Count  ;
extern uint16_t VcChgDr_Close_Count ;
extern uint16_t VcChgDr_RlyOn_Count ;

extern uint8_t VbChgDr_OpenDemandFlag ;
extern E_IO_STATE VbLSD_ChargDoorRlyCtrl_Func ;

extern float VfDTE_EWMA_AC_Power ;
extern float VfDTE_EWMA_HTR_Power ;
extern float VfDTE_VehSOE ;
extern float VfDTE_VCU_STS_ESTM_DRV_Range_SOC ;
extern float VfDTE_VCU_STS_ESTM_DRV_Range_SOE ;
extern uint8_t Vb_Flag4Soc ;
extern float VfDTE_VCU_STS_ESTM_DRV_Range ;
extern float VfDTE_VCU_STS_ESTM_DRV_Range_FinalVal ;

extern uint8_t VbGrad_APSAct_GradCalStop_Flag  ;
extern uint16_t VfGrad_APSAct_GradCalStop_Timer ;
extern uint8_t VbGrad_BPSAct_GradCalStop_Flag  ;
extern float VfGrad_LongAc_Filt ;
extern float VfGrad_VehAc_Filt  ;
extern float VfTORQ_phi_Grad		;

extern float VfVIOS_ACC_Engine_Torque ;
extern float VfVIOS_ACC_Engine_Torque_Pct ;
extern float VfVIOS_Virtual_APSPosition ;

extern uint8_t VfVIOS_PW;
extern uint8_t VeVIOS_PW_Virtual_Flag;
extern uint8_t VbVIOS_CAN_Driver_Accel_Override;

extern E_SPD_LIM_STATE VeVIOS_Spd_Lim_State ;
extern uint8_t VbTORQ_KickDownEn ;
extern uint8_t VbTORQ_OverspeedFlag_KickDown ;
extern uint8_t VbTORQ_OverspeedFlag ;

extern uint8_t VbVIOS_AccelPedalApplied_PW ;
extern uint8_t VbTORQ_TipInActive ;
extern uint8_t VbTORQ_TipOutActive ;
extern uint16_t VeTORQ_period ;

extern float VfTORQ_TipIn_LowZoneStepUp ;
extern float VfTORQ_TipIn_MidZoneStepUp ;
extern float VfTORQ_TipIn_HighZoneStepUp ;
extern float VfTORQ_TipIn_FilterCoefficientUp ;

extern float VfTORQ_HighZoneStepDown ;
extern float VfTORQ_MidZoneStepDown ;
extern float VfTORQ_LowZoneStepDown ;

extern uint16_t VeTORQ_TipIn_MiddleZoneLoTq_Th ;
extern uint16_t VeTORQ_TipIn_MiddleZoneHiTq_Th ;

extern float VfTORQ_TipOut_HighP_Th ;
extern float VfTORQ_TipOut_MidP_Th ;

extern uint8_t Vb_ExtTqReqExit_Flag ;

extern uint8_t VeSBWS_Lever_Position_Fault ;

extern T_DIAG_OUT VSVIOS_DGDMTestDiagOut ;
extern T_DIAG_HISTORY VSVIOS_DGDMTestDiagHistory ;
extern T_DIAG_FREEZEFRAME VSVIOS_DGDMTestFreezeFrame ;

extern uint8_t VeCOMM_P1D2h_VCU_REQ_EN_ACOMP ;
extern uint8_t VeCOMM_P1D2h_VCU_REQ_EN_Heater ;
extern uint8_t Vb_VCU_REQ_LMT_ACCOMP_PWR ;
extern uint8_t Vb_VCU_REQ_LMT_Blower_Step ;
extern uint8_t Vb_VCU_REQ_LMT_CABN_Heater_PWR ;

extern uint8_t VbSBWS_GearChangeTransition ;
extern uint8_t VbVIOS_DrivDoorAjarOpenFlag ;
extern uint8_t VbSBWS_LowSpdGearChangeTransition ;
extern uint8_t Vb_ExtECUIntervention_Active ;
extern uint8_t Vb_TorqCtrlDisabledCondMet ;

extern float VfODO_ThisKeyCycle ;
extern float VfODD_SinceCodeClear ;

extern float VfSPD_SpeedPer1km ;
extern uint32_t VcSPD_VehStopCounterPer1km ;
extern uint32_t VcSPD_VehMovingCounterPer1km ;
extern uint32_t VcSPD_VehStopCounterPer5km ;
extern T_VALPER5KM_INT VSSPD_VehStopCounterPer5km ;
extern uint32_t VcSPD_VehMovingCounterPer5km ;
extern T_VALPER5KM_INT VSSPD_VehMovingCounterPer5km ;
extern T_VALPER5KM_FLOAT VSSPD_AvgSpeedPer5km ;

extern float VfDTE_VehSpd_MovingAvg ;

extern uint8_t VbODO_ResetFlag1km ;
extern float VfODO_1000m ;
extern float VfODO_5000m ;
extern T_VALPER5KM_FLOAT VSODO_5000m ;

extern uint8_t VcChargeComplt_Min_DC ;
extern uint16_t VcChargeComplt_Min_AC_UnPortable ;
extern uint16_t VcChargeComplt_Min_AC_Portable ;
extern uint16_t VcChargeComplt_Min ;
extern uint16_t VcChargeComplt_Min_SOC80;
extern uint8_t Ve_VCU_CHAR_INLT_STS_WRN_MSG ;
extern uint8_t Vb_Service_Wrn_Ind ;
extern uint8_t Ve_Service_Wrn_Msg ;
extern uint8_t Vb_Chrging_Sts_Wrn_Msg ;

extern uint8_t Vb_VCU_LV_System_WRN_IND ;
extern uint8_t Ve_VCU_LV_System_WRN_MSG ;
extern uint8_t Vb_VCU_HV_ACT_IND ;

extern uint8_t Vb_STPM_Mode_Flag ;
extern uint8_t Vb_STPM_HVAC_Mode_Flag ;
extern E_REMOTE_RESPONSE Ve_VCU_Remote_Response ;
extern float VfCHAG_TotalChargePwr ;

extern uint8_t VeVIOS_Charging_Sts_IND ;

extern uint8_t VeVIOS_Check_Variable ;

extern uint8_t Vb_EVCCWakeupCmdbyVCU ;
extern uint8_t Vb_EVCCStandbyCmdbyVCU;

extern E_CHRG_INHIBITION_REASON VeChrg_ChrgInhibitition ;

extern float VfCharge_VCU_DC_EVTargetCurrent_Pct ;
extern float VfCharge_VCU_DC_EVTargetCurrent_CalculatedVal ;
extern float VfEVCC_Evse_LimitCurr_A ;
extern float VfECAN_RxEVCC_511h_EVSEMaxA ;

extern E_VCU_HV_PWR_STATE Ve_HV_Pwr_State ;
extern uint8_t Vb_VCU_HV_Low_SOC_WRN_IND ;
extern E_VCU_HV_PWR_LMT_WRN_MSG Ve_VCU_HV_PwrLmtWrnMsg ;

extern E_VCU_EVPWRDNWRN_IND_STATE Ve_VCU_EvPwrDnWrn_Ind_Sts ;
extern uint8_t Vb_VCU_EV_Power_Down_Wrn_Ind ;

extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_RSOC;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_DERATING;
//extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_BMS;
//extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Inverter;
//extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Motor;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_TmpHigh_COOLTS;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_TqLmt;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_HVDCLinkVLow;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnBMSPwrLow;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_2;
extern uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_10;

extern int32_t V_LVBatt_Volt ;
extern int32_t V_LVBatt_Temp ;
extern int32_t V_LVBatt_Curr ;
extern int32_t V_LVBatt_SOC ;
extern int32_t V_LVBatt_SOH ;
extern int32_t V_LVBatt_OCV ;
extern int32_t V_LVBatt_CNOM ;

extern uint8_t Vb_LIN1Rx_Flag ;
extern uint8_t Vb_LIN2Rx_Flag ;

extern T_LVAUTOCHRG_DISREASON Vs_LVAutoChrg_DisReason ;
extern uint8_t Vb_LVAutoChrgEn_Flag ;

extern uint8_t V_Flag_110Rx ;
extern uint8_t V_Flag_115Rx ;
extern uint64_t V_ECU_Immo ;

extern uint8_t V_NM_IGN3_STS_VCU ;
extern uint8_t V_NM_Ignition1Sts_VCU ;

extern uint8_t V_RxCGW_15Ah_ACChargingTargetSetCmd ;
extern uint8_t V_RxCGW_15Ah_DCChargingTargetSetCmd ;

extern uint8_t VcCount_DCCharge ;
extern uint8_t Vb_VoltDiffErr_Flag ;

extern E_TIPIN_STATE Ve_TipInState ;
extern E_TIPOUT_STATE Ve_TipOutState ;

extern uint8_t Vb_HVBattLowVolt_Condition_Flag ;
extern E_GEAR_POSITION Ve_Prev_KeyCycle_Gear_Position ;

extern E_VCU_SHIFT_UNMATCH_WRN Ve_VCU_Shift_COND_Unmatch_WRN_MSG ;
extern uint8_t Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_SPDCOND_1u ;
extern uint8_t Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOBRAKE_CHANGE_2u ;
extern uint8_t Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOSTOP_P_3u ;
extern uint8_t Vb_Flag_VCU_Shift_COND_Unmatch_WRN_MSG_NOBRAKE_PRELEASE_4u ;

extern E_VCU_SHIFTCTRLSTS_WRN_MSG Ve_VCU_ShiftCtrl_WRN_MSG ;
extern uint8_t Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_P_Engaged_1u ;
extern uint8_t Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_N_Engaged_2u ;
extern uint8_t Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_P_Malfunction_3u ;
extern uint8_t Vb_Flag_VCU_ShiftCtrl_Wrn_Msg_CheckSystem_4u ;

//extern uint8_t VcCount4Check_RomData_AutoLockSts;

extern uint8_t Vb_VCU_PAD_COND_WRN_MSG ;

extern float VfTORQ_v_CreepTargetSpd ;

extern uint8_t ACU_Crashout_ACU_135h_RAW ;

extern uint8_t ChargingStopCmdbyAVN_AVN_1CD_RAW ;
extern uint8_t RespChargingScheduleSts_AVN_1CD_RAW ;
extern uint8_t ScheduledChargingCmd_AVN_1CD_RAW ;

extern uint8_t FixedTypeChargeCurrentSetCmd_AVN_15Ah_RAW ;
extern uint8_t PortableTypeChargeCurrentSetCmd_AVN_15Ah_RAW ;
extern uint8_t AcChargingTartgetSetCmd_AVN_15Ah_RAW ;
extern uint8_t DcChargingTartgetSetCmd_AVN_15Ah_RAW ;

extern uint8_t HoodAjarSts4p_BCM_511h_RAW ;
extern uint8_t RearDefoggerActSts_BCM_511h_RAW ;
extern uint8_t FrontWiperMotorSts4P_BCM_511h_RAW ;
extern uint8_t HeadLightOnOff4P_BCM_511h_RAW ;
extern uint8_t DRLSts_BCM_511h_RAW ;
extern uint8_t DrivSeatBeltSts_BCM_511h_RAW ;

extern uint8_t BLS_PA_BS_200h_P_RAW ;
extern uint8_t BLS_BS_200h_P_RAW ;
extern uint8_t BZ200h_BS_200h_P_RAW ;
extern uint16_t DVL_BS_200h_P_RAW ;
extern uint16_t DVR_BS_200h_P_RAW ;
extern uint16_t TM_DL_BS_200h_P_RAW ;

extern uint8_t REGEN_ENABLE_STS_BS_207h_P_RAW ;
extern uint8_t PTS_SNS_FAIL_BS_207h_P_RAW ;
extern uint8_t RBC_DEF_BS_207h_P_RAW ;
extern uint8_t REQ_COAST_REGEN_EXIT_BS_207h_P_RAW ;
extern uint8_t Counter_207h_BS_207h_P_RAW ;
extern uint8_t REGEN_EXIT_MONITORING_BS_207h_P_RAW ;
extern uint8_t EBU_PW_BS_207h_P_RAW ;
extern uint8_t Checksum_207h_BS_207h_P_RAW ;
extern uint16_t REGEN_REQ_TQ_BS_207h_P_RAW ;
extern uint16_t DRIVER_REQ_PRESSURE_BS_207h_P_RAW ;

extern uint8_t TM_AUS_BS_208h_P_RAW ;
extern uint16_t DHR_BS_208h_P_RAW ;
extern uint16_t DHL_BS_208h_P_RAW ;

extern uint8_t HSA_DEF_FLG_BS_20Ah_P_RAW ;
extern uint8_t HSA_CTR_FLAG_BS_20Ah_P_RAW ;
extern uint8_t Counter_20Ah_BS_20Ah_P_RAW ;
extern uint8_t Checksum_20Ah_BS_20Ah_P_RAW ;
extern uint16_t ACC_Engine_Torque_Value_BS_20Ah_P_RAW ;

extern uint8_t MMOTSE_PA_BS_300h_P_RAW ;
extern uint8_t MMOTSR_PA_BS_300h_P_RAW ;
extern uint8_t MPAR_ESP_BS_300h_P_RAW ;
extern uint8_t TOGGLE_BS_300h_P_RAW ;
extern uint8_t MMAX_ESP_BS_300h_P_RAW ;
extern uint8_t MMIN_ESP_BS_300h_P_RAW ;
extern uint8_t MTGL_ESP_BS_300h_P_RAW ;
extern uint8_t Counter_300h_BS_300h_P_RAW ;
extern uint8_t BZ300h_BS_300h_P_RAW ;
extern uint8_t Checksum_300h_BS_300h_P_RAW ;
extern uint16_t M_ESP_BS_300h_P_RAW ;

extern uint8_t EBS_STATUS_BS_330h_P_RAW ;
extern uint8_t Counter_330h_BS_330h_P_RAW ;
extern uint8_t Checksum_330h_BS_330h_P_RAW ;
extern uint16_t EST_REF_VELOCITY_BS_330h_P_RAW ;

extern uint16_t PS_MEANVAL_BS_331h_P_RAW ;

extern uint8_t EPB_RBLRQ_BS_340h_EPB_RAW ;
extern uint8_t EPB_Status_BS_340h_EPB_RAW ;
extern uint8_t Counter_340h_BS_340h_EPB_RAW ;
extern uint8_t Checksum_340h_BS_340h_EPB_RAW ;

extern uint8_t AVH_LAMP_INFO_360h_AVH_RAW ;

extern uint8_t CCU_ChargingStopReq_CCU_1C4h_RAW ;
extern uint8_t CCU_ImmediateChargingReq_CCU_1C4h_RAW ;

extern uint8_t HeadLampHighSts_CGW_372h_RAW ;
extern uint8_t HazardSw_CGW_372h_RAW ;
extern uint8_t DrivDoorLockUnSts_CGW_372h_RAW ;
extern uint8_t DrivDoorAjarSts_CGW_372h_RAW ;
extern uint8_t BatteryCheckReqCmdbyCCU_CGW_372h_RAW ;

extern uint8_t NM_SleepFlag_CGW_CGW_448h_RAW ;
extern uint8_t NM_CommandCode_CGW_448h_RAW ;
extern uint8_t NM_Destination_CGW_448h_RAW ;

extern uint64_t DIAG_REQ_FUNC_700h_RAW ;

extern uint8_t Pmotor_Position_Failure_EGP_1E8h_RAW ;
extern uint8_t Shifting_In_Progress_EGP_1E8h_RAW ;
extern uint8_t EGP_Service_WRN_IND_EGP_1E8h_RAW ;
extern uint8_t Pmotor_Position_Status_EGP_1E8h_RAW ;
extern uint8_t EGP_OperationMode_EGP_1E8h_RAW ;
extern uint8_t Counter_1E8h_EGP_1E8h_RAW ;
extern uint8_t Pmotor_Error_Level_EGP_1E8h_RAW ;
extern uint8_t Checksum_1E8h_EGP_1E8h_RAW ;

extern uint16_t AC_REF_High_Pressure_EHVC_1EBh_RAW ;
extern uint16_t Cabin_HTR_Power_EHVC_1EBh_RAW ;

extern uint8_t eComp_Phase_Current_EHVC_33Eh_RAW ;
extern uint8_t eComp_Inverter_Temp_EHVC_33Eh_RAW ;
extern uint8_t eComp_Battery_Voltage_EHVC_33Eh_RAW ;
extern uint16_t eComp_Power_EHVC_33Eh_RAW ;
extern uint16_t eComp_Drive_RPM_EHVC_33Eh_RAW ;

extern uint8_t DATC_STS_CHILLER_EHVC_33Fh_RAW ;
extern uint8_t Cabin_HTR_Current_EHVC_33Fh_RAW ;

extern uint8_t ACC_SystemState_FRM_259h_RAW ;
extern uint8_t ACC_Mode_FRM_259h_RAW ;
extern uint8_t Counter_259h_FRM_259h_RAW ;
extern uint8_t Checksum_259h_FRM_259h_RAW ;

extern uint8_t FAN_Status_HVAC_235h_RAW ;
extern uint8_t HVAC_TEMP_Status_HVAC_235h_RAW ;
extern uint8_t HVAC_Mode_Status_HVAC_235h_RAW ;
extern uint8_t RearDefoggerSwSts_HVAC_235h_RAW ;
extern uint8_t Incar_Temp_HVAC_235h_RAW ;

extern uint8_t HVAC_Cooling_STS_HVAC_355h_RAW ;
extern uint8_t HVAC_Heating_STS_HVAC_355h_RAW ;
extern uint8_t HVAC_HEX_ICING_STS_HVAC_355h_RAW ;
extern uint8_t HVAC_DEF_STS_HVAC_355h_RAW ;
extern uint8_t HVAC_Temp_Act_STS_L_HVAC_355h_RAW ;
extern uint8_t HVAC_Temp_Act_STS_R_HVAC_355h_RAW ;

extern uint8_t DrvMode1_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t DrvMode2_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t DrvMode3_RegenLevelSetCmd_ICM_152h_RAW ;
extern uint8_t DrvMode4_RegenLevelSetCmd_ICM_152h_RAW ;

extern uint8_t ACC_SW_ICM_160h_RAW ;
extern uint8_t ACC_Accel_RES_SW_ICM_160h_RAW ;
extern uint8_t ACC_Decel_SET_SW_ICM_160h_RAW ;
extern uint8_t ACC_DistanceSW_ICM_160h_RAW ;
extern uint8_t SpeedLimitSW_ICM_160h_RAW ;
extern uint8_t RegenUpSW_ICM_160h_RAW ;
extern uint8_t RegenDownSW_ICM_160h_RAW ;
extern uint8_t Counter_160h_ICM_160h_RAW ;
extern uint8_t Checksum_160h_ICM_160h_RAW ;

extern uint8_t V_MPH_ICM_303h_RAW ;
extern uint8_t Counter_303h_ICM_303h_RAW ;
extern uint8_t T_Outside_ICM_303h_RAW ;
extern uint8_t Checksum_303h_ICM_303h_RAW ;
extern uint16_t Speed_Combi_ICM_303h_RAW ;
extern uint16_t V_ANZ_ICM_303h_RAW ;

extern uint8_t OM_High_ICM_304h_RAW ;
extern uint16_t KM16_ICM_304h_RAW ;

extern uint8_t LDC_Out_Emergency_LDC_3A0h_RAW ;
extern uint8_t LDC_Service_WRN_IND_LDC_3A0h_RAW ;
extern uint8_t LDC_STS_Ready_LDC_3A0h_RAW ;
extern uint8_t LDC_Out_Mode_LDC_3A0h_RAW ;
extern uint8_t LDC_STS_MODE_LDC_3A0h_RAW ;
extern uint8_t Counter_3A0h_LDC_3A0h_RAW ;
extern uint8_t LDC_STS_TEMP_LDC_3A0h_RAW ;
extern uint8_t Checksum_3A0h_LDC_3A0h_RAW ;
extern uint16_t LDC_STS_Power_OUT_LDC_3A0h_RAW ;

extern uint8_t LDC_STS_VOLT_OUT_LDC_3A1h_RAW ;
extern uint8_t LDC_STS_CURR_IN_LDC_3A1h_RAW ;
extern uint16_t LDC_STS_VOLT_IN_LDC_3A1h_RAW ;
extern uint16_t LDC_STS_CURR_OUT_LDC_3A1h_RAW ;

extern uint8_t MCU_Service_WRN_IND_MCU_327h_RAW ;
extern uint16_t MCU_PowerConsumption_MCU_327h_RAW ;

extern uint8_t OBC_STS_Ready_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_CONTRAB_OBC_3A8h_RAW ;
extern uint8_t OBC_CMD_Chg_Finished_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_AC_DETECT_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_Temporary_Stop_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_SC_State_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_PC_State_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_CHECK_GROUP_OBC_3A8h_RAW ;
extern uint8_t OBC_STS_TEMP_OBC_3A8h_RAW ;

extern uint16_t OBC_AC_V_rms_OBC_3A9h_RAW ;
extern uint16_t OBC_AC_I_rms_OBC_3A9h_RAW ;
extern uint16_t OBC_DC_Output_V_OBC_3A9h_RAW ;
extern uint16_t OBC_DC_Output_I_OBC_3A9h_RAW ;

extern uint8_t SBWS_STS_Parking_Release_SW_SBWS_1E7h_RAW ;
extern uint8_t SBW_STS_SBWS_1E7h_RAW ;
extern uint8_t SBW_ShutDown_Timer_SBWS_1E7h_RAW ;
extern uint8_t SBWS_Lever_SBWS_1E7h_RAW ;
extern uint8_t SBW_WRN_MSG_SBWS_1E7h_RAW ;
extern uint8_t Counter_1E7h_SBWS_1E7h_RAW ;
extern uint8_t Checksum_1E7h_SBWS_1E7h_RAW ;

extern uint8_t REKESChargingStopCmd_SKM_076h_RAW ;

extern uint8_t ST_REQ_SKM_110h_RAW ;

extern uint8_t HighVoltageRelayOnOffReqCmd_SKM_111h_RAW ;

extern uint64_t SKM_Immo_SKM_115h_RAW ;

extern uint8_t BatteryCheckReqCmdbySTPM_STPM_APPL01_161h_RAW ;

extern uint64_t VCU_Calibration_630h_RAW ;

extern uint64_t DGN_REQ_VCU_7E0h_RAW ;

extern uint8_t CF_Yrs_Yr_Fail_YRS_130h_RAW ;
extern uint8_t CF_Yrs_Yr_Init_YRS_130h_RAW ;
extern uint8_t CF_Yrs_LatAc_Fail_YRS_130h_RAW ;
extern uint8_t CF_Yrs_LatAc_Init_YRS_130h_RAW ;
extern uint8_t CR_Yrs_Crc1_YRS_130h_RAW ;
extern uint16_t CR_Yrs_Yr_YRS_130h_RAW ;
extern uint16_t CR_Yrs_LatAc_YRS_130h_RAW ;

extern uint8_t CR_Yrs_LongAc_Fail_YRS_140h_RAW ;
extern uint8_t CR_Yrs_LongAc_Init_YRS_140h_RAW ;
extern uint8_t CR_Yrs_MsgCnt2_YRS_140h_RAW ;
extern uint8_t CR_Yrs_Crc2_YRS_140h_RAW ;
extern uint16_t CR_Yrs_LongAc_YRS_140h_RAW ;


extern uint64_t ECU_Immo_VCU_105h_RAW ;

extern uint8_t HighVoltageRelayOnReqFb_VCU_116h_RAW ;

extern uint64_t VCU_Calibration_631h_Signal_VCU_631h_RAW ;
extern uint64_t VCU_Calibration_632h_Signal_VCU_632h_RAW ;
extern uint64_t VCU_Calibration_633h_Signal_VCU_633h_RAW ;
extern uint64_t VCU_Calibration_634h_Signal_VCU_634h_RAW ;

extern uint8_t ChargingScheduleCheck_VCU_1C5h_RAW ;

extern uint8_t FixedTypeChargeCurrentSetSts_VCU_3AFh_RAW ;
extern uint8_t PortableTypeChargeCurrentSetSts_VCU_3AFh_RAW ;
extern uint8_t DcChargingTartgetSetSts_VCU_3AFh_RAW ;
extern uint8_t AcChargingTartgetSetSts_VCU_3AFh_RAW ;

extern uint8_t ChargingFinish_VCU_1D7h_RAW ;
extern uint8_t ChargingStopReason_VCU_1D7h_RAW ;

extern uint64_t DGN_RESP_VCU_7E8h_RAW ;

extern uint8_t ImmediateChargingResult_VCU_1CCh_RAW ;
extern uint8_t ImmeChargingStartFailReason_VCU_1CCh_RAW ;
extern uint8_t ImmeChargingStopFailReason_VCU_1CCh_RAW ;

extern uint8_t NM_McanWakeupCmd_VCU_414h_RAW ;
extern uint8_t NM_IcanWakeupCmd_VCU_414h_RAW ;
extern uint8_t NM_CcanWakeupCmd_VCU_414h_RAW ;
extern uint8_t NM_SleepFlag_VCU_414h_RAW ;
extern uint8_t NM_CommandCode_VCU_414h_RAW ;
extern uint8_t NM_WakeupReason_VCU_414h_RAW ;
extern uint8_t NM_FormerState_VCU_414h_RAW ;
extern uint8_t NM_Destination_VCU_414h_RAW ;
extern uint16_t NM_Reserved_VCU_414h_RAW ;

extern uint8_t ScheduledChargingResult_VCU_1D6h_RAW ;
extern uint8_t ScheChargingStartFailReason_VCU_1D6h_RAW ;
extern uint8_t ScheChargingStopFailReason_VCU_1D6h_RAW ;

extern can_message_t ECAN_RX0_Message_Buffer[2];
extern can_message_t ECAN_RX1_Message_Buffer[2];
extern can_message_t ECAN_RX2_Message_Buffer[2];
extern can_message_t ECAN_RX3_Message_Buffer[2];
extern can_message_t ECAN_RX4_Message_Buffer[2];
extern can_message_t ECAN_RX5_Message_Buffer[2];
extern can_message_t ECAN_RX6_Message_Buffer[2];
extern can_message_t ECAN_RX7_Message_Buffer[2];

extern uint32_t ECAN_RX0_BufferIndex  ;
extern uint32_t ECAN_RX1_BufferIndex  ;
extern uint32_t ECAN_RX2_BufferIndex  ;
extern uint32_t ECAN_RX3_BufferIndex  ;
extern uint32_t ECAN_RX4_BufferIndex  ;
extern uint32_t ECAN_RX5_BufferIndex  ;
extern uint32_t ECAN_RX6_BufferIndex  ;
extern uint32_t ECAN_RX7_BufferIndex  ;

extern can_message_t PCAN_RX0_Message_Buffer[2];
extern can_message_t PCAN_RX1_Message_Buffer[2];
extern can_message_t PCAN_RX2_Message_Buffer[2];
extern can_message_t PCAN_RX3_Message_Buffer[2];
extern can_message_t PCAN_RX4_Message_Buffer[2];
extern can_message_t PCAN_RX5_Message_Buffer[2];
extern can_message_t PCAN_RX6_Message_Buffer[2];
extern can_message_t PCAN_RX7_Message_Buffer[2];

extern uint32_t PCAN_RX0_BufferIndex  ;
extern uint32_t PCAN_RX1_BufferIndex  ;
extern uint32_t PCAN_RX2_BufferIndex  ;
extern uint32_t PCAN_RX3_BufferIndex  ;
extern uint32_t PCAN_RX4_BufferIndex  ;
extern uint32_t PCAN_RX5_BufferIndex  ;
extern uint32_t PCAN_RX6_BufferIndex  ;
extern uint32_t PCAN_RX7_BufferIndex  ;

#endif

extern void variables_init(void) ;
//
//#endif /* E100_VARIABLES_H_ */


#endif /* E110_VARIABLES_H_ */
