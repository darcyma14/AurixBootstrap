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
**   $FILENAME   : Adc_HwHandle.h $                                           **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2015-04-16 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - function related to Hardware access of Adc.              **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef ADC_HWHANDLE_H
#define ADC_HWHANDLE_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of sfr file */
#include "IfxVadc_reg.h"
#include "IfxSrc_reg.h"
#include "IfxScu_reg.h"
/* Inclusion of Adc.h */
#include "Adc.h"  
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
  
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Starting address of ADC register set */

#define ADC_MODULE_GLOB                      (MODULE_VADC)

#define ADC_MODULE                           (&(MODULE_VADC.G[0]))

#define ADC_MODULE_SHS                       (&(MODULE_VADC.SHS[0]))

/* ADC request source node pointer */
/* RS0 - SR0, RS1 - SR1 */ 
#define ADC_RS0_RS1_NODEPOINTER              ((uint32)0x00000010)

/* RS0 - SR0, RS1 - SR1, ADC0RS3 - CG0SR1 */ 
#define ADC_RS0_RS1_ADC0RS3_NODEPOINTER      ((uint32)0x00005010)
/* RS0 - SR0, RS1 - SR1, ADC1RS3 - SR0 */ 
#define ADC_RS0_RS1_ADC1RS3_NODEPOINTER      ((uint32)0x00000010)

/* ADC request source node pointer */
/* RS2 - SR2 of common group 0 */ 
#define ADC_RS2_NODEPOINTER                  ((uint32)0x00000000)

#if ((ADC_GROUP_EMUX_SCAN == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON) ||\
                                           (ADC_RESULT_POLLING_MODE == STD_ON))
/* Macro for disable source interrupt */
#define ADC_REQSRC_INT_DISABLE                ((uint32)0)
#endif
/* Result registers configured for WFR mode enabled, FIFO disabled,
   Result interrupt disabled, and the data reduction filter is disabled.
*/
#define ADC_RESREG_WFR_ENABLE               ((uint32)0x01000000)

/* No of kernal input class = 2 */
#define ADC_NO_KERNEL_INP_CLASS             (2U)

/* No of global input class = 2 */
#define ADC_NO_GLOB_INP_CLASS               ((uint32)2)

/* Request source event occured */
#define ADC_REQSRC0_EVENT_OCCURED           (1U)
#define ADC_REQSRC1_EVENT_OCCURED           (2U)
#define ADC_REQSRC2_EVENT_OCCURED           (1U)
#define ADC_REQSRC3_EVENT_OCCURED           (8U)

/* Reset request source data */
#define ADC_REQSRC_RESET                    (0U)

/* Write access is enabled for timer, Gate & Trigger mode */
#define ADC_WRITE_TIM_GAT_TRG_MODE_ENABLE   (0x80808000U)

/* Write access is enabled for Gate & Trigger mode */
#define ADC_WRITE_GAT_TRG_MODE_ENABLE       (0x00808000U)

/* Write access is enabled for timer mode */
#define ADC_WRITE_TIMER_MODE_ENABLE         (0x80808000U)

/* Write access is enabled for gate input selection */
#define ADC_WRITE_GATE_SEL_ENABLE           (0x00800000U)

/* Shift value to enable the request source arbitration */
#define ADC_REQ_ARB_SLOT_SHIFT              (24U)

#define ADC_XTSEL_POS                       (0x0F00U)
#define ADC_XTMODE_POS                      (0x3000U)
#define ADC_XTMODE_SHIFT_POS                (1U)
#define ADC_GTSEL_POS                       (0x000FU)
#define ADC_GTSEL_SHIFT_POS                 (16U)
#define ADC_TMEN_POS                        (0x0010U)
#define ADC_TMEN_SHIFT_POS                  (28U)
#define ADC_ERU_EDGE_SHIFT_POS              (4U)
#define ADC_ERU_UNIT_REG_CALC               (0x3U)
/* For the Queue request source, the refill bit is set */
#define ADC_QUEUE_REFILL                    ((uint32)0x00000020)

