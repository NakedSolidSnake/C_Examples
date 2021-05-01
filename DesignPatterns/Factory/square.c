#include <square.h>
#include <stdio.h>

static void square_draw(void)
{
    printf("This is a square.\n");
}

Shape square_init(void)
{
    Shape shape = 
    {
        .draw = square_draw
    };

    return shape;
}