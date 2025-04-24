/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart.c $                                                   **
**                                                                           **
**  $CC VERSION : \main\50 $                                                 **
**                                                                           **
**  $DATE       : 2015-04-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of UART driver                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
   Traceability   : [cover parentID= 
   SAS_NAS_ALL_PR748,SAS_NAS_ALL_PR749,
   SAS_NAS_ALL_PR102,SAS_NAS_ALL_PR470,SAS_NAS_ALL_PR471,
   SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652]
   [/cover]
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of sfr file */
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"

/* Own header file, this includes own configuration file also */
/* Inclusion structure */
#include "Uart.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef UART_SW_MAJOR_VERSION
  #error "UART_SW_MAJOR_VERSION is not defined."
#endif

#ifndef UART_SW_MINOR_VERSION
  #error "UART_SW_MINOR_VERSION is not defined."
#endif

#ifndef UART_SW_PATCH_VERSION
  #error "UART_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( UART_SW_MAJOR_VERSION != 1U )
  #error "UART_SW_MAJOR_VERSION does not match."
#endif
#if ( UART_SW_MINOR_VERSION != 2U )
  #error "UART_SW_MINOR_VERSION does not match."
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ASCLIN Register Start Address Mapping */
#define UART_HW_MODULE                    (&MODULE_ASCLIN0)

#define UART_CSRREG_CLKSEL_NOCLK          (0U)  /* No Clock  */
#define UART_FRAMECONREG_INIT_MODE        (0U)  /* ASCLIN INIT mode */
#define UART_FRAMECONREG_ASC_MODE         (1U)  /* ASCLIN UART mode */
#define UART_CSRREG_CLKSEL_CLC            (8U)  /* Clk source = fASCLINF */

/* Digital Glitch Filter Disabled */
#define UART_IOCRREG_DEPTH_VAL            (0U) 
                                          
#define UART_BITCONREG_SM_VAL             (1U) 

#define UART_ENABLE_BIT                   (1U)
#define UART_DISABLE_BIT                  (0U)

#define UART_INVALID_CHANNEL              (0xFFU)

/* Configure Inlet width and outlet width for FIFO 
depending on the Datalength configured for the Channels */

#if (UART_NINEBITS_USED == STD_ON)
#define UART_TXFIFOCONREG_INW_VAL         (2U)
#define UART_RXFIFOCONREG_OUTW_VAL        (2U)
#define UART_STEPSIZE                     (2U)
#else 
#define UART_TXFIFOCONREG_INW_VAL         (1U)
#define UART_RXFIFOCONREG_OUTW_VAL        (1U)
#define UART_STEPSIZE                     (1U)
#endif

#define UART_ZERO_U                       (0U)
#define UART_ONE_U                        (1U)

#define UART_BIT_RESET                    (0U)
#define UART_BIT_SET                      (1U)

#define UART_TX_LOCK_IDX                  (0U)
#define UART_RX_LOCK_IDX                  (1U)

#define UART_NINEBIT_DATLEN               (9U)

/*Rx FIFO Buffer Int level is set to Store 16 bytes*/
#define UART_RX_FIFO_INT_LEVEL_VAL        (15U) 

/* SRC register for ASCLIN are offset by a below value  0x0C div 4 */
#define UART_SRC_ADDROFFSET               (0x03U)

/* Disable ASCLIN Module clock */
#define UART_DISABLE_ASCLIN_MODULE        (0x00000001U)     

#define UART_TIMEOUT_DURATION             (0xFFU)
            
#define UART_KRST_TIMEOUT                 (0x100U)

/* SRC register addresses */
#define UART_SRC_ASCLIN0TXADDR  ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0TX))
#define UART_SRC_ASCLIN0RXADDR  ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0RX))
#define UART_SRC_ASCLIN0ERRADDR ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0ERR))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
*                     Private Function Declarations                            *
*******************************************************************************/

IFX_LOCAL_INLINE void Uart_lHwInitClcReg(uint8 HwUnit, uint32 Value);

#if (UART_RESET_SFR_INIT == STD_ON)
IFX_LOCAL_INLINE void Uart_lHwInitKernelReg(uint8 HwUnit);
#endif

static void Uart_lHwInit(uint8 HwUnit,const Uart_ChannelType* ChannelConfigPtr);
static void Uart_lRead(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel);
static void Uart_lWrite(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel);

static void Uart_lEnableReadInterrupts(Ifx_ASCLIN* HwModulePtr);
static void Uart_lEnableWriteInterrupts(Ifx_ASCLIN* HwModulePtr);

/* Functions to clear flags for read and write functions */
static void Uart_lClearWriteInterrupts(Ifx_ASCLIN* HwModulePtr);
static void Uart_lClearReadInterrupts(Ifx_ASCLIN* HwModulePtr);

#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_ReturnType Uart_lChannelCheck( \
                             Uart_ChannelIdType Channel,uint8 ApiId);
#endif

/* Functions to enable SRE bit of curresponding hardware*/
static void  Uart_lHwEnableAscLinTxIntr(volatile uint8 HwUnit);
static void  Uart_lHwEnableAscLinRxIntr(volatile uint8 HwUnit);
static void  Uart_lHwEnableAscLinErrIntr(volatile uint8 HwUnit);

/* Functions to disable SRE bit of curresponding hardware*/
static void  Uart_lHwDisableAscLinTxIntr(volatile uint8 HwUnit);
static void  Uart_lHwDisableAscLinRxIntr(volatile uint8 HwUnit);
static void  Uart_lHwDisableAscLinErrIntr(volatile uint8 HwUnit);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (UART_PB_FIXEDADDR == STD_ON)

#define UART_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* UART Config Set Pointer */
static const Uart_ConfigType* const Uart_kConfigPtr = &Uart_ConfigRoot[0];

#define UART_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif /*(UART_PB_FIXEDADDR == STD_ON)*/


#if (UART_PB_FIXEDADDR == STD_OFF)

#define UART_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Uart_ConfigType* Uart_kConfigPtr;

#define UART_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif /*(UART_PB_FIXEDADDR == OFF)*/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*[cover parentID=DS_NAS_UART_PR115]Global and Static variable[/cover]*/

#define UART_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* Mapping of ASCLIN HW Units Used to the respective logical UART Channel Ids*/
static Uart_ChannelIdType Uart_BusChannelMap[UART_MAX_HW_UNIT]= \
{UART_INVALID_CHANNEL};

/* Variable used to check Uart Initialization Status */
#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_StateType Uart_InitStatus = UART_UNINITIALISED;
#endif

#define UART_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


#define UART_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (UART_DEBUG_SUPPORT == STD_ON)
/*IFX_MISRA_RULE_08_10_STATUS=Variable Uart_ChannelInfo is declared as
 extern in Uart_Dbg.h, which will be included application for
 debugging*/
Uart_ChannelInfoType  Uart_ChannelInfo[UART_MAXIMUM_CHANNEL];
#else
static Uart_ChannelInfoType Uart_ChannelInfo[UART_MAXIMUM_CHANNEL];
#endif

#define UART_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define UART_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*Resource Protection Flags for UART Channel Resource(using binary semaphore)*/
static uint32 Uart_ChLock[2][UART_MAXIMUM_CHANNEL];

#ifdef IFX_UART_DEBUG
extern volatile uint32 TestUart_DebugMask01;
#endif

