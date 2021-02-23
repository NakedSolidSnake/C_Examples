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
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char target_path[256];
	char *link_path = argv[1];

	int len = readlink(link_path, target_path, sizeof(target_path));

	if(len == -1)
	{
		if(errno == EINVAL)
			fprintf(stderr, "%s is not a symbolic link\n", link_path);
		else
			perror("readlink");
		return 1;
	}
	else
	{
		target_path[len] = '\0';
		printf("%s\n", target_path);
		return EXIT_SUCCESS;
	}
}
