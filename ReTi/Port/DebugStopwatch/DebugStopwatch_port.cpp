/*
 * DebugStopwatch_port.cpp
 *
 *  Created on: 20 ���. 2023 �.
 *      Author: 79141
 */


#include <ReTi/Port/DebugStopwatch/DebugStopwatch_port.h>

static BenchTimerFooInit   BenchTimerFooPtr = {65535,GetBenchTimerVal,BenchTimerInit};
       BenchTimer          benchTimer (&BenchTimerFooPtr);


/********************************************************************************
 *
 * functions for working Debug benchmark time service
 *
 ****************************************************************************** */
void BenchTimerInit(void)
{

}
uint32_t GetBenchTimerVal(void)
{

    return 0;
}
