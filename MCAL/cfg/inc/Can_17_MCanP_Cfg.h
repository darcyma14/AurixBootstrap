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
**  $FILENAME   : Can_17_MCanP_Cfg.h $                                       **
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
**                   file (Can_17_MCanP.bmd)                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_AS_CAN047,
                   DS_NAS_PR446,DS_AS4XX_CAN_PR2849,SAS_NAS_CAN_PR914,
                   SAS_NAS_CAN_PR915,SAS_AS4XX_CAN_PR678,SAS_NAS_CAN_PR916
                   DS_NAS_HE2_CAN_PR2893,DS_NAS_EP_CAN_PR2893]     **
**                                                                            **
**  [/cover]                                                                 **/


#ifndef CAN_17_MCANP_CFG_H
#define CAN_17_MCANP_CFG_H


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/* Autosar specification version */

#define CAN_17_MCANP_AS_VERSION (403)
#define CAN_17_MCANP_AR_RELEASE_MAJOR_VERSION  (4U)
#define CAN_17_MCANP_AR_RELEASE_MINOR_VERSION  (0U)
#define CAN_17_MCANP_AR_RELEASE_REVISION_VERSION  (3U)

/* Vendor specific implementation version information */
#define CAN_17_MCANP_SW_MAJOR_VERSION  (2U)
#define CAN_17_MCANP_SW_MINOR_VERSION  (3U)
#define CAN_17_MCANP_SW_PATCH_VERSION  (9U)


/*******************************************************************************
**                     Configuration options                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/* CAN ModuleR is available. i.e Additional 2 nodes/128 message objects are present */
#define CAN_MOD_R_AVAILABLE

/* Number of Config sets */
#define CAN_CONFIG_COUNT  (1U)

/* Number of Kernels available in the device */
#define CAN_NUM_KERNELS_IN_DEVICE  (2U)
/* Number of CAN Controllers available in the device */
#define CAN_NUM_CONTROLLERS_IN_DEVICE  (6U)
/* Number of CAN Controllers available in the First Kernel */
#define CAN_NUM_CONTROLLERS_IN_KERNEL1  (3U)
/* Maximum number of CAN Controllers configured in a ConfigSet */

#ifdef _APP_KIT_BOARD_
#define CAN_NUM_CONTROLLER_MAX         (4U)
/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    (13U)
/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    (8U)
#else
/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NUM_CONTROLLER_MAX         (3U)
/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    (12U)
/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    (6U)
#endif

/* Maximum number of Rx FIFO configurations in a ConfigSet */
#define CAN_NUM_RX_FIFO_MAX            (0U)

/* Configured Message Identifier Type */
/* STD_ON  : Only Standard Message Identifiers are configured */
/* STD_OFF : At least one Extended/Mixed Message Identifier is configured */
#define CAN_STANDARD_ID_ONLY           (STD_ON) 

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/

/* Is ERAY clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_ERAY_PLL_CLKSEL           (STD_OFF)


/* Is FD enabled ? */
#define CAN_FD_ENABLE           (STD_OFF)

/* Configuration: CAN_17_MCANP_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCANP_INSTANCE_ID                (0U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/      
#define CAN_DEV_ERROR_DETECT           (STD_ON)

/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_MCanP_GetVersionInfo API is enabled
 - STD_OFF - Can_17_MCanP_GetVersionInfo API is disabled
*/      
#define CAN_VERSION_INFO_API           (STD_OFF)

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/      
#define CAN_MULTIPLEXED_TRANSMISSION   (STD_OFF)

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until 
   a timeout is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION    (400U)

/* Configuration: CAN_PB_FIXEDADDR
 - STD_ON  - PB fixed address optimization is enabled 
 - STD_OFF - PB fixed address optimization is disabled 
*/
#define CAN_PB_FIXEDADDR               (STD_OFF)

/* Configuration: CAN_DEBUG_SUPPORT
 - STD_ON  - Debug support is enabled 
 - STD_OFF - Debug support is disabled 
*/
#define CAN_DEBUG_SUPPORT              (STD_OFF)

/* Configuration: CAN_CHANGE_BAUDRATE_API
 - STD_ON  - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are enabled
 - STD_OFF - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are disabled
*/
#define CAN_CHANGE_BAUDRATE_API              (STD_OFF)

