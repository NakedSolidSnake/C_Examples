#include <stdio.h>
#include <stdlib.h>
#include "Cube.h"

int main(int argc, char *argv[])
{
    Cube *cube = Cube_Create(25.0);

    printf("Cube size %e.\n", Cube_Get_Side(cube));
    printf("Cube Area %e.\n", Cube_Get_Area(cube));
    printf("Cube Volume %e.\n", Cube_Get_Volume(cube));

    Cube_Destroy(cube);
    return 0;
}
