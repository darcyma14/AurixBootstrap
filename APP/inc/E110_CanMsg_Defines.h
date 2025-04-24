///*
// * E100_CanMsg_Defines.h
// *
// *  Created on: 2019. 8. 12.
// *      Author: jinwo
// */
//
#ifndef E100_CANMSG_DEFINES_H_
#define E100_CANMSG_DEFINES_H_
//
//#include "Cpu.h"
#include <stdint.h>

/*Tx TCU*/
typedef struct
{
	uint8_t TQ_COMMAND_Low;
	uint8_t TQ_COMMAND_High;

	uint8_t Speed_Ctrl_Enable ;
//	uint8_t : 6;

	uint8_t EOP_Spd_Reference_Low;
	uint8_t EOP_Spd_Reference_High;
//	uint16_t EOP_Spd_Reference ;

//	uint16_t : 16;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
} TxTCU_ESCC;

typedef struct
{
	uint8_t DV_A_Final_Sol_Ctrl_Value_G1 ;
	uint8_t DV_A_Final_Sol_Ctrl_Value_G2 ;
	uint8_t DV_A_Final_Sol_Ctrl_Value_TV_R ;
	uint8_t DV_A_Final_Sol_Ctrl_Value_TV_L ;
	uint8_t DV_VehSpeed ;
	uint8_t DV_degC_OilTemp ;
	uint8_t DV_bar_SIG_PRES_MAIN_Low ;
	uint8_t DV_bar_SIG_PRES_MAIN_High ;
} TxTCU_debug1;

typedef struct
{
	uint8_t DV_bar_SIG_PRES_G1_Low ;
	uint8_t DV_bar_SIG_PRES_G1_High ;
	uint8_t DV_bar_SIG_PRES_G2_Low ;
	uint8_t DV_bar_SIG_PRES_G2_High ;
	uint8_t DV_bar_SIG_PRES_TV_L_Low ;
	uint8_t DV_bar_SIG_PRES_TV_L_High ;
	uint8_t DV_bar_SIG_PRES_TV_R_Low ;
	uint8_t DV_bar_SIG_PRES_TV_R_High ;
} TxTCU_debug2;

typedef struct
{
	uint8_t DV_DI_EPARK_L ;
	uint8_t DV_DI_EPARK_R ;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
} TxTCU_debug3;

/*Rx TCU*/
typedef struct
{
	uint8_t : 8;
	uint8_t : 8;

	uint8_t Speed_Ctrl_ReadySts ;
//	uint8_t : 6;

	uint8_t EOP_Spd_Low;
	uint8_t EOP_Spd_High;
//	uint16_t EOP_Spd ;

	uint8_t EOP_Spd_Reference_Low;
	uint8_t EOP_Spd_Reference_High;
//	uint16_t EOP_Spd_Reference ;

	uint8_t : 8;
} RxTCU_ESCS;

typedef struct
{
	uint8_t Mot_Speed_Low;
	uint8_t Mot_Speed_High;
	uint8_t Tq_Actual_Low;
	uint8_t Tq_Actual_High;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
} RxTCU_MCU;

typedef struct
{
	uint8_t DrivingPosition ;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
	uint8_t : 8;
} RxTCU_VEH;

typedef struct
{

	uint8_t Coolant_Temp;	// Volt, Scale = Vadc[v] x 10		I_AH_T1
	uint8_t Chrg_Plug_Temp;	// Volt, Scale = Vadc[v] x 10		I_AH_T5
	uint8_t APS1;			// Volt, Scale = Vadc[v] x 10		I_AL_APS1
	uint8_t APS2;			// Volt, Scale = Vadc[v] x 10		I_AL_APS2
	uint8_t Cruise_control_SW;	// Volt, Scale = Vadc[v] x 10	I_AX_CRZ

	uint8_t PWMI_Fan;		// Duty, Scale = 1					I_PH_02
	uint8_t PWMI_SBWS;		// Freq, Scale = PWMI / 10			I_PH_03
	uint8_t PWMI_EWP;		// Duty, Scale = 1					I_PH_04

}TxVCU_100H;

typedef struct
{
	uint8_t DI_1;
	//bit 0 : I_SH_02
	//bit 1 : I_SH_03
	//bit 2 : I_SH_05
	//bit 3 : I_SH_06
	//bit 4 : I_SL_01
	//bit 5 : I_SL_02
	//bit 6 : I_SL_03
	//bit 7 : I_SL_04

	uint8_t DI_2;
	//bit 0 : I_SL_06
	//bit 1 : I_SL_07
	//bit 2 : I_SL_08
	//bit 3 : I_SL_09
	//bit 4 : I_SL_10
	//bit 5 : P_ACC
	//bit 6 : P_IGN
	//bit 7 :

	uint8_t DO_1;
	//bit 0 : O_SH_02
	//bit 1 : O_SH_LED01
	//bit 2 : O_SH_LED02
	//bit 3 : O_SH_LED03
	//bit 4 : O_SL_01
	//bit 5 : O_SL_02
	//bit 6 : O_SL_03
	//bit 7 : O_SL_04

	uint8_t DO_2;
	//bit 0 : O_SL_07
	//bit 1 : O_SL_08
	//bit 2 : O_SL_10
	//bit 3 : O_SL_19
	//bit 4 :
	//bit 5 :
	//bit 6 :
	//bit 7 :

	uint8_t PWMO_Fan; 	//O_SL_17
	uint8_t PWMO_EWP; 	//O_SL_18
	uint8_t PWMO_SBWS; 	//O_SL_20

	uint8_t PMIC;		//PMIC voltage stat
	//bit 0 :
	//bit 1 :
	//bit 2 : Standby LDO voltage ready(QST)		1=OK, 0=NOK
	//bit 3 :
	//bit 4 : Communication LDO voltage ready(QCO)	1=OK, 0=NOK
	//bit 5 : Voltage reference voltage ready(QVR)	1=OK, 0=NOK
	//bit 6 : Tracker1 voltage ready(QT1)			1=OK, 0=NOK
	//bit 7 : Tracker2 voltage ready(QT2)			1=OK, 0=NOK
}TxVCU_101H;

typedef struct
{
	uint8_t data0;	// 0xAA
	uint8_t data1;
	uint8_t data2;
	uint8_t data3;
	uint8_t data4;
	uint8_t data5;
	uint8_t data6;
	uint8_t data7;
}TxVCU_6C0H;














//Valid Flag for CAN Msg Counter 220810 -wnjeong
//ECAN Msg Valid Flag
#define ECAN_1D4_VALID  (1 << 0)
#define ECAN_1D5_VALID  (1 << 1)
#define ECAN_3AE_VALID  (1 << 2)

//PCAN Msg Valid Flag
#define PCAN_1D3_VALID  (1 << 0)
#define PCAN_1D2_VALID  (1 << 1)
#define PCAN_211_VALID  (1 << 2)
#define PCAN_245_VALID  (1 << 3)
#define PCAN_1D1_VALID  (1 << 4)

//#pragma pack(1)

/* ECAN Msg Definitions */

typedef struct
{
	uint8_t VCU_MainContactorControl : 2 ;
	uint8_t VCU_ISOLT_MTR_STP_REQ : 1 ;
	uint8_t : 5 ;

	uint8_t : 8 ;
	uint16_t : 16 ;
	uint16_t : 16 ;

	uint8_t Counter_1D4h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_1D4h ;


} T_VCU_1D4H ;

typedef struct
{
	uint8_t ActualEPTCoolantFlow ;

	uint8_t EPTCoolantTemp ; //ADDED_20201201

	uint8_t CommandModeVCU : 2 ;
	uint8_t VCU_ACTV_Discharge_REQ : 1 ;
	uint8_t : 5 ;

	uint8_t OperationalModeCmd : 3 ;
	uint8_t : 5 ;

	uint16_t TorqueCommand ;

	uint8_t Counter_1D5h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_1D5h ;
} T_VCU_1D5H ;

typedef struct
{
	uint64_t Checksum_3AEh : 8 ;
	uint64_t Counter_3AEh : 4 ;
	uint64_t MaxChargeCurrent : 12 ;
	uint64_t MaxDischargeCurrent : 12 ;
	uint64_t : 1 ;
	uint64_t ActiveDampingDisableCommand : 2 ;
	uint64_t : 1 ;
	uint64_t MinBatteryVoltage : 10 ;
	uint64_t OperationRequest : 3 ;
	uint64_t : 1 ;
	uint64_t MaxBatteryVoltage : 10 ;

} T_VCU_3AEH ;	/* WARN: ENDIAN correct ? */

typedef struct
{
	uint16_t CMXVersion_VCU_ECAN  ;

	uint8_t DTCInfo_VCU_ECAN : 2 ;
	uint8_t : 6 ;

	uint8_t SupplyVolt_VCU_ECAN ;

	uint8_t RxErrCnt_VCU_ECAN ;

	uint8_t TxErrCnt_VCU_ECAN ;

	uint8_t BusOffCnt_VCU_ECAN ;

	uint8_t MsgAliveCnt_VCU_ECAN ;


} T_VCU_514H_OLD ; //ADDED_20201201

typedef struct
{
	uint8_t BMS_BatteryPackStatus : 4 ;
	uint8_t BMS_OperationMode : 4 ;

	uint16_t BMS_DCLinkVoltage ;
	uint16_t BMS_BatteryPackCurrent ;

	//uint8_t BMS_MainMinusContactorCoilState : 2 ; //ADDED_20201201
	//uint8_t BMS_MainPlusContactorCoilState : 2 ; //ADDED_20201201
	//uint8_t BMS_PrechargeusContactorCoilState : 2 ; //ADDED_20201201
	uint8_t : 6	;
	uint8_t BMS_IGN_STAT : 1 ;
	uint8_t BMS_HVILStatus : 1 ;

	uint8_t Counter_1D9h : 4 ;
	uint8_t BMS_MainMinusContactorState : 1 ;
	uint8_t BMS_MainPlusContactorState : 1 ;
	uint8_t BMS_PrechargeusContactorState : 1 ;
	uint8_t BMS_ContactOffRequest : 1 ;

	uint8_t Checksum_1D9h ;

} T_BMS_1D9H ;

typedef struct
{
	uint16_t BMS_BatteryPackVoltage ;

	uint16_t BMS_BatteryPackASOC : 10 ;
	uint16_t : 2 ;
	uint16_t BMS_Mode : 2 ;
	uint16_t BMS_CoolingPumpStatus : 1 ;
	uint16_t : 1 ;

	uint16_t BMS_BatteryPackRSOC : 10 ;
	uint16_t : 6 ;

	uint16_t BMS_BatteryPackSOH : 10 ;
	uint16_t : 6 ;

} T_BMS_321H ;

