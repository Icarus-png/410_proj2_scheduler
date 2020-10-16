/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content

#include <algorithm>
#include "../includes/scheduler_SRTF.h"

using namespace std;

/**
 * if time of process p > current processes remaining time, then we need to switch
 * or if remaining time of p is equal or belo zero we need to switch(similar to bas class)
 * otherwise we return false
 */
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	PCB temp = ready_q->front();
	if (p.remaining_cpu_time > temp.remaining_cpu_time || p.remaining_cpu_time <= 0) {
		return true;
	}
	return false;
}

/*
 * helper class comparing times of two processes
 * used in sort() algorithm
 */
bool comp_rem(PCB a, PCB b) {
	return a.remaining_cpu_time > b.remaining_cpu_time;
}

/*
 * RTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p)
 * or time_to_switch_processes is called
 */
void Scheduler_SRTF::sort() {
	vector<PCB> sorted;//vector to hold ready_q elements

	//Empty ready_q contents into vector
	while (!ready_q->empty()) {
		sorted.push_back(ready_q->front());
		ready_q->pop();
	}

	//sort vector using comp_rem
	std::sort(sorted.begin(), sorted.end(), comp_rem);

	//empty sorted vector back into ready_q
	while (!sorted.empty()) {
		ready_q->push(sorted.back());
		sorted.pop_back();
	}
}
