/*
 * fms_timers.h
 *
 *  Created on: 28.10.2013
 *      Author: pestrikovpp
 */

/***************************************************
 *      v2.0.1
 ************************************************* */


#ifndef FMS_TIMERS_H_
#define FMS_TIMERS_H_

//#include <ReTi/Port/ReTi_port.h>
#include <stdbool.h>
#include <stdint.h>

#include "system_settings.h"

/****************************************************************
 *
 * interface for working with a software timer. For non-blocking delays.
 *
 *************************************************************** */
extern volatile uint8_t g_SysTimersTick;       //global counter for the number of hardware timer interrupts

//definitions of units of time
#define _1_mil_sec      1            //hardware timer period
#define sec             (1000*_1_mil_sec)
#define min             (60 * sec)
#define hour            (60 * min)
#define day             (24 * hour)


typedef enum e_TimerMode{
    TimerMode_Stop = 0,
    TimerMode_Run = 1,
    TimerMode_Pause = 2
	}TimerMode;



class SysTimer
{
public:
    SysTimer();
    TimerMode workMode;         // Stopped, running or paused
    uint16_t tick;              //current timer value
};

class soft_timer
{
  public:
    soft_timer();

    void StartTimer();
    void StopTimer();       //Stopping a timer and resetting its counter
    void PauseTimer();      //Stopping a timer without resetting its counter
    void UnpauseTimer();
    void ResetTimer();      //reset timer counter
    uint16_t GetTimer();
    TimerMode GetMode();

  private:
    static uint8_t numb;    //number of timers in the system
    SysTimer* timer_ptr;

friend void ProcessTimers(void);
friend void InitTimers(void);
};

//The function initializes the timer service. Must be called before using timers in a project.
void InitTimers(void);
//Timer service. Must be called periodically.
void ProcessTimers(void);


/****************************************************************
 *
 * interface for working with a hardware timer. For blocking delays.
 *
 *************************************************************** */
//a structure containing pointers to functions for working with a specific hardware timer
typedef struct st_HwTimerFooInit{
    void (* TimerDisable) (void);                   //Disables the timer operation
    void (* TimerEnable) (void);                    //Allows the timer to run
    void (* TimerLoadSet) (uint32_t ui32Value);     //Loads a value in μs into the timer
}HwTimerFooInit;


class HwTimerAPI
{
public:
    HwTimerAPI(HwTimerFooInit * TimerFooInit);

    void delay_us_block(uint32_t time);     //multiplicity 1 µs

    void OVF_Handler(void);                 //must be called in the timer interrupt handler

private:
    volatile bool hwTimerOVF;
    HwTimerFooInit * TimerFooInit;
};


/*****************************************************************************
 *
 *  Debug benchmark time service
 *
 * ***************************************************************************/
#define MOVE_AVR_FILTER_DEEP    8   //must be the result of raising 2 to the power


//a structure containing pointers to functions for working with a specific hardware timer
typedef struct st_BenchTimerFooInit{
    uint32_t maxTimerValue;                         //maximum value in hardware timer
    uint32_t (* GetTimerVal) (void);                //reads the current value in the hardware timer
    void (* TimerInit) (void);                      //initializing the hardware timer
}BenchTimerFooInit;

typedef struct st_TimeStatistic{
    uint32_t minExecuTime;
    uint32_t maxExecuTime;
    uint32_t avrgExecuTime;
}TimeStatistic;


class BenchTimer
{
public:
    BenchTimer(BenchTimerFooInit * TimerFooInit);
    BenchTimer();

    void     Start(void);
    void     Stop(void);

    TimeStatistic workStatistic;

private:

    void StatisticProcessing(void);

    static BenchTimerFooInit * TimerFooInit;
    uint32_t avrMas[MOVE_AVR_FILTER_DEEP];
    static uint8_t moveAvrLiterPow;                //power of 2 filter depth
    uint32_t sartTime;
    uint32_t stopTime;
};



#endif /* FMS_TIMERS_H_ */
