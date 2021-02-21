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
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void print_time()
{
	struct timeval tv;
	struct tm *ptm;
	char time_string[40];
	long miliseconds;

	gettimeofday(&tv, NULL);

	ptm = localtime(&tv.tv_sec);
	strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", ptm);
	miliseconds = tv.tv_sec / 1000;

	printf("%S.%03ld\n", time_string, miliseconds);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
