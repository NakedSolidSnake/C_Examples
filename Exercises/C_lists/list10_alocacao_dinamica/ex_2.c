#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int amount;
    int *pVector = NULL;

    printf("Type a number to allocate.:");
    scanf("%d", &amount);

    pVector = (int *)malloc(sizeof(int) * amount);

    for(int i = 0; i < amount; i++)
    {
        printf("Enter a %dº number.: ", i + 1);
        scanf("%d", &pVector[i]);
    }

    for(int i = 0; i < amount; i++)
    {
        printf("Typed number %d on index %d. \n", pVector[i], i);
    }

    free(pVector);
    pVector = NULL;

    return EXIT_SUCCESS;
}