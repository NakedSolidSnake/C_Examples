#include <tasks.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if(fork() == 0){
        execv("./task", (char *)NULL);
    }
    return 0;
}
