#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float celsius;
    float fahrenheit;

    printf("Type a Temperature in Fahrenheit  degree.:");
    scanf("%f", &fahrenheit);

    celsius = 5.0 *(fahrenheit - 32.0) / 9.0;
    printf("The temperature in Celsius is %f.\n", celsius);
    return EXIT_SUCCESS;
}