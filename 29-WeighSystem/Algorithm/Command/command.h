/*
 * command.h
 *
 *  Created on: 13 de out de 2018
 *      Author: solid
 */

#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_

#include <stdint.h>

typedef void (*Command_Function_t)(void);

uint8_t Command_Register(const char *command_name, Command_Function_t function);
uint8_t Command_Execute(const char *command_name);

#endif /* INCLUDE_COMMAND_H_ */
