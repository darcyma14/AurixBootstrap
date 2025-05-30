/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Irq.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x\10 $                                       **
**                                                                           **
**  $DATE       : 2014-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains initisalization of interrupt priority   **
**                and interrupt category.                                    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef  _IRQ_H
#define  _IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h SPI070: */
#include "Std_Types.h"

/* Include Irq Configuration */
#include "Irq_Cfg.h"
#include "Mcal_Options.h"

/*******************************************************************************
**                          Published parameters                              **
*******************************************************************************/
/* Irq Vendor ID */
#define IRQ_VENDOR_ID              ((uint16)17)  
/* Irq Module ID */
#define IRQ_MODULE_ID              ((uint16)255)
/* Irq Instance ID */
#define IRQ_INSTANCE_ID            ((uint16)8)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define IRQ_DMA_AVAILABLE          (0U)
#define IRQ_DMA_USED_MCALADC       (1U)
#define IRQ_DMA_USED_MCALSPI_TX    (2U)
#define IRQ_DMA_USED_MCALSPI_RX    (3U)
#define IRQ_ASCLIN_AVAILABLE       (0U)
#define IRQ_ASCLIN_USED_MCALLIN    (1U)    
#define IRQ_ASCLIN_USED_MCALSTDLIN (2U)
#define IRQ_ASCLIN_USED_MCALUART   (3U)

#define Irq_InstallInterruptHandler(priority,irq_handler)
#if defined(_TASKING_C_TRICORE_)

#if (_TASKING_C_TRICORE_ == 1U)

#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectabNum, prio) \
                    void __interrupt(prio) __vector_table(vectabNum) isr(void)
#endif

#endif /* (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)

#if (_GNU_C_TRICORE_ == 1U)
#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectabNum, prio) \
                                   IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio)
#endif

#ifndef IFX_INTERRUPT_INTERNAL
#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) \
__asm__ (".ifndef .intr.entry.include                        \n"\
    ".altmacro                                           \n"\
    ".macro .int_entry.2 intEntryLabel, name \
                                # define the section and inttab entry code \n"\
        " .pushsection .\\intEntryLabel,\"ax\",@progbits   \n"\
        " __\\intEntryLabel :                              \n"\
        "   svlcx                                        \n"\
        "   movh.a  %a14, hi:\\name                      \n"\
        "   lea     %a14, [%a14]lo:\\name                \n"\
        "   ji      %a14                                 \n"\
        " .popsection                                      \n"\
    ".endm                                               \n"\
    ".macro .int_entry.1 prio,vectabNum,u,name           \n"\
      ".int_entry.2 intvec_tc\\vectabNum\\u\\prio,(name) \
                                                  # build the unique name \n"\
    ".endm                                               \n"\
        "                                                    \n"\
    ".macro .intr.entry name,vectabNum,prio              \n"\
      ".int_entry.1 %(prio),%(vectabNum),_,name \
                               # evaluate the priority and the cpu number \n"\
    ".endm                                               \n"\
    ".intr.entry.include:                                \n"\
    ".endif                                              \n"\
        ".intr.entry "#isr","#vectabNum","#prio               );\
_IFXEXTERN_ void __attribute__ ((interrupt_handler)) isr(); \
void isr (void)
#endif /* IFX_INTERRUPT */

#endif /* (_GNU_C_TRICORE_ == 1U) */

#elif defined(_DIABDATA_C_TRICORE_)

#if (_DIABDATA_C_TRICORE_ == 1U)

#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectabNum, prio) \
                                  IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio)
#endif

#ifndef IFX_INTERRUPT_INTERNAL
#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) \
  __asm ("\t.align\t 5\n\t\
  .section .int."#prio"\n \t.sectionlink  .intvec_tc"#vectabNum"_"#prio"\n\
#$$bf\n\
__intvec_tc"#vectabNum"_"#prio":\n\
      movh.a\t %a14,"#isr"@ha\n\
      lea\t %a14,[%a14]"#isr"@l\n\
      ji\t %a14\n\
#$$ef\n\t\
  .section .intend."#prio"\n \t.sectionlink   .text");\
  __interrupt__ void isr (void)
#endif /* IFX_INTERRUPT_INTERNAL */

#endif /* (_DIABDATA_C_TRICORE_ == 1U) */
#endif

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
#if (IFX_MCAL_USED == STD_ON)
#define IRQ_START_SEC_CODE
#include "MemMap.h"
#else
#define IFX_IRQ_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if (IFX_MCAL_USED == STD_ON)
/*******************************************************************************
** Syntax :  void IrqAscLin_Init(void)                                        **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqAscLin_Init(void);

/*******************************************************************************
** Syntax :  void IrqCcu6_Init(void)                                          **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqCcu6_Init(void);

/*******************************************************************************
** Syntax :  void IrqCan_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqCan_Init(void);

/*******************************************************************************
** Syntax :  void IrqHsm_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqHsm_Init(void);

/*******************************************************************************
** Syntax :  void IrqGpt_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqGpt_Init(void);

/*******************************************************************************
** Syntax :  void IrqGtm_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqGtm_Init(void);

/*******************************************************************************
** Syntax :  void IrqGpsrGroup_Init(void)                                     **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqGpsrGroup_Init(void);

/*******************************************************************************
** Syntax :  void IrqFlexray_Init(void)                                       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for ERay                       **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqFlexray_Init(void);

/*******************************************************************************
** Syntax :  void IrqSpi_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqSpi_Init(void);

/*******************************************************************************
** Syntax :  void IrqAdc_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for various                    **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqAdc_Init(void);

/*******************************************************************************
** Syntax :  void IrqEthernet_Init(void)                                      **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for Ethernet                   **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqEthernet_Init(void);

/*******************************************************************************
** Syntax :  void IrqDma_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for DMA                        **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqDma_Init(void);
/*******************************************************************************
** Syntax :  void IrqScu_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for                            **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqScu_Init(void);

/*******************************************************************************
** Syntax :  void IrqPmu_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for                            **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/

extern void IrqPmu_Init(void);

/*******************************************************************************
** Syntax :  void IrqSent_Init(void)                                          **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for                            **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/

extern void IrqSent_Init(void);

/*******************************************************************************
** Syntax :  void IrqI2c_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for                            **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqI2c_Init(void);

extern void Irq_ClearAllInterruptFlags(void);

#endif /* (IFX_MCAL_USED == STD_ON) */

/*******************************************************************************
** Syntax :  void IrqStm_Init(void)                                           **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : To set the interrupt priority for STM                        **
**               service nodes according to priority configurartion.          **
**                                                                            **
*******************************************************************************/
extern void IrqStm_Init(void);

#if (IFX_MCAL_USED == STD_ON)
#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
#else
#define IFX_IRQ_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* IRQ_H */
