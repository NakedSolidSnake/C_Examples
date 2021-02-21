#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue/queue.h>
#include <signal.h>
#include <unistd.h>


static int queue_id = -1;

void alarm_handler(int i)
{
    alarm(2);
}

int main()
{  
  char message[30] = "Cristiano Silva de Souza\n";
  queue_st queue;  
  queue_id = queue_init(123);

  signal(SIGALRM, alarm_handler);
  alarm(2);

  if(queue_id < 0){
    exit(EXIT_FAILURE);
  }

  queue.queueType = 1;

  
  
  
  queue_send(queue_id, &queue, sizeof(queue.bData));
  return 0;
}

