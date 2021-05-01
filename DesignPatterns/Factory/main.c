#include <shape_factory.h>

int main()
{
    Shape shape = get_shape("circle");
    print_shape(&shape);

    shape = get_shape("rectangle");
    print_shape(&shape);
    
    shape = get_shape("square");
    print_shape(&shape);

    return 0;
}