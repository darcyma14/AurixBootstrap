/*
    FreeRTOS V7.1.0 - Copyright (C) 2011 Real Time Engineers Ltd.


    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    >>>NOTE<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

/* Kernel includes. */
#include "FreeRTOS.h"

#include "Ifx_reg.h"
#include "Mcal.h"

void vPortTrapYield( int iTrapIdentification );

#define IFX_CFG_CPU_TRAP_SYSCALL_CPU0_HOOK( trapInfo )  vPortTrapYield( ( trapInfo ).tId )

#ifndef IFX_CFG_CPU_TRAP_TSR_HOOK
#   define IFX_CFG_CPU_TRAP_TSR_HOOK(trapWatch)          /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU0_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU1_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU1_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU2_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU2_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU3_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU3_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU4_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU4_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_SYSCALL_CPU5_HOOK
#   define IFX_CFG_CPU_TRAP_SYSCALL_CPU5_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_NMI_HOOK
#   define IFX_CFG_CPU_TRAP_NMI_HOOK(trapWatch)          ((void)trapWatch) /**< By default NMI macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_MME_HOOK
#   define IFX_CFG_CPU_TRAP_MME_HOOK(trapWatch)    ((void)trapWatch)      /**< By default memory Management Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_IPE_HOOK
#   define IFX_CFG_CPU_TRAP_IPE_HOOK(trapWatch)    ((void)trapWatch)      /**< By default internal Protection Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_IE_HOOK
#   define IFX_CFG_CPU_TRAP_IE_HOOK(trapWatch)     ((void)trapWatch)      /**< By default instruction Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_CME_HOOK
#   define IFX_CFG_CPU_TRAP_CME_HOOK(trapWatch)    ((void)trapWatch)      /**< By default context Management Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_BE_HOOK
#   define IFX_CFG_CPU_TRAP_BE_HOOK(trapWatch)     ((void)trapWatch)      /**< By default bus Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ASSERT_HOOK
#   define IFX_CFG_CPU_TRAP_ASSERT_HOOK(trapWatch) ((void)trapWatch)     /**< By default assertion is empty*/
#endif

#ifndef IFX_CFG_CPU_TRAP_DEBUG
 #define IFX_CFG_CPU_TRAP_DEBUG __debug()
#endif

IFX_INLINE void* Ifx__getA11( void )
{
    unsigned int *res;
    __asm( "mov.aa %0, a11": "=a" (res) : :"a11" );
    return res;
}

extern void vDbgPrintf( char *pecFmt, ... );

/*******************************************************************************
**                      Function definitions                          **
*******************************************************************************/
IFX_INLINE IfxCpu_Trap IfxCpu_Trap_extractTrapInfo( uint8 trapClass, uint32 tin )
{
    IfxCpu_Trap trapInfo;
    trapInfo.tAddr  = ( unsigned int )Ifx__getA11();
    trapInfo.tClass = trapClass;
    trapInfo.tId = tin;
    trapInfo.tCpu = 0;
    return trapInfo;
}

void IfxCpu_Trap_internalProtectionError( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_internalProtection, tin );
    IFX_CFG_CPU_TRAP_IPE_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("1");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

void IfxCpu_Trap_memoryManagementError( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_memoryManagement, tin );
    IFX_CFG_CPU_TRAP_MME_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("2");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

void IfxCpu_Trap_instructionError( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_instructionErrors, tin );
    IFX_CFG_CPU_TRAP_IE_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("3");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

void IfxCpu_Trap_contextManagementError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_contextManagement, tin );
    IFX_CFG_CPU_TRAP_CME_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("4");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

void IfxCpu_Trap_busError( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_bus, tin );
    IFX_CFG_CPU_TRAP_BE_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("5");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}


void IfxCpu_Trap_assertion( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_assertion, tin );
    IFX_CFG_CPU_TRAP_ASSERT_HOOK( trapWatch );
    IFX_CFG_CPU_TRAP_DEBUG;

//    vDbgPrintf("6");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}


void IfxCpu_Trap_systemCall_Cpu0(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_systemCall, tin );
    IFX_CFG_CPU_TRAP_SYSCALL_CPU0_HOOK( trapWatch );
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

void IfxCpu_Trap_nonMaskableInterrupt( uint32 tin )
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_extractTrapInfo( IfxCpu_Trap_Class_nonMaskableInterrupt, tin );
    IFX_CFG_CPU_TRAP_NMI_HOOK( trapWatch );
//    vDbgPrintf("8");
    __asm( "rslcx" ); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm( "rfe" );
}

#pragma protect on
#pragma section code "traptab_cpu0"

void IfxCpu_Trap_vectorTable0( void )
{
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_memoryManagementError );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_internalProtectionError );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_instructionError );
    IfxCpu_Tsr_CallCSATSR( IfxCpu_Trap_contextManagementError );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_busError );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_assertion );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_systemCall_Cpu0 );
    IfxCpu_Tsr_CallTSR( IfxCpu_Trap_nonMaskableInterrupt );
}

#pragma endprotect
