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
#include <unistd.h>

int main(void) {
	printf("The process ID is %d\n", (int)getpid());
	printf("The parent process ID is %d\n", (int)getppid());
	return EXIT_SUCCESS;
}
