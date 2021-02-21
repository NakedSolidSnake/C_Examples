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

int spawn(char *program, char **arg_list)
{
	pid_t child_pid;

	child_pid = fork();
	if(child_pid != 0)
		return child_pid;
	else{
		execv(program, arg_list);
		fprintf(stderr, "An error ocurred in execvp\n");
		abort();
	}
	return 0;
}

int main(void) {
	char *arg_list[] = {
			"ls",
			"-l",
			"/",
			NULL
	};

	spawn("ls", arg_list);
	printf("Done with main program\n");

	return EXIT_SUCCESS;
}
