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
**   $FILENAME   : Mcal.c $                                                   **
**                                                                            **
**   $CC VERSION : \main\66 $                                                 **
**                                                                            **
**   $DATE       : 2015-04-07 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains the startup code, endinit protection    **
**                 functions                                                  **
**                                                                            **
**   SPECIFICATION(S) :  NA                                                   **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Std_Types.h */
#include "Std_Types.h"
#include "IfxCpu_reg.h"
#include "IfxScu_reg.h"
#include "IfxFlash_reg.h"
/* Inclusion of Mcal.h */
#include "Mcal.h"
#include "Mcal_Options.h"
#if (IFX_MCAL_USED == STD_ON)
/* Inclusion of EcuM.h */
#include "EcuM.h"
#endif
/* Inclusion of Test_Print.h */
#include "Test_Print.h"
/* Inclusion of Irq.h */
#include "Irq.h"

#if (IFX_MCAL_USED == STD_ON)
/* #include "DemoApp_Cfg.h" */
#endif

#if (GPT_DELIVERY == STD_ON)
#include "Gpt.h"
#include "Gpt_Demo.h"
#endif
#if (DIO_DELIVERY == STD_ON)
#include "Dio_Demo.h"
#endif

#if (WDG_DELIVERY == STD_ON)
#include "Wdg_17_Scu_Demo.h"
#include "Wdg_17_Scu.h"
#endif

/* #if (GPT_DELIVERY == STD_ON) */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define TRICORE_VERSION    (16U)

#if (TRICORE_VERSION == 16U)
#define PCON0_PCBYP        (0x02U)
#define PCON0_NOPCBYP      (0x00U)
#define PCON1_PCINV        (0x01U)
#define PCON2_PCACHE_SIZE   (0x0008U)     /* Size = 8KB */
#define PCON2_PSCRATCH_SIZE (0x080000U)   /* Size = 8KB */
#define DCON2_DCACHE_SIZE   (0x0000U)     /* Size = 0KB */
#define DCON2_DSCRATCH_SIZE (0x700000U)   /* Size = 112KB */
#endif /* #if (TRICORE_VERSION == 16U) */

#define STACK_ALIGN         ( 0xFFFFFFF8U )
#define MCAL_CORE_ID_MASK   ( 0x7U )

#define DEBUG()  __debug()

/*******************************************************************************
Preprocessor definations for the Start Up Routine.
  - if defined the Option is Enabled
  - if not defined the Option is Disabled
*******************************************************************************/
/* #define MCAL_CALL_DEMOAPP */

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

#if (IFX_SAFETLIB_USED == STD_ON)
extern void SafeTlib_main(uint8 CoreId);
extern void SAFET_core1_RunTimeTest(void);
extern void SAFET_core2_RunTimeTest(void);
#endif

#if (OS_DELIVERY == STD_ON)
extern void Ifx_OSTask_ApplicationInit(void);
#endif

#ifdef MCAL_CALL_DEMOAPP
extern __indirect void DemoApp(void);
#endif

extern __indirect int Main(void);

/*
 With the following preprocessor definations, the code gets Enabled
*/
/* For CrossView utilty function */
/*#define _SYNC_ON_HALT*/

/*
With the following preprocessor definations, the code gets disabled
*/

/*
 Re-enable and reset the call depth counter and  make A0,A1,A8,A9
 write-able. It is required for CrossView that these RESET values are
 restored for each time the startup code is executed.
*/
/*#define _NO_PSW_RESET*/

/*
 user stack initialisation
*/
/*#define _NO_USP_INIT*/

/*
 Clear Previous Context Pointer Segment Address and Offset Field.
 It is required for CrossView stack trace that these RESET values
 are restored for each time the startup code is executed.
*/
/*#define _NO_PCX_RESET*/

/*
 Context Switch Area initialisation
*/
/*#define _NO_CSA_INIT*/

/*
 disable watchdog
*/
/*#define NO_WATCHDOG_DISABLE*/

/*
 Load Base Address of Trap Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_BTV_INIT*/

/*
 Load Base Address of Interrupt Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_BIV_INIT*/

