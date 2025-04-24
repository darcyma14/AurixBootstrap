/*
 * AppCan.c
 *
 *  Created on: 2021. 07. 01.
 *  Author: TSMART
 */

#include <stdint.h>
#include "AppCan.h"

/* uint8_t Test_RxConfirmCount = (uint8_t) 0; */
uint8 ESCC_TxConfirmCount = (uint8_t) 0;
uint8 DTO_TxConfirmCount = (uint8_t) 0;
uint8 DTM_TxConfirmCount = (uint8_t) 0;

uint8 DEBUG1_TxConfirmCount = (uint8_t) 0;
uint8 DEBUG2_TxConfirmCount = (uint8_t) 0;
uint8 DEBUG3_TxConfirmCount = (uint8_t) 0;

void AppCAN_Init(void)
{
	/* Can_17_MCanP_Init(&Can_ConfigRoot[0]); */

	Can_17_MCanP_SetControllerMode( Can_17_MCanPConf_CanController_CanController_0, CAN_T_START );
	Can_17_MCanP_SetControllerMode( Can_17_MCanPConf_CanController_CanController_1, CAN_T_START );
	Can_17_MCanP_SetControllerMode( Can_17_MCanPConf_CanController_CanController_2, CAN_T_START );
}


void AppCAN_Send (Can_HwHandleType Hth, Can_PduType *Can_MsgBox)
{
	if(Hth == MO_DTO)
		DTO_TxConfirmCount = 1u;
	else if(Hth == MO_DTM)
		DTM_TxConfirmCount = 1u;
	else if(Hth == MO_DEBUG1)
		DEBUG1_TxConfirmCount = 1u;
	else if(Hth == MO_DEBUG2)
		DEBUG2_TxConfirmCount = 1u;
	else if(Hth == MO_DEBUG3)
		DEBUG3_TxConfirmCount = 1u;
	else
		ESCC_TxConfirmCount = 1u;

	Can_17_MCanP_Write(Hth, Can_MsgBox);
}
