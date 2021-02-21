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

void *allocate_buffer(size_t size)
{
	return malloc(size);
}

void deallocate_buffer(void *buffer)
{
	free(buffer);
}

void do_some_work()
{
	void *temp_buffer = allocate_buffer(1024);
	pthread_cleanup_push(deallocate_buffer, temp_buffer);

	/* Do some work here */


	pthread_cleanup_pop (1);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
