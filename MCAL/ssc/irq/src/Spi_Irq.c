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
**  $FILENAME   : Spi_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\26 $                                                 **
**                                                                           **
**  $DATE       : 2015-05-21 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - ISRs of SPI Handler driver.                              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* MCAL driver utility functions for setting interrupt priority initialization 
    and interrupt category */
#include "Irq.h"
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
#if (IFX_SAFETLIB_USED == STD_ON)
#include "SafeWdgIf_Cfg.h"
#if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
extern void SafeWdgQspi_IsrTxRx(  void );
#endif
#endif

#if (IFX_MCAL_USED == STD_ON)
/* Own header file, this includes own configuration file also */
#include "Spi.h"
#endif


/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
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
#if (IFX_MCAL_USED == STD_ON)
#define IRQ_START_SEC_CODE
#include "MemMap.h"
#endif

/******************************************************************************
** Syntax : void QSPI4ERR_ISR(void)                                        **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Error interrupt of QSPIx                     **
**                                                                           **
*****************************************************************************/
/* Fixed for AI00248112 */
#define SPI_QSPI0_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI0_ERRISR_ENABLE
  #define SPI_QSPI0_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI0_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI0_INDEX)
  #undef SPI_QSPI0_ERRISR_ENABLE
  #define SPI_QSPI0_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI0_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI0_ESRC */
#if ((IRQ_QSPI0_ERR_PRIO > 0) || (IRQ_QSPI0_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI0_ERR_PRIO > 0) && (IRQ_QSPI0_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI0ERR_ISR, 0, IRQ_QSPI0_ERR_PRIO)
#elif IRQ_QSPI0_ERR_CAT == IRQ_CAT23
ISR(QSPI0ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI0_INDEX);  
}
#endif
#endif

#define SPI_QSPI1_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI1_ERRISR_ENABLE
  #define SPI_QSPI1_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI1_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI1_INDEX)
  #undef SPI_QSPI1_ERRISR_ENABLE
  #define SPI_QSPI1_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI1_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI1_ESRC */
#if ((IRQ_QSPI1_ERR_PRIO > 0) || (IRQ_QSPI1_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI1_ERR_PRIO > 0) && (IRQ_QSPI1_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI1ERR_ISR, 0, IRQ_QSPI1_ERR_PRIO)
#elif IRQ_QSPI1_ERR_CAT == IRQ_CAT23
ISR(QSPI1ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPIx Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI1_INDEX);  

}
#endif
#endif

#define SPI_QSPI2_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI2_ERRISR_ENABLE
  #define SPI_QSPI2_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI2_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI2_INDEX)
  #undef SPI_QSPI2_ERRISR_ENABLE
  #define SPI_QSPI2_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI2_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI2_ESRC */
#if ((IRQ_QSPI2_ERR_PRIO > 0) || (IRQ_QSPI2_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI2_ERR_PRIO > 0) && (IRQ_QSPI2_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI2ERR_ISR, 0, IRQ_QSPI2_ERR_PRIO)
#elif IRQ_QSPI2_ERR_CAT == IRQ_CAT23
ISR(QSPI2ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPIx Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI2_INDEX);  

}
#endif
#endif

#define SPI_QSPI3_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI3_ERRISR_ENABLE
  #define SPI_QSPI3_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI3_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI3_INDEX)
  #undef SPI_QSPI3_ERRISR_ENABLE
  #define SPI_QSPI3_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI3_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI3_ESRC */
#if ((IRQ_QSPI3_ERR_PRIO > 0) || (IRQ_QSPI3_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI3_ERR_PRIO > 0) && (IRQ_QSPI3_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI3ERR_ISR, 0, IRQ_QSPI3_ERR_PRIO)
#elif IRQ_QSPI3_ERR_CAT == IRQ_CAT23
ISR(QSPI3ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPIx Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI3_INDEX);  

}
#endif
#endif

#define SPI_QSPI4_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI4_ERRISR_ENABLE
  #define SPI_QSPI4_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI4_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI4_INDEX)
  #undef SPI_QSPI4_ERRISR_ENABLE
  #define SPI_QSPI4_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI4_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI4_ESRC */
