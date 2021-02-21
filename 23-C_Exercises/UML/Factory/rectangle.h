#ifndef __RECTANGLE_H
#define __RECTANGLE_H 

#include <shape.h>

typedef struct 
{
    Shape shape;
}Rectangle;

void Rectangle_constructor(Rectangle *rectangle);

#endif