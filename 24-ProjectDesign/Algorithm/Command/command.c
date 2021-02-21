/*
 * command.c
 *
 *  Created on: 13 de out de 2018
 *      Author: solid
 */


#include "command.h"
#include <string.h>

#define MAX_LETTERS 5
#define MAX_COMMAND_REGISTER 10

typedef struct Command_Table{
	char command_name[MAX_LETTERS];
	Command_Function_t function;
}Command_Table_t;

typedef struct Command_Context{
	Command_Table_t command_table[MAX_COMMAND_REGISTER];
	uint8_t command_count;
}Command_Context;

static Command_Context command_ctx = {
	.command_count = 0
};

uint8_t Command_Register(const char *command_name, Command_Function_t function)
{
	if(!command_name && !function){
		//Invalid Parameters
		return 1;
	}

	if(command_ctx.command_count > MAX_COMMAND_REGISTER)
	{
		//unable to register max registers reached
		return 1;
	}

	if(strlen(command_name) == MAX_LETTERS){
		strcpy(command_ctx.command_table[command_ctx.command_count].command_name, command_name);
		command_ctx.command_table[command_ctx.command_count].function = function;
		command_ctx.command_count++;
	}
	return 0;
}

uint8_t Command_Execute(const char *command_name)
{
	int idx;

	if(!command_name){
		//Invalid Parameters
		return 1;
	}

	for(idx = 0; idx < command_ctx.command_count; idx++)
	{
		if(!strcmp(command_ctx.command_table[idx].command_name, command_name))
		{
			command_ctx.command_table[idx].function();
			return idx;
		}
	}

	return 0;
}
