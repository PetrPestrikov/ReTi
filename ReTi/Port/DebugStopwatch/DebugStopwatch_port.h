/*
 * DebugStopwatch.h
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#ifndef RETI_PORT_DEBUGSTOPWATCH_DEBUGSTOPWATCH_PORT_H_
#define RETI_PORT_DEBUGSTOPWATCH_DEBUGSTOPWATCH_PORT_H_


#include "ReTi/System/fms_timers.h"
#include "ReTi/Port/HW_includes.h"

/*****************************************************************************
 *
 *  Debug benchmark time service
 *
 * ***************************************************************************/
extern  BenchTimer benchTimer;

void BenchTimerInit(void);
uint32_t GetBenchTimerVal(void);

#endif /* RETI_PORT_DEBUGSTOPWATCH_DEBUGSTOPWATCH_PORT_H_ */
