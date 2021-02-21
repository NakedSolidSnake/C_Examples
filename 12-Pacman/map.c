/*
 * map.c
 *
 *  Created on: 17 de mar de 2019
 *      Author: solid
 */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

struct position{
	int x;
	int y;
};

struct map{
	char **map_buffer;
	int columns;
	int lines;
	struct position pos;
};



static void get_player_position(MAP *map)
{
	if(map == NULL)
		return;
	for(int i = 0; i < map->lines; i++)
	{
		for(int j = 0; j < map->columns; j++)
		{
			if(map->map_buffer[i][j] == '@')
			{
				map->pos.x = i;
				map->pos.y = j;
				break;
			}
		}
	}
}

MAP *create_map(void)
{
	MAP *map = (MAP *)malloc(sizeof(MAP));

	FILE *map_file = fopen("mapa.txt", "r");
	if(map_file == NULL)
	{
		printf("Erro na abertura do mapa");
		return NULL;
	}

	fscanf(map_file, "%d %d", &map->lines, &map->columns);

	map->map_buffer = (char **)malloc(sizeof(char *) * map->lines);


	for(int i = 0; i < map->lines; i++){
		map->map_buffer[i] = (char *)malloc(map->columns + 1);
	}

	for(int i = 0; i < map->lines; i++)
	{
		fscanf(map_file, "%s", map->map_buffer[i]);
	}
	fclose(map_file);

	get_player_position(map);

	return map;
}

void free_map(MAP *map)
{

	if(map == NULL)
		printf("There is no memory to free.\n");

	for(int i = 0; i < map->lines; i++){
		free(map->map_buffer[i]);
	}

	free(map->map_buffer);
}

void print_map(MAP *map)
{
	if(map == NULL)
		return;

	for(int i = 0; i < map->lines; i++)
	{
		printf("%s\n", map->map_buffer[i]);
	}
}

void move(struct map *map, char direcao)
{
	if(map == NULL)
	{
		return;
	}

	int currentX = map->pos.x;
	int currentY = map->pos.y;

	switch(direcao)
	{
	case 'a':
		currentY--;
		break;
	case 'w':
		currentX--;
		break;
	case 's':
		currentX++;
		break;
	case 'd':
		currentY++;
		break;

	default:
		return;
	}

	if(currentX >= map->lines)
		return;
	if(currentY >= map->columns)
		return;
	if(map->map_buffer[currentX][currentY] != '.')
		return;

	map->map_buffer[currentX][currentY] = '@';
	map->map_buffer[map->pos.x][map->pos.y] = '.';
	map->pos.x = currentX;
	map->pos.y = currentY;

}

char get_command(void)
{
	char command;
	scanf(" %c", &command);
	return command;
}