/* For the Queue request source, the request source enable bit is set */
#define ADC_QUEUE_INT_ENABLE                ((uint32)0x00000040)

/* For the Queue request source, Wait for trigger event */
#define ADC_QUEUE_WAIT_TRIGGEVENT           ((uint32)0x00000080)

/* Queue request src is triggered by SW
   ENGT = 01b, TREV = 1b 
*/
#define ADC_QUEUE_SW_TRIG                   ((uint32)0x00000201)

/* Queue request src is triggered by External trigger
   ENTR = 1b 
*/
#define ADC_QUEUE_EXT_TRIG                  ((uint32)4)

/* For the Queue request source, CLRV = 1, FLUSH = 1, ENTR = 0, CEV = 1 */
#define ADC_QUEUE_MODE_CLEAR                ((uint32)0x00000D00)

/* Scan request source for scan continuously */
#define ADC_SCAN_CONTINUOUS                 ((uint32)0x00000010)

/* Clear CRCR register  - no channels for conversion */
#define ADC_SCAN_EMPTY                      ((uint32)0)

/* Clear scan pending bits */
#define ADC_SCAN_CLR_PENDING_BITS           ((uint32)0x00000100)

/* For the Scan request source, the request source enable bit is set */
#define ADC_SCAN_INT_ENABLE                ((uint32)0x0000008)

#define ADC_GROUP_FIRST_CH_INDEX            (1U)

/* Scan request source is triggered by SW 
   ENGT = 01b, LDM = 0, LDEV = 1
*/
#define ADC_SCAN_SW_TRIG                 ((uint32)0x00000201)

/* Scan request source is triggered by External trigger 
   ENTR = 1, LDM = 0, LDEV = 0
*/
#define ADC_SCAN_EXT_TRIG                ((uint32)0x00000004)

/* Background Request source event flag clear */
#define ADC_BACKGRND_RS_EVNT_CLEAR       ((uint32)0x01010000)

/* Interrupt node enable */
#define ADC_ENABLE_INTERRUPT             (1U)

/* Interrupt node Disable */
#define ADC_DISABLE_INTERRUPT            (0U)

#define ADC_GROUP_TIMER_ENABLE           (1U)

#if (ADC_CCU6_SYNCHRONIZATION  == STD_ON)
/* Macro to enable the write control of DIVA & DIVD bit fields and 
to enable (DCMSB) ADC - CCU6 synchronization for devices with metal fix for 
cross coupling effect */
#define ADC_DIV_PARAM_WRITE_ENABLE       ((uint32)0x00008080)
#else /* (ADC_CCU6_SYNCHRONIZATION  == STD_OFF) */
/* Macro to enable the write control of DIVA & DIVD bit fields */
#define ADC_DIV_PARAM_WRITE_ENABLE       ((uint32)0x00008000)
#endif /* (ADC_CCU6_SYNCHRONIZATION  == STD_ON) */

/* Macro to enable the write control of DIVS, ANOFF & AREF bit fields */
#define ADC_SHSCFG_WRITE_ENABLE          ((uint32)0x00008000)

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/*
  Macro for no error detection
*/
#define ADC_E_DET_NO_ERR                ((uint32)0)

#endif /* ADC_DEV_ERROR_DETECT */

/* Macro for ADC Module Enable request */
#define ADC_MODULE_ENABLE               (0x00000000U)
/* EDIS bit field position */
#define ADC_EDIS_BIT_POS                (3U)
/* Macro for ADC Module Disable request */
#define ADC_MODULE_DISABLE              (0x00000003U)

#if (ADC_DEINIT_API == STD_ON)

/* RST bit value of KRST0/KRST1 */
#define ADC_KERNEL_RESET                (1U)

#endif /* (ADC_DEINIT_API == STD_ON) */

/*
  Macro indicating request source is free
  Group ID  and Group priority of the trigger source data is set with this 
  value when its free
  and Lowest Channel number is set as invalid
  Set to do nothing in ISR
*/
#define ADC_GRP_REQ_SRC_FREE             ((Adc_GroupType)0xFFFF)

