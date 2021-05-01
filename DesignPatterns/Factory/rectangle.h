#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <shape.h>

typedef struct 
{
    Shape shape;
} Rectangle;

Shape rectangle_init(void);

#endif /* RECTANGLE_H */
