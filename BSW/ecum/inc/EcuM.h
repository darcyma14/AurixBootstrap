/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : EcuM.h $                                                   **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2014-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Contains a simple example of ECU State Manager Code       **
**                 This file is for Evaluation Purpose Only                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef     ECUM_H
#define     ECUM_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Ecum_Cfg.h"
#include "EcuM_Cbk.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*  Published parameters  */
/* EcuM Vendor ID */
#define ECUM_VENDOR_ID              ((uint16)17)
/* EcuM Module ID */
#define ECUM_MODULE_ID              ((uint8)10)

#ifndef MCU_USES_FIXED_ADDR
#define MCU_USES_FIXED_ADDR         (STD_OFF)
#endif

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* The Global Ptr used to identify the EcuM Configuration Set */
extern const EcuM_ConfigType*   EcuM_ConfigPtr;
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void EcuM_Init(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitOne                              **
**                                         (const EcuM_ConfigType *configptr) **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitOne(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitTwo                              **
**                                         (const EcuM_ConfigType *configptr) **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitThree                            **
**                                          (const EcuM_ConfigType *configptr)**
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitThree(const EcuM_ConfigType *configptr);

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitZero                             **
**                                          (const EcuM_ConfigType *configptr)**
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitZero(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* ECUM_H */
