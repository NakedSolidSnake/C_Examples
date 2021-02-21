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
#include "reciprocal.hpp"

int main(int argc, char *argv[]) {

	int i;
	i = atoi(argv[1]);
	printf("The reciprocal of %d us %g\n", i, reciprocal(i));
	return EXIT_SUCCESS;
}
