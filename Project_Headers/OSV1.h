/*
 * OSV1.h
 *
 *  Created on: Jan 19, 2018
 *      Author: Ricod
 */

#ifndef OSV1_H_
#define OSV1_H_
#define PROCESS_NAME_LENGTH 8
#define NB_PROCESS	(4)
#define NB_PRIO		(64)
#define NULL	((void*)0)
#if (NB_PRIO>255)
#error max is 255
#endif


typedef void (*T_function)(void);
typedef struct {
	unsigned char name[PROCESS_NAME_LENGTH];
	char prio;
	void (*function)();
	unsigned long execution_time;
	unsigned long timer;
} T_process;

typedef struct _elem {
	struct _elem *next;
	T_process * process;
} T_elem_list_process;

T_elem_list_process;
extern T_process processes[NB_PROCESS];
void os_init(void);
void os_start(void);
void os_sleep(unsigned int time);
void process_init(T_process *process, const unsigned char * name,
		const void (*function)(void));
void process_start(T_process * process);
#endif /* OSV1_H_ */
