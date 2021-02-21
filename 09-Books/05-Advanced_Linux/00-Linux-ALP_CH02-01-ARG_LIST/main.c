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

int main(int argc, char **argv) {

	printf("The name of this program is '%s'.\n", argv[0]);
	printf("This program was invoked with %d arguments.\n", argc - 1);

	if(argc > 1)
	{
		int i;
		printf("the arguments are:\n");
		for(i = 1; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	}
}