/*
 Load interupt stack pointer
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_ISP_INIT*/

/*
 Wait States for read access to PFlash is 6
 Wait states for Pflash access with wordline hit should be same as WSPFlash
 Wait States for read access to DFlash is 6
*/
/*#define _NO_FLASH_CONF*/

/*
 Inititialize global address registers a0/a1 to support
 __a0/__a1 storage qualifiers of the C compiler.
*/
/*#define _NO_A0A1_ADDRESSING*/

/*
 Inititialize global address registers a8/a9 to support
 __a8/__a9 storage qualifiers of the C compiler. A8 and A9
 are reserved for OS use, or for application use in cases
 where the application ans OS are tightly coupled.
*/
#define _NO_A8A9_ADDRESSING

/*
 Initialize Bus configuration registers
*/
/*#define _NO_BUS_CONF*/

/*
 Initialize and clear C variables
*/
/*#define _NO_C_INIT*/

/*
 Enable ICACHE
*/
#define _ENABLE_ICACHE

/*
 Enable DCACHE
*/
/* #define _ENABLE_DCACHE */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef struct {
  uint32 StackEndAddress;
  uint32 CsaStartAddress;
  uint32 CsaEndAddress;
  uint32 *TrapFn;
  uint32 IStackAddress;
  uint32 SmallData0;
  uint32 SmallData2;
  uint32 CopyTable;  /* Start Address in case of Diab */
  uint32 ClearTable; /* End Address in case of Diab */
  void (*CoreFn)(void);
}Mcal_CoreInit_t;

/* BMI Header to be placed at location 0xA0000000 */
typedef struct
{
  uint32 stadabm;       /*User Code Start Address                             */
  uint16 bmi;           /*Boot Mode Index (BMI)                               */
  uint16 bmhdid;        /*Boot Mode Header ID B359H                           */
  uint32 chkstart;      /*Memory Range to be checked - Start Address          */
  uint32 chkend;        /*Memory Range to be checked - End Address            */
  uint32 crcrange;      /*Check Result for the Memory Range                   */
  uint32 crcrangeinv;   /*Inverted Check Result for the Memory Range          */
  uint32 crchead;       /*Check Result for the ABM Header (offset 00H..17H)   */
  uint32 crcheadinv;    /*Inverted Check Result for the ABM Header            */
}BMD_HDR;

/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
#ifdef _SYNC_ON_HALT
void _sync_on_halt(void);    /* CrossView utilty function */
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/* Mcal specific startup code */
void _Mcal_Start(void );
void _START( void );          /* app init start address */
void _Exit( void );           /* exit return address */
/* C initialization function */
void _c_init( uint32 CoreNumber, uint32 Copytable );
#ifdef _DEFINE_CALL_ENDINIT
void _CALL_ENDINIT( void );  /* User definition function */
#endif

#ifdef _DEFINE_CALL_INIT
void _CALL_INIT( void );    /* User definition function */
#endif
void Mcal_Core0Container( void );

extern __indirect void Test_InitTime( void );
/* extern void DemoApp_CallMenuFctCpu1 (void);
extern void DemoApp_CallMenuFctCpu2 (void); */

/* interface to set/reset endinit of CPU/Safety watchdog */
static void safety_endinit_reset( void );
static void safety_endinit_set( void );
static void endinit_reset( void );
static void endinit_set( void );

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#ifdef _FREE_TASKING_C_COMPILER_
#pragma protect on
#pragma section farrom "bmhd_0"
const BMD_HDR Bmiheader =
{
    0x80000020,
    0x0370,
    0xB359,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x49E9B5B4,
    0xB6164A4B
};
#pragma protect restore
#pragma section farrom restore
#else
#define BMD_HDR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
const BMD_HDR Bmiheader =
{
    0x80000020,
    0x0370,
    0xB359,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x49E9B5B4,
    0xB6164A4B
};
#define BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif


#define MCAL_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"

#define MCAL_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"

extern void cpu0_trap_0 (void); /* trap table */
extern void inttab (void);      /* interrupt table */

extern uint8 * _SMALL_DATA_;       /* centre of A0 addressable area */
extern uint8 * _LITERAL_DATA_;     /* centre of A1 addressable area */

