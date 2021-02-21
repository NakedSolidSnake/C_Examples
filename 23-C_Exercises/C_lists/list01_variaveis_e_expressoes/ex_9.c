#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float celsius;
    float kelvin;

    printf("Type a Temperature in Celsius .:");
    scanf("%f", &celsius);

    kelvin = celsius + 273.15;
    printf("The temperature in Kelvin is %f.\n", kelvin);
    return EXIT_SUCCESS;
}