#define UART_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*Memory Map of the UART Code*/
#define UART_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1569,DS_NAS_HE2_UART_PR3018,  **
**                DS_NAS_EP_UART_PR3018][/cover]                              **
**                                                                            **
** Syntax : void Uart_Init( const Uart_ConfigType* ConfigPtr )                **
**    [/cover]                                                                **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to Uart driver configuration set    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function.                       **
** Service for UART initialization. The Initialization function shall         **
** initialize all common relevant registers of UART channels with the values  **
** of the structure referenced by the parameter ConfigPtr.                    **
*******************************************************************************/
void Uart_Init(const Uart_ConfigType* ConfigPtr)
{
  const Uart_ChannelType   *ChannelConfigPtr;
  uint8 ModuleNo;
  uint8 Chan;
  uint8 MaxChannel;
  
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ReturnStatus;
  ReturnStatus = E_OK;
  #endif
 
  #if (UART_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
   #if (UART_PB_FIXEDADDR == STD_OFF)
   if (ConfigPtr == NULL_PTR)
   {
     /* If the config pointer is equal to null pointer report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_PARAM_POINTER
                    );
     ReturnStatus = E_NOT_OK;
   }
   #else
   if (Uart_kConfigPtr != ConfigPtr)
   {
     /* In case of PB Fixed address if the Uart_kConfigPtr not equal to 
     ConfigPtr then report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_INVALID_POINTER
                    );
     ReturnStatus = E_NOT_OK;
   }
   #endif/*(UART_PB_FIXEDADDR == STD_ON)*/
 
   else if (Uart_InitStatus == UART_INITIALISED)
   {
     /* If Uart is already initialsed then report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_STATE_TRANSITION
                    );
     ReturnStatus = E_NOT_OK;
   }
   else
   {
     /* Do Nothing */
   }
  #endif  /* (UART_DEV_ERROR_DETECT == STD_ON) */
 
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    MaxChannel = ConfigPtr->NoOfChannels;
 
    /* Enable the ASCLIN hardware unit/s for all the  channels */
    for (Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(ConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the hwmodule */
      ModuleNo = ChannelConfigPtr->HwModule;
      /* Enable the ASCLIN module and also set the EDIS bit (Sleep setting) */
      Uart_lHwInitClcReg(ModuleNo, UART_ASCLIN_CLC);

      #if (UART_RESET_SFR_INIT == STD_ON)
      /* Reset ASCLIN Kernel  */
      Uart_lHwInitKernelReg(ModuleNo);
      #endif      
      
    }
    
    for(Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(ConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the Hw module */
      ModuleNo = ChannelConfigPtr->HwModule;
      /* Initialise the Uart Hardware. */
      Uart_lHwInit(ModuleNo, ChannelConfigPtr );
 
      /* Initialize the ChannelInfo containig UART Channel to HW Unit Mapping*/
      Uart_ChannelInfo[Chan].Uart_AssignedHW = ModuleNo;
 
      /* Init Uart_BusChannelMap Array */
      Uart_BusChannelMap[ModuleNo] = Chan;
 
      /* Init UART Channel Tx and Rx State variables */
      Uart_ChannelInfo[Chan].Uart_TxState = UART_INITIALISED;
      Uart_ChannelInfo[Chan].Uart_RxState = UART_INITIALISED;
 
      /* Init Uart Channel Tx/Rx Resource Lock */
      Uart_ChLock[UART_TX_LOCK_IDX][Chan] = UART_ZERO_U;
      Uart_ChLock[UART_RX_LOCK_IDX][Chan] = UART_ZERO_U;
    }
 
    /* Store ConfigPtr for use by APIs*/
    #if (UART_PB_FIXEDADDR == STD_OFF)
    Uart_kConfigPtr = ConfigPtr;
    #endif    /*(UART_PB_FIXEDADDR == OFF)*/
 
    #if (UART_DEV_ERROR_DETECT == STD_ON)
     /* Store UART driver initailization status */
    Uart_InitStatus = UART_INITIALISED;
    #endif/*(UART_DEV_ERROR_DETECT == STD_ON)*/
   }
  return ;
}

#if (UART_RESET_SFR_INIT == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Uart_lHwInitKernelReg             **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function resets the Kernel                         **
*******************************************************************************/
IFX_LOCAL_INLINE void Uart_lHwInitKernelReg(uint8 HwUnit)
{
   volatile uint32 Readback;
   uint32 WaitCount,RstStatus;
   
  WaitCount = UART_KRST_TIMEOUT; 
  /* Reset End Init Protection to access regsiters */
  Mcal_ResetENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLINKernels.*/
  UART_HW_MODULE[HwUnit].KRST0.B.RST = UART_ENABLE_BIT;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_HW_MODULE[HwUnit].KRST0.U ;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_HW_MODULE[HwUnit].KRST1.B.RST = UART_ENABLE_BIT;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_HW_MODULE[HwUnit].KRST1.U ;  
  /* Set End Init Protection */
  Mcal_SetENDINIT();
  do
  {
   WaitCount--;
   #ifdef IFX_UART_DEBUG
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
   RstStatus = UART_HW_MODULE[HwUnit].KRST0.B.RSTSTAT & TestUart_DebugMask01;
   #else
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
   RstStatus = UART_HW_MODULE[HwUnit].KRST0.B.RSTSTAT;
   #endif
  }  
  while ((RstStatus == 0U) && (WaitCount > 0U));
  /* Reset End Init Protection to access regsiters */
  Mcal_ResetENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_HW_MODULE[HwUnit].KRSTCLR.B.CLR = UART_ENABLE_BIT;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_HW_MODULE[HwUnit].KRSTCLR.U ;  
  /* Set End Init Protection */
  Mcal_SetENDINIT();
    
  UNUSED_PARAMETER(Readback)

}
#endif

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Uart_lHwInitClcReg                **
**                      (uint8 HwUnit, uint32 Value)                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function sets the clc register with given value    **
*******************************************************************************/
IFX_LOCAL_INLINE void Uart_lHwInitClcReg(uint8 HwUnit, uint32 Value)
{
  volatile uint32 ReadBack;
  
  /* Reset End Init Protection */
  Mcal_ResetENDINIT();

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  UART_HW_MODULE[HwUnit].CLC.U = Value;
 
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  ReadBack = (uint32)UART_HW_MODULE[HwUnit].CLC.U;
  
  /* Set End Init Protection */
  Mcal_SetENDINIT();

  UNUSED_PARAMETER (ReadBack)     
}
/*******************************************************************************
** Traceability :                                                             **
** Syntax           : static void Uart_lHwInit                                **
**                     (uint8 HwUnit,Uart_ChannelConfigType* ChannelConfigPtr)**
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                ChannelConfigPtr : Channel configuration pointer            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initialises the ASCLIN Hw module          **
*******************************************************************************/
static void Uart_lHwInit(uint8 HwUnit,const Uart_ChannelType* ChannelConfigPtr)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 TimeOutCount = UART_TIMEOUT_DURATION;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  HwModulePtr = &(UART_HW_MODULE[HwUnit]);

  /* Disable the Input Clock source */
  HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_NOCLK;
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /* Wait TW or poll for CSR.CON = 0 */
  while ((HwModulePtr->CSR.B.CON != UART_BIT_RESET) && (TimeOutCount > 0U)) 
  {
    TimeOutCount-- ;
  } 

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* Change to INIT mode */
  HwModulePtr->FRAMECON.B.MODE = UART_FRAMECONREG_INIT_MODE;
  /* Connect the Clock source */
  HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_CLC;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((HwModulePtr->CSR.B.CON != UART_BIT_SET) && (TimeOutCount > 0U)) 
  {
     TimeOutCount-- ;
  } 

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* Disable the Clock source. */
  HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_NOCLK;
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 0*/
  while ((HwModulePtr->CSR.B.CON != UART_BIT_RESET) && (TimeOutCount > 0U)) 
  {
     TimeOutCount-- ;
  } 
  /* Change to ASC mode */
  HwModulePtr->FRAMECON.B.MODE = UART_FRAMECONREG_ASC_MODE;

  /* Configure the Baudrate parameters */
  HwModulePtr->BRG.B.NUMERATOR = ChannelConfigPtr->HwBrgNumerator;
  HwModulePtr->BRG.B.DENOMINATOR = ChannelConfigPtr->HwBrgDenominator;
  HwModulePtr->BITCON.B.PRESCALER = ChannelConfigPtr->HwBitconPrescalar;
  HwModulePtr->BITCON.B.OVERSAMPLING = ChannelConfigPtr->HwBitconOversampling;

  /* Digital Glitch Filter = OFF */
  HwModulePtr->IOCR.B.DEPTH = UART_IOCRREG_DEPTH_VAL;

  /* Configure CTS */
  HwModulePtr->IOCR.B.CTSEN = ChannelConfigPtr->CtsEnable;
  HwModulePtr->IOCR.B.RCPOL = ChannelConfigPtr->CtsPolarity;
  
  /* Configure Sample mode(3 Bit), Sample point, Parity, Collision detection */
  HwModulePtr->BITCON.B.SM = UART_BITCONREG_SM_VAL;
  HwModulePtr->BITCON.B.SAMPLEPOINT = \
           (((ChannelConfigPtr->HwBitconOversampling)>>UART_ONE_U)+UART_ONE_U);
 
  HwModulePtr->FRAMECON.B.PEN = ChannelConfigPtr->ParityEnable;
  HwModulePtr->FRAMECON.B.ODD = ChannelConfigPtr->Parity;
  HwModulePtr->FRAMECON.B.IDLE = UART_BIT_SET;

  HwModulePtr->FRAMECON.B.STOP = ChannelConfigPtr->StopBits;

  /* Configure RX inlet, TX outlet width/s(8/16 bit) based on UartDataLength*/
  HwModulePtr->TXFIFOCON.B.INW = UART_TXFIFOCONREG_INW_VAL;
  HwModulePtr->RXFIFOCON.B.OUTW = UART_RXFIFOCONREG_OUTW_VAL;

  /*Data length Defines the number of bits in a character*/
  HwModulePtr->DATCON.B.DATLEN =  ChannelConfigPtr->DataLength - UART_ONE_U;

  HwModulePtr->IOCR.B.LB = UART_DISABLE_BIT;
  HwModulePtr->IOCR.B.ALTI =  ChannelConfigPtr->RxPinSelection; 
  
  /* Select the Clock source */
  HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_CLC;

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((HwModulePtr->CSR.B.CON != UART_BIT_SET) && (TimeOutCount > 0U)) 
  {
     TimeOutCount-- ;
  } 
}
#if (UART_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1570]                         **
** 
** Syntax : void Uart_DeInit( void )                                          **
**          [/cover]                                                          **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module DeInitialization function.                     **
** Service for UART de initialization.                                        **
*******************************************************************************/
void Uart_DeInit(void)
{
  Ifx_ASCLIN*  HwModulePtr;
  const Uart_ChannelType   *ChannelConfigPtr;
  uint32 TimeOutCount = UART_TIMEOUT_DURATION;
  uint8 ModuleNo;
  uint8 Chan;
  uint8 MaxChannel;
 
  #if (UART_DEV_ERROR_DETECT == STD_ON)
   Std_ReturnType ReturnStatus;
   ReturnStatus = E_OK;
  #endif
 
  #if (UART_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
  if (Uart_InitStatus == UART_UNINITIALISED)
   {
     /* If Uart is already unintialised Report to  DET */
     Det_ReportError(
                      UART_MODULE_ID,
                      UART_MODULE_INSTANCE,
                      UART_SID_DEINIT,
                      UART_E_UNINIT
                     );
     ReturnStatus = E_NOT_OK;
   }
  #endif  /* (_DEV_ERROR_DETECT == STD_ON) */
 
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    MaxChannel = Uart_kConfigPtr->NoOfChannels;
    
    for (Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the Hw module */
      ModuleNo = ChannelConfigPtr->HwModule;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       UART_HW_MODULE to access the SFRs of a particular HW Unit*/
      HwModulePtr = &(UART_HW_MODULE[ModuleNo]);
 
      /* Disable the Clock source */
      HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_NOCLK;
 
      TimeOutCount = UART_TIMEOUT_DURATION;
      /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
      /*Wait TW or poll for CSR.CON = 0*/
      while ((HwModulePtr->CSR.B.CON != UART_BIT_RESET) && (TimeOutCount > 0U)) 
      {
        TimeOutCount-- ;
      } 
      
      /* Change to  INIT mode */
      HwModulePtr->FRAMECON.B.MODE = UART_FRAMECONREG_INIT_MODE;
      /* Connect the Clock source */
      HwModulePtr->CSR.B.CLKSEL = UART_CSRREG_CLKSEL_CLC;
      
      TimeOutCount = UART_TIMEOUT_DURATION;
      /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
      /* Wait TW or poll for CSR.CON = 1 */
      while ((HwModulePtr->CSR.B.CON != UART_BIT_SET) && (TimeOutCount > 0U)) 
      {
        TimeOutCount-- ;
      } 
      
      /* Init the Uart_BusChannelMap Array */
      Uart_BusChannelMap[ModuleNo] = UART_INVALID_CHANNEL;
  
      /* Reset the channel Info*/
      Uart_ChannelInfo[Chan].Uart_TxState = UART_UNINITIALISED;
      Uart_ChannelInfo[Chan].Uart_RxState = UART_UNINITIALISED;
      Uart_ChannelInfo[Chan].Uart_TxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_RxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TotalDataTxd= UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TotalDataRxd= UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TxBuffPtr = NULL_PTR;
      Uart_ChannelInfo[Chan].Uart_RxBuffPtr = NULL_PTR;
      Uart_ChannelInfo[Chan].Uart_TxDataCopyCntr = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_AssignedHW = UART_INVALID_CHANNEL;
      
      /* Reset the Uart Channel Tx/Rx Resource Lock */
      Uart_ChLock[UART_TX_LOCK_IDX][Chan] = UART_ZERO_U;
      Uart_ChLock[UART_RX_LOCK_IDX][Chan] = UART_ZERO_U;
 
      /* Clear the read and write Interrupts*/
      Uart_lClearReadInterrupts(HwModulePtr);
      Uart_lClearWriteInterrupts(HwModulePtr);
 
      /* Disable Tx,Rx and Err Interrupts*/
      Uart_lHwDisableAscLinTxIntr(ModuleNo);
      Uart_lHwDisableAscLinRxIntr(ModuleNo);
      Uart_lHwDisableAscLinErrIntr(ModuleNo);
    }
 
    /* Reset End Init Protection to access regsiters */
    Mcal_ResetENDINIT();
    
    /* Disable the ASCLIN hardware unit/s for all the  channels */
    for (Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the hwmodule */
      ModuleNo = ChannelConfigPtr->HwModule;
      /* Disable the ASCLIN module */
      Uart_lHwInitClcReg(ModuleNo, UART_DISABLE_ASCLIN_MODULE);
    }
    /* Set End Init Protection */
    Mcal_SetENDINIT();
 
    #if (UART_DEV_ERROR_DETECT == STD_ON)
     /* Store UART driver initailization status */
    Uart_InitStatus = UART_UNINITIALISED;
    #endif/*(UART_DEV_ERROR_DETECT == STD_ON)*/
  }
  return ;
}
#endif
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1571]
**
** Syntax : Uart_ReturnType Uart_Read                                         **
**  (                                                                         **
**    Uart_ChannelIdType channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                    [/cover]                                                **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant(Not for same channel)                               **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed .                  **
**                  MemPtr - Pointer to location where data needs to be stored**
**                  Size - No of data that needs to be recieved               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Read operation was initiaited successfully     **
**                   UART_NOT_OK - Read operation couldn't be initiated       **
**                   due to developement errors                               **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                   read operation                                           **
**                                                                            **
** Description : Api to configure the given UART Channel for reception of the **
**       specified number of data bytes and the memory location (App Rx Buff) **
**        to be used to store the received data                               **
*******************************************************************************/

Uart_ReturnType Uart_Read \
         (Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size)
{
  Ifx_ASCLIN*  HwModulePtr;
  Uart_ReturnType Retvalue = UART_OK;
  uint8 HwUnit;
  uint8 TempIntLevel;
 
 #if (UART_DEV_ERROR_DETECT != STD_ON)
  uint32 ChRxLock;
 #endif
  
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /*If Uart is not initialised then  Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
  }
  else if (MemPtr == NULL_PTR)
  {
    /*If memory pointer is equal to null pointer Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_PARAM_POINTER
                   );
    Retvalue = UART_NOT_OK;
  }
  else if (Size == UART_ZERO_U )
  {
    /* If the size is equal to zero Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_INVALID_SIZE
                   );
    Retvalue = UART_NOT_OK;
  }
  else
  { 
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_READ);
 
    if (Retvalue == UART_OK)
    {
      /* If the channel is busy then Report to DET */
      if (Uart_ChannelInfo[Channel].Uart_RxState != UART_INITIALISED)
      {
        /*If channel is busy then Report to  DET */
        Det_ReportError(
                        UART_MODULE_ID,
                        UART_MODULE_INSTANCE,
                        UART_SID_READ,
                        UART_E_STATE_TRANSITION
                        );
        Retvalue = UART_IS_BUSY;
      }
    } 
  }
  #endif
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Retvalue == UART_OK)
  #else
   /* The Uart Read operation is already started for the channel. No other
      operation can be started on this Channel. This is implemented using a 
      binary semaphore mechanism */
   ChRxLock = Mcal_LockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);
 
   /* No other Uart Read operation is in progress on the same Channel */
   if (ChRxLock == MCAL_RESOURCE_BUSY)
   {
        Retvalue = UART_IS_BUSY;
   }
   else
  #endif
  {
    /* Update Uart_ChannelInfo for Read Operation */
    Uart_ChannelInfo[Channel].Uart_RxState= UART_OPERATION_IN_PROGRESS;
    Uart_ChannelInfo[Channel].Uart_RxBuffPtr= MemPtr;
    Uart_ChannelInfo[Channel].Uart_RxDataLeft = Size;
    Uart_ChannelInfo[Channel].Uart_TotalDataRxd =UART_ZERO_U;
 
    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);
    
    /* Configure RX Outlet Width */
    HwModulePtr->RXFIFOCON.B.OUTW = UART_RXFIFOCONREG_OUTW_VAL;
    
    if(Uart_ChannelInfo[Channel].Uart_RxDataLeft < UART_BUFFER_SIZE)
    {
      /*Set RX FIFO Interrupt level according to Uart Size*/
      TempIntLevel = (uint8)Uart_ChannelInfo[Channel].Uart_RxDataLeft \
                                  - (uint8)(UART_ONE_U);
      HwModulePtr->RXFIFOCON.B.INTLEVEL = TempIntLevel ;
    }
    else
    {
      /*Set RX FIFO Interrupt level to RX FIFO level*/
      HwModulePtr->RXFIFOCON.B.INTLEVEL = UART_RX_FIFO_INT_LEVEL_VAL;
    }
    
     /*Flush the Rx FIFO*/
    HwModulePtr->RXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
 
    /*Enable Rx(RxFIFO level) and Err(Parity,framing,rx underflow) Interrupts*/
    Uart_lEnableReadInterrupts(HwModulePtr);
 
     /*Enable Error and Rx Interrupts*/
    Uart_lHwEnableAscLinRxIntr(HwUnit);
    Uart_lHwEnableAscLinErrIntr(HwUnit);
 
     /*Enable Receiver and filling of RxFIFO*/
    HwModulePtr->RXFIFOCON.B.ENI = UART_ONE_U;
  }
  return Retvalue;
}


