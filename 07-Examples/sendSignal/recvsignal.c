#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig);
int main(int argc, char *argv[])
{

  signal(SIGUSR1, handler);

  while(1){
    pause();
    printf("Received signal\n");
  }

  return EXIT_SUCCESS;
}

void handler(int sig){
  static int p = 0;
  p++;
}
