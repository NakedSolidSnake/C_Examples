#include <rectangle.h>
#include <stdio.h>

static void rectangle_draw(void)
{
    printf("This is a rectangle.\n");
}


Shape rectangle_init(void)
{
    Shape shape = 
    {
        .draw = rectangle_draw
    };

    return shape;
}