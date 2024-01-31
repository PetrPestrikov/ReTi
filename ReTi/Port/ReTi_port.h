/*
 * ReTi_port.h
 *
 *  Created on: 17/10/2023 ã.
 *      Author: PestrikovPP
 */

/***************************************************
 *      v3.0.0
 ************************************************* */

#ifndef SYSTEM_RETI_PORT_H_
#define SYSTEM_RETI_PORT_H_



#include <ReTi/Port/CyclTimer/CyclTimer_port.h>
#include <ReTi/Port/DelayTimer/DelayTimer_port.h>

/*********************************************************************************
 * ReTi requires 3 hardware timers to work. The first is for the system clock.
 * Time interval 1 ms. The second is for “dumb” time delays.
 * The third is needed to measure the time intervals of code execution in debug mode.
 *
 * Steps to port ReTi to any microcontroller:
 * 1. configure the hardware timer of the microcontroller for cyclic interruptions every 1 ms.
 * 2. configure the second hardware timer to fire once. It will count time intervals from 1 to 1000 µs
 * 3. configure the third hardware timer to fire once. It will count time intervals from 1 to 1000 µs
 * 4. include hardware libraries in the file ReTi_port.h
 * 5. include the file ReTi_port.h into the project.
 * 6. call the function ReTiCiclSysTmrHdl in the interrupt handler of the first timer
 * 7. Write in an external file the functions for entering and exiting the critical section for the first timer.
 * 8. Write in an external file functions to operate timer 2.
 *
 * *******************************************************************************/



/*
HardWareTimer.TimerEnable = HwTimerEnable;
       HardWareTimer.TimerDisable = HwTimerDisable;
       HardWareTimer.TimerClear = HwTimerClear;
       HardWareTimer.TimerLoadSet = HwTimerLoadSet;
*/
#endif /* SYSTEM_RETI_PORT_H_ */
