/*
 * fsm_timers.cpp
 *
 *  Created on: 28.10.2013
 *      Author: pestrikovpp
 */ 

/***************************************************
 *      v2.0.0
 ************************************************* */

#include "fms_timers.h"
#include "ReTi/Port\ReTi_port.h"

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "grlib/grlib.h"
#include "driverlib/ssi.h"
#include "utils/uartstdio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"


static SysTimer Timers[MAX_TIMERS];

volatile uint8_t g_SysTimersTick;

uint8_t soft_timer :: numb = 0;

SysTimer :: SysTimer()
{
    tick = 0;
    workMode = TimerMode_Stop;
}

void InitTimers(void)
{
    g_SysTimersTick = 0;
}

void ProcessTimers(void)
{
    ReTiCycSysTmr_SetCritical();

        uint8_t TimeTick = g_SysTimersTick;
        g_SysTimersTick = 0;

	ReTiCycSysTmr_ReleaseCritical();

	//if at least one system time interval has passed since the last call,
	//then we go through the timers and increase the counter in the running timers.
    if (TimeTick > 0)
	 {
        for (uint32_t i=0; i< soft_timer :: numb; i++)
		 {
			if(Timers[i].workMode == TimerMode_Run)  Timers[i].tick += TimeTick;
         }
     }
}

soft_timer :: soft_timer()
{
    timer_ptr = &Timers[soft_timer :: numb];
    soft_timer :: numb++;
}

void soft_timer ::StartTimer()
{
	timer_ptr->workMode = TimerMode_Run;
}

void soft_timer ::StopTimer()
{
	timer_ptr->workMode = TimerMode_Stop;
	timer_ptr->tick = 0;
}

void soft_timer ::PauseTimer()
{
	timer_ptr->workMode = TimerMode_Pause;
}

void soft_timer ::UnpauseTimer()
{
	timer_ptr->workMode = TimerMode_Run;
}

void soft_timer ::ResetTimer()
{
	timer_ptr->tick = 0;
}

uint16_t soft_timer ::GetTimer()
{
	return timer_ptr->tick;
}

TimerMode soft_timer :: GetMode()
{
    return timer_ptr->workMode;
}



/**************************************************************
 *
 * HwTimerAPI
 *
 ************************************************************* */
HwTimerAPI::HwTimerAPI(HwTimerFooInit * TimerFooInit)
{
    hwTimerOVF = false;
    this->TimerFooInit = TimerFooInit;
}

void HwTimerAPI::delay_us_block(uint32_t time)
{
    TimerFooInit->TimerLoadSet(time); // setting for overflow after 1 us

    TimerFooInit->TimerEnable();

    while(!hwTimerOVF) { }
    hwTimerOVF = false;
}


void HwTimerAPI::OVF_Handler(void)
{
    TimerFooInit->TimerDisable();
    hwTimerOVF = true;
}

/*****************************************************************************
 *
 *  Debug benchmark time service
 *
 * ***************************************************************************/
uint8_t BenchTimer:: moveAvrLiterPow = 0;
BenchTimerFooInit *BenchTimer::TimerFooInit = (BenchTimerFooInit *)nullptr;

BenchTimer::BenchTimer(BenchTimerFooInit * TimerFooInit)
{
    workStatistic.avrgExecuTime = 0;
    workStatistic.maxExecuTime = 0;
    workStatistic.minExecuTime = 0;

    uint32_t temp = MOVE_AVR_FILTER_DEEP;
    uint8_t   powVal = 0;
    while(temp)
    {
        temp = temp/2;
        powVal++;
    }
    moveAvrLiterPow = powVal;

    this->TimerFooInit = TimerFooInit;

    TimerFooInit->TimerInit();

     sartTime = 0;
     stopTime = 0;

     for(uint32_t i = 0; i < MOVE_AVR_FILTER_DEEP; i ++) avrMas[i] = 0;
}

BenchTimer::BenchTimer()
{
    workStatistic.avrgExecuTime = 0;
    workStatistic.maxExecuTime = 0;
    workStatistic.minExecuTime = 0;

     sartTime = 0;
     stopTime = 0;

     for(uint32_t i = 0; i < MOVE_AVR_FILTER_DEEP; i ++) avrMas[i] = 0;
}

/******************************************************************************************************
 *
 *  Reads the current value from the timer into the stopTime variable
 *
 * *****************************************************************************************************/
void BenchTimer::Start()
{
    sartTime = TimerFooInit->GetTimerVal();
}

/******************************************************************************************************
 *
 *  Reads the current value from the timer into the stopTime variable
 *
 * *****************************************************************************************************/
void BenchTimer::Stop()
{
    stopTime = TimerFooInit->GetTimerVal();
    StatisticProcessing();
}

/******************************************************************************************************
 *
 * We read the value from the timer, write it to an array,
 * calculate the average, write it to statistics
 *
 * *****************************************************************************************************/
void  BenchTimer::StatisticProcessing()
{
    uint32_t benchVal;
    static uint32_t n = 0;
    uint32_t sum = 0;

    //calculate execution time
    if(stopTime >= sartTime)
    {
        benchVal = stopTime - sartTime;
    }
    else
    {
        benchVal = TimerFooInit->maxTimerValue - sartTime +  stopTime;
    }

    //calculate the average execution time using a moving average based on MOVE_AVR_FILTER_DEEP measurements
    avrMas[n] = benchVal;

    n = (n+1) % MOVE_AVR_FILTER_DEEP;

    for(uint32_t j=0;j<MOVE_AVR_FILTER_DEEP;j++)
    {
        sum = sum + avrMas[j];
    }
    workStatistic.avrgExecuTime = sum >> moveAvrLiterPow;

    //updating maximum and minimum values
    if(benchVal < workStatistic.minExecuTime)
    {
        workStatistic.minExecuTime = benchVal;
    }
    if(benchVal >workStatistic.maxExecuTime)
    {
        workStatistic.maxExecuTime = benchVal;
    }
}


