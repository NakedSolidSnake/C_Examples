#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  (void)argv;
  (void)argc;
  pid_t pid = fork();

  if(pid == 0)
  {
    printf("I am a child. My pid is %d\n", (int)getpid());
    sleep(5);
    printf("Exiting\n");
    exit(0);
  }
  else
    printf("Waiting child finishes.\n");
  wait(NULL);
  return 0;
}