extern uint8 * _A8_DATA_;          /* centre of A8 addressable area */
extern uint8 * _A9_DATA_;          /* centre of A9 addressable area */
extern uint8 * _lc_ub_table;

extern uint8 __far * _lc_ue_ustack_tc0;     /* user stack end */
extern uint8 __far * _lc_ub_csa_tc0;        /* context save area begin */
extern uint8 __far * _lc_ue_csa_tc0;        /* context save area end */

extern uint8 __far * _lc_u_trap_tab_tc0;    /* trap table */
extern uint8 __far * _lc_u_int_tab ; /* interrupt table */
extern uint8 __far * _lc_ue_istack_tc0 ; /* interrupt stack end */
extern uint32 __far  *_lc_cp ;       /* copy table (cinit) */
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
extern uint32 __far *_lc_gb_FLS_STATE_VAR ; /* FLS state variable */
#endif


extern unsigned int __TRAPTAB_CPU0[]; /**< trap table */
extern unsigned int __INTTAB_CPU0[];

#define __INTTAB    _lc_u_int_tab
#define __TRAPTAB   cpu0_trap_0
#define __CPU0_ISTACK ( &_lc_ue_istack_tc0 )

#define __CPU0_TRAPTAB (&_lc_u_trap_tab_tc0 )

#define __CPU0_USTACK ( &_lc_ue_ustack_tc0 )

#define CPU0_BASE_MEM_ADRRESS     (0x70000000U)
#define CPU1_BASE_MEM_ADRRESS     (0x60000000U)
#define CPU2_BASE_MEM_ADRRESS     (0x50000000U)
#define CPUX_BASE_MEM_ADDR_MASK   (0xF0000000U)


/* Semaphore Operations */
#define MCAL_SET_SEMAPHORE(Sem)   (Sem = 1U)
#define MCAL_CLEAR_SEMAPHORE(Sem) (Sem = 0U)

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define MCAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern void core0_main( void );
const Mcal_CoreInit_t Mcal_CoreInit[ MCAL_NO_OF_CORES ] = {
    {
        ( uint32 ) __CPU0_USTACK,
        ( uint32 ) &_lc_ub_csa_tc0,
        ( uint32 ) &_lc_ue_csa_tc0,
        ( uint32 * ) __CPU0_TRAPTAB,
        ( uint32 ) __CPU0_ISTACK,
        ( uint32 ) &_SMALL_DATA_,
        ( uint32 ) &_LITERAL_DATA_,
        ( uint32 ) &_lc_ub_table,
        0,
        &Mcal_Core0Container
    }
};

#define MCAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
uint8 Mcal_lGetEcumCfgSelector(void);
#endif
/* Semaphore to halt the processing of other cores until CORE0 completes
   initialization */

void Mcal_EcuMInit(void);


/*******************************************************************************
** Syntax : void _START(void)                                                 **
**                                                                            **
** Service ID:  0                                                             **
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
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/

#ifdef _FREE_TASKING_C_COMPILER_
#pragma protect on
#pragma section code "start"
#else
#pragma section code "libc.reset"
#pragma align 4
#endif

void _START( void )
{
    __asm( "j _Mcal_Start" );      /* jump to reset start address */
}

#ifdef _FREE_TASKING_C_COMPILER_
#pragma protect restore
#pragma section code restore
#endif

#pragma section code "libc"
#pragma align 4


/*******************************************************************************
** Syntax : void _Mcal_Start(void)                                            **
**                                                                            **
** Service ID:  0                                                             **
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
** Description :  MCAL Specific Start up code (Sample Test Code)              **
**                CrossView Requirement: Re-enable and reset the call depth   **
**                counter and  make A0,A1,A8,A9 accessible. User Stack        **
**                Pointer Initialization. PCX Reset: Clear Previous Context   **
**                Pointer Segment Address and Offset Field. CSA               **
**                initialization followed by clearing endinit bit.            **
**                Disable Watchdog.                                           **
**                Trap vector base address initialization.                    **
**                ISP - initlaization                                         **
**                Base Interrupt vector table initalization.                  **
**                Flash waitstates configuration followed by endinit set      **
**                A0,A1 addressing.                                           **
**                A8,A9 addressing.                                           **
**                Bus and LMB configuration                                   **
**                Initialization of RAM variables.                            **
**                Call to Mcal_Main                                           **
**                                                                            **
*******************************************************************************/

