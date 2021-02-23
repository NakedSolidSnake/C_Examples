#include <stdio.h>
#include <stdlib.h>

#define AXP_Settings  0
#define Discover_Settings  1

typedef struct
{
    int f;
}S;

int main(int argc, char *argv[])
{
    S s[] = {
        [AXP_Settings]      = { .f = 10 },
        [Discover_Settings] = { .f = 11 }, 
    };

    for(int i = 0; i < 2; i++)
    {
        S *pS = &s[i];
        printf("Value: %d.\n", pS->f);
    }
    return 0;
}
