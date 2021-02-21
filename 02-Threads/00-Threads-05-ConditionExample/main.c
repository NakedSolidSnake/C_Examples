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

pthread_cond_t is_zero;
pthread_mutex_t mutex;

int shared_data = 32767;

void *thread_function(void *args)
{
	while(shared_data > 0){
		pthread_mutex_lock(&mutex);
		--shared_data;
		pthread_mutex_unlock(&mutex);
	}

	pthread_cond_signal(&is_zero);
	return NULL;
}

int main(void) {
	pthread_t thread_ID;
	void *exit_status;

	pthread_cond_init(&is_zero, NULL);
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&thread_ID, NULL, thread_function, NULL);

	//wait for the shared data to reach zero
	pthread_mutex_lock(&mutex);
	while(shared_data != 0)
		pthread_cond_wait(&is_zero, &mutex);
	pthread_mutex_unlock(&mutex);

	pthread_join(thread_ID, &exit_status);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&is_zero);
	return EXIT_SUCCESS;
}
