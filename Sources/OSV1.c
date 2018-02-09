/*
 * OSV1.c
 *
 *  Created on: Jan 19, 2018
 *      Author: Ricod
 */

#include "OSV1.h"
#include "chained_list.h"
#define NULL ((void*)0)
T_process processes[4];
T_elem_list_process *ready;
T_elem_list_process *stopped;
T_elem_list_process *waiting;
T_elem_list_process *process_by_prio[NB_PRIO];
T_process*running_process = NULL;
void toto(void) {

}
void process_init(T_process *process, const unsigned char * name,
		const void (*function)(void)) {
	unsigned char i;

	for (i = 0; i < PROCESS_NAME_LENGTH; i++) {
		process->name[i] = name[i];
	}
	process->prio = 0;
	process->function = function;
	process->execution_time = 0;
	process->timer = 0;
}
void os_init(void) {
	unsigned char i;

	for (i = 0; i < NB_PROCESS; i++) {
		processes[i].function = NULL;
	}
	ready = NULL;
	stopped = NULL;
	waiting = NULL;
	for (i = 0; i < NB_PRIO; i++)
		process_by_prio[i] = NULL;
}
void os_sleep(unsigned int time) {
	unsigned long i;
	for (i = 0; i <= time; i++)
		;
}
void process_start(T_process * process) {
	T_elem_list_process *elem;
	elem = chained_list_create_element(process);
	chained_list_append(ready, elem);
}
void os_start() {
	T_elem_list_process *elem = ready;
	while (1) {
		elem->process->function();
		chained_list_pop_first(&ready);
		chained_list_append(ready, elem);
		elem = chained_list_get_first(ready);
	}
}
