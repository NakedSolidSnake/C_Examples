#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

extern const Interface interface;

int main(int argc, char *argv[])
{

    Config(&interface);

    Init(NULL);

    Open(NULL);

    Set(NULL);

    Get(NULL);

    Close(NULL);

    return 0;
}
