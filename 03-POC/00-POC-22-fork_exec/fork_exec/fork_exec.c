#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler(int sig_num);

int main(int argc, char *argv[])
{
  signal(SIGCHLD, signal_handler);
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork");
    exit(1);
  }
  else if(pid == 0)
  {
    //child process
    char *args[] = {"./hello", "1", "2", "3", NULL};
    execv(args[0], args);
  }

  for(int i = 0; i < 10; i++)
  {
    printf("i am doing cool stuff here.\n");
    usleep(1000);
  }
  printf("Now I will wait my child\n");
  pause();
  return 0;
}

void signal_handler(int sig_num)
{
  printf("child sends me a message.\n");
}
