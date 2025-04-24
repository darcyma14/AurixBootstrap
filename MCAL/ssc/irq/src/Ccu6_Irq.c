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
**  $FILENAME   : Ccu6_Irq.c $                                               **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2014-06-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt frames for the CCU6.      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* MCAL header file containing global macros, type definitions and functions 
  needed by all MCAL drivers. */
#include "Mcal.h"
#include "IfxCcu6_reg.h"
/* Include ICU header file - Icu.h */
#include "Icu_17_GtmCcu6.h"

/* MCAL driver utility functions for setting interrupt priority initialization 
  and interrupt category */
#include "Irq.h"


/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CCU6_KERNEL_0  0U
#define CCU6_KERNEL_1  1U
#define CCU6_KERNEL_2  2U
#define CCU6_KERNEL_3  2U

#define CCU6_CHANNEL_0  0U
#define CCU6_CHANNEL_1  1U
#define CCU6_CHANNEL_2  2U
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

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
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define IRQ_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax:           void CCU60_ISR_SRN00(void)                               **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This is Interrput Service request nodes 0 for the  CCU60.**
*******************************************************************************/
#if((IRQ_CCU60_SR0_PRIO > 0) || (IRQ_CCU60_SR0_CAT == IRQ_CAT23))
#if((IRQ_CCU60_SR0_PRIO > 0) && (IRQ_CCU60_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(CCU60SR0_ISR, 0, IRQ_CCU60_SR0_PRIO)
#elif IRQ_CCU60_SR0_CAT == IRQ_CAT23
ISR(CCU60SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  
  if((CCU60_IS.B.ICC60R & CCU60_IEN.B.ENCC60R) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU60_ISR.B.RCC60R = 1U; 
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_0);     
     CCU60_ISR.B.RCC60R = 1U;   
  }
  if((CCU60_IS.B.ICC60F & CCU60_IEN.B.ENCC60F) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU60_ISR.B.RCC60F = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_0);     
     CCU60_ISR.B.RCC60F = 1U;   
  }  
  if((CCU60_IS.B.ICC61R & CCU60_IEN.B.ENCC61R) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU60_ISR.B.RCC61R = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_1);     
     CCU60_ISR.B.RCC61R = 1U;   
  } 
  if((CCU60_IS.B.ICC61F & CCU60_IEN.B.ENCC61F) == 1U)  
  {  
     /* Call Icu Interrupt funtion */
     CCU60_ISR.B.RCC61F = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_1);     
     CCU60_ISR.B.RCC61F = 1U;   
  }   
  if((CCU60_IS.B.ICC62R & CCU60_IEN.B.ENCC62R) == 1U)
  {  
    /* Call Icu Interrupt funtion */
    CCU60_ISR.B.RCC62R = 1U;
    Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_2);     
     CCU60_ISR.B.RCC62R = 1U;   
  } 
  if((CCU60_IS.B.ICC62F & CCU60_IEN.B.ENCC62F) == 1U) 
  {  
    /* Call Icu Interrupt funtion */
     CCU60_ISR.B.RCC62F = 1U;
    Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_0,CCU6_CHANNEL_2);     
     CCU60_ISR.B.RCC62F = 1U;   
  }   

 /*   if((CCU60_IS.B.ICC60F & CCU60_IEN.B.ENCC60F) == 1U)
  {  

     Icu_17_GtmCcu6_Ccu_Isr(0U,0U,ICU_FALLING_EDGE);     
     CCU60_ISR.B.RCC60R = 1U;   
  } */
}
#endif

/*******************************************************************************
** Syntax:           void CCU61_ISR_SRN00(void)                               **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This is Interrput Service request nodes 0 for the  CCU61.**
*******************************************************************************/
#if((IRQ_CCU61_SR0_PRIO > 0) || (IRQ_CCU61_SR0_CAT == IRQ_CAT23))
#if((IRQ_CCU61_SR0_PRIO > 0) && (IRQ_CCU61_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(CCU61SR0_ISR, 0, IRQ_CCU61_SR0_PRIO)
#elif IRQ_CCU61_SR0_CAT == IRQ_CAT23
ISR(CCU61SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  if((CCU61_IS.B.ICC60R & CCU61_IEN.B.ENCC60R) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC60R = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_0);     
     CCU61_ISR.B.RCC60R = 1U;   
  }
  if((CCU61_IS.B.ICC60F & CCU61_IEN.B.ENCC60F) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC60F = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_0);     
     CCU61_ISR.B.RCC60F = 1U;   
  }  
  if((CCU61_IS.B.ICC61R & CCU61_IEN.B.ENCC61R) == 1U)
  {  
     /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC61R = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_1);     
     CCU61_ISR.B.RCC61R = 1U;   
  } 
  if((CCU61_IS.B.ICC61F & CCU61_IEN.B.ENCC61F) == 1U)  
  {  
     /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC61F = 1U;
     Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_1);     
     CCU61_ISR.B.RCC61F = 1U;   
  }   
  if((CCU61_IS.B.ICC62R & CCU61_IEN.B.ENCC62R) == 1U)
  {  
    /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC62R = 1U;
    Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_2);     
     CCU61_ISR.B.RCC62R = 1U;   
  } 
  if((CCU61_IS.B.ICC62F & CCU61_IEN.B.ENCC62F) == 1U) 
  {  
    /* Call Icu Interrupt funtion */
     CCU61_ISR.B.RCC62F = 1U; 
    Icu_17_GtmCcu6_Ccu_Isr(CCU6_KERNEL_1,CCU6_CHANNEL_2);     
     CCU61_ISR.B.RCC62F = 1U;   
  }   
  
}
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
