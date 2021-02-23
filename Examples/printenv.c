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

extern char **environ;

int main(void) {

	char ** var;

	for(var = environ; *var != NULL; ++var)
	{
		printf("%s\n", *var);
	}

	return EXIT_SUCCESS;
}
