/*
    Faca um programa que leia um numero real e o imprima.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float number;
    printf("Type a real number: ");
    scanf("%f", &number);
    printf("The number typed was: %f\n", number);
    return EXIT_SUCCESS;
}