/*******************************************************************************
** Syntax : static void Uart_lRead                                            **
**  (                                                                         **
**    Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel                      **
**  )                                                                         **
**                                                                            **
** Service ID: NA                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:   Reentrant(Not for same channel)                              **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : local function to copy the data from the RX FIFO buffer to   **
**               the user specified memory location(App Buffer)               **
*******************************************************************************/
static void Uart_lRead(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel)
{
  Uart_MemPtrType BuffPtr;
  uint16 Read_Count;
  uint8 TempIntLevel;
  uint8 UartDatalen;
  
  BuffPtr =  Uart_ChannelInfo[Channel].Uart_RxBuffPtr;
  
  if (Uart_ChannelInfo[Channel].Uart_RxDataLeft <= UART_BUFFER_SIZE)
  {
    /*Set Read byte Count equal to the amount of data Remaining */
    Read_Count = Uart_ChannelInfo[Channel].Uart_RxDataLeft;
  }
  else
  {
    /*Set Read byte Count equal to RX FIFO Buffer Size*/
    Read_Count = UART_BUFFER_SIZE;
  }
 
  while (Read_Count > UART_ZERO_U)
  { 
    UartDatalen = (uint8) HwModulePtr->DATCON.B.DATLEN + UART_ONE_U;
   
    /*Check if the data to be read is the last one and datalen is 7/8*/
    if ((Uart_ChannelInfo[Channel].Uart_RxDataLeft == UART_ONE_U) && \
                            (UartDatalen != UART_NINEBIT_DATLEN))
    {
      HwModulePtr->RXFIFOCON.B.OUTW = UART_ONE_U;
      
      *BuffPtr = (Uart_MemType)HwModulePtr->RXDATA.U;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
        BuffPtr to access next element of Application Data Buffer*/
      BuffPtr++;
      
      /*Complete data is copied so set the Rx FIFO Interrupt level to Zero*/
      HwModulePtr->RXFIFOCON.B.INTLEVEL = UART_ZERO_U;
 
      /*Complete data is copied so set Read count to Zero*/
      Read_Count = UART_ZERO_U;
      
      Uart_ChannelInfo[Channel].Uart_RxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Channel].Uart_TotalDataRxd += UART_ONE_U;
    }
    else
    {
      *BuffPtr = (Uart_MemType)HwModulePtr->RXDATA.U;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
        BuffPtr to access next element of Application Data Buffer*/
      BuffPtr++;
      
      /*Reduce the Read count by step size(i.e. One Data Count)*/
      Read_Count = Read_Count - UART_STEPSIZE;
      /*Update Uart_ChannelInfo for total data received and data
       bytes remaining to be received*/
      Uart_ChannelInfo[Channel].Uart_RxDataLeft -= UART_STEPSIZE;
      Uart_ChannelInfo[Channel].Uart_TotalDataRxd += UART_STEPSIZE;
    }
  }
  
  if(Uart_ChannelInfo[Channel].Uart_RxDataLeft < UART_BUFFER_SIZE)
  {
    if (Uart_ChannelInfo[Channel].Uart_RxDataLeft > UART_ZERO_U)
    {
      /*Set RX FIFO Interrupt level according to the amount of data remainig*/
      TempIntLevel = (uint8)Uart_ChannelInfo[Channel].Uart_RxDataLeft \
                                                  - ((uint8)UART_ONE_U);
      HwModulePtr->RXFIFOCON.B.INTLEVEL = (uint8)TempIntLevel;
    }
    else
    {
     /* Do Nothing */
    }
  }
  else
  {
    /*Set the RX FIFO Interrupt level to RX FIFO Buffer Size*/
    HwModulePtr->RXFIFOCON.B.INTLEVEL = UART_RX_FIFO_INT_LEVEL_VAL;
  }
    /*Update Uart_ChannelInfo for Memptr*/
  Uart_ChannelInfo[Channel].Uart_RxBuffPtr = BuffPtr;
  return ;
}


