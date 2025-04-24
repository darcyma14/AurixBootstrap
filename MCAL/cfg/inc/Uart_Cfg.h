/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Uart_Cfg.h $                                               **
**                                                                            **
**  $CC VERSION : \main\18 $                                                 **
**                                                                            **
**  DATE, TIME: 2022-10-01, 16:07:46                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
#ifndef UART_CFG_H 
#define UART_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*SW Version Information*/
#define UART_SW_MAJOR_VERSION   (1U)
#define UART_SW_MINOR_VERSION   (2U)
#define UART_SW_PATCH_VERSION   (0U)

/*
         Container : UartGeneral Configuration
*/

/*
Derived Configuration for UartDevErrorDetect 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
The detection of all development errors is configurable (On / Off) 
at precompile time. The switch UART_DEV_ERROR_DETECT  shall
activate or deactivate the detection of all development errors.

If the switch UART_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled. 
*/
#define UART_DEV_ERROR_DETECT  (STD_OFF)

/*
Derived Configuration for UartVersionInfoApi 
- if STD_ON, Function Uart_GetVersionInfo is available  
- if STD_OFF,Function Uart_GetVersionInfo is not available 
*/
#define UART_VERSION_INFO_API  (STD_OFF)

/*
Derived Configuration for UartPBFixedAddress 
- if STD_ON, Fixed Address feature is Enabled 
- if STD_OFF,Fixed Address feature is Disabled
*/
#define UART_PB_FIXEDADDR  (STD_OFF)

/*
Derived Configuration for UartDeinitApi 
- if STD_ON, Function UartDeinitApi is available  
- if STD_OFF,Function UartDeinitApi is not available 
*/
#define UART_DEINIT_API  (STD_OFF)
/*
Derived Configuration for UartAbortReadApi 
- if STD_ON, Function UartAbortReadApi is available  
- if STD_OFF,Function UartAbortReadApi is not available 
*/
#ifdef _McalModified_
#define UART_ABORT_READ_API  (STD_ON)
#else
#define UART_ABORT_READ_API  (STD_OFF)
#endif
/*
Derived Configuration for UartAbortWriteApi
- if STD_ON, Function UartAbortWriteApi is available  
- if STD_OFF,Function UartAbortWriteApi is not available 
*/
#define UART_ABORT_WRITE_API  (STD_OFF)

/* Derived Configuration for UartDebugSupport*/
#define UART_DEBUG_SUPPORT  (STD_OFF)

/* Derived Configuration for UartResetSfrAtInit*/
#define UART_RESET_SFR_INIT  (STD_OFF)

/* Derived Configuration for UartIndex*/
#define UART_INDEX  (0U)

/* Total no. of config sets */
#define UART_CONFIG_COUNT    (1U)

/* Total Number of ASCLIN HW Units Available*/
#define UART_MAX_HW_UNIT (2U)

#define UART_ASCLIN0 (0U)
#define UART_ASCLIN1 (1U)

/* 
Derived Configuration for UartDataLength  
Flag Indicating if 9 bit Datalength is used in Any Configuration Set
*/
#define UART_NINEBITS_USED (STD_OFF)

/* 
Configuration : UART_MAXIMUM_CHANNEL 
Maximum of No. of Uart channels configured in different PB Config Sets
*/
#define UART_MAXIMUM_CHANNEL (1U)


/*
Configuration: UART_ASCLINx_USED 
- if STD_ON, ASCLINx is used   
- if STD_OFF,ASCLINx is not used  
*/

#define UART_ASCLIN0_USED  (STD_OFF)
#define UART_ASCLIN1_USED  (STD_ON)



/* Derived Configuration for UartSleepEnable*/
#define UART_ASCLIN_CLC (0x08U)

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* UART_CFG_H */

