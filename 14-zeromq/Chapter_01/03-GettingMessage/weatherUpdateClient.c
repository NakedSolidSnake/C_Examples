#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    printf("Collecting updates from weather server...\n");
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);

    int rc = zmq_connect(subscriber, "tcp://localhost:5556");
    assert(rc == 0);

    const char *filter = (argc > 1) ? argv[1] : "10001 ";

    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, strlen(filter));

    assert(rc == 0);

    int update_nbr;
    long total_temp = 0;

    for(update_nbr = 0; update_nbr < 100; update_nbr++)
    {
        char buffer[256] = {0};        
        int size = zmq_recv(subscriber, buffer, 255, 0);
        if(size == -1)
            return EXIT_FAILURE;
        
        int zipcode, temperature, relhumidity;
        sscanf(buffer, "%d %d %d", &zipcode, &temperature, &relhumidity);
        total_temp += temperature;
    }

    printf("Average temperature for zipcode, '%s' was %dF\n", filter, (int)(total_temp/update_nbr));
    zmq_close(subscriber);
    zmq_ctx_destroy(context);

    return 0;
}

