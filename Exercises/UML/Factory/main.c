#include <shapefactory.h>
#include <shape.h>

int main(int argc, char *argv[])
{
    ShapeFactory shapeFactory;
    void *shape;
    ShapeFactory_constructor(&shapeFactory);

    shape = ShapeFactory_getShape(&shapeFactory, "circle");
    Shape_draw(shape);

    shape = ShapeFactory_getShape(&shapeFactory, "rectangle");
    Shape_draw(shape);

    shape = ShapeFactory_getShape(&shapeFactory, "square");
    Shape_draw(shape);

    return 0;
}
