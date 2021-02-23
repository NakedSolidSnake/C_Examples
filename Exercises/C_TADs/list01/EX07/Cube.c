#include "Cube.h"
#include <math.h>
#include <stdlib.h>

struct Cube
{
    double side;
};

Cube *Cube_Create(double side)
{
    Cube *cube = (Cube *)malloc(sizeof(Cube));
    if(cube)
    {
        cube->side = side;
    }

    return cube;
}

void Cube_Destroy(Cube *cube)
{
    if(cube)
    {
        free(cube);
    }
}


double Cube_Get_Side(const Cube *cube)
{
    return cube->side;
}

double Cube_Get_Area(const Cube *cube)
{
    return pow(cube->side, 2.0);
}

double Cube_Get_Volume(const Cube *cube)
{
    return pow(cube->side, 3.0);
}