#define ADC_BGND_REQ_SRC_FREE            ((uint8)0xFF)


  
#if ( ADC_INITCHECK_API == STD_ON )
/* Compare value of the init check */
#define ADC_INITCHK_COMP_VALUE  (0xFFFFFFFFU)
#endif /* ( ADC_INITCHECK_API == STD_ON ) */

#if ( ( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) ||\
        (ADC_GROUP_EMUX_SCAN == STD_ON) ||\
        (ADC_ENABLE_LIMIT_CHECK == STD_ON)\
      ) &&\
      ( (ADC_CH_EVNT_NPTR1_AVAILABLE == STD_ON) ||\
        (ADC_RES_EVNT_NPTR1_AVAILABLE == STD_ON)\
      )\
    )
    
#define ADC_CHANNELS_PER_CEVNP_REVNP      (8U)

#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Selection of Boundary bit field for Upper boundary*/
#define ADC_GRP_BOUND0              (0x0U)
/* Selection of Boundary bit field for Lower boundary*/
#define ADC_GRP_BOUND1              (0x1U)

/* Channel Event node pointer Gx SRN2 */
#define ADC_CH_EVNT_NODEPOINTER     ((uint32)0x00000002)

/* Position of the channel event node ptr*/
#define ADC_CH_NODEPOINTER_POS      (4U)

#define ADC_CHANNEL_EVENT_CLEAR     (0x000000FFU)

#define ADC_CHEVMODE_BITS           (0x3U)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/* RESULT bitfield of RES sfr */
#define ADC_RESULT_BIT              (0x0000FFFFU)
/* Bit position of RESPOS bit field */
#define ADC_RESPOS_BIT_POS          (21U)

/*ADC result interrupt enable */
#define ADC_DISABLE_RES_INTERRUPT   (0U)


/* KSELx bitfields of STEPCFG register value */
#define ADC_STEPCFG_KSEL            ((uint32)0x00003210U)

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
#define ADC_NO_SYNC_CHANNEL         (0xFFU)
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

#if ( ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE )

#define ADC_ARM_BIT_POS             (7U)
#define ADC_AREFDEF_BIT_POS         (4U)

#endif /* ( ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE ) */

#if ( ADC_ALTERNATE_REF_CH_USED == STD_OFF )

#define ADC_ARCDIS_BIT_POS          (2U)

#endif /* ( ADC_ALTERNATE_REF_CH_USED == STD_OFF ) */

#define ADC_CALMAX_BIT_POS          (24U)

#define ADC_SEN_BIT_POS             (4U)

#define ADC_GLOBAL_INPUT_CLASS      ((uint32)2)

#if ((ADC_USE_EMUX == STD_ON) || (ADC_GROUP_EMUX_SCAN == STD_ON))
/* Enable the write control of Emux cfg bit fields */
#define ADC_EMUX_CFG_WRITE_ENABLE    ((uint32)0x80000000U)
/* Steady mode Emux conversion */
#define ADC_EMUX_STEADY_MODE         ((uint32)0x04000000)
/* Single step mode Emux conversion */
#define ADC_EMUX_SINGLE_STEP_MODE    ((uint32)0x08000000)
/* Use of STCE for each conversion */
#define ADC_EMUX_STCE_EACH_CONV      ((uint32)0x20000000)
/* bit field position of EMUXCH bitfield */
#define ADC_EMUXCH_BIT_POS           ((uint32)16)

#endif /* (ADC_USE_EMUX == STD_ON || ADC_GROUP_EMUX_SCAN == STD_ON) */

#if ((ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) ||\
                                    (ADC_GROUP_EMUX_SCAN == STD_ON) \
    )

/*ADC result interrupt enable */
#define ADC_ENABLE_RES_INTERRUPT    (1U)

/* Result event node pointer programming bits in ADC RNPRx registers */
#define ADC_RESNODEPOINTER_BITFIELD (4U)

/* Group specific service request line 3 */
#define ADC_GROUP_SRN3              (3U)

#endif /* ADC using DMA for result transfer */

