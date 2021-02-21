#include <square.h>
#include <stdio.h>

static void Square_draw(void);

void Square_constructor(Square *square)
{
    square->shape.draw = Square_draw;
}

static void Square_draw(void)
{
    printf("Square draw.\n");
}