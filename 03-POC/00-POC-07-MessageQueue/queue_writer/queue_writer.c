#include <stdio.h>
#include <pqueue.h>
#include <people.h>
#include <string.h>

queue_t message;
people_t p;

int main(int argc, char *argv[])
{
    int msgid;

    people_init(&p);
    msgid = queue_init("progfile");
    message.id= 1;

    people_register(&p);
    memcpy(message.b, &p, sizeof(p));

    queue_send(msgid, &message);

    printf("Data send is : \n");
    people_print(&p);

    return 0;
}