typedef struct
{
	uint16_t BMS_BatteryMinCellVoltage ;
	uint16_t BMS_BatteryMaxCellVoltage ;
	uint16_t BMS_BatteryAvgCellVoltage ;
	//uint16_t BMS_BatterySumVoltage ; //ADDED_20201201
	uint16_t : 16	;
} T_BMS_322H ;

typedef struct
{
	uint8_t BMS_BatteryMinTemperature ;
	uint8_t BMS_BatteryMaxTemperature ;
	uint8_t BMS_BatteryAvgTemperature ;

	//uint8_t BMS_BatteryMinTempLocation: 4 ; //ADDED_20201201
	//uint8_t BMS_BatteryMaxTempLocation: 4 ; //ADDED_20201201
	uint8_t : 8	;

	//uint8_t BMS_CoolingPumpFBStatus: 4 ; //ADDED_20201201
	//uint8_t BMS_CoolingReq: 1 ; //ADDED_20201201
	uint8_t : 6 ;
	uint8_t BMS_ChargingStop: 1 ; // Position Change_20201201
	//uint8_t BMS_BHC_STS_OW_TS: 1 ; //ADDED_20201201
	uint8_t : 1	;

	//uint8_t BMS_BHC_STS_WHU_WT_O : 8 ; //ADDED_20201201

	//uint8_t : 6 ;
	//uint8_t BMS_BHC_STS_ERR: 2 ; //ADDED_20201201

	//uint8_t BMS_AuxBAT: 8 ; //ADDED_20201201

} T_BMS_323H ;

typedef struct
{
	uint64_t BMS_BatteryPackSOE : 10 ;
	uint64_t : 6 ;

	uint64_t BMS_DischargePowerAvailable_10 : 12 ;
	uint64_t BMS_ChargePowerAvailable_10 : 12 ;

	uint64_t BMS_DischargePowerAvailable_2 : 12 ;
	uint64_t BMS_ChargePowerAvailable_2 : 12 ;

} T_BMS_324H ;

typedef struct
{
	uint16_t : 4 ;
	uint16_t BMS_ChargeCurrentLimit : 12 ;

	uint16_t BMS_ChargeVoltageLimit ;

	//uint16_t BMS_InstanPowerConsumtion ;

	//uint16_t BMS_MinIsolationResistence ;

} T_BMS_325H;

//typedef struct
//{
//	uint8_t BMS_HW_Ver : 8;
//
//	uint8_t BMS_SW_Ver : 8;
//
//	uint8_t BMS_Boot_Ver: 8;
//
//	uint8_t BMS_INT_FLT: 1;
//	uint8_t BMS_CMI_FLT_INIT: 1;
//	uint8_t BMS_CMI_FLT: 1;
//	uint8_t BMS_FET_FLT: 1;
//	uint8_t BMS_RLY_MN_CS: 1;
//	uint8_t BMS_RLY_MP_CS: 1;
//	uint8_t BMS_I_TEMP_SH: 1;
//	uint8_t BMS_I_TEMP_SL: 1;
//
//	uint8_t BMS_ISO_FLT: 1;
//	uint8_t BMS_CRASH_OPN: 1;
//	uint8_t BMS_CRASH_HW: 1;
//	uint8_t BMS_CRASH_CAN: 1;
//	uint8_t BMS_VCU_LCM: 1;
//	uint8_t BMS_CRT_SENS_WAN: 1;
//	uint8_t BMS_CRT_SENS_DEV: 1;
//	uint8_t BMS_ECAN_BUS_OFF: 1;
//
//	uint8_t BMS_PCAN_BUS_OFF: 1;
//	uint8_t BMS_HEATER_FLT: 1;
//	uint8_t BMS_RLY_MN_COS: 1;
//	uint8_t BMS_RLY_MP_COS: 1;
//	uint8_t BMS_RLY_PC_COS: 1;
//	uint8_t BMS_RLY_MN_CCS: 1;
//	uint8_t BMS_RLY_MP_CCS: 1;
//	uint8_t BMS_RLY_PC_CCS: 1;
//
//	uint8_t BMS_CRASH_NR: 1;
//	uint8_t BMS_C_TEMP_FLT_ALL: 1;
//	uint8_t BMS_CELL_OPN: 1;
//	uint8_t BMS_C_TEMP_FLT: 1;
//	uint8_t BMS_CV_H_FLT: 1;
//	uint8_t BMS_CV_L_FLT: 1;
//	uint8_t BMS_CV_H_WAN: 1;
//	uint8_t BMS_CV_L_WAN: 1;
//
//	uint8_t BMS_CV_DEV_OCV_FLT: 1;
//	uint8_t BMS_CV_DEV_FLT: 1;
//	uint8_t BMS_PV_H_FLT: 1;
//	uint8_t BMS_PV_L_FLT: 1;
//	uint8_t BMS_PV_H_WAN: 1;
//	uint8_t BMS_PV_L_WAN: 1;
//	uint8_t BMS_CT_H_FLT: 1;
//	uint8_t BMS_CT_H_WAN: 1;
//
//
//
//} T_BMS_326H; //ADDED_20201201

typedef struct
{
	uint32_t BMS_TotalAccumltEngy: 32 ;

	uint32_t : 32 ;


} T_BMS_581H; //ADDED_20201201

//typedef struct
//{
//	uint16_t BMS_AccumltDrvDchg : 16 ;
//
//	uint16_t BMS_AccumltDrvReg : 16 ;
//
//	uint16_t BMS_AccumltChg : 16 ;
//
//	uint16_t  : 16 ;
//
//} T_BMS_582H; //ADDED_20201201

//typedef struct
//{
//	uint16_t BMS_AccumltFstChg : 16 ;
//
//	uint16_t BMS_AccumltFstChgCnt : 16 ;
//
//	uint16_t BMS_AccumltNrmChg : 16 ;
//
//	uint16_t BMS_AccumltNrmChgCnt : 16 ;
//
//} T_BMS_583H; //ADDED_20201201

//typedef struct
//{
//	uint16_t CMXVersion_BMS_ECAN : 16 ;
//
//	uint8_t DTCInfo_BMS_ECAN : 2 ;
//	uint8_t : 6 ;
//
//	uint8_t SupplyVolt_BMS_ECAN: 8 ;
//
//	uint8_t RxErrCnt_BMS_ECAN: 8 ;
//
//	uint8_t TxErrCnt_BMS_ECAN: 8 ;
//
//	uint8_t BusOffCnt_BMS_ECAN: 8 ;
//
//	uint8_t MsgAliveCnt_BMS_ECAN: 8 ;
//
//
//} T_BMS_561H; //ADDED_20201201

typedef struct
{
	uint16_t MotorTorqueEstimated_RS1 ;

	uint16_t MotorTorqueEstimated ;

	uint16_t MotorSpeed ;

	uint8_t Counter_1E1h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_1E1h ;

} T_MCU_1E1H ;

typedef struct
{
	uint16_t RegenTorqueAvail : 15 ;
	uint16_t : 1 ;

	uint16_t TractionTorqueAvail : 15 ;
	uint16_t : 1 ;

	uint8_t : 2 ;
	uint8_t MCU_ACTV_Discharge_STS : 3 ;
	uint8_t MCU_ACTV_Discharge_FAIL : 3 ;

	uint8_t : 8 ;

	uint8_t Counter_1E2h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_1E2h ;

} T_MCU_1E2H ;

typedef struct
{
	uint8_t StateMcu : 4 ;
	uint8_t : 4 ;

	uint16_t MaxSafeMotorSpeedReverse : 9 ;
	uint16_t : 3 ;
	uint16_t McuActiveDamping : 2 ;
	uint16_t : 2 ;

	uint16_t MaxSafeMotorSpeedForward : 9 ;
	uint16_t CommandMode : 3 ;
	uint16_t : 4 ;

	uint8_t RegenDerating : 4 ;
	uint8_t TractionDerating : 4 ;

	uint8_t Counter_3A3h : 4 ;
	uint8_t OperationMode : 3 ;
	uint8_t : 1 ;

	uint8_t Checksum_3A3h ;

} T_MCU_3A3H ;

typedef struct
{
	uint8_t Thermal_Performance_Indicator ; //Signal Name Change_20201201 : Performance_Indicator => Thermal_Performance_Indicator

	uint8_t : 8 ;

	uint8_t MCUCoolingFlowRequest ; //Signal Name Change_20201201 : DriveCoolingFlowRequest => MCUCoolingFlowRequest
	uint8_t ThermalIndicatorInverter  ;
	uint8_t ThermalIndicatorMotor  ;
	uint8_t MotorCoolingFlowRequest  ;

	uint16_t : 16 ;

//	uint8_t Counter : 4 ; //Removed_20201201
//	uint8_t : 4 ;

//	uint8_t Checksum ; //Removed_20201201

} T_MCU_3A4H ;

typedef struct
{
	uint16_t : 16 ;

	uint16_t HighPowerCurrent : 14 ;
	uint16_t : 2 ;

	uint16_t HighPowerVoltage : 11 ;
	uint16_t : 5 ;

	uint16_t : 16 ;

//	uint8_t Counter : 4 ; //Removed_20201201
//	uint8_t : 4 ;
//
//	uint8_t Checksum ; //Removed_20201201

} T_MCU_3A6H ;

typedef struct
{
	uint16_t RegenTorqueAvail_10s : 15 ;
	uint16_t : 1 ;

	uint8_t : 2 ;
	uint8_t Error_Level : 3 ;
	uint8_t : 3 ;

	uint16_t : 1 ;
	uint16_t TractionTorqueAvail_10s : 15 ;

	uint8_t : 8 ;

	uint16_t : 16 ;

//	uint8_t Counter : 4 ;//Removed_20201201
//	uint8_t : 4 ;
//
//	uint8_t Checksum ;//Removed_20201201

} T_MCU_3A7H ;

//typedef struct
//{
//	uint16_t CMXVersion_MCU_ECAN : 15 ;
//
//
//	uint8_t DTCInfo_MCU_ECAN : 2 ;
//	uint8_t : 6 ;
//
//	uint8_t SupplyVolt_MCU_ECAN : 8 ;
//
//	uint8_t RxErrCnt_MCU_ECAN : 8 ;
//
//	uint8_t TxErrCnt_MCU_ECAN : 8 ;
//
//	uint8_t BusOffCnt_MCU_ECAN : 8 ;
//
//	uint8_t MsgAliveCnt_MCU_ECAN: 8 ;
//
//} T_MCU_562H ; //ADDed_20201201

