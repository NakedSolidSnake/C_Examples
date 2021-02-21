#include <stdio.h>
#include <pqueue.h>
#include <string.h>
#include <signal.h>
#include <data.h>

static int quit = 0;

void quit_handler(int sig_num)
{
  (void)sig_num;
  quit = 1;
}

queue_t message;

void analize_id(data_t  *m);

int main(int argc, char *argv[])
{
    int msgid;
    data_t d;
    //register quit_handler 
    signal(SIGINT, quit_handler);
    msgid = queue_init("progfile");
    
    while(!quit)
    {
      printf("waiting message...\n");
      memset(message.b, 0, sizeof(message.b));
      queue_recv(msgid, &message, 1);
      
      data_init(&d);
      memcpy(&d, message.b, sizeof(data_t));
      analize_id(&d);
    }
    printf("Finished.\n");

    queue_delete(msgid);
    return 0;
}

void analize_id(data_t *m)
{
  if(m == NULL)
    return ;

  switch(m->id)
  {
    case 1:
      printf("English : ");
      break;

    case 2:
      printf("Deutsch: ");
      break;

    default:
      return ;

  }
  
  printf("%s\n", m->b_data);
  return ;
}
