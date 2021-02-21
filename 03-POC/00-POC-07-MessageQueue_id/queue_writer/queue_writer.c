#include <stdio.h>
#include <pqueue.h>
#include <string.h>
#include <data.h>

queue_t message;

int main(int argc, char *argv[])
{
    int msgid;
    data_t d;

    data_init(&d);
    d.id = 1;
    

    msgid = queue_init("progfile");
    message.id= 1;
    while(1)
    {
      strcpy(d.b_data, "Hello World");
      memcpy(message.b, &d, sizeof(data_t));
      queue_send(msgid, &message);
      data_init(&d);

      d.id = 2;
      strcpy(d.b_data, "Hallo Welt");
      memcpy(message.b, &d, sizeof(data_t));
      queue_send(msgid, &message);
    }
    return 0;
}

