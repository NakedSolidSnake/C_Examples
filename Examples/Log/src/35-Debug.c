/*
 ============================================================================
 Name        : 35-Debug.c
 Author      : Cristiano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/debugger.h"

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	DEBUG_LOG("This is a test MACRO DEBUG %d\n", 10);
	printLog("This is a test MACRO FUNCTION %d\n", 10);
	return EXIT_SUCCESS;
}
