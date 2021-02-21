#include <zmq.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int major, minor, patch;

    zmq_version(&major, &minor, &patch);

    printf("Current 0MQ version is %d.%d.%d\n", major, minor, patch);
    return 0;
}
