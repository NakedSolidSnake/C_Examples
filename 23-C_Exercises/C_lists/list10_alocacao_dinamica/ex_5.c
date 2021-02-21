#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int amount;
    int *pVector = NULL;

    printf("Type a number of position.:");
    scanf("%d", &amount);

    pVector = (int *)malloc(sizeof(int) * amount);

    for(int i = 0; i < amount; i++)
    {
        printf("Enter a %dº number.: ");
        scanf("%d", &pVector[i]);
    }

    for(int i = 0; i < amount; i++)
    {
        if(pVector[i] / amount)
            printf("%d is multiple of number %d.\n", pVector[i], amount);        
    }

    free(pVector);
    pVector = NULL;

    return EXIT_SUCCESS;
}