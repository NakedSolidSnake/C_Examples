#include <stdio.h>
#include <stdlib.h>
#include "Cilinder.h"

int main(int argc, char *argv[])
{
    Cilinder *cilinder = Cilinder_Create(.005, 0.010);

    printf("Cilinder radius %e.\n", Cilinder_Get_Radius(cilinder));
    printf("Cilinder Area %e.\n", Cilinder_Get_Area(cilinder));
    printf("Cilinder Volume %e.\n", Cilinder_Get_Volume(cilinder));

    Cilinder_Destroy(cilinder);
    return 0;
}
