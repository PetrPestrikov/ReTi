/*
 * ReTiDebug.h
 *
 *  Created on: 20 окт. 2023 г.
 *      Author: 79141
 */

#ifndef RETI_DEBUG_RETIDEBUG_H_
#define RETI_DEBUG_RETIDEBUG_H_

#include <ReTi/Port/DebugStopwatch/DebugStopwatch_port.h>



#define GLOBAL_STOPWATCH
//#define LOCAL_STOPWATCH






#ifdef GLOBAL_STOPWATCH

    BenchTimer g_globalExecuBench[MAX_TASKS];

#endif
#ifdef LOCAL_STOPWATCH

#endif


#endif /* RETI_DEBUG_RETIDEBUG_H_ */
