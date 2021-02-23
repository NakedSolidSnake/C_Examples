#ifndef __SHAPE_H
#define __SHAPE_H

typedef void (*Draw)(void);

typedef struct 
{
    Draw draw;
}Shape;

void Shape_draw(void *shape);

#endif