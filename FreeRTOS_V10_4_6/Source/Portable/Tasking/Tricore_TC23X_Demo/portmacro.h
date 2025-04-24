#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/* System Includes. */
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"


/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR		char
#define portFLOAT		float
#define portDOUBLE		double
#define portLONG		long
#define portSHORT		short
#define portSTACK_TYPE	unsigned long
#define portBASE_TYPE	long

typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;

#if( configUSE_16_BIT_TICKS == 1 )
	typedef uint16_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffff
#else
	typedef uint32_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffffffffUL

	/* 32-bit tick type on a 32-bit architecture, so reads of the tick count do
	not need to be guarded with a critical section. */
	#define portTICK_TYPE_IS_ATOMIC 1
#endif
/*---------------------------------------------------------------------------*/

/* Architecture specifics. */
#define portSTACK_GROWTH							( -1 )
#define portTICK_PERIOD_MS							( ( portTickType ) 1000 / configTICK_RATE_HZ )
#define portBYTE_ALIGNMENT							4
#define portNOP()									__asm volatile( " nop " )
#define portCRITICAL_NESTING_IN_TCB					1
#define portRESTORE_FIRST_TASK_PRIORITY_LEVEL		1


/*---------------------------------------------------------------------------*/

typedef struct MPU_SETTINGS { unsigned long ulNotUsed; } xMPU_SETTINGS;

/* Define away the instruction from the Restore Context Macro. */
#define portPRIVILEGE_BIT							0x0UL

#define portCCPN_MASK						( 0x000000FFUL )

extern void vTaskEnterCritical( void );
extern void vTaskExitCritical( void );
#define portENTER_CRITICAL()			vTaskEnterCritical()
#define portEXIT_CRITICAL()				vTaskExitCritical()
/*---------------------------------------------------------------------------*/

/* CSA Manipulation. */
#define portCSA_TO_ADDRESS( pCSA )			( ( unsigned long * )( ( ( ( pCSA ) & 0x000F0000 ) << 12 ) | ( ( ( pCSA ) & 0x0000FFFF ) << 6 ) ) )
#define portADDRESS_TO_CSA( pAddress )		( ( unsigned long )( ( ( ( (unsigned long)( pAddress ) ) & 0xF0000000 ) >> 12 ) | ( ( ( unsigned long )( pAddress ) & 0x003FFFC0 ) >> 6 ) ) )
/*---------------------------------------------------------------------------*/

void vPortYield( void );
#define portYIELD()								__syscall( 0 )
/* Port Restore is implicit in the platform when the function is returned from the original PSW is automatically replaced. */
#define portSYSCALL_TASK_YIELD					0
#define portSYSCALL_RAISE_PRIORITY				1
/*---------------------------------------------------------------------------*/

/* Critical section management. */

/* Set ICR.CCPN to configMAX_SYSCALL_INTERRUPT_PRIORITY. */
#define portDISABLE_INTERRUPTS()	{																									\
										unsigned long ulICR;																			\
										__disable();																						\
										ulICR = __mfcr( CPU_ICR ); 		/* Get current ICR value. */										\
										ulICR &= ~portCCPN_MASK;	/* Clear down mask bits. */											\
										ulICR |= configMAX_SYSCALL_INTERRUPT_PRIORITY; /* Set mask bits to required priority mask. */	\
										__mtcr( CPU_ICR, ulICR );		/* Write back updated ICR. */										\
										__isync();																						\
										__enable();																						\
									}

/* Clear ICR.CCPN to allow all interrupt priorities. */
#define portENABLE_INTERRUPTS()		{																	\
										unsigned long ulICR;											\
										__disable();														\
										ulICR = __mfcr( CPU_ICR );		/* Get current ICR value. */		\
										ulICR &= ~portCCPN_MASK;	/* Clear down mask bits. */			\
										__mtcr( CPU_ICR, ulICR );		/* Write back updated ICR. */		\
										__isync();														\
										__enable();														\
									}

/* Set ICR.CCPN to uxSavedMaskValue. */
#define portCLEAR_INTERRUPT_MASK_FROM_ISR( uxSavedMaskValue ) 	{																						\
																	unsigned long ulICR;																\
																	__disable();																			\
																	ulICR = __mfcr( CPU_ICR );		/* Get current ICR value. */							\
																	ulICR &= ~portCCPN_MASK;	/* Clear down mask bits. */								\
																	ulICR |= uxSavedMaskValue;	/* Set mask bits to previously saved mask value. */		\
																	__mtcr( CPU_ICR, ulICR );		/* Write back updated ICR. */							\
																	__isync();																			\
																	__enable();																			\
																}


/* Set ICR.CCPN to configMAX_SYSCALL_INTERRUPT_PRIORITY */
extern unsigned long uxPortSetInterruptMaskFromISR( void );
#define portSET_INTERRUPT_MASK_FROM_ISR() 	uxPortSetInterruptMaskFromISR()

/* As this port holds a CSA address in pxTopOfStack, the assert that checks the
pxTopOfStack alignment is removed. */
#define portALIGNMENT_ASSERT_pxCurrentTCB ( void )

/* Pend a priority 1 interrupt, which will take care of the context switch. */
#define portYIELD_FROM_ISR( xHigherPriorityTaskWoken ) 		if( xHigherPriorityTaskWoken != pdFALSE ) {	SRBs[CPU_ID]->B.TRIG0 = 1; _isync(); }

/*---------------------------------------------------------------------------*/

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )
/*---------------------------------------------------------------------------*/

/*
 * Port specific clean up macro required to free the CSAs that were consumed by
 * a task that has since been deleted.
 */
void vPortReclaimCSA( unsigned long *pxTCB );
#define portCLEAN_UP_TCB( pxTCB )		vPortReclaimCSA( ( unsigned long * ) ( pxTCB ) )

typedef struct
{
    unsigned int tAddr;
    unsigned int tId : 8;
    unsigned int tClass : 8;
    unsigned int tCpu : 3;
} IfxCpu_Trap;

typedef enum
{
    IfxCpu_Trap_Class_memoryManagement     = 0U,
    IfxCpu_Trap_Class_internalProtection   = 1U,
    IfxCpu_Trap_Class_instructionErrors    = 2U,
    IfxCpu_Trap_Class_contextManagement    = 3U,
    IfxCpu_Trap_Class_bus                  = 4U,
    IfxCpu_Trap_Class_assertion            = 5U,
    IfxCpu_Trap_Class_systemCall           = 6U,
    IfxCpu_Trap_Class_nonMaskableInterrupt = 7U
} IfxCpu_Trap_Class;

#define IfxCpu_Tsr_CallTSR(serviceRoutine)                                              \
    {                                                                                   \
        __ALIGN_TRAP_TAB__;                                                             \
        __asm("svlcx\n\tmov\td4,d15\n\tji\t%0\n" : : "a" (serviceRoutine) : "d4", "d15"); \
    }
#define __ALIGN_TRAP_TAB__ __asm(" .align 32");

#define IfxCpu_Tsr_CallCSATSR(serviceRoutine)                                              \
    {                                                                                   \
        __ALIGN_TRAP_TAB__;                                                             \
        __asm("mov\td4,d15\n\tji\t%0\n" : : "a" (serviceRoutine) : "d4", "d15"); \
    }
#define __ALIGN_TRAP_TAB__ __asm(" .align 32");


#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */
