/*
 * scheduler.h
 *
 *  Created on: Mar 21, 2019
 *      Author: cssouza
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/* this define runs on microseconds */
#define BASE_TIME_SCHEDULER			1000		//configures to 1ms interval

/* Define amount of tasks on the system */
#define MAX_TASKS 10

typedef void (*Task)(void);

typedef struct Tasks_t{
	Task callback;
	unsigned long int timeout;
}Tasks_t;

void register_task(Tasks_t *task);
void remove_task(Tasks_t *task);


void scheduler_run(void);

#endif /* SCHEDULER_H_ */