#if ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_TIMER_TRIGG == STD_ON))
/* Divider value for CM1 reg val */
#define ADC_TIMER_VALUE_DIV          (2U)
#define ADC_GTM_CHANNEL_INVALID      (0xFFU)

#endif /*(ADC_HW_TRIGGER_API == STD_ON && ADC_TIMER_TRIGG == STD_ON)*/

#if (ADC_GROUP_EMUX_SCAN == STD_ON)

/* DMA Related macros */
#define ADC_DMA_CH_WIDTH            (1U)

#define ADC_DMA_CH_INTCT            (2U)

/* DMA Channel Address control value */
/* DMA_ADRCR: Source address no modification, 
   INTCT = 10b, SCBE = 1b
   Destination address - DMF = 000b (1*CHDW), INCD = 1b, CBLD = 1111b
*/
#define ADC_DMA_ADR_CTR             ((uint32)0x0810F080)

/* Maximum number of kernels available for EMUX */
#define ADC_MAX_EMUX_KERNELS        (2U)
/* number of bits assigned per kernel */
#define ADC_EMUX_GROUP_BITS         (4U)
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_ERU_TRIGG == STD_ON)
/*
  Macros to define the Position of HW configuration ERU trigg parameters 
*/
#define ADC_POS_HW_CFG_ERU_UNIT      (16U)
#define ADC_POS_HW_CFG_ERU_OGU_UNIT  (28U)
#define ADC_POS_HW_CFG_ERU_SELECT    (31U)
#endif /* (ADC_ERU_TRIGG == STD_ON) */

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
#define ADC_START_SEC_CODE
#include "MemMap.h"
#if (ADC_RESULT_POLLING_MODE == STD_OFF)
/*******************************************************************************
** Syntax           : extern void Adc_lSetResetSre                            **
**                    (                                                       **
**                       uint32 AdcSreValue                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : AdcSreValue - Value to be written in SRE bit of SRC reg **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init and DeInit to initialise and        **
**                    Deinitialize the SRE bit of SRC registers               **
*******************************************************************************/
extern void Adc_lSetResetSre(uint32 AdcSreValue);
#endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           :  extern void Adc_lRSInterruptHandler                    **
**                           (uint8 AdcKernel, Adc_GroupType Group)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : ADC HW Unit ID, ADC Group ID                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Interrupt handler for any Request source                **
*******************************************************************************/
extern void Adc_lRSInterruptHandler(uint8 AdcKernel, Adc_GroupType Group);
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/*******************************************************************************
** Syntax           : extern void Adc_lAlignResultBuffer                      **
**                              (AdcKernel, Group, CurrentResBufPtr, ResVal)  **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : AdcKernel - Group HW Unit ID                            **
**                    Group - Group Id                                        **
**                    CurrentResBufPtr - Result Buffer                        **
**                    ResVal - Conversion result                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Align and Update the Group Result buffer on conversion  **
**                    complete                                                **
*******************************************************************************/
extern void Adc_lAlignResultBuffer
(
  uint8 AdcKernel, 
  Adc_GroupType Group,
  Adc_ValueGroupType *ResBufPtr, 
  uint32 ResVal
);

#if ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
                                               (ADC_HW_TRIGGER_API == STD_ON) )
/*******************************************************************************
** Syntax           : extern void Adc_lPrepareGrpForStart                     **
**                     (uint8 AdcKernel, Adc_GroupType GroupId)               **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ADC Group ID of the Kernel                              **
**                    ADC Kernel for which the Grp belongs                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for preparing all the channels of the group for **
**                    conversion                                              **
**                    Update TriggSrcData for Group Id                        **
**                    Update for Adc_AllRunningCh                             **
*******************************************************************************/
extern void Adc_lPrepareGrpForStart
(
  uint8 AdcKernel,
  Adc_GroupType GroupId
);

/*******************************************************************************
** Syntax           : extern void Adc_lClearReqSrcSfr                         **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                       uint8 GrpReqSrc                                      **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                    Rquest source in conversion                             **
**                    Adc HW Unit ID                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Group has to be stopped                  **
*******************************************************************************/
extern void Adc_lClearReqSrcSfr
(
  const Adc_GroupCfgType* GrpPtr,
  uint8 GrpReqSrc,
  uint8 AdcKernel
);

