/*
    Crie uma funcao recursiva que receba um numero inteiro positivo N e calcule o somatorio dos numeros de 1 a N.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int sum (int value)
{
    if(value)
        return (value + sum(value - 1));

    return 0;
}

int main(int argc, char *argv[])
{
    int value;
    printf("Type an integer number.:");
    scanf("%d", &value);

    printf("The sum is %d.\n", sum(value));
    return EXIT_SUCCESS;
}