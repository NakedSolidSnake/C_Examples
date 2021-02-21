#include <czmq.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
     zsock_t *pull = zsock_new_pull("tcp://*:3322");

    while(1)
    {
        char *recv = zstr_recvm(pull);
        printf("%s.\n", recv);
        zstr_free (&recv);
    }

    zsock_destroy(&pull);
    return 0;
}
