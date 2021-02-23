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
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	pid_t child_pid;

	child_pid = fork();
	if(child_pid > 0)
	{
		sleep(60);
	}
	else{
		exit(0);
	}
	return EXIT_SUCCESS;
}
