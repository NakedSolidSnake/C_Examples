#include <czmq.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    zsock_t *push = zsock_new_push("tcp://localhost:3322");

    while(1)
    {
        zstr_sendm(push, "/department");
        zstr_send(push, "/OnGetDepartment");

        sleep(1);

    }

    zsock_destroy(&push);
    return 0;
}