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
#include <unistd.h>

pthread_mutex_t lock;
int shared_data;

void *thread_function(void *args)
{
	int i;
	for(i = 0; i < 1024 * 1024 * 1024; i++)
	{
		//Shared data here
		pthread_mutex_lock(&lock);
		shared_data++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}


int main(void) {
	pthread_t thread_ID;
	void *exit_status;
	int i;

	/* Initialize mutex */
	pthread_mutex_init(&lock, NULL);

	pthread_create(&thread_ID, NULL, thread_function, NULL);

	//Try to use shared data
	for(i = 0; i < 10; i++)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("\rShared integer's value = %d\n", shared_data);
		pthread_mutex_unlock(&lock);
	}
	printf("\n");

	pthread_join(thread_ID, &exit_status);

	pthread_mutex_destroy(&lock);
	return EXIT_SUCCESS;
}