#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lStartSwConversionRS                    **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr,                      **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                    Adc HW Unit Id                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when SW trigger type Group has to be started  **
*******************************************************************************/
extern void Adc_lStartSwConversionRS
(
  const Adc_GroupCfgType* GrpPtr,
  uint8                   AdcKernel
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lStartHwConversionRS                    **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr,                      **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                    Adc HW Unit Id                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when HW trigg type Group has to be started    **
*******************************************************************************/
extern void Adc_lStartHwConversionRS
(
  const Adc_GroupCfgType* GrpPtr,
  uint8                   AdcKernel
);

#if (ADC_TIMER_TRIGG == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lGtmTimerCfg                            **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Enable Hardware                                         **
*******************************************************************************/
extern void Adc_lGtmTimerCfg(const Adc_GroupCfgType* GrpPtr);

/*******************************************************************************
** Syntax           : extern void Adc_lStopGtmTimer                           **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Disable Hardware                                        **
*******************************************************************************/
extern void Adc_lStopGtmTimer(const Adc_GroupCfgType* GrpPtr);

#endif /* ADC_TIMER_TRIGG == STD_ON */

#if (ADC_ERU_TRIGG == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lEruTrigCfg                             **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Enable Hardware                                         **
*******************************************************************************/
extern void Adc_lEruTrigCfg(uint32 HwCfgData);

/*******************************************************************************
** Syntax           : extern void Adc_lResetEruCfg                            **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Disable Hardware                                        **
*******************************************************************************/
extern void Adc_lResetEruCfg(uint32 HwCfgData);
#endif /* (ADC_ERU_TRIGG == STD_ON)*/

#if ( ADC_ERU_GATING == STD_ON )
/*******************************************************************************
** Syntax           : extern void Adc_lEruGateCfg                             **
**                    (                                                       **
**                       uint32 HwGateData                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU Gate Group has requested for         **
**                    Enable Hardware                                         **
*******************************************************************************/
extern void Adc_lEruGateCfg(uint32 HwGateData);

/*******************************************************************************
** Syntax           : extern void Adc_lResetEruGateCfg                        **
**                    (                                                       **
**                       uint32 HwGateData                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU gate Group has requested for         **
**                    Disable Hardware                                        **
*******************************************************************************/
extern void Adc_lResetEruGateCfg(uint32 HwGateData);

#endif /* ( ADC_ERU_GATING == STD_ON ) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) && \
                                   (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) )
/*******************************************************************************
** Syntax           : extern uint32 Adc_lSwConvDetCheck                       **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      uint8 AdcKernel,                                      **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    AdcKernel - Group HW Unit ID                            **
**                    Group - Group Number                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for validating the group parameters and         **
**                    reporting DET                                           **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lSwConvDetCheck
(
  uint8 ServiceId, 
  uint8 AdcKernel,
  Adc_GroupType Group
);
#endif
/*(ADC_DEV_ERROR_DETECT==STD_ON) And (ADC_ENABLE_START_STOP_GROUP_API==STD_ON)*/

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) )
/*******************************************************************************
** Syntax           : extern uint32 Adc_lValParamGrpEnableHwTrigg             **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    Group - Numeric ID of requested ADC Channel group       **
**                    AdcKernel - Group HW Unit ID                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for validating the group parameters and         **
**                    reporting DET for Enable Hardware Trigger API           **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lValParamGrpEnableHwTrigg
(uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel);
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) */

