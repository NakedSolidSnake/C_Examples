#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    bool status = false;
    char buffer[120 + 1];
    const char *people[] = 
    {
        "Cristiano Silva de Souza",
        "Sara de Oliveira",
        "Hugo dos Santos de Souza"
    };

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s name\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(buffer, argv[1], 120);
    
        
    for(int i = 0; i < 3; i++)
    {
        char *found = strstr(people[i], buffer);
        if(found != NULL)
        {            
            status = true;
            break;
        }
    }

    if(status)
        printf("Found!\n");
    else 
        printf("Not found!\n");

    return 0;
}