void _Mcal_Start(void)
{
    const Mcal_CoreInit_t *CoreTable;
    uint32 sp;
#ifndef _NO_A0A1_ADDRESSING
  void *a0;
  void *a1;
#endif
    uint8 CoreNumber = 0;
    CoreNumber = MFCR( CPU_CORE_ID );

    CoreTable = &( Mcal_CoreInit[ CoreNumber ] );

    /*
     Re-enable and reset the call depth counter and  make A0,A1,A8,A9
     write-able. It is required for CrossView that these RESET values are
     restored for each time the startup code is executed.
    */
    #ifndef _NO_PSW_RESET
    {
        MTCR( CPU_PSW, 0x00000980 );        /* clear PSW.IS and set to User Stack*/
    }
    #endif

    /*
     user stack init
    */
    #ifndef _NO_USP_INIT
    {
         sp = ( uint32 )( CoreTable->StackEndAddress ) & STACK_ALIGN;
         __asm( "mov.a\tsp, %0"::"d"( sp ) );
    }
    #endif

    /*
     Clear Previous Context Pointer Segment Address and Offset Field.
     It is required for CrossView stack trace that these RESET values
     are restored for each time the startup code is executed.
    */

    #ifndef _NO_PCX_RESET
    {
        sint32 PCXValue;
        PCXValue = __mfcr( CPU_PCXI );
        MTCR( CPU_PCXI, ( sint32 )( ( uint32 ) PCXValue & 0xFFF00000UL ) );
        __isync();
    }
    #endif

    #ifndef _NO_CSA_INIT
    {
        uint32 loopCount;
        uint32 x;
        uint32 _csa_index;
        uint32 _lcx_index;
        uint32 *_prev_csa;

        /*
         The total no of CSA's is computed between the difference of CSA boundary
         address.
         The logic goes like this , assume the CSA starts as 0xd0004000 and ends at
         0xd0005000. 64 CSA's and each CSA occupying 64 bytes ( total 0x1000 bytes)
         At the address 0xd0004000 ZERO is written, to indicate last CSA.
         At 0xd0004040 - link to the 0th CSA is written as 0x000D0100. ( D stands for segment number)
         At 0xd0004080 - link to the 1st CSA is written as 0x000D0101.
         The list continues finally
         At 0xd0004fc0 , link to the 62nd CSA is written as 0x000D013E
        */
        _prev_csa = ( uint32 * )( CoreTable->CsaStartAddress );
        /*
         Load the count with the value of total CSA
        */
        loopCount = ( ( ( uint32 ) ( CoreTable->CsaEndAddress - CoreTable->CsaStartAddress ) >> 6 ) - 1UL );
        x = ( ( ( uint32 )( CoreTable->CsaStartAddress ) >> 28 ) << 16 );

        /*   Load the null pointer for initial CSA (0th)      */
        *( _prev_csa ) = 0;
        /* Fill the complete list */
        while( loopCount != 0 )
        {
            _csa_index = ( ( ( ( uint32 ) ( _prev_csa ) << 10 ) >> 16 ) | x );
            _prev_csa += 0x10;
            *( _prev_csa ) = _csa_index;
            loopCount--;
        }
        _csa_index = ( ( ( ( uint32 ) ( _prev_csa ) << 10 ) >> 16 ) | x );

        /* Load the last but 2 CSA link into LCX register */
        _lcx_index = ( uint32)( ( uint32 * )( CoreTable->CsaStartAddress ) + 0x20 );
        _lcx_index = ( uint32)( ( ( _lcx_index << 10 ) >> 16) | x );
        MTCR( CPU_LCX, ( sint32 ) _lcx_index );
        __isync() ;

        /*
         Load FCX with the free context pointer
         Write the last segment number into FCX register
        */
        MTCR( CPU_FCX, ( sint32 ) _csa_index );
        __isync() ;

    }
    #endif

    endinit_reset();

    /* Icache enabling steps */
    /* Step 1: Set PCBYP to 1 */
    MTCR( CPU_PCON0, PCON0_PCBYP );
    /* Step 2: Call Isync */
    ISYNC();

    endinit_set();

    /* Step 3: Invalidate current settings */
    MTCR( CPU_PCON1, PCON1_PCINV );

    /* Step 5: wait till PCINV becomes zero */
    while(( __mfcr( CPU_PCON1 ) & PCON1_PCINV ) == PCON1_PCINV );

    /*
     Clear the ENDINIT bit in the WDT_CON0 register in order
     to disable the write-protection for registers protected
     via the EndInit feature (for example: WDT_CON1).
    */
    endinit_reset();


    #ifndef NO_WATCHDOG_DISABLE
    {
        /*
         disable Safety watchdog & Cpu0 watchdog
        */
        if( CoreNumber == 0 )
        {
            safety_endinit_reset();
            SCU_WDTSCON1.U = 0x00000008;
            safety_endinit_set();
        }
        MODULE_SCU.WDTCPU[ CoreNumber ].CON1.U = 0x00000008;
    }
    #endif

    /*
     Load Base Address of Trap Vector Table
     Disable this if not started from RESET vector. (E.g.
     ROM monitors require to keep in control of vectors)
    */
    #ifndef _NO_BTV_INIT
    {
        MTCR( CPU_BTV, ( uint32 ) ( CoreTable->TrapFn ) ); /* initialize BTV    */
    }
    #endif

    /*
     Load Base Address of Interrupt Vector Table
     Disable this if not started from RESET vector. (E.g.
     ROM monitors require to keep in control of vectors)
    */
    #ifndef _NO_BIV_INIT
    {
        MTCR ( CPU_BIV, ( uint32 ) &__INTTAB );
    }
    #endif

    /*
    Load interupt stack pointer
    Disable this if not started from RESET vector. (E.g.
    ROM monitors require to keep in control of vectors)
    */
    #ifndef _NO_ISP_INIT
    {
        MTCR( CPU_ISP, ( uint32 ) ( ( uint32 )( CoreTable->IStackAddress ) ) );
    }
    #endif

    #ifdef _ENABLE_ICACHE
    {
       /* After setting the size, enable end init protection */

       /* Step 6: Enable ICACHE memory, followed by ISYNC instruction */
       MTCR( CPU_PCON0, 0 );

       ISYNC();
    }
    #endif


    #ifdef _ENABLE_DCACHE
    {
       /* After setting the size, enable end init protection */

       /* Step 6: Enable DCACHE memory, followed by ISYNC instruction */
       MTCR( CPU_DCON0, 0 );

       ISYNC();
       DSYNC();
    }
    #endif

    /*
     Set the ENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out.
    */
    endinit_set();

    /*
     Inititialize global address registers a0/a1 to support
     __a0/__a1 storage qualifiers of the C compiler.
    */
    #ifndef _NO_A0A1_ADDRESSING
    {
        a0 = ( uint32 * ) CoreTable->SmallData0;
        __asm( "mov.aa\ta0,%0"::"a"(a0) );

        a1 = ( uint32 * ) CoreTable->SmallData2;
        __asm( "mov.aa\ta1,%0"::"a"(a1) );
    }
    #endif

    /*
     Inititialize global address registers a8/a9 to support
     __a8/__a9 storage qualifiers of the C compiler. A8 and A9
     are reserved for OS use, or for application use in cases
     where the application ans OS are tightly coupled.
    */
    #ifndef _NO_A8A9_ADDRESSING
    {
        void *a8 = _A8_DATA_;
        __asm( "mov.aa\ta8,%0"::"a"(a8) );

        void *a9 = _A9_DATA_;
        __asm( "mov.aa\ta9,%0"::"a"(a9) );
    }
    #endif

    endinit_reset();
    //FLASH0_FCON.U |= 0x00000002;
    FLASH0_FCON.U |= 0x00000015;
    endinit_set();

    /*
     Enabling LMB split mode means all LMB reads accepted by LFI where the LMB
     Master is not asserting lmb_no_split_n are taken as split transactions.
     Default state is All LMB reads accepted by LFI are taken as no split
     transactions.
     Modification of LFI_CON register is done only when the LMB mode is enabled.
     Its left to default state if the split is not  enabled hence code will not
     be generated
     In LFI_CON.U register the bit 0 is modified for the same, if LMB split
     is enabled.
    */

    /*
     Initialize and clear C variables
    */
    #ifndef _NO_C_INIT
    /* initialize data for all cores */
    {
        _c_init( CoreNumber, CoreTable->CopyTable );
    }
    #endif

    #if ( IFX_MCAL_USED == STD_ON )
        CoreTable->CoreFn();
    #endif /* #if (IFX_MCAL_USED == STD_ON) */
}
/*
 End of Function Start
*/

