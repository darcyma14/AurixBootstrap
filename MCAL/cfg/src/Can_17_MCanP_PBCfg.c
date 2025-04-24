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
**  $FILENAME   : Can_17_MCanP_PBCfg.c $                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\9 $                                **
**                                                                            **
**  DATE, TIME: 2022-10-01, 16:07:45                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CAN configuration generated out of ECU configuration       **
**                   file(Can_17_MCanP.bmd)                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_NAS_CAN_PR69_PR469_PR122,DS_NAS_CAN_PR446,
            DS_NAS_CAN_PR700,DS_NAS_CAN_PR701,DS_NAS_CAN_PR704,DS_NAS_CAN_PR707,
            DS_NAS_CAN_PR708,DS_NAS_CAN_PR712,DS_NAS_CAN_PR713,DS_NAS_CAN_PR714,
            DS_NAS_CAN_PR716,DS_NAS_CAN_PR717,DS_NAS_CAN_PR723,DS_NAS_CAN_PR724,
            DS_NAS_CAN_PR728,DS_NAS_CAN_PR709,SAS_AS4XX_CAN_PR680]
                     [/cover]                                                **/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_MCanP.h"

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

#define CAN_17_MCANP_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/******************************************************************************/
                /* CAN Controller Baudrate Configurations */
/******************************************************************************/
                          /* Baudrate Setting */
   /* (uint16)((DIV8 << 15)|(TSEG2 << 12)|(TSEG1 << 8)|(SJW << 6)|(BRP)) */
   /* SJW   -> CanControllerSyncJumpWidth - 1                            */
   /* TSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1              */
   /* TSEG2 -> CanControllerSeg2 - 1                                     */
/******************************************************************************/


/* CanConfigSet_0 -> CanController_0 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_0[] =
{
    {
        /* Configured Baudrate -> 500 kbps */
        /* Actual Baudrate     -> 505.050505050505 kbps */
        /* BRP   -> 8 */
        /* SJW   -> 0  */
        /* TSEG1 -> 15  */
        /* TSEG2 -> 4  */
        /* DIV8  -> 0  */
        0x4f08U,
        500U
    }
};

/* CanConfigSet_0 -> CanController_1 Baudrate Configuration */
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_1[] =
{
    {
        /* Configured Baudrate -> 500 kbps */
        /* Actual Baudrate     -> 505.050505050505 kbps */
        /* BRP   -> 8 */
        /* SJW   -> 0  */
        /* TSEG1 -> 15  */
        /* TSEG2 -> 4  */
        /* DIV8  -> 0  */
        0x4f08U,
        500U
    }
};

/* CanConfigSet_0 -> CanController_2 Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_2[] =
{
    {
        /* Configured Baudrate -> 500 kbps */
        /* Actual Baudrate     -> 505.050505050505 kbps */
        /* BRP   -> 8 */
        /* SJW   -> 0  */
        /* TSEG1 -> 15  */
        /* TSEG2 -> 4  */
        /* DIV8  -> 0  */
        0x4f08U,
        500U
    }
};

#ifdef _APP_KIT_BOARD_
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_0_3[] =
{
    {
        /* Configured Baudrate -> 500 kbps */
        /* Actual Baudrate     -> 505.050505050505 kbps */
        /* BRP   -> 8 */
        /* SJW   -> 0  */
        /* TSEG1 -> 15  */
        /* TSEG2 -> 4  */
        /* DIV8  -> 0  */
        0x4f08U,
        500U
    }
};
#endif

static const Can_BaudrateConfigPtrType Can_kBaudrateConfig_0[] =
{
    { &Can_kBaudrateConfig_0_0[ 0 ] },
    { &Can_kBaudrateConfig_0_1[ 0 ] },
    { &Can_kBaudrateConfig_0_2[ 0 ] },
#ifdef _APP_KIT_BOARD_
    { &Can_kBaudrateConfig_0_3[ 0 ] },
#endif
};

/******************************************************************************/
            /* Loopback and receive input pin selection setting */
/******************************************************************************/

