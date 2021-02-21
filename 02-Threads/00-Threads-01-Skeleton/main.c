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
#include <pthread.h>

void *thread_function(void *arg)
{
	int *incoming = (int *)arg;

	return NULL;
}

int main(void) {
	pthread_t thread_ID;
	void *exit_status;
	int value;

	value = 42;
	pthread_create(&thread_ID, NULL, thread_function, &value);

	pthread_join(thread_ID, &exit_status);

	return EXIT_SUCCESS;
}
