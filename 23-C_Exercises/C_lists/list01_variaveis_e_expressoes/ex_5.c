/*
    Leia um numero real e imprima a quinta parte deste numero.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float number;
    printf("Type a real number.:");
    scanf("%f", &number);
    printf("The fifth part about the number is %f.\n", number / 5.0);
    return EXIT_SUCCESS;
}