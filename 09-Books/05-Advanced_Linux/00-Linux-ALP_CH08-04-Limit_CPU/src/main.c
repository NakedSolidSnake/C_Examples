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

int main(void) {

	struct rlimit rl;

	getrlimit(RLIMIT_CPU, &rl);
	rl.rlim_cur = 1;
	setrlimit(RLIMIT_CPU, &rl);

	while(1);
	return EXIT_SUCCESS;
}

