/*
 * hw_level_connection.h
 *
 *  Created on: 20 мая 2022 г.
 *      Author: 79141
 */

#ifndef HW_LEVEL_CONNECTION_H_
#define HW_LEVEL_CONNECTION_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "inc/hw_types.h"

#include "inc/hw_gpio.h"

#include "inc/hw_memmap.h"

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
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

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/fpu.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/i2c.h"
#include "driverlib/ssi.h"
#include "grlib/grlib.h"
#include "utils/uartstdio.h"
#include "driverlib/interrupt.h"
#include "driverlib/adc.h"
#include "inc/hw_types.h"
#include "driverlib/timer.h"

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/fpu.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/eeprom.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/i2c.h"
#include "driverlib/ssi.h"
#include "grlib/grlib.h"
#include "utils/uartstdio.h"
#include "driverlib/interrupt.h"
#include "driverlib/adc.h"
#include "inc/hw_types.h"
#include "driverlib/timer.h"

#include "ReTi/SYSTEM\fms_timers.h"
#include "ReTi/SYSTEM\messages.h"
#include "ReTi/SYSTEM\Scheduler.h"
#include "ReTi/SYSTEM\Task.h"
#include "ReTi/Port\ReTi_port.h"


/*****************************************************************************
 *
 * All hardware dependent functions and variables are declared
 *
 * ***************************************************************************/
void HardwareSetup(void);


/***********************************************************************************
 *
 *  Naming hardware resources
 *
 ********************************************************************************* */
/////////////////////////////////////////////////////////////////////////////////////
//
//                  ReTi Rtos
//
//////////////////////////////////////////////////////////////////////////////////////

/////////////////////   soft timers   ////////////////////////////////////////
#define RETI_TIMER_PERIPH                     SYSCTL_PERIPH_TIMER1
#define RETI_TIMER_BASE                       TIMER1_BASE
#define RETI_TIMER                            TIMER_A
#define RETI_TIMER_INT                        INT_TIMER1A

/////////////////////   hard timers   ////////////////////////////////////////
#define HW_TIMER_PERIPH                     SYSCTL_PERIPH_TIMER0
#define HW_TIMER_BASE                       TIMER0_BASE
#define HW_TIMER                            TIMER_A
#define HW_TIMER_INT                        INT_TIMER0A




#endif /* HW_LEVEL_CONNECTION_H_ */
