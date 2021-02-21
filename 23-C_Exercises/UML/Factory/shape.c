#include <shape.h>

void Shape_draw(void *shape)
{
    ((Shape *)shape)->draw();
}