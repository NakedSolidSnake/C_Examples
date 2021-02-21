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
#include "map.h"

int main(void) {

	MAP *map;

	map = create_map();
	do{
		print_map(map);
		move(map, get_command());
	}while(1);

	free_map(map);
	return EXIT_SUCCESS;
}