#if ((IRQ_QSPI4_ERR_PRIO > 0) || (IRQ_QSPI4_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI4_ERR_PRIO > 0) && (IRQ_QSPI4_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPIXERR_ISR, 0, IRQ_QSPI4_ERR_PRIO)
#elif IRQ_QSPI4_ERR_CAT == IRQ_CAT23
ISR(QSPIXERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPIx Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI4_INDEX);  

}
#endif
#endif

#define SPI_QSPI5_ERRISR_ENABLE (STD_OFF)
#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
  #undef SPI_QSPI5_ERRISR_ENABLE
  #define SPI_QSPI5_ERRISR_ENABLE (STD_ON)
#elif((SPI_QSPI5_USED == STD_ON) && (SPI_SLAVE_ENABLE == STD_ON))
   #if (SPI_SLAVE_MODULE_INDEX == SPI_QSPI5_INDEX)
  #undef SPI_QSPI5_ERRISR_ENABLE
  #define SPI_QSPI5_ERRISR_ENABLE (STD_ON)
   #endif
#endif
#if (SPI_QSPI5_ERRISR_ENABLE == STD_ON)
/* This node is for QSPI5_ESRC */
#if ((IRQ_QSPI5_ERR_PRIO > 0) || (IRQ_QSPI5_ERR_CAT == IRQ_CAT23))
#if ((IRQ_QSPI5_ERR_PRIO > 0) && (IRQ_QSPI5_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI5ERR_ISR, 0, IRQ_QSPI5_ERR_PRIO)
#elif IRQ_QSPI5_ERR_CAT == IRQ_CAT23
ISR(QSPI5ERR_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPIx Interrupt funtion*/                                              
  Spi_IsrQspiError(SPI_QSPI5_INDEX);  

}
#endif
#endif


/******************************************************************************
** Syntax : void QSPIXPT_ISR(void)                                       **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Phase transition interrupt (PT2) used by QSPIx    **
**                                                                           **
*****************************************************************************/
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI0_PT_PRIO > 0) || (IRQ_QSPI0_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI0_PT_PRIO > 0) && (IRQ_QSPI0_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI0PT_ISR, 0, IRQ_QSPI0_PT_PRIO)
#elif IRQ_QSPI0_PT_CAT == IRQ_CAT23
ISR(QSPI0PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI0_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI1_PT_PRIO > 0) || (IRQ_QSPI1_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI1_PT_PRIO > 0) && (IRQ_QSPI1_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI1PT_ISR, 0, IRQ_QSPI1_PT_PRIO)
#elif IRQ_QSPI1_PT_CAT == IRQ_CAT23
ISR(QSPI1PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI1_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI2_PT_PRIO > 0) || (IRQ_QSPI2_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI2_PT_PRIO > 0) && (IRQ_QSPI2_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI2PT_ISR, 0, IRQ_QSPI2_PT_PRIO)
#elif IRQ_QSPI2_PT_CAT == IRQ_CAT23
ISR(QSPI2PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI2_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI3_PT_PRIO > 0) || (IRQ_QSPI3_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI3_PT_PRIO > 0) && (IRQ_QSPI3_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI3PT_ISR, 0, IRQ_QSPI3_PT_PRIO)
#elif IRQ_QSPI3_PT_CAT == IRQ_CAT23
ISR(QSPI3PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI3_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI4_PT_PRIO > 0) || (IRQ_QSPI4_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI4_PT_PRIO > 0) && (IRQ_QSPI4_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI4PT_ISR, 0, IRQ_QSPI4_PT_PRIO)
#elif IRQ_QSPI4_PT_CAT == IRQ_CAT23
ISR(QSPI4PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI4_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI5_PT_PRIO > 0) || (IRQ_QSPI5_PT_CAT == IRQ_CAT23))
#if ((IRQ_QSPI5_PT_PRIO > 0) && (IRQ_QSPI5_PT_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI5PT_ISR, 0, IRQ_QSPI5_PT_PRIO)
#elif IRQ_QSPI5_PT_CAT == IRQ_CAT23
ISR(QSPI5PT_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiPt(SPI_QSPI5_INDEX);  
}
#endif
#endif