/*******************************************************************************
** Syntax : static void Uart_lEnableReadInterrupts (Ifx_ASCLIN* HwModulePtr)  **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Enable Rx and Err Interrupts in read fnt   **
**                                                                            **
*******************************************************************************/
static void Uart_lEnableReadInterrupts(Ifx_ASCLIN* HwModulePtr)
{
  /*Enable Parity, Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
  HwModulePtr->FLAGSENABLE.B.PEE = UART_ENABLE_BIT;   

  HwModulePtr->FLAGSENABLE.B.FEE = UART_ENABLE_BIT;   

  HwModulePtr->FLAGSENABLE.B.RFLE = UART_ENABLE_BIT;

  HwModulePtr->FLAGSENABLE.B.RFUE = UART_ENABLE_BIT;
}
  
/*******************************************************************************
** Syntax : static void Uart_lClearReadInterrupts (Ifx_ASCLIN* HwModulePtr)   **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Disable  Rx and Err Interrupts in read fnt **
**                                                                            **
*******************************************************************************/
static void Uart_lClearReadInterrupts(Ifx_ASCLIN* HwModulePtr)
{
  /*Clear Parity,Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
  HwModulePtr->FLAGSCLEAR.B.PEC = UART_ENABLE_BIT;  

  HwModulePtr->FLAGSCLEAR.B.FEC = UART_ENABLE_BIT;  

  HwModulePtr->FLAGSCLEAR.B.RFLC = UART_ENABLE_BIT;

  HwModulePtr->FLAGSCLEAR.B.RFUC = UART_ENABLE_BIT;
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1572]                         **
** Syntax : Uart_ReturnType Uart_Write                                        **
**  (                                                                         **
**    Uart_ChannelIdType channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                    [/cover]                                                **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  MemPtr - Pointer to location where transmit data is stored**
**                  Size - No. of data bytes that needs to be transmitted     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Write operation was initiaited successfully    **
**                   UART_NOT_OK - Write operation couldn't performed         **
**                                 due to developement error                  **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                                  write operation                           **
**                                                                            **
** Description : Api to transmit data from user memory location(App Buffer)   **
**               on to the given channel                                      **
**                                                                            **
*******************************************************************************/
Uart_ReturnType Uart_Write\
          (Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size)
{
  const Uart_ChannelType *ChannelConfigPtr;
  Ifx_ASCLIN* HwModulePtr;
  Uart_ReturnType Retvalue = UART_OK;
  uint8 HwUnit;
 
 #if (UART_DEV_ERROR_DETECT != STD_ON)
  uint32 ChTxLock;
 #endif
  
   #if (UART_DEV_ERROR_DETECT == STD_ON)
 
   if (Uart_InitStatus == UART_UNINITIALISED)
   {
     /* If Uart is not initialised then report the DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_UNINIT
                    );
     Retvalue = UART_NOT_OK;
   }
   else if (MemPtr == NULL_PTR)
   {
     /* If the memory pointer passed is a Null Pointer report the DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_PARAM_POINTER
                    );
     Retvalue = UART_NOT_OK;
   } 
   else if (Size == UART_ZERO_U )
   {
     /* If the parameter Size is equal to zero Report to  DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_INVALID_SIZE
                    );
     Retvalue = UART_NOT_OK;
   }
   else
   {
     /* If the channelId is Invalid Report to DET */
     Retvalue = Uart_lChannelCheck(Channel,UART_SID_WRITE);
 
     if (Retvalue == UART_OK)
     {
       if (Uart_ChannelInfo[Channel].Uart_TxState != UART_INITIALISED)
       {
        /* If the channel is Busy(Read/Write on-going) Report to  DET */
        Det_ReportError(
                        UART_MODULE_ID,
                        UART_MODULE_INSTANCE,
                        UART_SID_WRITE,
                        UART_E_STATE_TRANSITION
                       );
        Retvalue = UART_IS_BUSY;
       }
     }
   }
  #endif
  
  #if (UART_DEV_ERROR_DETECT == STD_ON)
   if (Retvalue == UART_OK)
  #else
   /* The Uart Write operation is already started for the channel. No other
      operation can be started on this Channel. This is implemented using a 
      binary semaphore mechanism*/
   ChTxLock = Mcal_LockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);
 
   /* No other Uart Write operation is in progress */
   if (ChTxLock == MCAL_RESOURCE_BUSY)
   {
        Retvalue = UART_IS_BUSY;
   }
   else
  #endif
   {
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
     ChannelConfigPtr to access the Configuration of Channel passed*/
   ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
    /*Update driver state in Uart_ChannelInfo as Write Operation*/
   Uart_ChannelInfo[Channel].Uart_TxState= UART_OPERATION_IN_PROGRESS;
 
   /* Extract asssigned HWUnit module ptr */
   HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
   HwModulePtr= &(UART_HW_MODULE[HwUnit]);
   
   /* Set TX FIFO Inlet width */
   HwModulePtr->TXFIFOCON.B.INW =UART_TXFIFOCONREG_INW_VAL;
 
   /* Set TX Datalength */
   HwModulePtr->DATCON.B.DATLEN =ChannelConfigPtr->DataLength - UART_ONE_U;
   
   /*Update Tx BuffPtr,size in Uart_ChannelInfo for Write Operation*/
   Uart_ChannelInfo[Channel].Uart_TxBuffPtr= MemPtr;
   Uart_ChannelInfo[Channel].Uart_TxDataLeft = Size;
   Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ZERO_U;
   
   /* Flush TX FIFO */
   HwModulePtr->TXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
 
   /*local function to copy the Tx data to FIFO*/
   Uart_lWrite(HwModulePtr,Channel);
   
   /*Check if only one data needs to be txd*/
   if (Size == UART_ONE_U )
   {
     /*Clear the Tx Complete flag*/
     HwModulePtr->FLAGSCLEAR.B.TCC = UART_ENABLE_BIT;
     /*Enable the Tx Complete flag*/
     HwModulePtr->FLAGSENABLE.B.TCE = UART_ENABLE_BIT;
     Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ONE_U;  
   }
   else
   {
     /*Enable Tx and Err Interrupts*/
     Uart_lEnableWriteInterrupts(HwModulePtr);
     Uart_lHwEnableAscLinTxIntr(HwUnit);
   }
 
   Uart_lHwEnableAscLinErrIntr(HwUnit);
 
   /*Enable the Tx FIFO*/
   HwModulePtr->TXFIFOCON.B.ENO =UART_ENABLE_BIT;
  }
  return Retvalue;
}
/*******************************************************************************
** Syntax : static void Uart_lWrite                                           **
**  (                                                                         **
**    Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel                      **
**  )                                                                         **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : local function to copy the transmit data from specified      **
**               memory location(App buffer) to TX FIFO Buffer                **
*******************************************************************************/
static void Uart_lWrite(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel)
{
  Uart_MemPtrType BuffPtr;
  uint16 Write_Count =UART_ZERO_U;
  uint8 Uartdata = UART_ZERO_U;
  uint8 UartDatalen ;
  
  BuffPtr = Uart_ChannelInfo[Channel].Uart_TxBuffPtr;
  Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
  
  if (Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_STEPSIZE)
  {
     /*Set the Write byte Count to copy the last data*/
    Write_Count = UART_STEPSIZE;
  }
  else if (Uart_ChannelInfo[Channel].Uart_TxDataLeft <= UART_BUFFER_SIZE)
  {
    /*Set the Write byte Count to copy the Data left minus last data*/
    Write_Count = (Uart_ChannelInfo[Channel].Uart_TxDataLeft - UART_STEPSIZE);
  }
  else
  {
   /*Set the data copy  byte Count to Tx Fifo Buff Size */
    Write_Count = UART_BUFFER_SIZE;
  }
 
  while (Write_Count > UART_ZERO_U)
  {
     UartDatalen = (uint8)  HwModulePtr->DATCON.B.DATLEN + UART_ONE_U;
     
   /*Check if the data to Write is the last one and datalen is 7/8*/
     if ((Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ONE_U) && \
                        (UartDatalen !=UART_NINEBIT_DATLEN))
     {
       /* Set TX FIFO Inlet width to One as one byte TX data is there*/
       HwModulePtr->TXFIFOCON.B.INW = UART_ONE_U;
       
       /*Copy the data from the mem to Tx FIFO buffer*/
       Uartdata = *((uint8*)(void*)BuffPtr) ;
       HwModulePtr->TXDATA.U = Uartdata; 
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
        BuffPtr to access next element of Application Data Buffer*/
       BuffPtr++;
        
     /*Reset Data Copy counter and Tx Data left cntr to one as Tx is complete*/
       Uart_ChannelInfo[Channel].Uart_TxDataLeft = UART_ZERO_U;
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr += UART_ONE_U;
 
       /* Reset Write count as Tx is complete*/
       Write_Count = UART_ZERO_U;
     }
     else
     {
       /*Copy the data from the mem to Tx FIFO buffer*/
       HwModulePtr->TXDATA.U  = *( BuffPtr);
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
        BuffPtr to access next element of Application Data Buffer*/
       BuffPtr++;
       
   /*Decrement TxData Left Cntr and increment TxData Copy cntr by step size*/
       Uart_ChannelInfo[Channel].Uart_TxDataLeft -= UART_STEPSIZE;       
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr += UART_STEPSIZE;
 
       /*Decrement the Data copy counter by step size(i.e. one Data Count)*/
       Write_Count = Write_Count - UART_STEPSIZE;
     }
  }
 
  Uart_ChannelInfo[Channel].Uart_TxBuffPtr = BuffPtr;
  return ;
}

/*******************************************************************************
** Syntax : static void Uart_lEnableWriteInterrupts                           **
**                   ( Ifx_ASCLIN* HwModulePtr)                               **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in):   HwModulePtr - Asclin Hardware Pointer                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Enable Interrupts for Write Operation      **
**                                                                            **
*******************************************************************************/
static void Uart_lEnableWriteInterrupts(Ifx_ASCLIN* HwModulePtr)
{
  /*Set Tx FIFO Int level and Enable Tx FIFO overflow and Level flags*/
  HwModulePtr->TXFIFOCON.B.INTLEVEL = UART_ZERO_U;

  HwModulePtr->FLAGSENABLE.B.TFLE = UART_ENABLE_BIT;

  HwModulePtr->FLAGSENABLE.B.TFOE = UART_ENABLE_BIT;
}
  
/*******************************************************************************
** Syntax : static void Uart_lClearWriteInterrupts                            **
**                   ( Ifx_ASCLIN* HwModulePtr)                               **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in):   HwModulePtr - Asclin Hardware Pointer                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Disable Interrupts for Write operation     **
**                                                                            **
*******************************************************************************/
static void Uart_lClearWriteInterrupts(Ifx_ASCLIN* HwModulePtr)
{
  /*Clear Tx FIFO overflow and Level flags*/
  HwModulePtr->FLAGSCLEAR.B.TFLC = UART_ENABLE_BIT;

  HwModulePtr->FLAGSCLEAR.B.TFOC = UART_ENABLE_BIT;
}

 #if (UART_ABORT_READ_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1573]                         **
** Syntax : Uart_SizeType Uart_AbortRead( Uart_ChannelIdType Channel )        **
**              [/cover]                                                      **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                               recieved and stored to the memory location   **
**                               before the read operation was aborted        **
** Description : Api to Abort the read operation on the specified channel     **
**                                                                            **
*******************************************************************************/
Uart_SizeType Uart_AbortRead(Uart_ChannelIdType  Channel)
{
  Ifx_ASCLIN* HwModulePtr;
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_SizeType UartRetSize = UART_ZERO_U ;
  uint8 HwUnit;

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Uart_ReturnType Retvalue = UART_OK;
  
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /* If uart is not uninitialised Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_ABORT_READ,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
    UartRetSize = UART_ZERO_U ;
  }
  else
  {
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_ABORT_READ);
    UartRetSize = UART_ZERO_U ;
  }
  #endif
  
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Retvalue == UART_OK)
  #else
   /* Release the lock so that New Uart Read Operation can be started*/
  Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);
  #endif
  {
    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);
    
    /*Disable RxFIFO and flush It*/
    HwModulePtr->RXFIFOCON.B.ENI = UART_DISABLE_BIT;
    HwModulePtr->RXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
    
    /*Clear Rx overflow and level Interrupts*/
    Uart_lClearReadInterrupts(HwModulePtr);
    
    /*Disable Rx and Err Interrupts*/
    Uart_lHwDisableAscLinRxIntr(HwUnit);
    Uart_lHwDisableAscLinErrIntr(HwUnit);
    
    /*Return Total Data Rxd before Read operation was Aborted */
    UartRetSize = Uart_ChannelInfo[Channel].Uart_TotalDataRxd;
 
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
     ChannelConfigPtr to access the Configuration of Channel passed*/
    ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
   /*Reinitialise the HW Unit*/
    Uart_lHwInit(HwUnit, ChannelConfigPtr );
    
    /*Reset Uart_ChannelInfo*/
    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;
    Uart_ChannelInfo[Channel].Uart_RxBuffPtr = NULL_PTR;
    
    /*Reset Data Rxd Counter*/
    Uart_ChannelInfo[Channel].Uart_TotalDataRxd = UART_ZERO_U;
    
    if(ChannelConfigPtr->UartNotif.UartAbortReceiveNotifPtr != NULL_PTR)
    {
      /*Call Abort Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartAbortReceiveNotifPtr(UART_NO_ERR);
    }
  }
  return UartRetSize ;
}
#endif 

#if (UART_ABORT_WRITE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1574]                         **
** Syntax : Uart_SizeType Uart_AbortWrite( Uart_ChannelIdType Channel )       **
**            [/cover]                                                        **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                       transmitted before the write operation was aborted   **
**                                                                            **
** Description : Api to Abort Transmission of data on the specified channel   **
**                                                                            **
*******************************************************************************/
Uart_SizeType Uart_AbortWrite(Uart_ChannelIdType Channel)
{
  Ifx_ASCLIN* HwModulePtr;
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_SizeType UartRetSize = UART_ZERO_U;
  uint16 tempsum;
  uint8 HwUnit;
  
   #if (UART_DEV_ERROR_DETECT == STD_ON)
   Uart_ReturnType Retvalue;
   #endif
 
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /* Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_ABORT_WRITE,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
    UartRetSize = UART_ZERO_U;
  }
  else
  {
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_ABORT_WRITE);
    UartRetSize = UART_ZERO_U;
  }
  
  if (Retvalue == UART_OK)
  #else
   /* Release the lock so that New Uart Write Operation can be started*/
  Mcal_UnlockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);
  #endif
  {
 
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
     ChannelConfigPtr to access the Configuration of Channel passed*/
    ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);
    
    /*Disable TxFIFO*/
    HwModulePtr->TXFIFOCON.B.ENO = UART_DISABLE_BIT;
 
   if((Uart_ChannelInfo[Channel].Uart_TxState == UART_INITIALISED) && \
         (Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ZERO_U))
    { 
       /*Reset Txd Data Fill to zero*/
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
    }
    
    /*Return the Count of Data Txd before the write operation was aborted*/
    tempsum =(uint16)Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr - \
                              ((uint16)HwModulePtr->TXFIFOCON.B.FILL);
    Uart_ChannelInfo[Channel].Uart_TotalDataTxd += tempsum;
 
    UartRetSize = Uart_ChannelInfo[Channel].Uart_TotalDataTxd;
   
   /*Flush TxFIFO*/
    HwModulePtr->TXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
    
   /*Clear Tx overflow and level Interrupts*/
    Uart_lClearWriteInterrupts(HwModulePtr);
 
   /*Disable Tx and Err Interrupts*/
    Uart_lHwDisableAscLinTxIntr(HwUnit);
    Uart_lHwDisableAscLinErrIntr(HwUnit);
    
   /*Reinitialise the HW Unit*/
    Uart_lHwInit(HwUnit, ChannelConfigPtr );
    
   /*Reset Uart_ChannelInfo*/
    Uart_ChannelInfo[Channel].Uart_TxBuffPtr = NULL_PTR;
    Uart_ChannelInfo[Channel].Uart_TxState = UART_INITIALISED;
    Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ZERO_U;
    Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
    
    if(ChannelConfigPtr->UartNotif.UartAbortTransmitNotifPtr != NULL_PTR)
    {
      /*Call Abort Transmit Notification Function*/
      ChannelConfigPtr->UartNotif.UartAbortTransmitNotifPtr(UART_NO_ERR);
    }
   } 
  return UartRetSize;
}
#endif

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1575]                         **
** Syntax : Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel)        **
**            [/cover]                                                        **
** Service ID:      0x06                                                      **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Re-entrant                                                **
**                                                                            **
** Parameters (in): Channel    : Uart channel to be addressed                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:                                                              **
**                  UART_BUSY : Uart channel is busy with transmission        **
**                                    or Reception operation                  **
**                  UART_IDLE : Uart channel is currently free to use         **
**                                                                            **
**                  UART_UNINIT: Uart channel is not uninitialised            **
**                                                                            **
** Description :    Indicates the current driver status for the UART channel  **
**                                                                            **
*******************************************************************************/
Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel)
{
  Uart_StatusType UartDriverState = UART_UNINIT;
  
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Uart_ReturnType Retvalue = UART_OK;
 
  /*Check for driver initialisation */
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_GETSTATUS,
                    UART_E_UNINIT
                   );
 
    Retvalue = UART_NOT_OK;            
 
    UartDriverState = UART_UNINIT;   
  }
  else
  {
     /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_GETSTATUS);
 
    UartDriverState = UART_BUSY;
  }
  
  if (Retvalue == UART_OK)
  #endif
  {
   /*Return state as BUSY if channel is busy with Read or Write Operation*/
  
    if((Uart_ChannelInfo[Channel].Uart_TxState == UART_OPERATION_IN_PROGRESS) \
     ||( Uart_ChannelInfo[Channel].Uart_RxState == UART_OPERATION_IN_PROGRESS))
    {
      UartDriverState = UART_BUSY;
    }
    else if (( Uart_ChannelInfo[Channel].Uart_TxState == UART_INITIALISED)\
     &&( Uart_ChannelInfo[Channel].Uart_RxState == UART_INITIALISED))
    {
      UartDriverState = UART_IDLE;
    }
    else
    {
      UartDriverState = UART_UNINIT;
    }
  } 
  
  return UartDriverState;
}


