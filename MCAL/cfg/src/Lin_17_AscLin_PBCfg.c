/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Lin_17_AscLin_PBCfg.c                                         **
**                                                                            **
**  $CC VERSION : \main\40 $                                                 **
**                                                                            **
**  DATE, TIME: 2022-10-01, 16:07:44                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  MODULE DECRIPTION : Lin_17_AscLin.bmd/.xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Lin configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_LIN_Driver, Release 4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
TRACEABILITY : [cover parentID= DS_NAS_LIN_PR446, SAS_AS_LIN064,
DS_NAS_LIN_PR701,DS_NAS_LIN_PR704,DS_NAS_LIN_PR707,DS_NAS_LIN_PR708,
DS_NAS_LIN_PR712,DS_NAS_LIN_PR713,DS_NAS_LIN_PR714,DS_NAS_LIN_PR716,
DS_NAS_LIN_PR719,DS_NAS_LIN_PR720,DS_NAS_LIN_PR723,DS_NAS_LIN_PR724,
DS_NAS_LIN_PR709,DS_NAS_LIN_PR699,SAS_AS4XX_LIN_PR680,DS_NAS_LIN_PR717,
DS_NAS_LIN_PR700,DS_NAS_LIN_PR728,SAS_NAS_LIN_PR729] [/cover]      
*******************************************************************************/
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/

/* Include LIN Module File */
#include "Lin_17_AscLin.h"
    
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*
                     Container: LinChannelConfiguration
*/
#define LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"




/* Lin_Channel: User configured channel initialization structure. */

static const Lin_17_AscLin_ChannelType  Lin_kChannelConfig0[ 1 ] =
{
	/* LIN Channel ID: 0 Configuration */
	{
		/* BaudRate : 19200 Hz  */
		{
			341U,  	/* BRG.NUMERATOR value */
			1000U,	/* BRG.DENOMINATOR value */
			110U,	/* BITCON.PRESCALAR value */
			234U,	/* Prescalar value for wakeup detection */
			0U,		/* Inter byte or response space value */
			63U		/* IOCR DEPTH value for wakeup detection */
		},
		25U,          /* EcuM Wakeup Source ID */
		LIN_ASCLIN0,                   /* Hw Module used */
		LIN_CHANNEL_WAKEUP_ENABLED,    /* Wakeup Support */
		/*Rx alternate pin select */
		2U
	},
};


/* 
   The over all initialization data for the LIN driver. 
   The user configured Lin driver initialization structure.
*/
const Lin_17_AscLin_ConfigType  Lin_ConfigRoot[1] = 
{
	{
		Lin_kChannelConfig0,
		1U,
	}
};

#define LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
is allowed only for MemMap.h*/
#include "MemMap.h"



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