//ECAN�߰�
//TX VCU
typedef struct
{
	uint8_t : 1	;
	uint8_t VCU_EvStat : 1	;
	uint8_t : 3	;
	uint8_t VCU_PDU_ContactorState : 1	;
	uint8_t : 2	;

	uint8_t : 1	;
	uint8_t VCU_ChgFinished : 1	;
	uint8_t : 5	;
	uint8_t VCU_S2_OnReqACnDC : 1	;

//	uint8_t VCU_S2_OnReqDC : 1	;
	uint8_t : 8	;

	uint8_t VCU_EvSOC	;

	uint16_t VCU_EvMaxCurrent	;

	uint16_t VCU_EvMaxVolt 	;

} T_VCU2EVCC_3ABH ;

typedef struct
{
	uint16_t : 16	;
	uint16_t VCU_EvTargetVolt	;
	uint16_t VCU_EvTargetCurrent	;
	uint16_t : 16	;
} T_VCU2EVCC_3ACH ;

typedef struct
{
	uint16_t VCU_FullSOCRemainTime ;
	uint16_t VCU_BulkSOCRemainTime	;
	uint16_t VCU_PresentVolt	;

	uint8_t VCU_AutoLockSwitch 		: 1	;
	uint8_t VCU_BulkChgComplete  	: 1	;
	uint8_t VCU_FullChgComplete 	: 1	;
	uint8_t DTC_Mode 				: 1	;
	uint8_t EVCCWakeupCmdbyVCU 		: 1 ;
	uint8_t VCU_StandbyReq 			: 1 ;
	uint8_t VCU_DrivDoorLockUnSts	: 1 ;
	uint8_t DTC_LOCK_Control		: 1 ;

	uint8_t : 8	;
} T_VCU2EVCC_3ADH ;

//typedef struct
//{
//	uint8_t VCU_OBC_STS_Ready : 1	;
//	uint8_t : 7	;
//
//	uint8_t VCU_OBC_STS_CONTRAB : 1	;
//	uint8_t VCU_BMS_ContactorState : 1	;
//	uint8_t : 6	;
//} T_VCU_506H ;

//TX EVCC
typedef struct
{
	uint8_t EVCC_PwrStat 			: 1	;
	uint8_t DTC_LOCK_Actuator_R 	: 1	;
	uint8_t DTC_LOCK_Actuator_L 	: 1	;
	uint8_t DTC_DC_Charger_Falut 	: 1	;
	uint8_t DTC_PD_ShortGND_Falut 	: 1	;
	uint8_t DTC_DC_DutyCycle_Falut	: 1	;
	uint8_t DTC_PlugLock_Falut		: 1	;
	uint8_t : 1	;

	uint8_t EVCC_SW_Version	;

	uint8_t Evse_EvContactorOnReq	: 1	;
	uint8_t : 1							;
	uint8_t EVCC_CPStat	: 3				;
	uint8_t EVCC_S2_OnStat	: 1			;
	uint8_t EVCC_PDStat	: 2 			;

	uint8_t EVSE_DutyValue : 7			;
	uint8_t : 1							;

	uint16_t EVCC_AC_PDResValue : 12 	;
	uint16_t : 4 						;

	uint8_t EVCC_StepNum 				;
	uint8_t EVCC_ErrorCode              ;
} T_EVCC_341H ;

typedef struct
{
	uint16_t Evse_MaxVolt_V ;
	uint16_t Evse_MaxCurr_A ;
	uint16_t Evse_OutVolt_V  ;
	uint16_t Evse_OutCurr_A ;
} T_EVCC_342H ;

typedef struct
{
	uint16_t Evse_MinVolt_V	;
	uint16_t Evse_MinCurr_A	;
	uint16_t Evse_MaxPwr_W 	;

	uint8_t EVCC_LockStat : 1	;
	uint8_t : 1	;
	uint8_t EVCC_Lock_alarm : 2	;
	uint8_t Secc_DCAC_ChgMode : 2	;
	uint8_t EVCC_StandbyRes : 1	;
	uint8_t : 1	;

	uint8_t EVSE_EVCC_ChgFinished  : 1	;
	uint8_t Secc_ACMaxCurrentValue  : 7	;
} T_EVCC_343H ;

typedef struct
{
	uint16_t EVCC_InletTemp ;

	uint16_t : 16 ;
	uint32_t : 32 ;

} T_EVCC_513H ;

//I/O���� CAN Msg�߰�
typedef struct
{
	uint16_t VcADC_AccelPosition1 	 : 12 ;
//	uint16_t VbDIH_BrakeLampSw 	  	 : 1  ;
//	uint16_t VbDIH_BrakeSwitchCruise : 1  ;
	uint16_t VbDIH_ChargDoorLockFb 	 : 1  ;
	uint16_t VeMain_EV_READY_STATE	 : 3 ;

	uint16_t VcADC_AccelPosition2 	 : 12 ;
//	uint16_t VbDIH_IGN1		   	  	 : 1  ;
//	uint16_t VbDIH_IGN3Fb		  	 : 1  ;
	uint16_t VbDIH_IGN4Fb		  	 : 1  ;
	uint16_t VeTORQ_DriveMode	  	 : 3  ;

	uint16_t VcADC_IGN2 			  		  : 12 ;
//	uint16_t VbDIH_MainRlyFb		  		  : 1  ;
//	uint16_t VbDIH_Qck_Chrg_NegaRly_Fb		  : 1  ;
	uint16_t VbDIH_Qck_Chrg_PosiRly_Fb		  : 1  ;
	uint16_t VeVIOS_ACC_State	  			  : 3  ;

	uint16_t VcADC_12VBAT			 		 : 12  ;
//	uint16_t VbDIL_Auto_Lock_SW  	 		 : 1   ;
//	uint16_t VbDIL_ChargDoorOpCld    		 : 1   ;
	uint16_t VbDIL_DriveModeSwitch   		 : 1   ;
	uint16_t VbDIL_EVCC_Wku          		 : 1   ;
	uint16_t VbDIL_Scheduled_Chrg_Cancel_SW  : 1   ;
	uint16_t VbTORQ_LimitSpdCtrlEnabled		 : 1   ;
} T_VCU_DBG1 ;

typedef struct
{
	uint16_t VcAdc_CruiseControlSW					: 12 ;
	uint16_t VeSBWS_GearState4MCUCtrl				: 4  ;
//	uint16_t VbHSD_ChrgPlugAutoLockIndCmd			: 1  ;
//	uint16_t VbHSD_EVCCEnableCmd					: 1  ;

	uint8_t VfVIOS_FinalAccelPosition ;

	uint8_t VbVIOS_AccelPedalApplied : 1;
	uint8_t VbVIOS_BrakePedalApplied: 1;
	uint8_t : 2;
	uint8_t VeSBWS_GearState4TqCtrl				: 4  ;
//	uint16_t VbLSD_QckChrgNegaRlyCmd				: 1  ;
//	uint16_t VbLSD_QckChrgPosiRlyCmd				: 1  ;

	uint8_t VfVIOS_FO_CoolFan_DutyCmd 		;
	uint8_t VfVIOS_FO_SBWS_DutyCmd			;
	uint8_t VfVIOS_FO_SBWS_PeriodCmd		;
	uint8_t VfVIOS_FO_WaterPump_DutyCmd		;
} T_VCU_DBG2 ;

typedef struct
{
	uint8_t VfVIOS_FI_SBWS_Freq				;
	uint8_t VfVIOS_FI_WaterPump_DutyFb		;
	uint8_t VfTORQ_RegenLevel				;
	uint8_t VfTORQ_v_LimitSpeed				;

	uint16_t VfTorq_EBURegenREQTq			;
	uint16_t VfTORQ_M_CoastRegenTq			;
} T_VCU_DBG3 ;

typedef struct
{
	uint16_t VfTORQ_M_CreepTq				;
	uint16_t VfTORQ_M_DriverDemandTorque	;
	uint16_t VfTORQ_M_DriverGenTorque		;
	uint16_t VfTORQ_M_DriverMotorTorque		;
} T_VCU_DBG4 ;

typedef struct
{
	uint16_t VfTORQ_M_EVCommandTorque			;
	uint16_t VfTORQ_M_EVDemandTorque			;
	uint16_t VfTORQ_M_Generating_MaxTq			;
	uint16_t VfTORQ_M_MotorAvailableTorque		;
} T_VCU_DBG5 ;

typedef struct
{
	uint16_t VfTORQ_M_Motoring_LaunchAssist		;
	uint16_t VfTORQ_M_Motoring_MaxTq			;
	uint16_t VfTORQ_M_Motoring_Tq_APS			;
	uint16_t VfTORQ_M_RegenAvailableTorque		;
} T_VCU_DBG6 ;

typedef struct
{
	uint8_t VbLSD_ChargDoorRlyCmd 	: 1	;
	uint8_t VbLSD_FanRlyCmd 	  	: 1	;
	uint8_t VbLSD_IGN3Cmd		  	: 1	;
	uint8_t VbLSD_IGN4Cmd		  	: 1	;
	uint8_t VbLSD_MainRlyCmd 	  	: 1	;
	uint8_t VbLSD_QckChrgNegaRlyCmd : 1	;
	uint8_t VbLSD_QckChrgPosiRlyCmd : 1	;
	uint8_t VbLSD_WaterPumpRlyCmd 	: 1	;

	uint8_t VeCharge_State 			: 4 ;
	uint8_t VeVIOS_Main_State		: 4 ;

	uint8_t VbDIH_BrakeSwitchCruise 	 : 1	;
	uint8_t VbDIH_BrakeLampSw 			 : 1	;
	uint8_t VbDIH_IGN1					 : 1	;
	uint8_t VbDIH_IGN3Fb				 : 1	;
	uint8_t VbDIH_MainRlyFb			 	 : 1	;
	uint8_t VbDIH_Qck_Chrg_NegaRly_Fb	 : 1 	;
	uint8_t VbDIL_ChargDoorOpCld 		 : 1	;
	uint8_t VbDIL_Auto_Lock_SW			 : 1	;

	uint8_t VbHSD_ChrgPlugAutoLockIndCmd : 1	;
	uint8_t VbHSD_EVCCEnableCmd  		 : 1	;
	uint8_t VbSBWS_LowSpdGearChangeTransition  : 1	;
	uint8_t Vb_ExtTqReqExit_Flag : 1	;
	uint8_t Vb_TorqCtrlDisabledCondMet : 1	;
	uint8_t VbTORQ_TipInActive : 1	;
	uint8_t VbTORQ_TipOutActive : 1	;
	uint8_t Vb_ExtECUIntervention_Active : 1	;

	uint16_t VfTORQ_M_EVFianlDemandTorque ;

	uint8_t VcWakeUp_SPIMODE	;
	uint8_t VcWakeUp_WakeUpStat ;

} T_VCU_DBG7 ;

