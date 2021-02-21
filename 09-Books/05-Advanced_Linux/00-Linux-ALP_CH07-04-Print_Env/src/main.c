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
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_process_enviroment(pid_t pid)
{
	int fd;
	char filename[24];
	char environment[1024 * 8];
	size_t length;
	char *next_var;

	snprintf(filename, sizeof(filename), "/proc/%d/environ", (int)pid);

	fd = open(filename, O_RDONLY);
	length = read(fd, environment, sizeof(environment));
	close(fd);

	environment[length] = '\0';

	next_var = environment;

	while(next_var < environment + length)
	{
		printf("%s\n", next_var);
		next_var += strlen(next_var) + 1;
	}
}

int main(int argc, char *argv[1]) {
	pid_t pid = (pid_t)atoi(argv[1]);
	print_process_enviroment(pid);
	return EXIT_SUCCESS;
}
