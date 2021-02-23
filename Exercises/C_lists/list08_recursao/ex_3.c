/*
    Escreva uma funcao recursiva que calcule a soma dos primeiros n cubos: S(n) = 1³ + 2³ + ... + n³
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cube_sum(int value)
{
    if(value == 1)
        return 1;

    return (pow(value, 3.0) + (value - 1));
}

int main(int argc, char *argv[])
{
    int value;
    printf("Enter an integer number .:");
    scanf("%d", &value);
    printf("The cube sum is %d.\n", cube_sum(value));
    return EXIT_SUCCESS;
}