/*******************************************************************************
** Syntax :          void Uart_IsrReceive( uint8  HwUnit)                     **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents ASCLIN hw module number              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever  data                   **
**                   is completely received by the ASCLIN w/o any errors      **
*******************************************************************************/
void Uart_IsrReceive(uint8  HwUnit)
{
  const Uart_ChannelType *ChannelConfigPtr; 
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr= &(UART_HW_MODULE[HwUnit]);
  Uart_ChannelIdType Channel;
  
  /* Extract the Channel */
  Channel = Uart_BusChannelMap[HwUnit];
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
    ChannelConfigPtr to access the Configuration of Channel passed*/
  ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
  
  /* Local fnt to read the Data from Rx FIFO */
  Uart_lRead(HwModulePtr,Channel);
  
  if (Uart_ChannelInfo[Channel].Uart_RxDataLeft == UART_ZERO_U)
  {
    /*Flush RxFIFO*/
    HwModulePtr->RXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
    
    /*Clear Rx Overflow and Level Interrupts*/
    Uart_lClearReadInterrupts(HwModulePtr);
    
    /*Disable Rx FIFO*/
    HwModulePtr->RXFIFOCON.B.ENI = UART_DISABLE_BIT;
    
    /*Disable Rx Interrupt*/
    Uart_lHwDisableAscLinRxIntr(HwUnit);
    
    /* Release the lock so that other Uart Read Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);
    
    Uart_ChannelInfo[Channel].Uart_RxBuffPtr = NULL_PTR;
    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;
 
    if(ChannelConfigPtr->UartNotif.UartReceiveNotifPtr != NULL_PTR)
    {
      /*Call the Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartReceiveNotifPtr(UART_NO_ERR);
    }
    else
    {
     /* Do Nothing */
    }
  }
  return ;
}
  
