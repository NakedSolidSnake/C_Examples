#include <czmq.h>

int main(void)
{
    zsock_t *client = zsock_new_req("tcp://localhost:5556");
    // zsock_t *client = zsock_new_req("ipc://example");
    if(client == NULL)
    {
        return -1;
    }

    while(1)
    {
        zstr_send(client, "/department/OnGetDeparment");

        char * receive = zstr_recv(client);

        if(receive == NULL)
        {
            continue;
        }

        printf("%s.\n", receive);
        free(receive);
        sleep(1);
    }
}