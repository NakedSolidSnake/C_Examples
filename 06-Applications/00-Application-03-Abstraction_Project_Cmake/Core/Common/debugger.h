/*
 * debugger.h
 *
 *  Created on: 17 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_COMMON_DEBUGGER_H_
#define CORE_COMMON_DEBUGGER_H_


#include <stdio.h>

#if DEBUG == 1
#define DEBUG_LOG(format, ...)	fprintf (stdout, format, __VA_ARGS__)
#else
#define DEBUG_LOG(format, ...)
#endif

#endif /* CORE_COMMON_DEBUGGER_H_ */