/*******************************************************************************
** Syntax :          void Uart_IsrTransmit( uint8  HwUnit)                    **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the data                **
**                   is successfully transmitted by the ASCLIN w/o any errors **
**                                                                            **
*******************************************************************************/
void Uart_IsrTransmit(uint8  HwUnit)
{
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr = &(UART_HW_MODULE[HwUnit]);
  uint16 Tempsum;
  Uart_ChannelIdType Channel;

  /* Extract the Channel */
  Channel = Uart_BusChannelMap[HwUnit];
  Tempsum = (uint16)(Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr - \
                           ((uint16)HwModulePtr->TXFIFOCON.B.FILL));
  Uart_ChannelInfo[Channel].Uart_TotalDataTxd += Tempsum;
  
  if ( Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ZERO_U)
   {
     /*Clear the transmission complete flag*/
     HwModulePtr->FLAGSCLEAR.B.TCC = UART_ENABLE_BIT;
 
     /*Clear all write interrupts */
     Uart_lClearWriteInterrupts(HwModulePtr);
     
     /*Disable the Tx Overflow and Level Interrupt*/
     HwModulePtr->FLAGSENABLE.B.TFLE = UART_DISABLE_BIT;
     HwModulePtr->FLAGSENABLE.B.TFOE = UART_DISABLE_BIT;
     
     /*Disable Tx Interrupts*/
     Uart_lHwDisableAscLinTxIntr(HwUnit);
 
     Uart_ChannelInfo[Channel].Uart_TxBuffPtr = NULL_PTR;
     Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
   }
   else
   {
     /*Clear the transmission complete flag*/
     HwModulePtr->FLAGSCLEAR.B.TCC = UART_ENABLE_BIT;
     
     if(Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_STEPSIZE)
     {
       /* Enable the transmission complete interrupt
       for the last data transmission*/
       HwModulePtr->FLAGSENABLE.B.TCE = UART_ENABLE_BIT;
     }
     
     /*Disable TxFIFO*/
     HwModulePtr->TXFIFOCON.B.ENO = UART_DISABLE_BIT;
     
     /*Clear Tx Overflow and Level Interrupt*/
     Uart_lClearWriteInterrupts(HwModulePtr);
 
     /* Write the Data to Tx FIFO */
     Uart_lWrite(HwModulePtr,Channel);
     
     /*Enable the Tx Overflow and Level Interrupt*/
     Uart_lEnableWriteInterrupts(HwModulePtr);
     
     /*Enable TxFIFO*/
     HwModulePtr->TXFIFOCON.B.ENO = UART_ENABLE_BIT;
   }
  return ;
}
/*******************************************************************************
** Syntax :          void Uart_IsrError( uint8  HwUnit)                       **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever there is data           **
**                   transmission or reception error on ASCLINx HW Unit       **
*******************************************************************************/
void Uart_IsrError(uint8 HwUnit)
{
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr= &(UART_HW_MODULE[HwUnit]);
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_ErrorIdType ErrId = UART_NO_ERR;
  uint8 Channel = Uart_BusChannelMap[HwUnit];
   
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
    ChannelConfigPtr to access the Configuration of Channel passed*/
  ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
  
  /* Check parity error*/
  if ((HwModulePtr->FLAGS.B.PE) == UART_ONE_U)  
  {
    HwModulePtr->FLAGSCLEAR.B.PEC = UART_ONE_U;
    ErrId = UART_PARITY_ERR;
  }
  /* Check framing error*/
  else if ((HwModulePtr->FLAGS.B.FE) == UART_ONE_U)  
  {
    HwModulePtr->FLAGSCLEAR.B.FEC = UART_ONE_U;
    ErrId = UART_FRAME_ERR;
  }
   /* Check TxFIFO Overflow error*/
  else if ((HwModulePtr->FLAGS.B.TFO) == UART_ONE_U)  
  {
    HwModulePtr->FLAGSCLEAR.B.TFOC = UART_ONE_U;
    ErrId = UART_TXOVERFLOW_ERR;
  }
    /* Check RxFIFO Overflow error*/
  else if ((HwModulePtr->FLAGS.B.RFO) == UART_ONE_U)  
  {
    HwModulePtr->FLAGSCLEAR.B.RFOC = UART_ONE_U;
    ErrId = UART_RXOVERFLOW_ERR;
  }
   /* Check RxFIFO Underflow error*/
  else if ((HwModulePtr->FLAGS.B.RFU) == UART_ONE_U)  
  {
    HwModulePtr->FLAGSCLEAR.B.RFUC = UART_ONE_U;
    ErrId = UART_RXUNDERFLOW_ERR;
  }
    /* Check Tx Complete */
  else if ((HwModulePtr->FLAGS.B.TC) == UART_ONE_U)  
  {
    /* Disable TxFIFO */
    HwModulePtr->TXFIFOCON.B.ENO = UART_DISABLE_BIT;
 
    /* Clear Transmit complete */
    HwModulePtr->FLAGSCLEAR.B.TCC = UART_ENABLE_BIT;
    
    ErrId = UART_NO_ERR;
    
    /* Disable Tx complete interrupt */
    HwModulePtr->FLAGSENABLE.B.TCE = UART_DISABLE_BIT;
 
    /* Flush TxFIFO */
    HwModulePtr->TXFIFOCON.B.FLUSH = UART_ENABLE_BIT;
    
    /* Disable Err interrupts */
    Uart_lHwDisableAscLinErrIntr(HwUnit);
  }
  else
  {
     /* Do Nothing */
  }
  
  /*Call Notification fnt*/
  if ((ErrId == UART_PARITY_ERR)||(ErrId == UART_FRAME_ERR) \
   ||(ErrId == UART_RXOVERFLOW_ERR)||(ErrId == UART_RXUNDERFLOW_ERR))
  {
    /* Release the lock so that other Uart Read Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);
 
    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;
 
    if(ChannelConfigPtr->UartNotif.UartReceiveNotifPtr != NULL_PTR)
    {
      /*Call Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartReceiveNotifPtr(ErrId);
    }
  }
  else
  {
     /* Do Nothing */
  }

  if ((ErrId == UART_TXOVERFLOW_ERR)||(ErrId == UART_NO_ERR))
  {
    /* Release the lock so that other Uart Write Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);
 
    Uart_ChannelInfo[Channel].Uart_TxState = UART_INITIALISED;
 
    if(ChannelConfigPtr->UartNotif.UartTransmitNotifPtr != NULL_PTR)
    {
       /*Call Transmit Notification Function*/
      ChannelConfigPtr->UartNotif.UartTransmitNotifPtr(ErrId);
    }
  }
  else
  {
     /* Do Nothing */
  }
    
} 
/*******************************************************************************
** Syntax : static Uart_ReturnType Uart_lChannelCheck                         **
**  (                                                                         **
**    Uart_ChannelIdType Channel,uint8 ApiId                                  **
**  )                                                                         **
**                                                                            **
** Service ID:    NA                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  ApiId - Service id of the Api which calls this function   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to check whether channel is valid or not      **
**                                                                            **
*******************************************************************************/
#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_ReturnType Uart_lChannelCheck( \
                                       Uart_ChannelIdType Channel,uint8 ApiId)
{
  uint8 MaxChannel;
  Uart_ReturnType Retvalue;
 
  MaxChannel = Uart_kConfigPtr->NoOfChannels;
  
  if(Channel < MaxChannel)
  {
    Retvalue = UART_OK;
  }
  else 
  {
    /* If the channelid is invalid Report to  DET */
 
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    ApiId,
                    UART_E_INVALID_CHANNEL
                   );
 
    Retvalue = UART_NOT_OK;
  }
  
  return Retvalue; 
}
#endif