/*******************************************************************************
** Syntax : void _Exit(void)                                                  **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Exits and calls debug16 instruction                          **
**                                                                            **
*******************************************************************************/
void _Exit( void )
{
    while( 1 )
    {
        __asm( "debug16" );
    }
}

#pragma section code "libc"
#pragma align 4

/*******************************************************************************
** Syntax : void _c_init(uint32 CoreNumber, uint32 Copytable)                 **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  CoreNumber - CoreId of the core executing               **
**                    Copytable - Copytable to be initialized/copied          **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialize or clear data segments as specified by the copy   **
**               table, It is an array of 4 word entries generated by the     **
**               locator. offset  0: type- 0=end, 1=copy, 2=clear             **
**               offset  4: destination address                               **
**               offset  8: source address (copy only)                        **
**               offset 12: length             - length in bytes.             **
**                                                                            **
*******************************************************************************/
void _c_init( uint32 CoreNumber, uint32 Copytable )
{
    uint32 *table;

    uint32 type;
    uint32 *src;
    uint32 *dest;
    uint32 lenb; /* length in bytes */
    uint8 *tempsrc;
    uint8 *tempdest;

    table = ( uint32 * )Copytable ;
    type  = *table++ ; /* extract the first table entry; */

    while( ( 1 == type ) || ( 2 == type ) )
    {
        dest = (uint32 *)*table++;
        src = (uint32 *)*table++;
        lenb = *table++;

        /* Do copytable only if shared address and CPU0 address */
        if( ( CoreNumber == 0U )
            && ( ( ( ( uint32 ) dest & CPUX_BASE_MEM_ADDR_MASK ) == CPU1_BASE_MEM_ADRRESS )
                 || ( ( ( uint32 ) dest & CPUX_BASE_MEM_ADDR_MASK ) == CPU2_BASE_MEM_ADRRESS ) )
                )
        {
            type = *table++ ; /* extract the next table entry */
            continue;
        }

        if( 1 == type )
        {
            tempsrc = ( uint8 * ) src;
            tempdest = ( uint8 * ) dest;

            while( lenb )
            {
                *tempdest++ = *tempsrc++;
                lenb-- ;
            }
        }

        if( 2 == type ) /* clear */
        {
            tempdest = ( uint8 * ) dest;

            while( lenb )
            {
                *tempdest++ = 0 ;
                lenb-- ;
            }
        }
        type = *table++ ; /* extract the next table entry */
    } /* while (type == 1 || type == 2) */
}


