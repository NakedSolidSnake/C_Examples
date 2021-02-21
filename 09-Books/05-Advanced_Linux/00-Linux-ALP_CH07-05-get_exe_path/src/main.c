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
#include <limits.h>
#include <string.h>
#include <unistd.h>

size_t get_executable_path(char *buffer, size_t len)
{
	char *path_end;

	if(readlink("/proc/self/exe", buffer, len) <= 0)
	{
		return -1;
	}

	path_end = strrchr(buffer, '/');
	if(path_end == NULL)
		return -1;

	++path_end;

	*path_end = '\0';

	return (size_t)(path_end - buffer);
}

int main(void) {
	char path[PATH_MAX];
	get_executable_path(path, sizeof(path));
	printf("This program is in the directory %s\n", path);
	return EXIT_SUCCESS;
}
