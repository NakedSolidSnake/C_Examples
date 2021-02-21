#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int wr_proc = -1;
    int rd_proc = -1;

 char *proc1[] = {
        "./pipewrite.out", "args",NULL,
    };

char *proc2[] = {
        "./piperead.out", "args", NULL
    };

    printf("Running other programming.\n");

    wr_proc = fork();
    if(wr_proc == 0){
       if(execvp(proc1[0], proc1)){
            printf("Error launch %s.\n", proc1[0]);
            return EXIT_FAILURE;
        }
    }

    rd_proc = fork();
    if(rd_proc == 0){
        if(execvp(proc2[0], proc2)){
            printf("Error launch %s.\n", proc2[0]);
            return EXIT_FAILURE;
        }
    }
        
    return 0;
}
