/*
 * MainTask.h
 *
 *  Created on: 31 џэт. 2024 у.
 *      Author: 79141
 */

#ifndef TASKS_MAINTASK_H_
#define TASKS_MAINTASK_H_

#include <ReTi/System/Task.h>

#include "hw_level_connection.h"


class MainTask: public Task
{
public:
    MainTask();
    virtual ~MainTask();
    virtual uint8_t ProcessTask();

    InputMsgObj Input;
    InputMsgObj broadcastMsg;


    OutputMsgObj outMsgSysInfo;


private:


    soft_timer Timer;               //common mode timer

};



#endif /* TASKS_MAINTASK_H_ */
