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

pid_t get_pid_from_proc_self()
{
	char target[32];
	int pid;

	readlink("/proc/self", target, sizeof(target));
	sscanf(target, "%d", &pid);
	return (pid_t)pid;
}

int main(void) {
	printf("/proc/self reports process id %d\n",(int) get_pid_from_proc_self ());
	printf ("getpid() reports process id %d\n", (int) getpid ());
	return EXIT_SUCCESS;
}
