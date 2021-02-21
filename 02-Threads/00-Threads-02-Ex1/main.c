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

void *print_hello(void *args)
{
	int p = (*(int *)args);
	for(int i = 0; i < 5; i++)
		printf("Hello, World (thread %d)\n", p);
	return NULL;
}

int main(void) {
	int i ;
	pthread_t threads[10];

	for(i = 0; i < 10; i++)
		pthread_create(&threads[i], NULL, print_hello, (void *)&i);

	for(i = 0; i < 10; i++)
		pthread_join(threads[i], NULL);

	return EXIT_SUCCESS;
}
