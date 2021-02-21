#include "program_b.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>   
#include <sys/resource.h> 
#include <system_memory.h>

static int segfault = -1;
static int quit = -1;
static int update = 0;

static void segfaultSignal(int sig){
    segfault = 1;
}

static void quitSignal(int sig){
    quit = 1;
}

static void update_time(int sig){
    update = 1;
}

static void wakeup(int sig){
    update = 1;
}


#ifdef PROCESS
int main(int argc, char const *argv[])
{
    program_b(NULL);
    return 0;
}
#endif

void *program_b(void *args)
{
    struct timespec  current;
    signal(SIGUSR1, wakeup);
    signal(SIGUSR2, segfaultSignal);
    signal(SIGTERM, quitSignal);
    signal(SIGALRM, update_time);    

    systemMemory_st *mem = memoryGet();
    if(mem == NULL)
        return NULL;

    alarm(1);

    printf("Work running Program B.\n");
    printf("Send USR2 command to force a segfault.\n");
    printf("Send SIGTERM to quit application.\n");
    printf("e.g: kill -USR2 pid_process.\n");

    while(1){
        
        usleep(100);
        if(segfault > 0){
            int *p = 0x00;
            *p = 5;
        }

        if(quit > 0){
            exit(0);
        }

         if(update){
            clock_gettime(CLOCK_MONOTONIC, &current);
            mem->processes[1].update = (time_t)((double)current.tv_sec + (double)current.tv_nsec/(double)1000000000);
            update = 0;
            alarm(1);
        }  
        
    }
    printf("\n");
    return NULL;
}