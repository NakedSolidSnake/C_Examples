#include <interface.h>
#include <database_factory.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    Interface *iface = Factory_build_type(MySQL_type);    

    Init(iface, NULL);
    Open(iface, NULL);
    Set(iface, NULL);
    Get(iface, NULL);
    Close(iface, NULL);

    return 0;
}
