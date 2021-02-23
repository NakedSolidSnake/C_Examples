/*
 * Point.h
 *
 *  Created on: Mar 15, 2019
 *      Author: cssouza
 */

#ifndef POINT_H_
#define POINT_H_

typedef struct point Point;

Point * Point__create(int x, int y);
void Point__destroy(Point * self);
int Point__x(Point * self);
int Point__y(Point * self);

#endif /* POINT_H_ */
