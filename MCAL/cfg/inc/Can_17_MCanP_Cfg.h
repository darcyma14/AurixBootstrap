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
**  DATE, TIME: 2021-12-28, 13:38:10                                      **
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
#define CAN_NUM_CONTROLLER_MAX         (3U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    (2U)

/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    (1U)

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

/******************************************************************************/
              /* CONTROLLER_1_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER1_ACTIVATION           (STD_OFF)

/******************************************************************************/
              /* CONTROLLER_2_MULTICANPLUS_NODE2 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER2_ACTIVATION           (STD_OFF)

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

/* CONTROLLER_5_MULTICANPLUS_NODE2 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER5_ACTIVATION           (STD_ON)

/* CONTROLLER_5_MULTICANPLUS_NODE2 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER5        (CAN_INTERRUPT)

/* CONTROLLER_5_MULTICANPLUS_NODE2 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER5        (CAN_INTERRUPT)

/* CONTROLLER_5_MULTICANPLUS_NODE2 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER5        (CAN_NO_PROCESSING)

/* CONTROLLER_5_MULTICANPLUS_NODE2 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER5        (CAN_INTERRUPT)

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
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)

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

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Hardware Objects 
*******************************************************************************/

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
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTO /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DTO != 1U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DTO is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DTO   (1U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTO */
#ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTM /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_MO_DTM != 2U)
    #error Can_17_MCanPConf_CanHardwareObject_MO_DTM is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_MO_DTM   (2U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_MO_DTM */

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
