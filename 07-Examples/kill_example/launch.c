#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t pid_process;
  pid_t pid_control;
  char buf[30];

  pid_process = fork();
  if(pid_process == 0){
    execv("./process",  NULL);
  }else if(pid_process > 0){
    pid_control = fork();
    if(pid_control == 0){
      sprintf(buf, "%d", pid_process);
      char *p[] = {"./control", buf, NULL};
      execvp(p[0], p);
    }else if(pid_control > 0){
      return 0;
    }
  }else{
  
  }
}
