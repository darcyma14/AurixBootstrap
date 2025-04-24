/*
 * E100_Struct_Defines.h
 *
 *  Created on: 2019. 8. 13.
 *      Author: jinwo
 */

#ifndef E100_STRUCT_DEFINES_H_
#define E100_STRUCT_DEFINES_H_

#include <stdint.h>
#define _E110


#ifdef _E110

	//TIMER
	extern void prvVIOS10msTimerCallback( void );
	extern void prvVIOS50msTimerCallback( void );
	extern void prvVIOS100msTimerCallback( void );
	extern void prvVIOS1secTimerCallback( void );
	extern void prvBPSDiagTimerCallback(void);

	//TASK
	extern void prvMainTask( void *pvParameters );
	extern void prvAPSLearnTask( void *pvTaskParameters );
	extern void prvCANMngTask( void *pvParameters );
	extern void prvDriveTask( void *pvParameters );
	extern void prvChargeTask( void *pvParameters );
	extern void prvDiagTask( void *pvParameters );

	extern void start_timer(void);
	extern void stop_timer(void);

	extern uint8_t bMain_Task, bAPS_Task_Resume, bCAN_Task_Resume, bDrive_Task_Resume, bCharge_Task_Resume, bDiag_Task_Resume;
	extern uint8_t bTask, gbTimerStart;

	extern uint16_t RT_1ms;

	extern uint8_t bCAN_10ms_Send_Flag;
	extern uint8_t bCAN_20ms_Send_Flag;
	extern uint8_t bCAN_100ms_Send_Flag;
	extern uint8_t bCAN_200ms_Send_Flag;
	extern uint8_t bCAN_500ms_Send_Flag;

	extern void vApplicationIdleHook( void );
	extern void E110_scheduler(void);
	extern void RTime_Cnt(void);

	extern uint16_t fwGetTimeTick(void);
	extern uint16_t fwGetETime(uint16_t STime);

	extern void IC_Recovery(void);
	extern void VCU_poweroff(void);

	#define SCREEN_CLR			print_f("\033[2J\033[1;1H");

	#define	_CGRN				("\033[92m")
	#define	_CYEL				("\033[33m")
	#define	_CRED				("\033[31m")
	#define	_CBLU				("\033[34m")
	#define _CMAG               ("\033[35m")
	#define _CCYAN              ("\033[36m")

	#define	_CEND				("\033[0m")

#endif

//#pragma pack(1) 20220923
typedef struct
{
	uint8_t : 4 ;
	uint8_t TestFailed : 1 ;
	uint8_t TestPassed : 1 ;
	uint8_t TestFailThisKeyCycle : 1 ;
	uint8_t TestPassThisKeyCycle : 1 ;

	uint16_t FailCounter ;
	uint16_t PassCounter ;
} T_DIAG_OUT ;

typedef struct
{
	uint8_t TestFailCycleCnt ;
	uint8_t TestPassCycleCnt ;

	uint8_t TestFailSinceCodeClear : 1 ;
	uint8_t TestPassSinceCodeClear : 1 ;
	uint8_t MIL_Status : 1 ;
	uint8_t FreezeFrameWrittenFlag : 1 ;
	uint8_t : 4 ;

} T_DIAG_HISTORY;

typedef struct
{
	float MotorSpeed ;
	float BAT_SOC	 ;

} T_DIAG_FREEZEFRAME;

typedef struct
{
	uint8_t : 4 ;
	uint8_t LearnDownHadBeenMet : 1 ;
	uint8_t LearnUpHadBeenMet : 1 ;
	uint8_t LearnDownEnable : 1 ;
	uint8_t LearnUpEnable : 1 ;

	uint16_t LearnDownCount ;
	uint16_t LearnUpCount ;

	float LearnValue ;
	float LearnNormHigh ;
	float LearnNormLow ;


} T_LEARN_OUT ;

typedef struct
{
	uint16_t StableCount ;
	float StableThres ;
	float LearnDownStep ;
	float LearnUpStep ;
	float LearnUpEnableThres ;
	float LearnUpActiveThres ;
	float LearnHi ;
	float LearnLow ;
} T_LEARN_CAL ;

typedef struct
{
	uint32_t Val_5km ;
	uint32_t Val_10km ;
	uint32_t Val_15km ;
	uint32_t Val_20km ;
	uint32_t Val_25km ;
} T_VALPER5KM_INT;

typedef struct
{
	float Val_5km ;
	float Val_10km ;
	float Val_15km ;
	float Val_20km ;
	float Val_25km ;
} T_VALPER5KM_FLOAT;

//ROMDATA¿¡ AC,HTR Ãß°¡
typedef struct
{
	uint32_t rom_check ;
	T_LEARN_OUT APS1MinLearnOut ;
	T_LEARN_OUT APS2MinLearnOut ;
	uint32_t OdoMeter ;
	float DTE_EWMA_AC_Power ;
	float DTE_EWMA_HTR_Power ;
	T_VALPER5KM_INT DTE_SPD_VehMovingCounter ;
	T_VALPER5KM_FLOAT DTE_SPD_AvgSpeed ;
	T_VALPER5KM_FLOAT DTE_ODO_5000m ;
	uint8_t ACChargingTargetSetCmd ;
	uint8_t DCChargingTargetSetCmd ;
	uint8_t PrevKeyGearState4TqCtrl;
	uint8_t PrevKeyAutoLockSts;
} T_ROMDATA ;

typedef struct
{
	uint8_t data[20] ;
} T_ROMDATA_VIN;

typedef struct
{
	T_DIAG_HISTORY DGDMTestDiagHistory ;
	T_DIAG_FREEZEFRAME DGDMTestFreezeFrame ;
} T_ROMDATA_DGDM;

typedef struct
{
	uint8_t LVAUTOCHRG_DIS_OBC : 1;
	uint8_t LVAUTOCHRG_DIS_PD : 1;
	uint8_t LVAUTOCHRG_DIS_LVBATT : 1;
	uint8_t LVAUTOCHRG_DIS_HVBATT : 1;
	uint8_t LVAUTOCHRG_DIS_DOOR : 1;
	uint8_t LVAUTOCHRG_DIS_REMOTE : 1;
	uint8_t LVAUTOCHRG_DIS_PWRDN : 1;
	uint8_t LVAUTOCHRG_DIS_LIN_ERROR : 1;
} T_LVAUTOCHRG_DISREASON;

typedef struct _bit
{
	uint8_t bit0 : 1 ;
	uint8_t bit1 : 1 ;
	uint8_t bit2 : 1 ;
	uint8_t bit3 : 1 ;
	uint8_t bit4 : 1 ;
	uint8_t bit5 : 1 ;
	uint8_t bit6 : 1 ;
	uint8_t bit7 : 1 ;

} BIT;



// #pragma pack() 20220923

#endif /* E100_STRUCT_DEFINES_H_ */
