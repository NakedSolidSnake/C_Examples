#ifndef SQUARE_H
#define SQUARE_H

#include <shape.h>

typedef struct  
{
    Shape shape;
} Square;

Shape square_init(void);

#endif /* SQUARE_H */
