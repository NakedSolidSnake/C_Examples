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

void *thread_function(void *arg)
{
	fprintf(stderr, "child thread pid is %d\n", (int)getpid());

	while(1);
	return NULL;
}

int main(void) {
	pthread_t thread;
	fprintf(stderr, "main thread pid is %d\n", (int)getpid());

	pthread_create(&thread, NULL, &thread_function, NULL);
	while(1);
	return EXIT_SUCCESS;
}
