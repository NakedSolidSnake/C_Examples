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
#include <semaphore.h>

struct job{
	struct job *next;
	int data;
};

struct job *job_queue;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