/* Config 0 */
static const struct Can_NPCRValueType Can_kNPCR_0[] =
{
#ifdef _APP_KIT_BOARD_
    /* LoopBack Disabled, RXDCANxB */
    { 1U },
#endif
    /* LoopBack Disabled, RXDCANxB */
    { 1U },
    /* LoopBack Disabled, RXDCANxB */
    { 1U },
    /* LoopBack Disabled, RXDCANxG */
    { 6U },
};


/*******************************************************************************
               Transmit / Receive Hardware Object Configurations
********************************************************************************
 Tx Object -> { HW MO Id, [No. of Multiplexed MOs,] Hw Controller Id, Id Type }
        Rx Object -> { Mask, Msg Id, HW MO Id, Hw Controller Id, [Id Type] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
                           0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/

/* CanConfigSet_0 -> Transmit Hardware Object Configuration */
static const Can_TxHwObjectConfigType Can_kTxHwObjectConfig_0[] =
{

#ifdef _APP_KIT_BOARD_
    { 8U, 0U },
    { 9U, 1U },
    { 10U, 1U },
    { 11U, 2U },
    { 12U, 2U },
    { 13U, 2U },
    { 14U, 2U },
    { 15U, 2U },
    { 16U, 2U },
    { 17U, 2U },
    { 18U, 3U },
    { 19U, 3U },
    { 20U, 3U }
#else
    { 5U, 1U },
    { 6U, 1U },
    { 7U, 2U },
    { 8U, 2U },
    { 9U, 2U },
    { 10U, 2U },
    { 11U, 2U },
    { 12U, 2U },
    { 13U, 2U },
    { 1U, 3U },
    { 2U, 3U },
    { 3U, 3U }
#endif
};

/* CanConfigSet_0 -> Receive Hardware Object Configuration */
static const Can_RxHwObjectConfigType Can_kRxHwObjectConfig_0[] =
{

#ifdef _APP_KIT_BOARD_
    { 0x7ffU, 0x66U, 0U, 0U },
    { 0x7ffU, 0x6fU, 1U, 0U },
    { 0x7ffU, 0x630U, 2U, 1U },
    { 0x7ffU, 0x500U, 3U, 2U },
    { 0x7ffU, 0x501U, 4U, 2U },
    { 0x7ffU, 0x502U, 5U, 2U },
    { 0x7ffU, 0x6b0U, 6U, 2U },
    { 0x7ffU, 0x6b0U, 7U, 3U }
#else
    { 0x7ffU, 0x630U, 0U, 1U },
    { 0x7ffU, 0x500U, 1U, 2U },
    { 0x7ffU, 0x501U, 2U, 2U },
    { 0x7ffU, 0x502U, 3U, 2U },
    { 0x7ffU, 0x6b0U, 4U, 2U },
    { 0x7ffU, 0x6b0U, 0U, 3U }
#endif
};


/*******************************************************************************
              CAN Controller <-> CAN Hardware Object Mapping
********************************************************************************
        { First Rx Hardware Object, No. of Rx Hardware Objects,
          First Tx Hardware Object, No. of Tx Hardware Objects }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - CAN Hardware Object Mapping */
static const Can_ControllerMOMapConfigType Can_kControllerMOMapConfig_0[] =
{
#ifdef _APP_KIT_BOARD_
    { { 0U, 2U, 8U, 1U } },
    { { 2U, 1U, 9U, 2U } },
    { { 3U, 4U, 11U, 7U } },
    { { 7U, 1U, 18U, 3U } }
#else
    { { 0U, 1U, 5U, 2U } },
    { { 1U, 4U, 7U, 7U } },
    { { 0U, 1U, 1U, 3U } }
#endif
};


/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanBusoffProcessing, CanRxProcessing,
          CanTxProcessing, CanWakeupProcessing }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - Handling of Events */
static const Can_EventHandlingType Can_kEventHandlingConfig_0[] =
{
    { { (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT)} },
    { { (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT)} },
    { { (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT), (CAN_INTERRUPT)} }
};



/*******************************************************************************
              CAN Controller <-> Default Baudrate Mapping
********************************************************************************
          { NBTR Register Settings, Default Baudrate in kbps }
*******************************************************************************/

