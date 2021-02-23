/*
    Pecaa ao usuario para digitar tres valores inteiros e imprima a soma deles
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int number1, number2, number3;
    printf("Type three integer numbers: ");
    scanf("%d%d%d", &number1, &number2, &number3);
    printf("The sum is %d\n", number3 + number2 + number1);
    return EXIT_SUCCESS;
}