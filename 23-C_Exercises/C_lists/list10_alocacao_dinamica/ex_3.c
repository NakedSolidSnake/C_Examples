#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int amount;
    int *pVector = NULL;
    int even = 0;
    int odd = 0;

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
        if(pVector[i] & 0x01)
            odd++;
        else 
            even++;
    }

    printf("Even numbers: %d.\nOdd numbers: %d.\n", even, odd);
    free(pVector);
    pVector = NULL;

    return EXIT_SUCCESS;
}