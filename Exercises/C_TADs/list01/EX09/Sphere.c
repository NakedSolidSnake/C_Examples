#include "Sphere.h"
#include <stdlib.h>
#include <math.h>

struct Sphere
{
    double radius;
};


Sphere *Sphere_Create(double radius)
{
    Sphere *sphere = (Sphere *)malloc(sizeof(Sphere));
    if(sphere)
    {
        sphere->radius = radius;
    }

    return sphere;
}
void Sphere_Destroy(Sphere *sphere)
{
    if(sphere)
    {
        free(sphere);
    }
}

double Sphere_Get_Radius(const Sphere *sphere)
{
    return sphere->radius;
}

double Sphere_Get_Area(const Sphere *sphere)
{
    return 4.0 * M_PI * pow(sphere->radius, 2.0);
}

double Sphere_Get_Volume(const Sphere *sphere)
{
    return 4.0 * M_PI * pow(sphere->radius, 3.0) / 3.0;
}