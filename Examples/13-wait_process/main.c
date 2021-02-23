#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t m1, m2;
    char *argsM1[] = {
        "./message.out", "hello world", "5", NULL
    };

    char *argsM2[] = {
        "./message.out", "Hallo Welt", "8", NULL
    };

    m1 = fork();
    if(m1 == 0){
        printf("Running %s process.\n", argsM1[0]);
        if(execvp(argsM1[0], argsM1)){
            printf("Error launch %s.\n", argsM1[0]);
            return EXIT_FAILURE;
        }
    }


    m2 = fork();
    if(m2 == 0){
        printf("Running %s process.\n", argsM2[0]);
        if(execvp(argsM2[0], argsM2)){
            printf("Error launch %s.\n", argsM2[0]);
            return EXIT_FAILURE;
        }
    }

    printf("Waiting children finish.\n");

    waitpid(m1, (int *) 0, __WALL);
    waitpid(m2, (int *) 0, __WALL);

    printf("children finished.\n");
    
    
    return EXIT_SUCCESS;
}