/*******************************************************************************
** Syntax           : uint8 EcuM_lGetCfgSelector(void)                        **
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
#if ( ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE )
uint8 Mcal_lGetEcumCfgSelector( void )
{
    /* Get Selector based on ......*/

    return( 0 );
}
#endif


#if (IFX_MCAL_USED == STD_ON)
void Mcal_EcuMInit()
{
#if ( ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE )
    uint8 CfgSelector;
#endif
    const struct EcuM_ConfigType_Tag *EcuMConfigPtr;


    /*Determine ECU Configuration Set */
    #if ( ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE )
    {
        /*Get Memory Location of the EcuM Configuration Set*/
        EcuMConfigPtr = EcuM_ConfigAddressPtr;
        /* In case of loadable the FlsStateVar memory area 48 bytes should be cleared.
        */
    }
    #endif

    #if ( ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE )
    {
        /*Get Configuration Set from available alternatives*/
        CfgSelector = Mcal_lGetEcumCfgSelector();
        EcuMConfigPtr =  &EcuM_ConfigAlternative[ CfgSelector ];
    }
    #endif

    #if ( OS_DELIVERY == STD_OFF )
    {
        Test_InitTime(); /* Initialize Time Measurement For Run Time Calc */
        Test_InitPrint();/* Initialize ASC0 for Hyperterminal Communication*/
    }
    #endif
    /*Initialize ECUM Module*/
    EcuM_Init( EcuMConfigPtr );
}

