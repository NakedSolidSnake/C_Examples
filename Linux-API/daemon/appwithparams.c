#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc != 2)
        return EXIT_FAILURE;
    
    int delay = atoi(argv[1]);

    while(1)
    {
        printf("App with parameters.\n");
        sleep(delay);
    }
}
