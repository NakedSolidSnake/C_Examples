#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

static int sigterm = 0;

static void handle_sigterm(int n)
{
    sigterm = 1;
}


int main(int argc, char **argv)
{
    int wr_proc = -1;
    int rd_proc = -1;

    char *proc1[] = {
        "./appnoparams.out", "args",NULL,
    };

    char *proc2[] = {
        "./appwithparams.out", "10", NULL
    };

    if(argc > 1)
        if(strncmp("daemon", argv[1], 6) == 0){
            printf("Become a daemon.\n");
            daemon(1, 1);
        }

    struct sigaction sa;
    sigset_t s;
    sa.sa_handler = handle_sigterm;
    sa.sa_flags = SA_NODEFER;
    sigaction(SIGTERM, &sa, NULL);
    sigemptyset(&s);
    sigaddset(&s, SIGTERM);

    sa.sa_handler = handle_sigterm;
    sa.sa_flags = SA_NODEFER;
    sigaction(SIGUSR1, &sa, NULL);
    sigemptyset(&s);
    sigaddset(&s, SIGUSR1);
    

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

    
    
    pid_t pid;
    int estado;
    while(1){
        pid = wait(&estado);       
        // waitpid(wr_proc, &estado, 0);
        // printf("estado : %d\n", estado);         
        // if (((pid = waitpid(wr_proc, &estado, 0)) < 0) || ((pid = waitpid(rd_proc, &estado, 0)) < 0)) {        
        if ((pid == wr_proc) || (pid == rd_proc) || sigterm) {        
            printf("wr_proc: %d\n", wr_proc);
            printf("rd_proc: %d\n", rd_proc);
            printf("pid: %d\n", pid);
            printf("Receive a dead child.\n");
            kill(wr_proc, SIGKILL);
            kill(rd_proc, SIGKILL);
            break;
        }        
        usleep(1000000);
    }

    return EXIT_SUCCESS;    
  
}

