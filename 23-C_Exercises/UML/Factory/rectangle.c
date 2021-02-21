#include <rectangle.h>
#include <stdio.h>

static void Rectangle_draw(void);

void Rectangle_constructor(Rectangle *rectangle)
{
    rectangle->shape.draw = Rectangle_draw;
}

static void Rectangle_draw(void)
{
    printf("Rectangle draw.\n");
}