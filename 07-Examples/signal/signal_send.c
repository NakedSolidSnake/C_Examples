#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){

  while(1){

    kill(20437, SIGUSR1);
    printf("send SIGUSR1\n");
    sleep(1);

  }
}
