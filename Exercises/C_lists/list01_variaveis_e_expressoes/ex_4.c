/*
    Leia um numero real e imprima o resultado do quadrado desse numero.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float number;
    printf("Type a real number.: ");
    scanf("%f", &number);
    printf("The double is %f\n", number * number);
    return EXIT_SUCCESS;
}