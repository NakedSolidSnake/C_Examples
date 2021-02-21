/*
 * scheduler.c
 *
 *  Created on: Mar 21, 2019
 *      Author: cssouza
 */

#include "scheduler.h"

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct sched{
	Tasks_t tasks[MAX_TASKS];
	unsigned long int old_time[MAX_TASKS];
	int task_amount;
}Sched;

static Sched sched_ctx = {
		.task_amount = 0
};

static void *switch_tasks(void * args);

void register_task(Tasks_t *task)
{

	if(task == NULL)
		return;

	if(sched_ctx.task_amount <= MAX_TASKS)
	{
		sched_ctx.tasks[sched_ctx.task_amount].callback = task->callback;
		sched_ctx.tasks[sched_ctx.task_amount].timeout = task->timeout * BASE_TIME_SCHEDULER;
		sched_ctx.task_amount++;
	}
}

void remove_task(Tasks_t *task)
{
	if(sched_ctx.task_amount > 0)
	{
		sched_ctx.tasks[sched_ctx.task_amount].callback = NULL;
		sched_ctx.tasks[sched_ctx.task_amount].timeout = 0;
		sched_ctx.task_amount--;
	}
}

void scheduler_run(void)
{
	pthread_t threadTimer;
	pthread_create(&threadTimer, NULL, switch_tasks, NULL);
	pthread_join(threadTimer, NULL);
}


void *switch_tasks(void *args)
{
	static unsigned long int delay = 0;

	while(1)
	{

		usleep(1000);
		for(int idx = 0; idx < sched_ctx.task_amount; idx++)
		{
			unsigned long int current = sched_ctx.old_time[idx] + sched_ctx.tasks[idx].timeout;
			if( current < delay  )
			{
				sched_ctx.tasks[idx].callback();
				sched_ctx.old_time[idx] = delay;
			}
		}

		++delay;
	}

	return NULL;
}