/*******************************************************************************
** Syntax           :  static void Uart_lHwDisableAscLinErrIntr               **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the  Err              **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinErrIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                   
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0ERRADDR  + Offset);

  if (IntrSrc.SRE == UART_BIT_SET)
  {
    IntrSrc.CLRR = UART_BIT_SET;
    IntrSrc.SRE = UART_BIT_RESET; /*  Disable intr */
  }

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0ERRADDR + Offset) = IntrSrc;
}

/*******************************************************************************
** Syntax           :    static void Uart_lHwDisableAscLinRxIntr              **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the   RX              **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinRxIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                    
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0RXADDR  + Offset);

  if (IntrSrc.SRE == UART_BIT_SET)
  {
    IntrSrc.CLRR = UART_BIT_SET;
    IntrSrc.SRE = UART_BIT_RESET; /*  Disable intr */
  }

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0RXADDR + Offset) = IntrSrc;
}
/*******************************************************************************
** Syntax           :  static void Uart_lHwDisableAscLinTxIntr                **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the TX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinTxIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                   
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0TXADDR + Offset);

  if (IntrSrc.SRE == UART_BIT_SET)
  {
    IntrSrc.CLRR = UART_BIT_SET;
    IntrSrc.SRE = UART_BIT_RESET; /*  Disable intr */
  }

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0TXADDR + Offset) = IntrSrc;
}

