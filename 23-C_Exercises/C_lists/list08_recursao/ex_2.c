/*
    Faca uma funcao recursiva que calcule e retorne o fatorial de um numero inteiro N.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int factor)
{
    if(factor == 0)
        return 1;

    return (factor * factorial(factor - 1));
}

int main(int argc, char *argv[])
{
    int number;
    printf("Enter with an integer value: ");
    scanf("%d", &number);
    printf("THe Factorial is %d.\n", factorial(number));
    return EXIT_SUCCESS;
}