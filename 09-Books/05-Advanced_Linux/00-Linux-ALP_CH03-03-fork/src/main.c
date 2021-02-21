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

	printf("The main program process ID is %d\n", (int)getpid());

	child_pid = fork();
	if(child_pid != 0)
	{
		printf("This is a parent process, with id %d\n", (int)getpid());
		printf("The child process ID is %d\n", (int)child_pid);
	}
	else{
		printf("This is the child process, with id %d\n", (int)getpid());
	}

	return EXIT_SUCCESS;
}
