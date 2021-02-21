/*
 * Point.c
 *
 *  Created on: Mar 15, 2019
 *      Author: cssouza
 */


#include "Point.h"
#include <stdlib.h>

struct point{
	int x;
	int y;
};

static void Point__init(Point *self, int x, int y)
{
	self->x = x;
	self->y = y;
}

Point *Point__create(int x, int y)
{
	Point *point = (Point *)malloc(sizeof(Point));
	if(point == (void *)0)
		return (void *)0;
	Point__init(point, x, y);
	return point;
}

static void Point__reset(Point *self)
{

}

void Point__destroy(Point *point)
{
	if(point)
	{
		Point__reset(point);
		free(point);
	}
}

int Point__x(Point *self)
{
	return self->x;
}


int Point__y(Point *self)
{
	return self->y;
}
