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
#include "Point.h"

int main(void) {

	Point *point = Point__create(10, 10);
	if(point == NULL)
	{
		return EXIT_FAILURE;
	}


	printf("Point x = %d\n", Point__x(point));
	printf("Point y = %d\n", Point__y(point));

	Point__destroy(point);

	return EXIT_SUCCESS;
}
