#ifndef APP_INC_INCL_H_
#define APP_INC_INCL_H_

#include "Ifx_reg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <LIMITS.h>

#include "FreeRTOS.h"
#include "task.h"

#include "Mcal.h"
#include "Mcal_Options.h"
#if (IFX_MCAL_USED == STD_ON)
/* Inclusion of EcuM.h */
#include "EcuM.h"
#endif
#include "Irq.h"
#include "Port.h"
#include "Uart.h"
#include "Gpt.h"
#include "Spi.h"
#include "FlsLoader.h"
#include "Can_17_MCanP.h"

#include "Test_Print.h"

#include "xType.h"
#include "xHelper.h"
#include "xDebug.h"
#include "Ymodem.h"

#endif /* APP_INC_INCL_H_ */
