#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <shape.h>

Shape get_shape(const char *shape_name);

void print_shape(Shape *shape);

#endif /* SHAPE_FACTORY_H */
