/*
 * ReTi_HW_CyclTmr_port.h
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#ifndef RETI_PORT_CYCLTIMER_CYCLTIMER_PORT_H_
#define RETI_PORT_CYCLTIMER_CYCLTIMER_PORT_H_

#include "ReTi/System/fms_timers.h"

#include "ReTi/Port/HW_includes.h"


/************************************************************************************
 *  functions of entry and exit from the critical section for timer No. 1
 * **********************************************************************************/
inline void ReTiCycSysTmr_SetCritical(){
    //post hardware dependent code below
     IntDisable(INT_TIMER2A);
}
inline void ReTiCycSysTmr_ReleaseCritical(){
    //post hardware dependent code below
    IntEnable(INT_TIMER2A);
}

void ReTiCyclSysTmrHdl(void);


#endif /* RETI_PORT_CYCLTIMER_CYCLTIMER_PORT_H_ */
