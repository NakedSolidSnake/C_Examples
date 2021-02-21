/*
    Faca um programa que leia um numero inteiro e o imprima.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int number;
    printf("Type an integer number: ");
    scanf("%d", &number);
    printf("The number typed was: %d\n", number);
    return EXIT_SUCCESS;
}