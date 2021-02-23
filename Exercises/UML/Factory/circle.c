#include <circle.h>
#include <stdio.h>

static void Circle_draw(void);

void Circle_constructor(Circle *circle)
{
    circle->shape.draw = Circle_draw;
}

static void Circle_draw(void)
{
    printf("Circle draw.\n");
}