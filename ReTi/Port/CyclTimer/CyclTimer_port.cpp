/*
 * test.cpp
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#include <ReTi/Port/CyclTimer/CyclTimer_port.h>

/*************************************************************************
 *
 * Hardware timer handler for servicing software timers
 *
 *********************************************************************** */
void ReTiCyclSysTmrHdl(void)
{
    //post hardware dependent code below
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);


    //system code for ReTi operation
    g_SysTimersTick++;
}
