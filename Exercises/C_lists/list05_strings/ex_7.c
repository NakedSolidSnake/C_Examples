#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int ret = 0;
    char *nome1 = "cristiano";
    char *nome2 = "cristiano";

    char *pNome1 = nome1;
    char *pNome2 = nome2;

    while(*pNome1 != '\0' && *pNome2 != '\0')
    {
        if(*pNome1 == *pNome2){
            pNome1++;
            pNome2++;
        }else {
            if(*pNome1 > *pNome2)
                ret = -1;
            else
                ret = 1;
            break;
        }
    }

    switch (ret)
    {
    case 0:
        printf("Are equal.\n");
        break;
    case -1:
        printf("Name 1 is greater.\n");
        break;

    case 1:
        printf("Name 2 is greater.\n");
        break;
    
    default:
        break;
    }

    return EXIT_SUCCESS;
}