/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinErrIntr                 **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  Err               **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinErrIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                   
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0ERRADDR + Offset);

  IntrSrc.CLRR = UART_BIT_SET;
  IntrSrc.SWSCLR = UART_BIT_SET;
  IntrSrc.IOVCLR = UART_BIT_SET;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0ERRADDR + Offset) = IntrSrc;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0ERRADDR  + Offset);
  IntrSrc.SRE = UART_BIT_SET; /*  Enable intr */

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0ERRADDR + Offset) = IntrSrc;
}


/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinRxIntr                  **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  RX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinRxIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                   
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0RXADDR  + Offset);

  IntrSrc.CLRR = UART_BIT_SET;
  IntrSrc.SWSCLR = UART_BIT_SET;
  IntrSrc.IOVCLR = UART_BIT_SET;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0RXADDR + Offset) = IntrSrc;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0RXADDR  + Offset);
  IntrSrc.SRE = UART_BIT_SET; /*  Enable intr */

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0RXADDR + Offset) = IntrSrc;

}
/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinTxIntr                  **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  TX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinTxIntr(volatile uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;
                                   
  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0TXADDR  + Offset);

  IntrSrc.CLRR = UART_BIT_SET;
  IntrSrc.SWSCLR = UART_BIT_SET;
  IntrSrc.IOVCLR = UART_BIT_SET;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0TXADDR + Offset) = IntrSrc;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  IntrSrc = *(UART_SRC_ASCLIN0TXADDR  + Offset);
  IntrSrc.SRE = UART_BIT_SET; /*  Enable intr */

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  *(UART_SRC_ASCLIN0TXADDR + Offset) = IntrSrc;
}

#define UART_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

