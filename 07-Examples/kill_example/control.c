#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <common.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char *argv[])
{
  int pid;
  if(argc != 2){
    log("control", "number of arguments incorrect\n");
    return 1;
  }

  pid = atoi(argv[1]);

  while(1){
  
    kill(pid, SIGUSR1);
    sleep(2);
  }
}
