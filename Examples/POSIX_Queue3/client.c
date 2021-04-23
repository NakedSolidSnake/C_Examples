/*
 * client.c: Client program
 *           to demonstrate interprocess communication
 *           with POSIX message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME   "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main (int argc, char **argv)
{
    int value = 0;
    char buffer [64];
    mqd_t qd_writer;

    if ((qd_writer = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        perror ("Client: mq_open (server)");
        exit (1);
    }

    while (1) {

        snprintf(buffer, 64, "%d", value++);
        // send message to server
        if (mq_send (qd_writer, buffer, strlen (buffer) + 1, 0) == -1) {
            perror ("Client: Not able to send message to server");
            continue;
        }

        sleep(1);

    }

    if (mq_unlink (SERVER_QUEUE_NAME) == -1) {
        perror ("Client: mq_unlink");
        exit (1);
    }

    exit (0);
}