#include <stdio.h>
#include <pqueue.h>
#include <string.h>
#include <people.h>

queue_t message;
people_t p;

int main(int argc, char *argv[])
{
    int msgid;

    msgid = queue_init("progfile");
    people_init(&p);
    
    while(strncmp("quit", message.b, 4) != 0)
    {
      printf("waiting message...\n");
      memset(message.b, 0, sizeof(message.b));
      queue_recv(msgid, &message, 1);
      memcpy(&p, message.b, sizeof(p));
      people_print(&p);
    }
    printf("Finished.\n");

    queue_delete(msgid);
    return 0;
}
