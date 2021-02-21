/*
 * map.h
 *
 *  Created on: 17 de mar de 2019
 *      Author: solid
 */

#ifndef MAP_H_
#define MAP_H_

typedef struct map MAP;

void free_map(MAP *map);
MAP *create_map(void);
void print_map(MAP *map);
void move(MAP *map, char direction);
char get_command(void);

#endif /* MAP_H_ */
