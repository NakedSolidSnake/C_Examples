#ifndef __SQUARE_H
#define __SQUARE_H 

#include <shape.h>

typedef struct 
{
    Shape shape;
}Square;

void Square_constructor(Square *square);

#endif