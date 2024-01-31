/*
 * Task.h
 *
 */ 

/***************************************************
 *      v2.0.0
 ************************************************* */


#ifndef TASK_H_
#define TASK_H_

#include <stdint.h>

#include "messages.h"
#include "fms_timers.h"
#include "Scheduler.h"
#include "system_settings.h"

#define ALARM_TASK_STATE           40   //task crash state
#define NOT_ACTIVE_STATE        50        //state number, the same for all automata. In this state, the machine does nothing


extern volatile uint8_t NumCurrentTask;    //number of the current idle task in the general array of tasks



class Task
{
	public:
		Task();
		virtual uint8_t ProcessTask(void);            //task handler

        uint8_t currStateVariable;                 // number of the current state of the vending machine
        uint8_t prevStateVariable;                 //number of the previous state of the machine
		uint8_t NumTask;
};

extern Task* Tasks_ptr[MAX_TASKS];


#endif /* TASK_H_ */
