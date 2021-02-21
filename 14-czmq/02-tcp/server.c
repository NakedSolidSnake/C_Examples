#include <czmq.h>

int main()
{
    // zsock_t *server = zsock_new_rep("tcp://*:5556");
    zsock_t *server = zsock_new_rep("ipc://example");
    if(server == NULL)
    {
        return 0;
    }


    while(1)
    {
        char * receive = zstr_recv(server);
        if(receive == NULL)
        {
            continue;
        }

        printf("%s.\n", receive);

        zstr_send(server, "Accepted.");
        free(receive);
    }
}