#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>

typedef struct 
{
    Shape shape;
} Circle;

Shape circle_init(void);

#endif /* CIRCLE_H */
