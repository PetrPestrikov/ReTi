/*
 * Task.cpp
 *
 * Created: 03.04.2021 2:33:41
 *  Author: Рабочий
 */ 

/***************************************************
 *      v2.0.0
 ************************************************* */


#include <ReTi/System/Task.h>

volatile uint8_t NumCurrentTask = 0;
 
Task* Tasks_ptr[MAX_TASKS];

#define ZERO_CURR_STATE        0
#define ZERO_PREV_STATE        1

Task ::Task()
{
	Task::NumTask = NumCurrentTask;
	Tasks_ptr[NumCurrentTask] = this;
	NumCurrentTask++;
	Task::currStateVariable = ZERO_CURR_STATE;
	Task::prevStateVariable = ZERO_PREV_STATE;
}

 uint8_t Task ::ProcessTask()
{
	return 0;
}