/* CanConfigSet_0 -> CAN Controller - default baudrate mapping */
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kDefaultBaudrateConfig_0[] =
{
#ifdef _APP_KIT_BOARD_
    { 0x4f08U, 500U },
#endif
    /* CAN Controller 0 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 505.050505050505 kbps */
    { 0x4f08U, 500U },
    /* CAN Controller 1 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 505.050505050505 kbps */
    { 0x4f08U, 500U },
    /* CAN Controller 2 :
     Configured Baudrate -> 500 kbps
     Actual Baudrate     -> 505.050505050505 kbps */
    { 0x4f08U, 500U }
};

#ifdef _APP_KIT_BOARD_
/* CAN L-PDU Receive Callout Function */
/*IFX_MISRA_RULE_08_08_STATUS= Support L-PDU callout function if configured*/
extern boolean CanLpduReceiveNotification (uint8 Hrh,
                                     Can_IdType CanId,
                                     uint8 CanDlc,
                                     const uint8 *CanSduPtr);
#endif

/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

const Can_17_MCanP_ConfigType Can_17_MCanP_ConfigRoot[] =
{
    {
        /* Pointer to Loopback and receive input pin selection setting */
        &Can_kNPCR_0[0],

        /* Pointer to CAN Controller <-> Hardware Objects Mapping */
        &Can_kControllerMOMapConfig_0[0],

        /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
        &Can_kEventHandlingConfig_0[0],

        /* Pointer to Controller Baudrate Configuration */
        &Can_kBaudrateConfig_0[0],

        /* Pointer to default baudrate configuration */
        &Can_kDefaultBaudrateConfig_0[0],

#ifdef _APP_KIT_BOARD_
        &CanLpduReceiveNotification,
#endif

        /* Pointer to Configuration of transmit hardware objects */
        &Can_kTxHwObjectConfig_0[0],

        /* Pointer to Configuration of receive hardware objects */
        &Can_kRxHwObjectConfig_0[0],


        /* CAN Module clock configuration : Fractional Divider Register setting */
        /* NORMAL_DIVIDER - Bit 14 is set */
        /* CanClockStepValue 1023 (0x3ff) is assigned to bit 0-9. */
        0x43ffU,

        /* Number of configured CAN controllers */
#ifdef _APP_KIT_BOARD_
        4U,
        /* CanControllerId --> CanHwControllerId (MultiCAN+ Controller Id) */
        { 0U, 1U, 2U, 3U },

        /* CAN Controller-wise number of baudrate configurations */
        { 1U, 1U, 1U, 1U },

        /* Total number of Transmit Hardware Objects */
        13U,

        /* Total number of Receive Hardware Objects */
        8U,

        /* Number of Receive Rx MOs + Rx FIFO MOs */
        8U,

        /* Transmit Hardware Objects Offset Kernel wise */
        { 8U },

        /* Receive Hardware Objects Offset Kernel wise */
        { 0U },

        /* Number of Rx FIFO MOs Kernel wise*/
        { 0U },
#else
        3U,
        /* CanControllerId --> CanHwControllerId (MultiCAN+ Controller Id) */
        { 1U, 2U, 3U },

        /* CAN Controller-wise number of baudrate configurations */
        { 1U, 1U, 1U },

        /* Total number of Transmit Hardware Objects */
        12U,

        /* Total number of Receive Hardware Objects */
        6U,

        /* Number of Receive Rx MOs + Rx FIFO MOs */
        6U,

        /* Transmit Hardware Objects Offset Kernel wise */
        { 5U, 1U },

        /* Receive Hardware Objects Offset Kernel wise */
        { 0U, 5U },

        /* Number of Rx FIFO MOs Kernel wise*/
        { 0U, 0U },
#endif


        /* Last MSPND register to be scanned for Rx MOs */
        0U,

        /* First MSPND register to be scanned for Tx MOs */
        0U,

        /* Last MSPND register to be scanned for Tx MOs */
        0U,
    }
};

#define CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
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

