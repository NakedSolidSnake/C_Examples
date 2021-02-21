#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
  if(sig == SIGKILL)
    printf("I was killed.\n");
  else if(sig == SIGTERM)
   printf("I die but i'll say the truth\n");

  exit(1);
}

int main()
{

  signal(SIGTERM, signal_handler);
  signal(SIGKILL, signal_handler);

  while(1)
  {

    sleep(1);
  }
}
