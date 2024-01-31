/*
 * DelayTimer_port.h
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#ifndef RETI_PORT_DELAYTIMER_DELAYTIMER_PORT_H_
#define RETI_PORT_DELAYTIMER_DELAYTIMER_PORT_H_

#include "ReTi/System/fms_timers.h"
#include "ReTi/Port/HW_includes.h"


/*****************************************************************************
 *
 *  System hardware timer
 *
 * ***************************************************************************/
extern  HwTimerAPI HWTimer;

void HwTimerDisable(void);
void HwTimerEnable(void);
void HwTimerLoadSet (uint32_t ui32Value);

void Timer0AIntHandler(void);

#endif /* RETI_PORT_DELAYTIMER_DELAYTIMER_PORT_H_ */
