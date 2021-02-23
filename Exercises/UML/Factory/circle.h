#ifndef __CIRCLE_H
#define __CIRCLE_H 

#include <shape.h>

typedef struct 
{
    Shape shape;
}Circle;

void Circle_constructor(Circle *circle);

#endif