#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *args[] = {
        "./message.out", "hello world", NULL
    };

    printf("Running other programming.\n");
    if(execvp(args[0], args)){
        printf("Error launch %s.\n", args[0]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
