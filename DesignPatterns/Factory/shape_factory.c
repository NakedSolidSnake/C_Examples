#include <shape_factory.h>
#include <string.h>
#include <circle.h>
#include <rectangle.h>
#include <square.h>

#define CIRCLE      "circle"
#define SQUARE      "square"
#define RECTANGLE   "rectangle"

Shape get_shape(const char *shape_name)
{
    Shape shape;

    if(!strncmp(shape_name, CIRCLE, strlen(CIRCLE)))
    {
        shape = circle_init();
    }
    else if(!strncmp(shape_name, SQUARE, strlen(SQUARE)))
    {
        shape = square_init();
    }

    else if(!strncmp(shape_name, RECTANGLE, strlen(RECTANGLE)))
    {
        shape = rectangle_init();
    }

    return shape;
}

void print_shape(Shape *shape)
{
    shape->draw();
}
