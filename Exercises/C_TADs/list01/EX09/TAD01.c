#include <stdio.h>
#include <stdlib.h>
#include "Sphere.h"

int main(int argc, char *argv[])
{
    Sphere *sphere = Sphere_Create(.005);

    printf("Sphere radius %e.\n", Sphere_Get_Radius(sphere));
    printf("Sphere Area %e.\n", Sphere_Get_Area(sphere));
    printf("Sphere Volume %e.\n", Sphere_Get_Volume(sphere));

    Sphere_Destroy(sphere);
    return 0;
}
