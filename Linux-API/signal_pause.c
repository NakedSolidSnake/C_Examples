#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

void handle_signal(int num)
{
  (void)num;
  flag = 1; 
}


int main(int argc, char *argv[])
{

  signal(SIGINT, handle_signal);

  while(1)
  {

    printf("system paused.\nwaiting for a signal [ctrl + c]\n");
    if(flag == 0)
      pause();
    flag = 0;
  }
  return 0;
}
