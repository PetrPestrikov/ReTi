/**
 * main.c
 */


#include "ReTi/SYSTEM\fms_timers.h"
#include "ReTi/SYSTEM\messages.h"
#include "ReTi/SYSTEM\Scheduler.h"
#include "ReTi/SYSTEM\Task.h"

#include "ReTi/CommTypes\directions.h"

#include "hw_level_connection.h"


int main(void)
{
    InitTimers();       //initializing the software timer service
    InitMessages();     //message service initialization


    HWTimer.delay_us_block(20000);

    while (true)
    {
        ProcessTimers(); //software timer service

        Scheduler();
        ProcessMessages(); //messaging service

    }
	return 0;
} // End main