typedef struct
{
	uint8_t VfVIOS_Pct_APS1IndPosition ;
	uint8_t VfVIOS_Pct_APS1LearnedMin ;
	uint8_t VfVIOS_Pct_APS1NormPctVoltage ;
	uint8_t VfVIOS_Pct_APS1PctVoltage ;
	uint8_t VfVIOS_k_APS1WeightFactor ;

	uint8_t Vb_CanRx_448h_Flag : 1;
	uint8_t VbTORQ_VehStopped : 1;
	uint8_t VbTORQ_LaunchActive : 1;
	uint8_t VbTORQ_LaunchEnable : 1;
	uint8_t VbTORQ_CreepActive : 1;
	uint8_t VeVIOS_Step2GearChange : 1;
	uint8_t VbVIOS_P2N_ByReleaseSW_flag : 1;
	uint8_t : 1;

	uint8_t VcActiveCreep_count0 ;
//	uint8_t : 8 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_RSOC : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_DERATING : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_TqLmt : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_HVDCLinkVLow : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnBMSPwrLow : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_2 : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_BMSAvailablePwrLow_10 : 1 ;
	uint8_t Vb_VCU_EVPwrDnWrnInd_Reason_TmpHigh_COOLTS : 1 ;
} T_VCU_DBG8 ;	//220727 HJ Add to Check PwrDnWrnInd

typedef struct
{
	uint8_t VfVIOS_Pct_APS2IndPosition ;
	uint8_t VfVIOS_Pct_APS2LearnedMin ;
	uint8_t VfVIOS_Pct_APS2NormPctVoltage ;
	uint8_t VfVIOS_Pct_APS2PctVoltage ;
	uint8_t VfVIOS_k_APS2WeightFactor ;
	uint8_t VCURx_DcChargingTargetSetCmd : 4;
	uint8_t VCURx_AcChargingTargetSetCmd : 4;
	uint8_t VCURx_ScheduledChargingCmd : 4;
	uint8_t VCURx_RespChargingScheduleSts : 4;
	uint8_t VCURx_PortableTypeChgCurrSetCmd : 2;
	uint8_t VCURx_FixedTypeChgCurrSetCmd : 2;
	uint8_t VCURx_ChargingStopCmdbyAVN : 2;
	uint8_t VCURx_CCU_ChargingStopReq : 2;
} T_VCU_DBG9 ;

typedef struct
{
	uint16_t VfGrad_VehAc_Filt ;
	uint16_t VfTORQ_phi_Grad ;
	uint8_t VfTORQ_v_VehSpd_WSS ;
	uint8_t VfTORQ_v_FiltVehSpdScalarMCU ;
	uint16_t VfTORQ_v_FiltVehSpdVectorMCU : 12 ;
	uint16_t VfTORQ_v_CreepTargetSpd : 4 ;
//	uint16_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_BMS : 1 ;
//	uint16_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Inverter : 1 ;
//	uint16_t Vb_VCU_EVPwrDnWrnInd_Reason_EPTnHVTmpHigh_Motor: 1 ;
//	uint16_t : 1 ;
} T_VCU_DBG10 ;	//220727 HJ Add to Check PwrDnWrnInd

typedef struct
{
	uint16_t VfTORQ_v_VehSpd_Vector_MCU: 12 ;
	uint16_t VbCharg_NormalChargFinished: 1 ;
	uint16_t VbCharg_AbnormalChargFinished : 1 ;
	uint16_t VbCharg_ChargFinished : 1 ;
	uint16_t Vb_LVAutoChrgEn_Flag: 1 ;

	uint8_t V_LVBatt_SOC ;
	uint8_t VeCharge_VCU_ChgFinished ;

	uint16_t VcADC_Temp1 : 12 ;
	uint16_t : 4 ;
//	uint16_t VeSBWS_GearState4TqCtrl : 4 ;

	uint16_t VcADC_Temp2 : 12 ;
	uint16_t : 4 ;
//	uint16_t VeSBWS_GearState4MCUCtrl : 4 ;
} T_VCU_DBG11 ;

typedef struct
{
	uint8_t Ve_TipInState: 2 ;
	uint8_t Ve_TipOutState: 2 ;
	uint8_t Vb_HVBattLowVolt_Condition_Flag : 1 ;
	uint8_t Vb_STPM_Mode_Flag : 1 ;
	uint8_t Vb_STPM_HVAC_Mode_Flag : 1 ;
	uint8_t : 1 ;

	uint8_t : 8 ;

	uint8_t VcCount_Main_Task 		: 4 ;
	uint8_t VcCount_Charge_Task 	: 4 ;

	uint8_t VcCount_Drive_Task 		: 4 ;
	uint8_t VcCount_CANMng_Task 	: 4 ;

	uint8_t VcCount_APSLearn_Task 	: 4 ;
	uint8_t VcCount_Diag_Task 		: 4 ;

	uint8_t : 8 ;
	uint8_t : 8 ;
	uint8_t : 8 ;
} T_VCU_DBG12 ;

/* PCAN Msg Definitions */

typedef struct
{
	uint64_t  : 8;
	uint64_t ECU_Immo : 56;

} T_VCU_105H ;	// none

typedef struct
{
	uint8_t HighVoltageRelayOnReqFb : 2 ;
	uint8_t : 6 ;

	uint32_t : 32;

	uint16_t : 16;

	uint8_t : 8 ;

} T_VCU_116H ;	// ADDED_20201201

typedef struct
{
	uint16_t VCU_CMD_AC_CHARG_TARGT_VOLT ;

	uint16_t VCU_CMD_AC_CHARG_TARGT_CURNT ;

	uint8_t : 2 ;
	uint8_t VCU_CMD_AC1_CHARG_CRT_SET : 2 ;
	uint8_t VCU_CMD_AC2_CHARG_CRT_SET : 2 ;
	uint8_t : 2 ;

	uint8_t : 8 ;

	uint8_t Counter_1D1h : 4 ;
	uint8_t VCU_CMD_EN_OBC : 1 ;
	uint8_t AC_Charging_Ready : 2 ;
	uint8_t : 1 ;

	uint8_t Checksum_1D1h ;

} T_VCU_1D1H ;	// 10 ms

typedef struct
{
	uint8_t VCU_CMD_LDC_TARGT_VOLT ;

	uint8_t VCU_REQ_EN_ACOMP : 1 ;
	uint8_t VCU_REQ_EN_Heater : 1 ;
	uint8_t VCU_REQ_LMT_Blower_Step : 1 ;
	uint8_t VCU_REQ_LMT_ACOMP_PWR : 1 ;
	uint8_t VCU_CMD_EN_LDC : 1 ;
	uint8_t VCU_REQ_Brake_Light_On : 1 ;
	uint8_t VCU_REQ_LMT_CABN_Heater_PWR : 1 ;
	uint8_t VCU_STS_REGN_AVAL_STS_EPT : 1 ;

	uint8_t CcanWakeupCmdbyVCU : 2 ; //ADDED_20201201
	uint8_t : 5 ;
	uint8_t VCU_EPBoeratingReq : 1 ;

	uint8_t : 8 ;

	uint16_t VCU_STS_REGN_AVAIL_TQ ;

	uint8_t Counter_1D2h : 4 ;
	uint8_t McanWakeupCmdbyVCU : 2 ; //ADDED_20201201
	uint8_t IcanWakeupCmdbyVCU : 2 ; //ADDED_20201201

	uint8_t Checksum_1D2h ;

} T_VCU_1D2H ;	// 20 ms

typedef struct
{
	uint16_t CoastRegenTorque ;

	uint8_t VCU_STS_Paddle_LV : 4 ;
	uint8_t VCU_CMD_CHAR_CP : 4 ;

	uint8_t VCU_ChargeConnectionStatus : 4 ;
	uint8_t VCU_STS_VEH_Mode : 3 ;
	uint8_t : 1 ;

	uint16_t VCU_CMD_CHAR_PWM : 10 ;
	uint16_t VCU_CMD_CHAR_PD : 2 ;
	uint16_t VCU_STS_CHARG_PLG_AT_Lock_SW : 2 ;
	uint16_t VCU_STS_CHARG_RLS_SW : 2 ;

	uint8_t Counter_1D3h : 4 ;
	uint8_t VCU_CMD_AC_CHARG_ST_REQ : 2 ;
	uint8_t : 2 ;

	uint8_t Checksum_1D3h ;

} T_VCU_1D3H ;	// 10 ms

typedef struct
{
	uint8_t PW ;

	uint8_t PW_Virtual_Flag : 2 ;
	uint8_t PW_ERR : 1 ;
	uint8_t SMC_E_S : 3 ;
	uint8_t CAN_Driver_Accel_Override : 1 ;
	uint8_t CAN_Engine_ACC_failure : 1 ;

	uint8_t SPDLIM_Ready : 1 ;
	uint8_t SPDLIM_ACT : 1 ;
	uint8_t SPDLIM_Overspeed : 1 ;
	uint8_t SPDLIM_Overide : 1 ;
	uint8_t ACC_Ready : 1 ;
	uint8_t ACC_ACT : 1 ;
	uint8_t : 2 ;

	uint16_t M_FEV : 13 ;
	uint16_t M_ESP_E : 1 ;
	uint16_t VCU_transPmotorparkReg : 2 ;

	uint8_t : 8 ;

	uint8_t Counter_211h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_211h ;

} T_VCU_211H ;	// 20 ms

typedef struct
{
	uint16_t VCU_STS_ESTM_DRV_Range : 12 ;
	uint16_t Immo_light: 2 ; //ADDED_20201201
	uint16_t : 2 ;

	uint8_t : 8 ;

	uint8_t VCU_Ready : 2 ;
	uint8_t DrivingPosition : 3 ;
	uint8_t : 3 ;

	uint16_t : 16 ;

	uint8_t Counter_245h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_245h ;

} T_VCU_245H ;	// 20 ms

