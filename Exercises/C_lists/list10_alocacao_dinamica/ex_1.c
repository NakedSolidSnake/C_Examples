#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int *p = (int *)malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++)
    {
        printf("Type %dº number.:" , i + 1);
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%dº Typed number %d.\n" , i + 1, p[i]);        
    }

    free(p);
    return EXIT_SUCCESS;
}