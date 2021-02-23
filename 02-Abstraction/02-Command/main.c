/*
 * main.c
 *
 *  Created on: 13 de out de 2018
 *      Author: solid
 */

#include <stdio.h>
#include "include/command.h"

void print_Hello(void)
{
	printf("Hello\n");
}

void sum(void)
{
	printf("Sum\n");
}


int main(int argc, char **argv) {
	char command_get[10] = {0};

	Command_Register("HELLO", print_Hello);
	Command_Register("_SUM_", sum);

	do{
		memset(command_get, '\0', sizeof(command_get));
		(void)gets(command_get);
		Command_Execute(command_get);
	}while((strcmp(command_get, "exit")));

	return 0;
}