typedef struct
{
//	uint8_t VCU_STS_CHARG_COMPLT_Hour : 5 ;
//	uint8_t : 3 ;
//
//	uint8_t VCU_STS_CHARG_COMPLT_MINT : 6 ;
//	uint8_t : 2 ;
//
//	uint8_t VCU_STS_AC_LV1_CHARG_COMPLT_Hour : 5 ;
//	uint8_t : 3 ;
//
//	uint8_t VCU_STS_AC_LV1_CHARG_COMPLT_MINT : 6 ;
//	uint8_t : 2 ;
//
//	uint8_t VCU_STS_AC_LV2_CHARG_COMPLT_Hour : 5 ;
//	uint8_t : 3 ;
//
//	uint8_t VCU_STS_AC_LV2_CHARG_COMPLT_MINT : 6 ;
//	uint8_t : 2 ;
//
//	uint8_t VCU_STS_DC_CHARG_EST_COMPLT_Hour : 5 ;
//	uint8_t : 3 ;
//
//	uint8_t VCU_STS_DC_CHARG_EST_COMPLT_MINT : 6 ;
//	uint8_t : 2 ;

	uint64_t : 9;
	uint64_t VCU_STS_CHARG_COMPLT_MINT_SOC_80 : 6 ; //ADDED_20201201
	uint64_t VCU_STS_CHARG_COMPLT_Hour_SOC_80 : 5 ; //ADDED_20201201
	uint64_t VCU_STS_DC_CHARG_EST_COMPLT_MINT : 6 ;
	uint64_t VCU_STS_DC_CHARG_EST_COMPLT_Hour : 5 ;
	uint64_t VCU_STS_AC_LV2_CHARG_COMPLT_MINT : 6 ;
	uint64_t VCU_STS_AC_LV2_CHARG_COMPLT_Hour : 5 ;
	uint64_t VCU_STS_AC_LV1_CHARG_COMPLT_MINT : 6;
	uint64_t VCU_STS_AC_LV1_CHARG_COMPLT_Hour : 5;
	uint64_t VCU_STS_CHARG_COMPLT_MINT : 6 ;
	uint64_t VCU_STS_CHARG_COMPLT_Hour : 5 ;


} T_VCU_351H ;	// 100 ms

//typedef struct
//{
//
//	uint16_t VCU_STS_AC_LV1_CHARG_COMPLT_Hour : 5 ;
//	uint16_t : 11 ;
//
//	uint16_t : 16 ;
//
//	uint16_t : 4 ;
//	uint16_t VCU_STS_AC_LV1_CHARG_COMPLT_Hour : 5 ;
//	uint16_t VCU_STS_AC_LV2_CHARG_COMPLT_Hour : 11 ;
//
//	uint16_t : 16 ;
//
//} T_VCU_351H ;

typedef struct
{
	uint8_t ECO_Guide_Level_IND : 5 ;
	uint8_t : 1 ; //ADDED_20201201
	uint8_t ECO_Energy_Flow_IND : 2 ;

	uint8_t VCU_IGN3_STS : 1 ;
	uint8_t VCU_IGN4_STS : 1 ;
	uint8_t Charging_Sts_IND : 3 ;
	uint8_t : 1 ;
	uint8_t VCU_PAD_COND_WRN_MSG: 2 ; //ADDED_20201201

	uint8_t VCU_Service_WRN_IND : 1 ;
	uint8_t VCU_Cert_Status : 1 ; //ADDED_20201201
	uint8_t : 3 ;
	uint8_t Charge_DR_STS : 1 ;
	uint8_t VCU_HV_ACT_IND : 2 ;

	uint8_t DrivingModeDisplay : 2 ;
	uint8_t DrivingMode_VCU : 3 ;
	uint8_t : 3 ;

	uint8_t : 8 ;

	uint8_t VCU_RemotetFailReason : 4 ; //ADDED_20201201
	uint8_t VCU_RemoteResponse : 4 ; //ADDED_20201201

	uint8_t CruiseTargetKPH ;
	uint8_t CruiseTargetMPH ;

} T_VCU_3ACH ;	// 100 ms

typedef struct
{
	uint16_t VCU_STS_ESTM_DRV_Range_CLIMT_OFF : 11 ;
	uint16_t VCU_EV_Power_Down : 1 ;
	uint16_t VCU_LV_SYS_WRN_MSG : 3 ;
	uint16_t VCU_LV_System_WRN_IND : 1 ;

	uint8_t VCU_Shift_CTRL_STS_WRN_MSG : 4 ;
	uint8_t VCU_Shift_COND_Unmatch_WRN_MSG : 3 ;
	uint8_t : 1 ;

	uint8_t VCU_HV_DISP_SOC ;

	uint16_t VCU_Total_CHARG_PWR : 12 ;
	uint16_t VCU_HV_PWR_LMT_WRN_MSG : 3 ;
	uint16_t VCU_HV_Low_SOC_WRN_IND : 1 ;

	uint8_t VCU_CHAR_INLT_STS_WRN_MSG: 2 ;
	uint8_t VCU_Service_WRN_MSG : 3 ; //ADDED_20201202
	uint8_t VCU_Charging_Sts_WRN_MSG : 3 ;

	uint8_t DrvMode1_RegenLevelSetSts : 2 ; //ADDED_20201202
	uint8_t DrvMode2_RegenLevelSetSts : 2 ; //ADDED_20201202
	uint8_t DrvMode3_RegenLevelSetSts : 2 ; //ADDED_20201202
	uint8_t DrvMode4_RegenLevelSetSts : 2 ; //ADDED_20201202

} T_VCU_3ADH ;	// 100 ms

typedef struct
{
	uint16_t I_Batt ;

	uint16_t U_Batt : 14 ;
	uint16_t I_range : 2 ;

	uint16_t T_Batt : 9 ;
	uint16_t BS_Invaild : 2 ;
	uint16_t : 5 ;

	uint8_t SOC ;
	uint8_t SOH ;

} T_VCU_510H ;	// 100 ms

typedef struct
{
	uint8_t : 2 ;
	uint8_t FSOC : 2 ;
	uint8_t FSOH : 2 ;
	uint8_t : 2 ;

	uint8_t : 8 ;
	uint8_t : 8 ;

	uint8_t Norminal_Capacity  ;

	uint16_t OCV : 12 ;
	uint16_t : 4 ;

	uint16_t : 16 ;

} T_VCU_512H ;	// 100 ms

typedef struct
{
	uint8_t NM_Destination ;

	uint8_t NM_CommandCode : 3 ;
	uint8_t : 1 ;
	uint8_t NM_SleepFlag : 2 ;
	uint8_t : 2 ;

	uint8_t NM_WakeupReason : 4 ;
	uint8_t NM_FormerState : 4 ;

//	uint8_t : 2 ;
//	uint8_t NM_IgnitionSts : 1 ; //Removed_20201202
//	uint8_t NM_VCU_HV_ACT_IND : 1 ; //Removed_20201202
//	uint8_t NM_ChargeConnectionStatus : 1 ;  //Removed_20201202
//	uint8_t : 3 ;

	uint8_t  : 2 ;
	uint8_t NM_VCU_IGN3_STS_VCU : 1 ; //ADDED_20201202
	uint8_t NM_Ignition1Sts_VCU : 1 ; //ADDED_20201202
	uint8_t NM_McanWakeupCmd_VCU : 1 ; //ADDED_20201202
	uint8_t NM_IcanWakeupCmd_VCU : 1 ; //ADDED_20201202
	uint8_t NM_CcanWakeupCmd_VCU : 1 ; //ADDED_20201202
	uint8_t  : 1 ;

	uint16_t : 16 ;

	uint16_t NM_Reserved ;

} T_VCU_414H ;

typedef struct
{
	uint16_t CMX_Version_VCU ;

	uint8_t DTCInfo_VCU : 2 ;
	uint8_t : 6 ;

	uint8_t SupplyVolt_VCU  ;
	uint8_t RxErrCnt_VCU  ;
	uint8_t TxErrCnt_VCU  ;
	uint8_t BusOffCnt_VCU  ;
	uint8_t MsgAliveCnt_VCU  ;

} T_VCU_514H ;	// 500 ms

typedef struct
{
	uint64_t VCU_CAL_630h_Signal ;

} T_CGW_630H ; //ADDED_20201202

typedef struct
{
	uint64_t VCU_CAL_631h_Signal ;

} T_VCU_631H; //ADDED_20201202

typedef struct
{
	uint64_t VCU_CAL_632h_Signal ;

} T_VCU_632H; //ADDED_20201202

typedef struct
{
	uint64_t VCU_CAL_633h_Signal ;

} T_VCU_633H; //ADDED_20201202

typedef struct
{
	uint64_t VCU_CAL_634h_Signal ;

} T_VCU_634H; //ADDED_20201202

typedef struct
{
	uint8_t ChargingScheduleCheck : 2 ;
	uint8_t  : 6 ;

	uint32_t :32;

	uint16_t  : 16 ;

	uint8_t  : 8 ;

} T_VCU_1C5H; //ADDED_20201202

typedef struct
{
	uint8_t DcChargingTartgetSetSts : 4 ;
	uint8_t AcChargingTartgetSetSts : 4 ;

	uint8_t FixedTypeChargeCurrentSetSts : 2 ;
	uint8_t PortableTypeChargeCurrentSetSts : 2 ;
	uint8_t : 4 ;

	uint32_t :32;

	uint16_t  : 16 ;

} T_VCU_3AFH ; //ADDED_20201202

typedef struct
{
	uint8_t ChargingFinish  ;

	uint8_t ChargingStopReason  ;


	uint32_t :32;

	uint16_t  : 16 ;

} T_VCU_1D7H ; //ADDED_20201202

typedef struct
{
	uint64_t DGN_REQ_VCU  ;

} T_CGW_7E0H ; //ADDED_20201202


typedef struct
{
	uint64_t DGN_RESP_VCU  ;

} T_VCU_7E8H; //ADDED_20201202






typedef struct
{
	uint8_t ImmediateChargingResult  ;

	uint8_t : 8 ;

	uint8_t ImmeChargingStartFailReason ;

	uint8_t ImmeChargingStopFailReason ;

	uint32_t : 32 ;

} T_VCU_1CCH; //ADDED_20201202


typedef struct
{
	uint8_t ScheduledChargingResult  ;

	uint8_t ScheChargingStartFailReason ;

	uint8_t ScheChargingStopFailReason ;

	uint8_t : 8 ;

	uint32_t : 32 ;

} T_VCU_1D6H; //ADDED_20201202