#endif

void Mcal_Core0Container()
{
    /* EcuM Init will be done only after all the other cores startup is completed
       This is because, if any of Core0's code accesses information belonging to
       other cores, then this information will not hold correct value until
       copy table is initialized. Also, if Core 0 updates a variable that resides
       in the memory allocated to other cores, then this data will  vanish during
       the copy table/clear table routine of the other cores. Hence it is safe
       to wait for the completion of the startup of the other cores before
       starting the application */

    #if (IFX_MCAL_USED == STD_ON)
    {
        Mcal_EcuMInit();
        Main();
    }
    #endif
}

/* Function to reset the endinit bit of Safety watchdog */
static void safety_endinit_reset( void )
{
    Mcal_ResetCpuENDINIT( -1 );
}

/* Function to set the endinit bit of Safety watchdog */
static void safety_endinit_set( void )
{
    Mcal_SetCpuENDINIT( -1 );
}

/* Function to reset the endinit bit of executing CPU watchdog */
static void endinit_reset( void )
{
    uint32 CoreID = ( ( uint32 ) MFCR(CPU_CORE_ID ) & MCAL_CORE_ID_MASK );
    Mcal_ResetCpuENDINIT( ( sint8 ) CoreID );
}

/* Function to set the endinit bit of executing CPU watchdog */
static void endinit_set( void )
{
    uint32 CoreID = ( ( uint32 ) MFCR(CPU_CORE_ID ) & MCAL_CORE_ID_MASK );
    Mcal_SetCpuENDINIT( ( sint8 ) CoreID );
}

/*******************************************************************************
** Syntax           : void Mcal_SafeErrorHandler(uint32 ErrorType)            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ErrorType                                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This is an Error handler function which can be called   **
                      in two conditions                                       **
** 1. Any detection of inconsistency in copies of relevant global variables   **
**    is reported to the user via the function Mcal_SafeErrorHandler.         **
**    Mcal_SafeErrorHandler shall never return, else it may lead to           **
**    unpredictable behavior.The user is expected to perform the error        **
**    handling in this function.                                              **
**                                                                            **
**    The error reported is MCAL_DIV_INCONSISTENCY:Typical error reactions    **
**    could be to reset the microcontroller (software reset)                  **
**                                                                            **
** 2. Support functions are called to access the protected registers,         **
**    these functions can be called from multiple cores concurrently, a       **
**    spinlock mechanism with timeout is provided. In case, the timeout       **
**    expires, it is reported to the user via Mcal_SafeErrorHandler.          **
**    The user is expected to perform the error handling in this function.    **
**                                                                            **
**    The error reported is MCAL_SPINLOCK_TIMEOUT:Typical error reactions     **
**    could be to the terminate the operating system task or restart the      **
**    partition or reset the microcontroller.                                 **
**                                                                            **
**    This funtion is written here only to avoid build error.                 **
**    The user needs to implement this functionality (Mcal_SafeErrorHandler)  **
**    in a separate file and needs to add this file as part of the build.     **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void Mcal_SafeErrorHandler( uint32 ErrorType )
{
    volatile uint32 TimeOut;

    TimeOut = 0U;
    /* User can add the code here */
    UNUSED_PARAMETER( ErrorType )
    /* While loop added for UTP AI00252128 */
    while( TimeOut < 0xFFFFFFFFU )
    {
        TimeOut++;
    }
    /* Control should not reach here. WDG timeout happens before this. */
    DEBUG();
}


