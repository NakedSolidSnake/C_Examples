#include <stdio.h>
#include <stdlib.h>

#define MAX         2

int main(int argc, char *argv[])
{
    int value_1 = 10;
    int value_2 = 20;

    int *pValue1 = &value_1;
    int *pValue2 = &value_2;

    int **vectors = (int **)malloc(sizeof(int *) * MAX);
    if(vectors == NULL)
        return EXIT_FAILURE;

    vectors[0] = pValue1;
    vectors[1] = pValue2;


    for(int i = 0; i < MAX; i++)
    {
        printf("vectors apontando para array_%d.\n", i + 1);
        printf("value: %d.\n", *vectors[i]);
    }

    return 0;
}
