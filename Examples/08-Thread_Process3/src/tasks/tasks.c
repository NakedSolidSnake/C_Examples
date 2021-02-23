#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static int segfault = -1;
static int quit = -1;

static void segfaultSignal(int sig){
    segfault = 1;
}

static void quitSignal(int sig){
    quit = 1;
}


#ifdef PROCESS
int main(int argc, char const *argv[])
{
    work(NULL);
    return 0;
}
#endif

void *work(void *args)
{
    
    signal(SIGUSR2, segfaultSignal);
    signal(SIGTERM, quitSignal);
    printf("Work running.\n");
    printf("Send USR2 command to force a segfault.\n");
    printf("Send SIGTERM to quit application.\n");
    printf("e.g: kill -USR2 pid_process.\n");

    while(1){
        
        sleep(1);
        if(segfault > 0){
            int *p = 0x00;
            *p = 5;
        }

        if(quit > 0){
            exit(0);
        }
        
    }
    printf("\n");
    return NULL;
}