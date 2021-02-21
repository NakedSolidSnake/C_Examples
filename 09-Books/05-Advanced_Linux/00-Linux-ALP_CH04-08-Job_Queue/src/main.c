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
	struct job* next;
	void *data;
};

struct job* job_queue;

int process_job(struct job *jobs)
{

}

void *thread_function(void *arg)
{
	while(job_queue != NULL)
	{
		struct job* next_job = job_queue;
		job_queue = job_queue->next;
		process_job(next_job);
		free(next_job);
	}
	return NULL;
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
