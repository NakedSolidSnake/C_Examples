/*
    Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
    A formula de conversao eh:  F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit
    e C a temperatura em Celsius
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float celsius;
    float fahrenheit;

    printf("Type a Temperature in celsius degree.:");
    scanf("%f", &celsius);

    fahrenheit = celsius * (9.0 / 5.0) + 32.0;
    printf("The temperature in Fahrenheit is %f.\n", fahrenheit);
    return EXIT_SUCCESS;
}