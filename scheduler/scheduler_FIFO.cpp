/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_FIFO.h"

/*
 * override base class behaviour if necessary, otherwise call it
 * not preemptive so no need to check for algorithm
 * scheduler implementation already accounts for this so call
 * scheduler::time_to_switch_processes
 */
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

/*
 * FIFO - not preemptive - no sorting needed
 */
void Scheduler_FIFO::sort(){}
