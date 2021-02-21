#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Connecting to hello world server\n");

    void *context = zmq_ctx_new();
    void *resquester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(resquester, "tcp://localhost:5555");

    int request_nbr;
    for(request_nbr = 0; request_nbr != 10; request_nbr++)
    {
        char buffer[10];
        printf("Sending Hello %d...\n", request_nbr);
        zmq_send(resquester, "Hello", 5, 0);
        zmq_recv(resquester, buffer, 10, 0);
        printf("Received world %d\n", request_nbr);
    }

    zmq_close(resquester);
    zmq_ctx_destroy(context);
    return 0;
}