#if ( (ADC_DEINIT_API == STD_ON) && (ADC_CCU6_SYNCHRONIZATION == STD_ON) )
/*******************************************************************************
** Syntax           : extern void Adc_lCcu6DeInit                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from DeInit to deinitialise the CCU6 module   **
**                                                                            **
*******************************************************************************/
extern void Adc_lCcu6DeInit(void);
#endif /* (ADC_DEINIT_API == STD_ON) && (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteClcSfr            **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value to be written to the SFR               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write CLC SFR                        **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteClcSfr(uint32 SfrValue)
{
  volatile uint32 ReadBack;

  Mcal_ResetENDINIT();
  ADC_MODULE_GLOB.CLC.U = (unsigned_int)SfrValue;    
  Mcal_SetENDINIT();

  /* Read back the CLC register */
  ReadBack = ADC_MODULE_GLOB.CLC.U;
  /* to remove the unused param warning in GNU */
  UNUSED_PARAMETER (ReadBack)
}

#if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lDisableResultInt       **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint8 ChannelNo                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    ChannelNo: Channel Number                               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write SRGEN bite field of RCR sfr    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lDisableResultInt
(
  uint8 KernelNo,
  Adc_ChannelType ChannelNo
)
{
  ADC_MODULE[KernelNo].RCR[ChannelNo].B.SRGEN = ADC_DISABLE_RES_INTERRUPT;
}
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */

#if ( (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) || \
                                (ADC_RESULT_POLLING_MODE == STD_ON) )
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadResult           **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint8 ChannelNo                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    ChannelNo: Channel Number                               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read RESULT bit field of RES sfr     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadResult
(
  uint8 KernelNo,
  Adc_ChannelType ChannelNo
)
{
  uint32 RetValue;
  
  RetValue = ((ADC_MODULE[KernelNo].RES[ChannelNo].U) & ADC_RESULT_BIT);

  return(RetValue);
}
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_RESULT_POLLING_MODE == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadValidFlag        **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint8 ChannelNo                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    ChannelNo: Channel Number                               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read VF bit field of RES sfr         **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadValidFlag
(
  uint8 KernelNo,
  Adc_ChannelType ChannelNo
)
{
  uint32 RetValue;
  
  RetValue = (uint32)(ADC_MODULE[KernelNo].RES[ChannelNo].B.VF);

  return(RetValue);
}
#endif /* (ADC_RESULT_POLLING_MODE == STD_ON) */

