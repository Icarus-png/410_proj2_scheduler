/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"

/*
 * override base class behaviour if necessary, otherwise call it
 * need to override base class for RR
 * I first check remaining cpu time to see if we need to switch
 * else check required vs remaining mod time_slice
 * if zero return true
 * (Gone over in class)
 */
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	else {
		return (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0;
	}
}

/*
 * RR - preemptive - no sorting of ready_q needed.
 */
void Scheduler_RR::sort(){}
