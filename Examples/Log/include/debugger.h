/*
 * debugger.h
 *
 *  Created on: 17 de fev de 2019
 *      Author: solid
 */

#ifndef DEBUGGER_H_
#define DEBUGGER_H_

#define DEBUGGER_MACRO    0
#define DEBUGGER_FUNCTION 0

#include <stdio.h>
#include <stdarg.h>

/* Macro debug */
#if DEBUGGER_MACRO == 1
#define DEBUG_LOG(x, arguments)		printf(x, arguments)
#else
#define DEBUG_LOG(x, arguments)
#endif

/* Function Debug */
void printLog(char *format, ...)
{
#if DEBUGGER_FUNCTION == 1
	char log[80];

	va_list args;
	va_start(args, format);
	vsprintf(log, format, args);
	//send message
	printf("%s", log);
	va_end(args);

#endif
}


#endif /* DEBUGGER_H_ */