#define CAN_RESET_SFR_AT_INIT              (STD_OFF)

/* Configuration: CAN_RESET_SFR_AT_INIT
 - STD_ON  - CAN Kernel Registers?reset feature is enabled
 - STD_OFF - CAN Kernel Registers?reset feature is not enabled
*/

#define CAN_DEINIT_API              (STD_OFF)

/* Configuration: CAN_DEINIT_API
 - STD_ON  - CAN De-initialization API is enabled
 - STD_OFF - CAN De-initialization API is not enabled
*/

/* CAN Hardware Timeout DEM */
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_DISABLE_DEM_REPORT)


/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/

/******************************************************************************/
              /* CONTROLLER_0_MULTICANPLUS_NODE0 Configuration */
/******************************************************************************/

#ifdef _APP_KIT_BOARD_
/* CONTROLLER_0_MULTICANPLUS_NODE0 Activation
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/
#define CAN_HWCONTROLLER0_ACTIVATION           (STD_ON)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism
*/
#define CAN_TX_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism
*/
#define CAN_RX_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism
*/
#define CAN_WU_PROCESSING_HWCONTROLLER0        (CAN_NO_PROCESSING)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism
*/
#define CAN_BO_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)
#else
#define CAN_HWCONTROLLER0_ACTIVATION           (STD_OFF)
#endif

/******************************************************************************/
              /* CONTROLLER_1_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

/* CONTROLLER_1_MULTICANPLUS_NODE1 Activation
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/
#define CAN_HWCONTROLLER1_ACTIVATION           (STD_ON)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism
*/
#define CAN_TX_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism
*/
#define CAN_RX_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism
*/
#define CAN_WU_PROCESSING_HWCONTROLLER1        (CAN_NO_PROCESSING)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism
*/
#define CAN_BO_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_2_MULTICANPLUS_NODE2 Configuration */
/******************************************************************************/

/* CONTROLLER_2_MULTICANPLUS_NODE2 Activation
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER2_ACTIVATION           (STD_ON)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER2        (CAN_NO_PROCESSING)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_3_MULTICANPLUS_NODE0 Configuration */
/******************************************************************************/

/* CONTROLLER_3_MULTICANPLUS_NODE0 Activation
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/
#define CAN_HWCONTROLLER3_ACTIVATION           (STD_ON)

/* CONTROLLER_3_MULTICANPLUS_NODE0 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism
*/
#define CAN_TX_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/* CONTROLLER_3_MULTICANPLUS_NODE0 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism
*/
#define CAN_RX_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/* CONTROLLER_3_MULTICANPLUS_NODE0 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism
*/
#define CAN_WU_PROCESSING_HWCONTROLLER3        (CAN_NO_PROCESSING)

/* CONTROLLER_3_MULTICANPLUS_NODE0 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism
*/
#define CAN_BO_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_4_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER4_ACTIVATION           (STD_OFF)

/******************************************************************************/
              /* CONTROLLER_5_MULTICANPLUS_NODE2 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER5_ACTIVATION           (STD_OFF)

/****************** End Of CAN Controller Configurations **********************/

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/      
#define CAN_WAKEUP_CONFIGURED                  (STD_OFF)

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/      
#ifdef _APP_KIT_BOARD_
#define CAN_LPDU_RX_CALLOUT                    (STD_ON)
#else
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)
#endif
/*******************************************************************************
    Symbolic Name Defintions of CAN Controllers and CAN Hardware Objects
*******************************************************************************/

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Controllers 
*******************************************************************************/

#ifdef Can_17_MCanPConf_CanController_CanController_0 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_0 != 0U)
    #error Can_17_MCanPConf_CanController_CanController_0 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_0   (0U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_0 */
#ifdef Can_17_MCanPConf_CanController_CanController_1 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_1 != 1U)
    #error Can_17_MCanPConf_CanController_CanController_1 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_1   (1U)
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_1 */

#ifdef Can_17_MCanPConf_CanController_CanController_2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_2 != 2U)
    #error Can_17_MCanPConf_CanController_CanController_2 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_2   (2U)
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_2 */

