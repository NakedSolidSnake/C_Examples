/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_xs(void *args)
{
	while(1)
		fputc('x', stderr);
	return NULL;
}

int main(void) {
	pthread_t thread_id;

	pthread_create(&thread_id, NULL, &print_xs, NULL);
	while(1)
		fputc('o', stderr);
	return EXIT_SUCCESS;
}
