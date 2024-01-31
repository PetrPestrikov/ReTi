/*
 * Scheduler.cpp
 *
 * Created: 06.04.2021 13:01:26
 *  Author: Рабочий
 */ 

/***************************************************
 *      v2.0.0
 ************************************************* */

#include "Scheduler.h"
#include "ReTi/Debug/ReTiDebug.h"
#include <ReTi/Port/DebugStopwatch/DebugStopwatch_port.h>


//select tasks ready for execution and switch to them
void Scheduler_InterruptHandl(void)
{
	unsigned char i = 0;
	Task * Taskptr;

	for(i = 0; i<MAX_TASKS; i++)
	{
		Taskptr = Tasks_ptr[i];
		if(Taskptr == NULL) break;

	}
	
}

//View the list of tasks and call them
void Scheduler(void)
{
	unsigned char i = 0;
	Task * Taskptr;

	for(i = 0; i<NumCurrentTask; i++)
	{
		Taskptr = Tasks_ptr[i];
		if(Taskptr == NULL) break;

#ifdef GLOBAL_STOPWATCH
    benchTimer.Start();
#endif

		Taskptr->ProcessTask();

#ifdef GLOBAL_STOPWATCH
     benchTimer.Stop();
#endif

	}
}

