#include <circle.h>
#include <stdio.h>

static void circle_draw(void)
{
    printf("This is a circle.\n");
}


Shape circle_init(void)
{
    Shape shape = 
    {
        .draw = circle_draw
    };

    return shape;
}