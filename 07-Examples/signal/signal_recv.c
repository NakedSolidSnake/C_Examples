#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int update = 0;

void handler(int n){
  update = 1;
}

int main(){

  signal(SIGUSR1, handler);

  while(1){

    if(update){
      printf("updated\n");
      update = 0;
    }
  }
}
