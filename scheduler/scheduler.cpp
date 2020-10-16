/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/scheduler.h"

/*
 *add a process, either a new one or one that
 *had been running on the CPU and has been preempted
 */
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
}

/*
 * returns the next process in the ready_q
 */
PCB Scheduler::getNext() {
	PCB next;
	if (!ready_q->empty()) {
		next = ready_q->front();
		ready_q->pop();
	}
	return next;
}

/*
 * Checks the ready_q to see if there are any jobs on queue
 * returns true if empty and false otherwise
 */
bool Scheduler::isEmpty() {
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (preemptive && tick_count >= time_slice) {
		return true;
	}
	else {
		return p.remaining_cpu_time <=0;
	}
}
/*
 * sort ready_q based on the scheduler algorithm used whenever add(PCB p) is called
 * pure virtual function
 */
void Scheduler::sort(){}
