#include <stdio.h>

int main(int argc, char const *argv[])
{

    for(int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            printf("func1.\n");
            break;

        case 1:
            printf("func2.\n");
            break;

        case 2:
            printf("func3.\n");
            break;

        case 3:
            printf("func4.\n");
            break;
        
        default:
            break;
        }
    }

    return 0;
}