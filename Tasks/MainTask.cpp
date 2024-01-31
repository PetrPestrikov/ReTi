/*
 * MainTask.cpp
 *
 *  Created on: 31 џэт. 2024 у.
 *      Author: 79141
 */


#include "MainTask.h"



//status codes of the MainTask FSM
#define PREPARE_MAINTASK_STATE          0
#define SYSTEM_INIT_STATE               1
#define MAIN_TASK_WORK_STATE            2
#define ALARM_MODE_STATE                3





MainTask::MainTask()
{

}

MainTask::~MainTask()
{
    // TODO Auto-generated destructor stub
}


uint8_t MainTask::ProcessTask()
{
    switch (currStateVariable)
    {
        /////////////////////////////////
        case PREPARE_MAINTASK_STATE:
        {
            if(prevStateVariable != currStateVariable)       //first entry into state
            {
                prevStateVariable = currStateVariable;

            }//first entry into state


            break;
        }
        /////////////////////////////////
        case SYSTEM_INIT_STATE:
        {
            if(prevStateVariable != currStateVariable)       //first entry into state
            {
                prevStateVariable = currStateVariable;
            }//first entry into state





            break;
        }
        /////////////////////////////////
        case MAIN_TASK_WORK_STATE:
        {
            if(prevStateVariable != currStateVariable)       //first entry into state
            {
                prevStateVariable = currStateVariable;
            }//first entry into state


            break;
        }
        /////////////////////////////////////
        case NOT_ACTIVE_STATE:
        {
            if(prevStateVariable != currStateVariable)       //first entry into state
            {
                prevStateVariable = currStateVariable;
            }//first entry into state


            break;
        }
        //////////////////////////////////////////////////////////////////////////////
        case ALARM_MODE_STATE:
        {
            if(prevStateVariable != currStateVariable)       //first entry into state
            {
                prevStateVariable = currStateVariable;
            }//first entry into state


            break;
        }
    /////////////////////////////////
    }

    return 0;
}














