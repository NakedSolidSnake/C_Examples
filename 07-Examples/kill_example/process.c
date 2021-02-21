#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <common.h>

static int value = 0;

void signal_proc(int sig){
  value = 1;
}

int main()
{

  signal(SIGUSR1, signal_proc);

  while(1){
    if(value){
      log("process", "Received the signal to read");
      value = 0;
    }else{
      sleep(1);
    }
  }
}
