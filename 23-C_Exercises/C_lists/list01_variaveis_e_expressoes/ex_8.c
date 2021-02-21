#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float celsius;
    float kelvin;

    printf("Type a Temperature in Kelvin .:");
    scanf("%f", &kelvin);

    celsius = kelvin - 273.15;
    printf("The temperature in Celsius is %f.\n", celsius);
    return EXIT_SUCCESS;
}