/******************************************************************************
** Syntax : void QSPIXUD_ISR(void)                                       **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for User interrupt (PT1) used by QSPIx    **
**                                                                           **
*****************************************************************************/
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI0_UD_PRIO > 0) || (IRQ_QSPI0_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI0_UD_PRIO > 0) && (IRQ_QSPI0_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI0UD_ISR, 0, IRQ_QSPI0_UD_PRIO)
#elif IRQ_QSPI0_UD_CAT == IRQ_CAT23
ISR(QSPI0UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI0_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI1_UD_PRIO > 0) || (IRQ_QSPI1_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI1_UD_PRIO > 0) && (IRQ_QSPI1_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI1UD_ISR, 0, IRQ_QSPI1_UD_PRIO)
#elif IRQ_QSPI1_UD_CAT == IRQ_CAT23
ISR(QSPI1UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI1_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI2_UD_PRIO > 0) || (IRQ_QSPI2_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI2_UD_PRIO > 0) && (IRQ_QSPI2_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI2UD_ISR, 0, IRQ_QSPI2_UD_PRIO)
#elif IRQ_QSPI2_UD_CAT == IRQ_CAT23
ISR(QSPI2UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI2_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI3_UD_PRIO > 0) || (IRQ_QSPI3_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI3_UD_PRIO > 0) && (IRQ_QSPI3_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI3UD_ISR, 0, IRQ_QSPI3_UD_PRIO)
#elif IRQ_QSPI3_UD_CAT == IRQ_CAT23
ISR(QSPI3UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI3_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI4_UD_PRIO > 0) || (IRQ_QSPI4_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI4_UD_PRIO > 0) && (IRQ_QSPI4_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI4UD_ISR, 0, IRQ_QSPI4_UD_PRIO)
#elif IRQ_QSPI4_UD_CAT == IRQ_CAT23
ISR(QSPI4UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI4_INDEX);  
}
#endif
#endif

#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if ((IRQ_QSPI5_UD_PRIO > 0) || (IRQ_QSPI5_UD_CAT == IRQ_CAT23))
#if ((IRQ_QSPI5_UD_PRIO > 0) && (IRQ_QSPI5_UD_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI5UD_ISR, 0, IRQ_QSPI5_UD_PRIO)
#elif IRQ_QSPI5_UD_CAT == IRQ_CAT23
ISR(QSPI5UD_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

  /* Call QSPI0 Interrupt funtion*/                                              
  Spi_IsrQspiUsr(SPI_QSPI5_INDEX);  
}
#endif
#endif

#if (IFX_MCAL_USED == STD_ON)
#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
#endif



#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_IRQ_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif
/******************************************************************************
** Syntax : void QSPIXTX_ISR(void)                                       **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Tx  interrupt (TX) used by QSPIx    **
**                                                                           **
*****************************************************************************/

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI0_TX_PRIO > 0) || (IRQ_QSPI0_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI0_TX_PRIO > 0) && (IRQ_QSPI0_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI0TX_ISR, 0, IRQ_QSPI0_TX_PRIO)
#elif IRQ_QSPI0_TX_CAT == IRQ_CAT23
ISR(QSPI0TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI1_TX_PRIO > 0) || (IRQ_QSPI1_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI1_TX_PRIO > 0) && (IRQ_QSPI1_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI1TX_ISR, 0, IRQ_QSPI1_TX_PRIO)
#elif IRQ_QSPI1_TX_CAT == IRQ_CAT23
ISR(QSPI1TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI2_TX_PRIO > 0) || (IRQ_QSPI2_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI2_TX_PRIO > 0) && (IRQ_QSPI2_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI2TX_ISR, 0, IRQ_QSPI2_TX_PRIO)
#elif IRQ_QSPI2_TX_CAT == IRQ_CAT23
ISR(QSPI2TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI3_TX_PRIO > 0) || (IRQ_QSPI3_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI3_TX_PRIO > 0) && (IRQ_QSPI3_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI3TX_ISR, 0, IRQ_QSPI3_TX_PRIO)
#elif IRQ_QSPI3_TX_CAT == IRQ_CAT23
ISR(QSPI3TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI4_TX_PRIO > 0) || (IRQ_QSPI4_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI4_TX_PRIO > 0) && (IRQ_QSPI4_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI4TX_ISR, 0, IRQ_QSPI4_TX_PRIO)
#elif IRQ_QSPI4_TX_CAT == IRQ_CAT23
ISR(QSPI4TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI5_TX_PRIO > 0) || (IRQ_QSPI5_TX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI5_TX_PRIO > 0) && (IRQ_QSPI5_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI5TX_ISR, 0, IRQ_QSPI5_TX_PRIO)
#elif IRQ_QSPI5_TX_CAT == IRQ_CAT23
ISR(QSPI5TX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
}
#endif
#endif