#ifdef _APP_KIT_BOARD_
#ifdef Can_17_MCanPConf_CanController_CanController_3 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_3 != 3U)
    #error Can_17_MCanPConf_CanController_CanController_3 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_3   (3U)
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_3 */
#endif

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Hardware Objects 
*******************************************************************************/
#ifdef _APP_KIT_BOARD_

#ifdef Can_17_MCanPConf_CanHardwareObject_MO0_00 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO0_00 != 0U)
    #error Can_17_MCanPConf_CanHardwareObject_MO0_00 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO0_00   (0U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO0_00 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO0_01 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO0_01 != 1U)
    #error Can_17_MCanPConf_CanHardwareObject_MO0_01 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO0_01   (1U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO0_01 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_02 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_02 != 2U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_02 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_02   (2U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_02 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_03 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_03 != 3U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_03 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_03   (3U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_03 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_04 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_04 != 4U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_04 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_04   (4U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_04 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_05 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_05 != 5U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_05 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_05   (5U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_05 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_06 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_06 != 6U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_06 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_06   (6U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_06 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO3_07 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO3_07 != 7U)
    #error Can_17_MCanPConf_CanHardwareObject_MO3_07 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO3_07   (7U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO3_07 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO0_08 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO0_08 != 8U)
    #error Can_17_MCanPConf_CanHardwareObject_MO0_08 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO0_08   (8U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO0_08 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_09 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_09 != 9U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_09 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_09   (9U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_09 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_10 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_10 != 10U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_10 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_10   (10U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_10 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_11 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_11 != 11U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_11 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_11   (11U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_11 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_12 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_12 != 12U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_12 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_12   (12U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_12 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_13 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_13 != 13U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_13 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_13   (13U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_13 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_14 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_14 != 14U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_14 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_14   (14U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_14 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_15 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_15 != 15U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_15 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_15   (15U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_15 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_16 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_16 != 16U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_16 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_16   (16U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_16 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_17 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_17 != 17U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_17 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_17   (17U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_17 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO3_18 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO3_18 != 18U)
    #error Can_17_MCanPConf_CanHardwareObject_MO3_18 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO3_18   (18U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO3_18 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO3_19 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO3_19 != 19U)
    #error Can_17_MCanPConf_CanHardwareObject_MO3_19 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO3_19   (19U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO3_19 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO3_20 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO3_20 != 20U)
    #error Can_17_MCanPConf_CanHardwareObject_MO3_20 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO3_20   (20U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO3_20 */

#endif

#ifdef Can_17_MCanPConf_CanHardwareObject_MO_CRM /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_CRM != 0U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_CRM is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_CRM   (0U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_CRM */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_ESCS /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_ESCS != 1U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_ESCS is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_ESCS   (1U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_ESCS */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_MCU /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_MCU != 2U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_MCU is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_MCU   (2U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_MCU */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_VEH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_VEH != 3U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_VEH is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_VEH   (3U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_VEH */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_6B0h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_6B0h != 4U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_6B0h is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_6B0h   (4U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_6B0h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_6B0h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_6B0h != 5U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_6B0h is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_6B0h   (5U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_6B0h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTO /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DTO != 6U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DTO is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DTO   (6U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTO */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTM /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DTM != 7U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DTM is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DTM   (7U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTM */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_ESCC /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_ESCC != 8U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_ESCC is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_ESCC   (8U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_ESCC */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1 != 9U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1   (9U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG1 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2 != 10U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2   (10U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG2 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3 != 11U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3 is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3   (11U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DEBUG3 */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_100h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_100h != 12U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_100h is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_100h   (12U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_100h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_101h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_101h != 13U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_101h is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_101h   (13U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_101h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO1_6C0h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO1_6C0h != 14U)
    #error Can_17_MCanPConf_CanHardwareObject_MO1_6C0h is already defined with a different value
  #endif
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO1_6C0h   (14U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO1_6C0h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_100h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_100h != 15U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_100h is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_100h   (15U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_100h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_101h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_101h != 16U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_101h is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_101h   (16U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_101h */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO2_6C0h /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO2_6C0h != 17U)
    #error Can_17_MCanPConf_CanHardwareObject_MO2_6C0h is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO2_6C0h   (17U)
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO2_6C0h */


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* CAN_17_MCANP_CFG_H */
