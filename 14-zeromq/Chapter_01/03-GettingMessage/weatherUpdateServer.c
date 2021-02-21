#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>

#define randof(num) (int)((float)(num) * random() / (RAND_MAX + 1.0))

int main(int argc, char const *argv[])
{
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);

    int rc = zmq_bind(publisher, "tcp://*:5556");
    assert(rc == 0);

    srandom((unsigned) time(NULL));

    while(1)
    {
        int zipcode, temperature, relhumidity;
        zipcode = randof(1000000);
        temperature = randof(215) - 80;
        relhumidity = randof(50) + 10;

        char update[20];

        snprintf(update, 20, "%05d %d %d", zipcode, temperature, relhumidity);        
        zmq_send(publisher, update, strlen(update), 0);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