typedef struct
{
	uint16_t CR_Yrs_Yr ;
	uint16_t CR_Yrs_LatAc ;

	uint8_t CF_Yrs_Yr_Fail : 1 ;
	uint8_t CF_Yrs_Yr_Init : 1 ;
	uint8_t : 2 ;
	uint8_t CF_Yrs_LatAc_Fail : 1 ;
	uint8_t CF_Yrs_LatAc_Init : 1 ;
	uint8_t : 2 ;

	//uint8_t CF_Yrs_MCUStat_Fail : 1 ;
	//uint8_t CF_Yrs_MCUStat_UV : 1 ;
	//uint8_t CF_Yrs_MCUStat_OV : 1 ;
	//uint8_t CF_Yrs_MCUStat_BusOff : 1 ;
	//uint8_t : 4 ;
	uint8_t : 8	;

	//uint8_t CR_Yrs_MsgCnt1 : 4 ;
	//uint8_t : 4 ;
	uint8_t : 8	;

	uint8_t CR_Yrs_Crc1 ;

} T_ACU_130H ;

typedef struct
{
	uint16_t CR_Yrs_LongAc ;

	uint8_t CR_Yrs_LongAc_Fail : 1 ;
	uint8_t CR_Yrs_LongAc_Init : 1 ;
	//uint8_t : 2 ;
	//uint8_t CF_ISC_ResetStat : 1 ;
	//uint8_t : 3 ;
	uint8_t : 6 ;

	//uint8_t CR_Yrs_Temp ;
	uint8_t : 8 ;

	//uint8_t YRS_Temp_Stat : 1 ;
	//uint8_t : 3 ;
	//uint8_t CF_Yrs_Type : 4 ;
	uint8_t : 8 ;

	uint8_t : 8 ;

	uint8_t CR_Yrs_MsgCnt2 : 4 ;
	uint8_t : 4 ;

	uint8_t CR_Yrs_Crc2 ;
} T_ACU_140H ;

typedef struct
{
	uint8_t ACU_Crashout : 1 ;
	uint8_t : 7 ;
//
//	uint32_t : 32 ;
//
//	uint8_t : 8 ;
//
//	uint8_t Counter_135h: 4 ;  //ADDED_20201202
//	uint8_t : 4 ;
//
//	uint8_t Checksum_135h ;  //ADDED_20201202

} T_ACU_135H ;

//typedef struct
//{
//	uint8_t Airbag_WL : 2 ;
//	uint8_t PAB_Off : 2 ;
//	uint8_t PAB_On : 2 ;
//	uint8_t  : 2 ;
//
//	uint32_t : 32 ;
//
//	uint16_t : 16 ;
//
//	uint8_t : 8 ;
//
//} T_ACU_335H ; //ADDED_20201202

//typedef struct
//{
//
//	uint64_t DGN_REQ_ACU : 64 ;
//
//} T_CGW_7D3H ; //ADDED_20201202
//
//typedef struct
//{
//
//	uint64_t DGN_RESP_ACU : 64 ;
//
//} T_ACU_7DBH ; //ADDED_20201202

//typedef struct
//{
//
//	uint16_t CMX_Version_ACU_PCAN ;
//
//	uint8_t DTCInfo_ACU_PCAN : 2 ;
//	uint8_t : 6 ;
//
//	uint8_t SupplyVolt_ACU_PCAN  ;
//	uint8_t RxErrCnt_ACU_PCAN  ;
//	uint8_t TxErrCnt_ACU_PCAN  ;
//	uint8_t BusOffCnt_ACU_PCAN  ;
//	uint8_t MsgAliveCnt_ACU_PCAN ;
//
//}T_ACU_509H ; //ADDED_20201202

//typedef struct
//{
//
//	uint64_t DGN_ACU_Pmode_REQ : 64 ;
//
//} T_CGW_7D4H  ; //ADDED_20201202
//
//
//typedef struct
//{
//
//	uint64_t DGN_ACU_Pmode_RESP : 64 ;
//
//} T_ACU_7DCH ; //ADDED_20201202
//
//typedef struct
//{
//
//	uint64_t DGN_ACU_Scrap_REQ : 64 ;
//
//} T_CGW_7F1H ; //ADDED_20201202


//typedef struct
//{
//
//	uint64_t DGN_ACU_Scrap_RESP : 64 ;
//
//} T_ACU_7F9H ; //ADDED_20201202

typedef struct
{

	uint8_t RespChargingScheduleSts : 4 ;
	uint8_t ScheduledChargingCmd : 4 ;

	uint8_t ChargingStopCmdbyAVN : 2 ;
	uint8_t  : 6 ;

	uint16_t  : 16 ;

	uint32_t :32 ;

} T_CGW_1CDH; //ADDED_20201202

typedef struct
{

	uint8_t  AcChargingTartgetSetCmd: 4 ;
	uint8_t  DcChargingTartgetSetCmd: 4 ;

	uint8_t  FixedTypeChargeCurrentSetCmd : 2 ;
	uint8_t  PortableTypeChargeCurrentSetCmd : 2 ;
	uint8_t  : 4 ;

	uint16_t  : 16 ;

	uint32_t :32 ;

} T_CGW_15AH ; //ADDED_20201202

//typedef struct
//{
//
//	uint8_t VoiceHvacCmd : 4 ;
//	uint8_t  : 2 ;
//	uint8_t VoiceHvacRecCmd : 2 ;
//
//	uint8_t VoiceHvacTempSetCmd ;
//
//	uint8_t  VoiceHvacTempUpDnCmd : 2 ;
//	uint8_t  : 6 ;
//
//	uint8_t VoiceHvacBlowerSetCmd : 4 ;
//	uint8_t VoiceHvacBlowerUpDnCmd : 2 ;
//	uint8_t  : 2 ;
//
//	uint8_t  AVNTunnelModeCmd: 2 ;
//	uint8_t  : 6 ;
//
//	uint16_t  : 16 ;
//
//	uint8_t  : 8 ;
//
//} T_CGW_1D0H; //ADDED_20201202


typedef struct
{
	uint8_t DrivDoorAjarSts4P : 2 ;
	uint8_t HoodAjarSts4p : 2 ;
	uint8_t : 2 ;
	uint8_t RearDefoggerActSts : 2 ;

	uint8_t FrontWiperMotorSts4P : 2 ;
	uint8_t HeadLightOnOff4P : 2 ;
	uint8_t DRLSts : 2 ;
	uint8_t DrivSeatBeltSts4P : 2 ;

	uint8_t PsgnrSeatBeltSts : 2 ;
	uint8_t RearRHSeatBeltSts : 2 ;
	uint8_t RearCntSeatBeltSts : 2 ;
	uint8_t RearLHSeatBeltSts : 2 ;
//
//	uint8_t FrtSeatBeltWarnCmd : 2 ; //ADDED_20201202
//	uint8_t RearSeatBeltWarnCmd : 1 ; //ADDED_20201202
//	uint8_t FrtSeatBeltINDCmd : 1 ; //ADDED_20201202
//	uint8_t BrakeLampFailSts : 2 ; //ADDED_20201202
//	uint8_t RearDefoggerINDCmd : 2 ; //ADDED_20201202
//
//	uint8_t AutoPanelDimCmd_P : 1 ; //ADDED_20201202
////	uint8_t DrivDoorLockUnSts : 1 ; //REMOVE_20201202
//	uint8_t InteriorTailLampCmd : 1 ; //ADDED_20201202
//	uint8_t : 6 ;
//
//	uint16_t : 16 ;
//
//	uint8_t : 8 ;

} T_BCM_511H ;

//typedef struct
//{
//
//	uint8_t TPS_FR : 3 ;
//	uint8_t TPV_FR : 1 ;
//	uint8_t TPS_FL : 3 ;
//	uint8_t TPV_FL : 1 ;
//
//	uint8_t TPS_RR : 3 ;
//	uint8_t TPV_RR : 1 ;
//	uint8_t TPS_RL : 3 ;
//	uint8_t TPV_RL : 1 ;
//
//	uint8_t TP_FL ;
//
//	uint8_t TP_FR ;
//
//	uint8_t TP_RL ;
//
//	uint8_t TP_RR ;
//
//	uint8_t TAS_R : 2 ;
//	uint8_t TAS_F : 2 ;
//	uint8_t : 4 ;
//
//	uint8_t TMPI_S : 4 ;
//	uint8_t : 2 ;
//	uint8_t TMPIR : 2 ;
//
//} T_BCM_530H ; //ADDED_20201202

//typedef struct
//{
//
//	uint64_t BCM_CAL_REQ : 64 ;
//
//} T_BCM_681H ; //ADDED_20201202

//typedef struct
//{
//
//	uint64_t BCM_CAL_RESP : 64 ;
//
//} T_BCM_682H ; //ADDED_20201202
//
//typedef struct
//{
//
//	uint64_t DGN_REQ_BCM : 64 ;
//
//} T_BCM_701H ; //ADDED_20201202
//
//typedef struct
//{
//
//	uint64_t DGN_RESP_BCM : 64 ;
//
//} T_BCM_709H; //ADDED_20201202

//typedef struct
//{
//
//	uint16_t CMX_Version_BCM_PCAN ;
//
//	uint8_t DTCInfo_BCM_PCAN : 2 ;
//	uint8_t : 6 ;
//
//	uint8_t SupplyVolt_BCM_PCAN ;
//	uint8_t RxErrCnt_BCM_PCAN  ;
//	uint8_t TxErrCnt_BCM_PCAN  ;
//	uint8_t BusOffCnt_BCM_PCAN  ;
//	uint8_t MsgAliveCnt_BCM_PCAN ;
//
//} T_BCM_541H ; //ADDED_20201202

//typedef struct
//{
//
//	uint8_t BMS_BatteryMinTemperature : 8 ;
//
//	uint8_t BMS_BatteryMaxTemperature : 8 ;
//
//	uint8_t BMS_BatteryAvgTemperature : 8 ;
//
//	uint8_t BMS_BatteryMinTempLocation : 4 ;
//	uint8_t BMS_BatteryMaxTempLocation : 4 ;
//
//	uint8_t BMS_CoolingPumpFeedbackStatus : 4 ;
//	uint8_t BMS_CoolingRequest : 1 ;
//	uint8_t  : 1 ;
//	uint8_t BMS_ChargingStop : 1 ;
//	uint8_t BMS_BHC_STS_OW_TS : 1 ;
//
//	uint8_t BMS_BHC_STS_WHU_WT_O : 8 ;
//
//
//	uint8_t  : 6 ;
//	uint8_t BMS_BHC_STS_ERR : 2 ;
//
//	uint8_t BMS_AuxBattery : 8 ;
//
//} T_BMS_323H ; //ADDED_20201202