#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteKernelRstSfr      **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value to be written to the SFR               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write KRST0/1 SFR                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteKernelRstSfr(uint32 SfrValue)
{
  Mcal_ResetENDINIT();
  
  ADC_MODULE_GLOB.KRST0.U = (unsigned_int)SfrValue; 
  ADC_MODULE_GLOB.KRST1.U = (unsigned_int)SfrValue; 
  
  Mcal_SetENDINIT();
}
#endif /* (ADC_DEINIT_API == STD_ON) */

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobCfgSfr        **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write GLOBCFG sfr                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobCfgSfr(uint32 SfrValue)
{
  ADC_MODULE_GLOB.GLOBCFG.U = (unsigned_int)SfrValue;
}

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobIpClassSfr    **
**                                (                                           **
**                                  uint8 RegNo,                              **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   RegNo    : Register Number                              **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write GLOBICLASS sfr                 **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobIpClassSfr
(
  uint8 RegNo,
  uint32 SfrValue
)
{
  ADC_MODULE_GLOB.GLOBICLASS[RegNo].U = (unsigned_int)SfrValue;
}

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobEvntNpSfr     **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write GLOBEVNP sfr                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobEvntNpSfr(uint32 SfrValue)
{
  ADC_MODULE_GLOB.GLOBEVNP.U = (unsigned_int)SfrValue;
}

#if (ADC_USE_EMUX == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteEmuxSelSfr        **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write EMUXSEL sfr                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteEmuxSelSfr(uint32 SfrValue)
{
  ADC_MODULE_GLOB.EMUXSEL.U = (unsigned_int)SfrValue;
}
#endif /* (ADC_USE_EMUX == STD_ON) */

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteArbCfgSfr         **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write ARBCFG sfr                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteArbCfgSfr(uint8 KernelNo, uint32 SfrValue)
{
  ADC_MODULE[KernelNo].ARBCFG.U = (unsigned_int)SfrValue;
}

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteArbPrSfr          **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write ARBPR sfr                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteArbPrSfr(uint8 KernelNo, uint32 SfrValue)
{
  ADC_MODULE[KernelNo].ARBPR.U = (unsigned_int)SfrValue;
}

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteGrpIpClassSfr     **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint8 RegNo,                              **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    RegNo    : Register Number                              **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write GxICLASS sfr                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteGrpIpClassSfr
(
  uint8 KernelNo,
  uint8 RegNo,
  uint32 SfrValue
)
{
  ADC_MODULE[KernelNo].ICLASS[RegNo].U = (unsigned_int)SfrValue;
}

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteSynCtrSfr         **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write SYNCTR sfr                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteSynCtrSfr(uint8 KernelNo, uint32 SfrValue)
{
  ADC_MODULE[KernelNo].SYNCTR.U = (unsigned_int)SfrValue;
}
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteSrcEvntNpSfr      **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write SEVNP sfr                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteSrcEvntNpSfr
(
  uint8 KernelNo, 
  uint32 SfrValue
)
{
  ADC_MODULE[KernelNo].SEVNP.U = (unsigned_int)SfrValue;
}

#if (ADC_USE_EMUX == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteEmuxCtrSfr        **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write EMUXCTR sfr                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteEmuxCtrSfr
(
  uint8 KernelNo,
  uint32 SfrValue
)
{
  ADC_MODULE[KernelNo].EMUXCTR.U = (unsigned_int)SfrValue;
}
#endif /* (ADC_USE_EMUX == STD_ON) */

/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteSrcEvntClrFlagSfr **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write SEFCLR sfr                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteSrcEvntClrFlagSfr
(
  uint8 KernelNo, 
  uint32 SfrValue
)
{
  ADC_MODULE[KernelNo].SEFCLR.U = (unsigned_int)SfrValue;
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteChEvntClrFlagSfr  **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write CEFCLR sfr                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteChEvntClrFlagSfr
(
  uint8 KernelNo, 
  uint32 SfrValue
)
{
  ADC_MODULE[KernelNo].CEFCLR.U = (unsigned_int)SfrValue;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_SAFETY_ENABLE == STD_OFF)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobEvntFlagSfr   **
**                                (                                           **
**                                  uint32 SfrValue                           **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   SfrValue : Value of the SFR to be written               **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To write GLOBEFLAG sfr                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lWriteGlobEvntFlagSfr(uint32 SfrValue)
{
  ADC_MODULE_GLOB.GLOBEFLAG.U = (unsigned_int)SfrValue;
}
#endif /* (ADC_SAFETY_ENABLE == STD_OFF) */

  
#if ( (ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC_REQSRC1 == ADC_REQSRC_USED) )
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadSrcEvntFlagSfr   **
**                                (                                           **
**                                  uint8 KernelNo,                           **
**                                  uint32 MaskValue                          **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                    MaskValue : Value of the bit field to be read           **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read SEFLAG sfr                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadSrcEvntFlagSfr
(
  uint8 KernelNo, 
  uint32 MaskValue
)
{
  uint32 RetValue;
  
  RetValue = (ADC_MODULE[KernelNo].SEFLAG.U & MaskValue);
  
  return(RetValue);
}
#endif /*(ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC_REQSRC1 == ADC_REQSRC_USED)*/

#if ( (ADC0_REQSRC2 == ADC_REQSRC_USED) || (ADC1_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC2_REQSRC2 == ADC_REQSRC_USED) || (ADC3_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC4_REQSRC2 == ADC_REQSRC_USED) || (ADC5_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC6_REQSRC2 == ADC_REQSRC_USED) || (ADC7_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC8_REQSRC2 == ADC_REQSRC_USED) || (ADC9_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC10_REQSRC2 == ADC_REQSRC_USED) )
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadGlobEvntFlagSfr  **
**                                (                                           **
**                                  uint32 MaskValue                          **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   MaskValue : Value of the SFR to be written              **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read GLOBEFLAG sfr                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadGlobEvntFlagSfr(uint32 MaskValue)
{
  uint32 RetValue;
  
  RetValue = (ADC_MODULE_GLOB.GLOBEFLAG.U & MaskValue);

  return(RetValue);
}
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadChEvntFlagSfr    **
**                                (                                           **
**                                  uint8 KernelNo                            **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read CEFLAG sfr                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadChEvntFlagSfr(uint8 KernelNo)
{
  uint32 RetValue;
  
  RetValue = (ADC_MODULE[KernelNo].CEFLAG.U);
  
  return(RetValue);
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_WAIT_ON_STOP == STD_ON)
/*******************************************************************************
** Syntax :           _IFXEXTERN_ IFX_INLINE uint32 Adc_lReadArbCfgSfr        **
**                                (                                           **
**                                  uint8 KernelNo                            **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   KernelNo : Adc Hw unit Number                           **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      uint32                                                  **
**                                                                            **
** Description :      Local function :To read ARBCFG sfr                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lReadArbCfgSfr(uint8 KernelNo)
{
  uint32 RetValue;
  
  RetValue = (ADC_MODULE[KernelNo].ARBCFG.U);
  
  return(RetValue);
}
#endif /* (ADC_WAIT_ON_STOP == STD_ON) */
  
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void Adc_lSetChEvntNodePtr       **
**                    (                                                       **
**                       uint8 AdcKernel,                                     **
**                       Adc_ChannelType IntChNum                             **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcKernel - Adc kernel id                               **
**                    IntChNum - Internal Adc channel number                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Is called when Limit check Group has to be started      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lSetChEvntNodePtr
(
  uint8 AdcKernel, 
  Adc_ChannelType IntChNum
)
{
  
#if ( ADC_CH_EVNT_NPTR1_AVAILABLE == STD_ON )
  
  if ( IntChNum >= ADC_CHANNELS_PER_CEVNP_REVNP )
  {
    ADC_MODULE[AdcKernel].CEVNP1.U = 
      (uint32)(ADC_CH_EVNT_NODEPOINTER << 
          ((IntChNum - ADC_CHANNELS_PER_CEVNP_REVNP) * ADC_CH_NODEPOINTER_POS));
  }
  else
#endif /* ( ADC_CH_EVNT_NPTR1_AVAILABLE == STD_ON ) */
  {
    ADC_MODULE[AdcKernel].CEVNP0.U = (uint32)(ADC_CH_EVNT_NODEPOINTER << 
                                         (IntChNum * ADC_CH_NODEPOINTER_POS));
   
  }
     
} /* Adc_lSetChEvntNodePtr */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_RESULT_POLLING_MODE == STD_OFF)
#if ( ( ADC_GROUP_EMUX_SCAN == STD_ON ) || \
                         (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) )
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void Adc_lSetResEventNode        **
**                    (                                                       **
**                       uint8 AdcKernel,                                     **
**                       uint32 IntChNr                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcKernel - Adc kernels number                          **
**                    IntChNr - Analog channel number                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Set the Result event node pointer          **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lSetResEventNode
(
  uint8 AdcKernel, 
  uint32 IntChNr
)
{
  #if ( ADC_RES_EVNT_NPTR1_AVAILABLE == STD_ON )
  
  if ( IntChNr >= ADC_CHANNELS_PER_CEVNP_REVNP )
  {
    ADC_MODULE[AdcKernel].REVNP1.U =
           (unsigned_int)( (uint32)ADC_GROUP_SRN3 << 
                             ((uint32)ADC_RESNODEPOINTER_BITFIELD * 
                               (uint32)(IntChNr - ADC_CHANNELS_PER_CEVNP_REVNP))
                         );
  }
  else
  #endif /* ( ADC_RES_EVNT_NPTR1_AVAILABLE == STD_ON ) */
  {
    ADC_MODULE[AdcKernel].REVNP0.U =
         (unsigned_int)( (uint32)ADC_GROUP_SRN3 << 
                         ((uint32)ADC_RESNODEPOINTER_BITFIELD * (uint32)IntChNr)
                       );
  }
  
} /* Adc_lSetResEventNode */

#endif 
/*(ADC_GROUP_EMUX_SCAN)or(ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
#endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */


#define ADC_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ADC_HWHANDLE_H */

