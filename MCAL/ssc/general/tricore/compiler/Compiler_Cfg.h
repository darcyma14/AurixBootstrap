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
**   $FILENAME   : Compiler_Cfg.h $                                           **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
**                                                                            **
**   $DATE       : 2014-03-17 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION :File contains additional   typedefs that are used for       **
**              bit field structures. Also the tasking intrinsic functions    **
**              are listed here.                                              **
**              Macros given for Modules are not in use.                      **
**                                                                            **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY : [cover parentID= SAS_NAS_ALL_PR758,SAS_NAS_ALL_PR755] 
                   [/cover]
*******************************************************************************/


#ifndef COMPILER_CFG_H 
#define COMPILER_CFG_H   (0)



/* 

 * The following memory and pointer classes can be configured per module.

 * Those defines are passed to the compiler abstraction macros in Compiler.h

 */
 


/*******************************************************************************

**                                 MCU                                        **

*******************************************************************************/

/*To be used for code*/

#define MCU_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define MCU_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define MCU_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define MCU_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define MCU_VAR (0)



/*To be used for global or static constants*/

#define MCU_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define MCU_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define MCU_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define MCU_APPL_CODE (0)



/*******************************************************************************

**                                 PORT                                        *

*******************************************************************************/

/*To be used for code*/

#define PORT_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define PORT_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define PORT_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define PORT_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define PORT_VAR (0)



/*To be used for global or static constants*/

#define PORT_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define PORT_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define PORT_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define PORT_APPL_CODE (0)



/*******************************************************************************

**                                 DIO                                        **

*******************************************************************************/

/*To be used for code*/

#define DIO_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define DIO_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define DIO_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define DIO_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define DIO_VAR (0)



/*To be used for global or static constants*/

#define DIO_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define DIO_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define DIO_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define DIO_APPL_CODE (0)



/*******************************************************************************

**                                 ADC                                        **

*******************************************************************************/

/*To be used for code*/

#define ADC_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define ADC_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define ADC_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define ADC_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define ADC_VAR (0)



/*To be used for global or static constants*/

#define ADC_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define ADC_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define ADC_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define ADC_APPL_CODE (0)



/*******************************************************************************

**                                 GPTA                                        *

*******************************************************************************/

/*To be used for code*/

#define GPTA_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define GPTA_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define GPTA_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define GPTA_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define GPTA_VAR (0)



/*To be used for global or static constants*/

#define GPTA_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define GPTA_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define GPTA_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define GPTA_APPL_CODE (0)



/*******************************************************************************

**                                 GPT                                        **

*******************************************************************************/

/*To be used for code*/

#define GPT_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define GPT_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define GPT_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define GPT_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define GPT_VAR (0)



/*To be used for global or static constants*/

#define GPT_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define GPT_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define GPT_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define GPT_APPL_CODE (0)



/*******************************************************************************

**                                 ICU                                        **

*******************************************************************************/

/*To be used for code*/

#define ICU_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define ICU_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define ICU_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define ICU_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define ICU_VAR (0)



/*To be used for global or static constants*/

#define ICU_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define ICU_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define ICU_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define ICU_APPL_CODE (0)



/*******************************************************************************

**                                 PWM                                        **

*******************************************************************************/

/*To be used for code*/

#define PWM_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define PWM_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define PWM_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define PWM_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define PWM_VAR (0)



/*To be used for global or static constants*/

#define PWM_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define PWM_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define PWM_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define PWM_APPL_CODE (0)



/*******************************************************************************

**                                 SPI                                        **

*******************************************************************************/

/*To be used for code*/

#define SPI_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define SPI_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define SPI_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define SPI_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define SPI_VAR (0)



/*To be used for global or static constants*/

#define SPI_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define SPI_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define SPI_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define SPI_APPL_CODE (0)



/*******************************************************************************

**                                 CAN                                        **

*******************************************************************************/

/*To be used for code*/

#define CAN_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define CAN_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define CAN_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define CAN_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define CAN_VAR (0)



/*To be used for global or static constants*/

#define CAN_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define CAN_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define CAN_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define CAN_APPL_CODE (0)



/*******************************************************************************

**                                 WDG                                        **

*******************************************************************************/

/*To be used for code*/

#define WDG_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define WDG_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define WDG_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define WDG_VAR_FAST (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define WDG_VAR (0)



/*To be used for global or static constants*/

#define WDG_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define WDG_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define WDG_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define WDG_APPL_CODE (0)



/*******************************************************************************

**                                 CANTRCV                                     *

*******************************************************************************/

/*To be used for code*/

#define CANTRCV_CODE (0)



/*To be used for all global or static variables that are never initialized*/

#define CANTRCV_VAR_NOINIT  (0)



/*To be used for all global or static variables that are initialized only after power on reset*/

#define CANTRCV_VAR_POWER_ON_INIT  (0)



/* To be used for all global or static variables that have at least one of the 

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define CANTRCV_VAR_FAST  (0)



/*To be used for global or static variables that are initialized after every 

reset.*/

#define CANTRCV_VAR (0)



/*To be used for global or static constants*/

#define CANTRCV_CONST (0)



/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define CANTRCV_APPL_DATA (0)



/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define CANTRCV_APPL_CONST (0)



/*To be used for references on application functions. (e.g. call back function pointers)*/

#define CANTRCV_APPL_CODE (0)



#endif /* COMPILER_CFG_H */

