#include <shapefactory.h>
#include <string.h>

void ShapeFactory_constructor(ShapeFactory *shapeFactory)
{
    Circle_constructor(&shapeFactory->circle);
    Rectangle_constructor(&shapeFactory->rectangle);
    Square_constructor(&shapeFactory->square);
}

void *ShapeFactory_getShape(ShapeFactory *shapeFactory, const char *shapeType)
{
    void *shape = NULL;
    if(!strncmp(RECTANGLE_NAME, shapeType, 9))
    {
        shape = (void *)&shapeFactory->rectangle;
    }
    else if(!strncmp(CIRCLE_NAME, shapeType, 6))
    {
        shape = (void *)&shapeFactory->circle;
    }
    else if(!strncmp(SQUARE_NAME, shapeType, 6))
    {
        shape = (void *)&shapeFactory->square;
    }

    return shape;
}