/******************************************************************************
** Syntax : void QSPIXRX_ISR(void)                                       **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for Rx  interrupt (RX) used by QSPIx    **
**                                                                           **
*****************************************************************************/

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI0_RX_PRIO > 0) || (IRQ_QSPI0_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI0_RX_PRIO > 0) && (IRQ_QSPI0_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI0RX_ISR, 0, IRQ_QSPI0_RX_PRIO)
#elif IRQ_QSPI0_RX_CAT == IRQ_CAT23
ISR(QSPI0RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();

    /* Call QSPI0 Rx Interrupt funtion*/

  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)    
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI1_RX_PRIO > 0) || (IRQ_QSPI1_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI1_RX_PRIO > 0) && (IRQ_QSPI1_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI1RX_ISR, 0, IRQ_QSPI1_RX_PRIO)
#elif IRQ_QSPI1_RX_CAT == IRQ_CAT23
ISR(QSPI1RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  /* Call QSPI1 Rx Interrupt funtion*/                                                
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI2_RX_PRIO > 0) || (IRQ_QSPI2_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI2_RX_PRIO > 0) && (IRQ_QSPI2_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI2RX_ISR, 0, IRQ_QSPI2_RX_PRIO)
#elif IRQ_QSPI2_RX_CAT == IRQ_CAT23
ISR(QSPI2RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  /* Call QSPI2 Rx Interrupt funtion*/                                                
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI3_RX_PRIO > 0) || (IRQ_QSPI3_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI3_RX_PRIO > 0) && (IRQ_QSPI3_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI3RX_ISR, 0, IRQ_QSPI3_RX_PRIO)
#elif IRQ_QSPI3_RX_CAT == IRQ_CAT23
ISR(QSPI3RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  /* Call QSPI3 Rx Interrupt funtion*/                                                
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI4_RX_PRIO > 0) || (IRQ_QSPI4_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI4_RX_PRIO > 0) && (IRQ_QSPI4_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI4RX_ISR, 0, IRQ_QSPI4_RX_PRIO)
#elif IRQ_QSPI4_RX_CAT == IRQ_CAT23
ISR(QSPI4RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  /* Call QSPI4 Rx Interrupt funtion*/                                               
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif


#if (IFX_SAFETLIB_USED == STD_ON)
#if ((IRQ_QSPI5_RX_PRIO > 0) || (IRQ_QSPI5_RX_CAT == IRQ_CAT23))
#if ((IRQ_QSPI5_RX_PRIO > 0) && (IRQ_QSPI5_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(QSPI5RX_ISR, 0, IRQ_QSPI5_RX_PRIO)
#elif IRQ_QSPI5_RX_CAT == IRQ_CAT23
ISR(QSPI5RX_ISR)
#endif
{
  /* Enable Global Interrupts */
  Mcal_EnableAllInterrupts();
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  /* Call QSPI5 Rx Interrupt funtion*/                                                
  SafeWdgQspi_IsrTxRx();
  #endif  
}
#endif
#endif


#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_IRQ_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif



