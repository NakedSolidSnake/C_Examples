#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    void *context = zmq_ctx_new();

    printf("Connecting to hello world server...\n");
    void *requester = zmq_socket(context, ZMQ_REQ);

    zmq_connect(requester, "tcp://localhost:5555");

    int request_nbr;

    for(request_nbr = 0;  request_nbr != 10; request_nbr++){
        zmq_msg_t request;
        zmq_msg_init_size(&request, 5);
        memcpy(zmq_msg_data(&request), "Hello", 5);
        printf("Sending hello %d...\n", request_nbr);
    }
}