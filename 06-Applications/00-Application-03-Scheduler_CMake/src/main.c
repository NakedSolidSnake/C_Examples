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
#include "scheduler.h"

void hello_world(void)
{
	printf("Hello World 1\n");
}

void bye(void)
{
	printf("bye\n");
}

int main(void) {

	Tasks_t task1 = {
			.callback = hello_world,
			.timeout = 1
	};

	Tasks_t task2 = {
			.callback = bye,
			.timeout = 10
	};

	register_task(&task1);
	register_task(&task2);

	scheduler_run();

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