typedef struct
{
	uint16_t BMS_BatteryPackSOE : 10 ;
//	uint16_t : 3 ;
//	uint16_t BMS_BAT_STS_MSG : 1 ;
//	uint16_t HV_BAT_Over_Temp_MSG : 1 ;
//	uint16_t HV_BAT_Low_Temp_Power_Limit_MSG : 1 ;
	uint16_t : 6 ;

	uint16_t BMS_BatteryPackRSOC : 10 ;
	uint16_t : 6 ;

	uint16_t BMS_BatteryPackSOH : 10 ;
	uint16_t : 6 ;

} T_BMS_352H ;

typedef struct
{

	uint8_t CCU_ChargingStopReq : 2 ;
	uint8_t CCU_ImmediateChargingReq : 2 ;
	uint8_t  : 4 ;


	uint32_t : 32 ;

	uint16_t : 16 ;

	uint8_t : 8 ;

} T_CGW_1C4H; //ADDED_20201203

typedef struct
{
	uint8_t STPMStartCmd ;

	uint8_t BatteryCheckReqCmd : 2 ;
	uint8_t : 6 ;

} T_CGW_161H ;

typedef struct
{

	uint8_t DrvMode1_RegenLevelSetCmd : 2 ;
	uint8_t DrvMode2_RegenLevelSetCmd : 2 ;
	uint8_t DrvMode3_RegenLevelSetCmd : 2 ;
	uint8_t DrvMode4_RegenLevelSetCmd : 2 ;



	uint32_t : 32 ;

	uint16_t : 16 ;

	uint8_t : 8 ;

} T_CGW_152H ; //ADDED_20201202

typedef struct
{
	uint8_t ACC_SW : 2 ;
	uint8_t ACC_Accel_RES_SW : 2 ;
	uint8_t ACC_Decel_SET_SW : 2 ;
	uint8_t ACC_DistanceSW : 2 ;

	uint8_t SpeedLimitSW : 2 ;
	uint8_t : 2 ;
	uint8_t RegenUpSW : 2 ; //ADDED_20201202
	uint8_t RegenDownSW : 2 ; //ADDED_20201202

	uint16_t : 16 ;
	uint16_t : 16 ;

	uint8_t Counter_160h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_160h ;

} T_CGW_160H ;

typedef struct
{
	uint8_t : 8  ;

	uint8_t T_Outside ;

	uint16_t Speed_Combi : 10 ;
	//uint16_t : 5 ;
	//uint16_t T_OutsideInitSts : 1 ;
	uint16_t : 6 ;

	uint16_t V_ANZ : 12 ;
	uint16_t : 3 ;
	uint16_t V_MPH : 1 ;

	uint8_t Counter_303h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_303h ;

} T_CGW_303H;

typedef struct
{
//	uint8_t IG_S : 1 ;
//	uint8_t Eng_Lamp_status : 1 ;
//	uint8_t : 1 ;
//	uint8_t Rheo_Stat_Level : 5 ;
	uint8_t : 8 ;

	uint8_t OM_High : 4 ;
//	uint8_t : 1 ;
//	uint8_t Airbag_WL_Fb : 3 ;
	uint8_t : 4 ;

	uint16_t KM16 ;

	uint16_t : 16 ;
//
//	uint8_t Counter_304h : 4 ;
//	uint8_t : 4 ;
//
//	uint8_t Checksum_304h ;

} T_CGW_304H ;

typedef struct
{
	uint8_t ACC_SystemState : 1 ;
	uint8_t ACC_Mode : 2 ;
	uint8_t : 5 ;

	uint8_t : 8 ;
	uint16_t : 16 ;

	uint16_t : 16 ;

	uint8_t Counter_259h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_259h ;
} T_CGW_259H ;

typedef struct
{
	uint8_t HeadLampHighSts : 1 ;
	uint8_t HazardSw : 1 ;
	uint8_t : 6 ;

	uint8_t DrivDoorLockUnSts : 1 ; //ADDED_20201203
	uint8_t : 3 ;
	uint8_t DrivDoorAjarSts : 2 ;  //ADDED_20201203
	uint8_t BatteryCheckReqCmdbyCCU : 2 ;  //ADDED_20201203

	uint32_t : 32 ;

	uint16_t : 16 ;
} T_CGW_372H ;

typedef struct
{
	uint8_t NM_Destination ;

	uint8_t NM_CommandCode : 3 ;
	uint8_t : 1 ;
	uint8_t NM_SleepFlag : 2 ;
	uint8_t : 2 ;

	uint8_t NM_WKUReason_CGW: 4 ;
	uint8_t NM_RormerState_CGW: 4 ;

	uint8_t : 2 ;
	uint8_t NM_IgnitionSts : 1 ;
	uint8_t NM_BatterycheckReqCmd_STPM: 1 ;
	uint8_t NM_WelcomeGoodbyeSoundCmd_BCM: 1 ;
	uint8_t NM_DoorAjarSts_BCM: 1 ;
	uint8_t : 2 ;

	uint8_t NM_DoorLockUnSts_BCM: 1 ;
	uint8_t : 2 ;
	uint8_t NM_PcanWakeupCmd_CCU : 1 ;
	uint8_t NM_PcanWakeupCmd_AVN : 1 ;
	uint8_t : 3 ;

	uint8_t : 8 ;

	uint16_t NM_Reserved_CGW ;

} T_CGW_448H ;

typedef struct
{
//	uint8_t EPB_Info_Lamp : 4 ;
//	uint8_t EPB_Fail_Lamp : 2 ;
//	uint8_t EPB_Alarm : 2 ;
//
//	uint8_t EPB_Display ;
	uint16_t : 16	;

//	uint8_t EPB_Switch : 2 ;
//	uint8_t EPB_Fail_Info : 3 ;
	uint8_t : 5	;
	uint8_t EPB_Status : 3 ;

	uint8_t EPB_RBLRQ : 1 ;
	uint8_t : 7 ;

	uint16_t : 16 ;

	uint8_t Counter_340h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_340h  ;

} T_CGW_340H ;

typedef struct
{
	uint16_t : 16	;
	uint8_t : 8	;

	uint8_t AVH_CTL_STATUS: 2 ;
	uint8_t AVH_LAMP_INFO : 3 ;
	uint8_t AVH_DRIVER_WARNING: 3 ;

	uint16_t : 16	;

	uint8_t Counter_360h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_360h ;

} T_CGW_360H;

typedef struct
{
//	uint8_t ESS_INFO : 1 ;
//	uint8_t ESP_BL : 1 ;
//	uint8_t ABS_KL : 1 ;
//	uint8_t ESP_KL : 2 ;
//	uint8_t ESP_OFF_KL : 1 ;
//	uint8_t EBD_KL : 1 ;
//	uint8_t : 1 ;
	uint8_t : 8 ;

	uint8_t BLS : 2 ;
	uint8_t BZ200h : 4 ;
	uint8_t BLS_PA : 1 ;
	uint8_t : 1 ;

	uint16_t DVL : 14 ;
	//uint16_t DRTGVL : 2 ;
	uint16_t : 2 ;

	uint16_t DVR : 14 ;
	//uint16_t DRTGVR : 2 ;
	uint16_t : 2 ;

	uint16_t TM_DL : 14 ;
	//uint16_t DRTGTM : 2 ;
	uint16_t : 2 ;
} T_EBU_200H ;

typedef struct
{
	uint16_t REGEN_REQ_TQ : 13 ;
	uint16_t REGEN_ENABLE_STS : 1 ;
	uint16_t PTS_SNS_FAIL : 1 ;
	//uint16_t PTS_CAL_STS : 1 ;
	uint16_t : 1 ;

	uint8_t EBU_PW ;

	//uint8_t BBC_DEF : 2 ;
	uint8_t : 2 ;
	uint8_t RBC_DEF : 1 ;
	//uint8_t BBC_KL : 1 ;
	//uint8_t RBC_KL : 1 ;
	uint8_t : 2 ;
	uint8_t REQ_COAST_REGEN_EXIT : 2 ;
	uint8_t : 1 ;

	uint16_t DRIVER_REQ_PRESSURE ;

	uint8_t Counter_207h : 4 ;
	uint8_t REGEN_EXIT_MONITORING : 4 ;

	uint8_t Checksum_207h ;

} T_EBU_207H ;

typedef struct
{
	uint8_t : 8 ;

	uint8_t : 4 ;
	uint8_t TM_AUS : 1 ;
	//uint8_t SZS : 2 ;
	//uint8_t : 2 ;
	uint8_t : 3 ;

//	uint16_t MBRE_ESP : 12 ;
//	uint16_t : 1 ;
//	uint16_t ANFN : 2 ;
//	uint16_t BRE_AKT_ART : 1 ;
	uint16_t : 16	;

	uint16_t DHR : 14 ;
	//uint16_t DRTGHR : 2 ;
	uint16_t : 2 ;

	uint16_t DHL : 14 ;
	//uint16_t DRTGHL : 2 ;
	uint16_t : 2 ;
} T_EBU_208H ;

typedef struct
{
	uint8_t : 4 ;
	uint8_t HSA_DEF_FLG : 1 ;
	uint8_t HSA_CTR_FLG : 1 ;
	uint8_t : 2 ;

	uint8_t : 8 ;

	uint16_t ACC_Engine_Torque_Value : 13 ;
	uint16_t ACC_Engine_Torque_Request : 1 ;
	uint16_t : 2 ;
//	uint16_t : 3 ;

	uint16_t : 16 ;

	uint8_t Counter_20Ah : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_20Ah ;

} T_EBU_20AH ;

typedef struct
{
	uint8_t BZ300h : 6 ;
	uint8_t MMOTSE_PA : 1 ;
	uint8_t MMOTSR_PA : 1 ;

//	uint8_t SFB : 2 ;
//	uint8_t SFB_PA : 1 ;
//	uint8_t : 2 ;
//	uint8_t AMR_AKT_ESP : 1 ;
//	uint8_t : 1 ;
	uint8_t : 7 ;
	uint8_t MPAR_ESP : 1 ;

	uint8_t MMOTSR ;

	uint8_t MMOTSE : 7 ;
	uint8_t TOGGLE : 1 ;

	uint16_t M_ESP : 13 ;
	uint16_t MMAX_ESP : 1 ;
	uint16_t MMIN_ESP : 1 ;
	uint16_t MTGL_ESP : 1 ;

	uint8_t Counter_300h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_300h ;

} T_EBU_300H ;

