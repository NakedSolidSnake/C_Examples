#include <tasks.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if(fork() == 0){
        execl("./task", "./task", NULL);
    }
    return 0;
}
