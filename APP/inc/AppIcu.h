/*
 * AppIcu.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef APPICU_H_
#define APPICU_H_ (0)

#include "reuse.h"
#include "Gpt.h"
#include "Icu_17_GtmCcu6.h"

extern int  Speed_Count;
extern float    Speed_RPM;

extern void Init_Speed(void);
extern float Read_Speed(void);

#endif /* APPICU_H_ */