typedef struct
{
	uint8_t EBS_STATUS : 2 ;
	//uint8_t RQ_Clutch_OP : 2 ;
	uint8_t : 2 ;
	uint8_t Counter_330h : 4 ;

	//uint16_t CPL_TQ_LIMIT ;
	uint16_t : 16	;

	//uint16_t LAT_ACCEL : 11 ;
	//uint16_t : 1 ;
	//uint16_t Checksum_330h : 4 ;
	uint16_t : 16	;

	uint16_t EST_REF_VELOCITY ;

	//uint8_t LONG_ACCEL ;
	uint8_t Checksum_330h ;


} T_EBU_330H ;

typedef struct
{
	uint16_t LAT_ACCEL : 11 ;
	uint16_t : 5 ;
	uint8_t LONG_ACCEL ;
	uint8_t : 8 ;

	uint16_t PS_MEANVAL ;

	uint16_t GER_ROH ;

} T_EBU_331H ;

typedef struct
{
	uint8_t EGP_OperationMode : 4 ;
	uint8_t Pmotor_Position_Failure : 1 ;
	uint8_t Pmotor_Position_Status : 2 ;
	uint8_t Shifting_In_Progress : 1 ;

	uint8_t EGP_Service_WRN_IND : 1 ;
	uint8_t : 7 ;

	uint16_t : 16 ;
	uint16_t : 16 ;

	uint8_t Counter_1E8h : 4 ;
	uint8_t Pmotor_Error_Level : 4 ;

	uint8_t Checksum_1E8h ;

} T_EGP_1E8H ;

typedef struct
{
	uint16_t : 6 ;
	uint16_t AC_REF_High_Pressure : 10 ;

	uint16_t Cabin_HTR_Power : 10 ;
	uint16_t : 6 ;

	uint32_t : 32 ;

} T_EHVC_1EBH ;

typedef struct
{
	uint16_t eComp_Drive_RPM ;

	uint8_t eComp_Phase_Current ;
	uint8_t eComp_Inverter_Temp ;
	uint8_t eComp_Battery_Voltage ;

	uint16_t eComp_Power : 10 ;
	uint16_t : 6 ;

} T_EHVC_333H ;

typedef struct
{
	uint16_t eComp_Drive_RPM ;

	uint8_t eComp_Phase_Current ;
	uint8_t eComp_Inverter_Temp ;
	uint8_t eComp_Battery_Voltage ;

	uint16_t eComp_Power : 10 ;
	uint16_t : 6 ;

	uint8_t : 8 ;

} T_EHVC_33EH ;

typedef struct
{
	uint8_t DATC_STS_CHILLER : 1 ;
	uint8_t : 7 ;

	uint8_t Cabin_HTR_Current ;

} T_EHVC_337H ; // id change 33F

typedef struct
{
	uint8_t DATC_STS_CHILLER : 1 ;
	uint8_t : 7 ;

	uint8_t Cabin_HTR_Current ;

	uint16_t : 16 ;

	uint16_t : 16 ;

	uint16_t : 16 ;

} T_EHVC_33FH ;

typedef struct
{
	uint8_t : 1 ;
	uint8_t FAN_Status : 1 ;
	uint8_t HVAC_TEMP_Status : 2 ;
//	uint8_t HVAC_Mode_Status : 2 ;
	uint8_t  : 2 ;
	uint8_t  : 2 ;

	uint8_t Incar_Temp ;

	uint8_t RearDefoggerSwSts : 2 ;
	uint8_t : 6 ;

	uint8_t AC_Req : 2 ;
	uint8_t HP_Req : 2 ;
	uint8_t : 4 ;
//
//	uint8_t : 4 ;
//	uint8_t HvacMaxModeSts : 2 ;
//	uint8_t : 2 ;

} T_HVAC_235H ;

typedef struct
{
	uint8_t  : 8 ;

	uint8_t HVAC_Temp_Act_STS_L ;

	uint16_t : 16 ;

	uint8_t HVAC_Temp_Act_STS_R ;

	uint8_t : 8 ;

	uint8_t HVAC_MODE_DEF_STS : 2 ;
	uint8_t : 6 ;

	uint8_t : 8 ;

} T_HVAC_355H ;

typedef struct
{
	uint8_t LDC_STS_Ready : 2 ;
	uint8_t LDC_STS_MODE : 3 ;
	uint8_t : 1 ;
	uint8_t LDC_Out_Mode : 2 ;

	uint8_t : 2 ;
	uint8_t LDC_Out_Emergency : 1 ;
	uint8_t : 1 ;
	uint8_t LDC_Service_WRN_IND : 1 ;
	uint8_t : 3 ;

	uint16_t LDC_STS_Power_OUT ;

	uint8_t LDC_STS_TEMP ;

	uint8_t : 8 ;

	uint8_t Counter_3A0h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_3A0h ;

} T_LDC_3A0H ;

typedef struct
{
	uint16_t LDC_STS_VOLT_IN ;
	uint8_t LDC_STS_VOLT_OUT ;
	uint8_t LDC_STS_CURR_IN ;
	uint16_t LDC_STS_CURR_OUT ;

	uint16_t : 16 ;

} T_LDC_3A1H ;

typedef struct
{
	uint16_t : 14;
	uint16_t MCU_Service_WRN_IND : 1;
	uint16_t : 1;

	uint16_t : 16 ;

	uint16_t MCU_PowerConsumption : 10 ;
	uint16_t : 6 ;

	uint16_t : 16 ;

} T_MCU_327H ;

typedef struct
{
	uint8_t OBC_STS_Ready : 1 ;
	uint8_t OBC_STS_CONTRAB : 1 ;
	uint8_t OBC_CMD_Chg_Finished : 1 ;
	uint8_t OBC_STS_AC_DETECT : 1 ;
	uint8_t : 1 ;
	uint8_t OBC_STS_Temporary_Stop : 1 ;
	uint8_t OBC_STS_WRN : 1 ; //ADDED_20201202
	uint8_t OBC_STS_FLT : 1 ; //ADDED_20201202
//	uint8_t : 2 ;

//	uint8_t OBC_STS_PWR_LIM_1 : 1 ; //ADDED_20201202
//	uint8_t OBC_STS_PWR_LIM_2 : 1 ; //ADDED_20201202
//	uint8_t : 3 ;
//	uint8_t  OBC_STS_Precharge_step : 3 ; //ADDED_20201202
	uint8_t : 8 ;

	uint8_t OBC_STS_SC_State : 3 ;
	uint8_t : 2 ;
	uint8_t OBC_STS_PC_State : 3 ;

	uint8_t OBC_STS_TEMP ;

	uint8_t OBC_STS_CHECK_GROUP : 4 ;
	uint8_t : 4 ;

//	uint8_t OBC_STS_CHECK_ID : 5 ;
//	uint8_t : 3 ;

} T_OBC_3A8H ;

typedef struct
{
	uint16_t OBC_AC_V_rms ;
	uint16_t OBC_AC_I_rms ;
	uint16_t OBC_DC_Output_V ;
	uint16_t OBC_DC_Output_I ;
} T_OBC_3A9H ;

typedef struct
{
	uint8_t SBWS_Lever : 4 ;
	uint8_t SBWS_STS_Parking_Release_SW : 2 ;
	uint8_t SBW_STS : 2 ;

	uint8_t SBW_WRN_MSG : 4 ;
	uint8_t SBW_ShutDown_Timer : 2 ;
	uint8_t : 2 ;

	uint16_t : 16 ;
	uint16_t : 16 ;

	uint8_t Counter_1E7h : 4 ;
	uint8_t : 4 ;

	uint8_t Checksum_1E7h ;

} T_SBWS_1E7H ;

typedef struct
{
	uint16_t SAS_Angle ;

	uint8_t : 8 ;
	uint8_t SAS_OK : 1 ;
	uint8_t SAS_CAL : 1 ;
	uint8_t : 6 ;

	uint16_t : 16 ;

	uint8_t MsgCount : 4 ;
	uint8_t : 4 ;
	uint8_t CheckSum ;
} T_EPS_231H ;

typedef struct
{
	uint8_t REKESChargingStopCmd : 1 ;
	uint8_t : 7 ;

	uint32_t : 32 ;

	uint16_t : 16 ;

	uint8_t : 8 ;

} T_SKM_076H ;

typedef struct
{
	uint32_t : 32 ;
	uint8_t : 8 ;

	uint8_t : 4 ;
	uint8_t ST_REQ : 2 ;
	uint8_t : 2 ;

	uint16_t : 16 ;

} T_SKM_110H ;

typedef struct
{

	uint8_t HighVoltageRelayOnOffReqCmd : 2 ;
	uint8_t  : 6 ;

	uint32_t : 32 ;

	uint16_t : 16 ;

	uint8_t : 8 ;

} T_SKM_111H ;

typedef struct
{
	uint64_t SKM_Immo ;
} T_SKM_115H ;

typedef struct
{
	uint8_t RemoteStartSts : 2 ;
	uint8_t : 6 ;

	uint8_t : 8 ;
	uint16_t : 16 ;

	uint32_t : 32 ;

} T_SKM_248H ;

typedef struct
{

	uint8_t : 8 ;

	uint8_t BatteryCheckReqCmdbySTPM : 2 ;
	uint8_t : 2 ;
	uint8_t : 2 ;
	uint8_t : 2 ;

	uint8_t : 2 ;
	uint8_t : 2 ;
	uint8_t : 2 ;

	uint32_t : 32 ;

}T_CGW_161H_OLD; //ADDED_20201202

typedef struct
{

	uint64_t DIAG_REQ_FUNC ;

} T_CGW_700H; //ADDED_20201202

//210107
typedef struct
{
	uint8_t BmsReady : 1 ;
	uint8_t BmsRlyStatus : 3 ;
	uint8_t : 1 ;
	uint8_t BmsWarning : 1 ;
	uint8_t BmsProtection : 1 ;
	uint8_t BmsError : 1 ;

	uint8_t BmsSoC ;
	uint8_t BmsTempH ;
	uint8_t BmsTempL ;

	uint16_t BmsVolt ;
	uint16_t BmsCurr ;

} T_BMS_610H ;	/* Motorola */

//#pragma pack(0)

#endif /* E100_CANMSG_DEFINES_H_ */





