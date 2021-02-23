#ifndef __SHAPEFACTORY_H
#define __SHAPEFACTORY_H

#include <circle.h>
#include <square.h>
#include <rectangle.h>

#define CIRCLE_NAME     "circle"
#define RECTANGLE_NAME  "rectangle"
#define SQUARE_NAME     "square"

typedef struct 
{
    Circle circle;
    Square square;
    Rectangle rectangle;
}ShapeFactory;

void ShapeFactory_constructor(ShapeFactory *shapeFactory);
void *ShapeFactory_getShape(ShapeFactory *shapeFactory, const char *shapeType);

#endif