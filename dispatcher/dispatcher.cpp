/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

/*
 * pull current process (if any) off CPU and return it
 * if nothing on CPU returns an uninitialized PCB
 */
PCB Dispatcher::get_from_CPU() {
	is_valid_job_on_cpu = false;
	return cpu->get_process_off_core();
}

/*
 * place the current process on the CPU for execution
 */
void Dispatcher::put_on_CPU(PCB &process) {
	is_valid_job_on_cpu = true;
	cpu->put_process_on_core(process);
}

/*
 * is CPU idle or working
 * returns bool
 */
bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}



