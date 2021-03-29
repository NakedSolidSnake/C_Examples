#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int pid;
    int status;

    pid = fork();

    if(pid == 0)
    {
        //start button process
        char *args[] = {"./daemon", NULL};
        status = execvp(args[0], args);
        printf("Error to start daemon process, status = %d\n", status);
        abort();
    } 
    return 0;
}
