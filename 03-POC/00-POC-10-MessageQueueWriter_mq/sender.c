#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MSG_SIZE        256
#define MSG_BUFFER_SIZE     (MAX_MSG_SIZE + 10)


int main(int argc, char **argv){

    char buffer[MSG_BUFFER_SIZE];
    int queue_handle = 0;
    int queue_send_ret;

    if(argc <= 1){
        printf("provide a reciepient msgQ name : format </msgq-name>\n");
        return 0;
    }

    memset(buffer, 0, MSG_BUFFER_SIZE);
    printf("Enter msg to be sent to reciever %s\n", argv[1]);
    scanf("%s", buffer);

    queue_handle = mq_open (argv[1], O_WRONLY | O_CREAT,0,0);
    if ( queue_handle == -1) {
        printf ("Client: mq_open failed, errno = %d", errno);
        exit (1);
    }

    queue_send_ret = mq_send (queue_handle, buffer, strlen (buffer) + 1, 0);

    if ( queue_send_ret == -1 ) {
        perror ("Client: Not able to send message to server");
        exit (1);
    }

    mq_close(queue_handle);
    return 0;
}

