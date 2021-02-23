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
#include "malloc_contro.h"

int main(void) {

	int *p = (int *)malloc_register(sizeof(int) * 1);
	int *p2 = (int *)malloc_register(sizeof(int) * 1);

	int t = malloc_registered();

	printf("total alocado = %d\n", t);

	free_register(p);
	free_register(p2);



	return EXIT_SUCCESS;
}
