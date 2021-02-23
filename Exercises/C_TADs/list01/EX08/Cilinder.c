#include "Cilinder.h"
#include <math.h>


struct Cilinder
{
    double radius;
    double height;
};

Cilinder *Cilinder_Create(double radius, double height)
{
    Cilinder *cilinder = (Cilinder *)malloc(sizeof(Cilinder));
    if(cilinder)
    {
        cilinder->height = height;
        cilinder->radius = radius;
    }

    return cilinder;
}

void Cilinder_Destroy(Cilinder *cilinder)
{
    if(cilinder)
    {
        free(cilinder);
    }
}

double Cilinder_Get_Height(const Cilinder *cilinder)
{    
    if(cilinder)
    {
        return cilinder->height;
    }

    return -1.0;
}

double Cilinder_Get_Radius(const Cilinder *cilinder)
{
    if(cilinder)
    {
        return cilinder->radius;
    }

    return -1.0;
}

double Cilinder_Get_Area(const Cilinder *cilinder)
{
    if(cilinder)
    {
        return M_PI * pow(cilinder->radius, 2.0);
    }

    return -1.0;
}

double Cilinder_Get_Volume(const Cilinder *cilinder)
{
    if(cilinder)
    {
        return Cilinder_Get_Area(cilinder) * cilinder->height;
    }

    return -1.0;
}