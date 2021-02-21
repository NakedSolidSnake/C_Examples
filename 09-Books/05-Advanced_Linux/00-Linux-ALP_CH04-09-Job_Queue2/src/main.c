/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

struct job{
	struct job *next;
};

struct job *job_queue;

int process_job(struct job *job_execute)
{
	return 0;
}

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
	while(1)
	{
		struct job *next_job;

		pthread_mutex_lock(&job_queue_mutex);

		if(job_queue == NULL)
			next_job = NULL;
		else
		{
			next_job = job_queue;
			/* Remove job from list */
			job_queue = job_queue->next;
		}

		pthread_mutex_unlock(&job_queue_mutex);

		if(next_job == NULL)
			break;

		process_job(next_job);
		free(next_job);
	}
	return NULL;
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
