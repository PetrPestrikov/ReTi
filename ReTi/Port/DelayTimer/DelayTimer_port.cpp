/*
 * DelayTimer_port.cpp
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#include <ReTi/Port/DelayTimer/DelayTimer_port.h>


static HwTimerFooInit   hwTimerFooPtr = {HwTimerDisable,HwTimerEnable,HwTimerLoadSet};
       HwTimerAPI       HWTimer (&hwTimerFooPtr);


 /********************************************************************************
  *
  * functions for working with the hardware timer interface
  *
  ****************************************************************************** */
 void HwTimerDisable(void)
 {
     TimerDisable(TIMER0_BASE, TIMER_A);
 }

 void HwTimerEnable(void)
 {
     TimerEnable(TIMER0_BASE, TIMER_A);
 }
 void HwTimerLoadSet (uint32_t ui32Value)
 {
     TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Value*(SysCtlClockGet()/1000000)); // setting for overflow after 1 us
 }


 //interrupt handler for interface to hardware timer
 void Timer0AIntHandler(void)
 {
     //post hardware dependent code below
     TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

     //system code for ReTi operation
     HWTimer.OVF_Handler();
 }
