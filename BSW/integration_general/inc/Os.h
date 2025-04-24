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
**  $FILENAME   : Os.h $                                                     **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                 - functionality of OS driver.                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef OS_H
#define OS_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Call to OS Enable Interrupts */
#define EnableAllInterrupts()    //(OSEKMP_UserEnableAllInterrupts())

/* Call to OS Disable Interrupts */
#define DisableAllInterrupts()   //(OSEKMP_UserDisableAllInterrupts())

/* Call to OS Suspends Interrupts, nested */
#define SuspendAllInterrupts()   //(OSEKMP_UserSuspendAllInterrupts())

/* Call to OS Resume Interrupts, nested */
#define ResumeAllInterrupts()    //(OSEKMP_UserResumeAllInterrupts())

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
** Syntax           : void OSEKMP_UserEnableAllInterrupts(void)               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Enables all interrupts                    **
**                                                                            **
*******************************************************************************/
void OSEKMP_UserEnableAllInterrupts(void);


/*******************************************************************************
** Syntax           : void OSEKMP_UserDisableAllInterrupts(void)              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Disables all interrupts                   **
**                                                                            **
*******************************************************************************/
void OSEKMP_UserDisableAllInterrupts(void);

/******************************************************************************/

/*******************************************************************************
** Syntax           : void OSEKMP_UserSuspendAllInterrupts(void)              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Suspends all interrupts                   **
**                                                                            **
*******************************************************************************/
void OSEKMP_UserSuspendAllInterrupts(void);

/*****************************************************************************/


/*******************************************************************************
** Syntax           : void OSEKMP_UserResumeAllInterrupts(void)               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Resumes all interrupts                    **
**                                                                            **
*******************************************************************************/

void OSEKMP_UserResumeAllInterrupts(void);

/*****************************************************************************/

/*******************************************************************************
** Syntax           : void Os_GetCurrentStackArea(void  **start, void **end)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : start: Start address of Stack, end: Stack End address   **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function provides the stack's range                **
**                                                                **
*******************************************************************************/
void Os_GetCurrentStackArea(void  **, void **);
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/


#endif /* OS_H */
