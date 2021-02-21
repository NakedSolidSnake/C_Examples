#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct mesg_buffer{
    long mesg_type;
    char mesg_text[100];
}message;

int main(int argc, char *argv[])
{
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT );
    
    while(strcmp("quit", message.mesg_text) != 0)
    {
      printf("waiting message...\n");
      memset(message.mesg_text, 0, sizeof(message.mesg_text));
      msgrcv (msgid, &message, sizeof(message),1, 0);
      printf("Data received is %s: \n", message.mesg_text);
    }

    msgctl (msgid, IPC_RMID, NULL);

    return 0;
}
