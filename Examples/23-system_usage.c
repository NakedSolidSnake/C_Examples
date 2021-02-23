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
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

void print_cpu_time()
{
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	printf("CPU time: %d.%06ld sec user, %ld.%06ld sec system\n", usage.ru_utime.tv_sec,
			usage.ru_utime.tv_usec, usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
