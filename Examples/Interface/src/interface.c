#include <interface.h>
#include <stdlib.h>


bool Init(const Interface *interface, void *args)
{
    interface->init(args);
}

bool Open(const Interface *interface, void *args)
{
    interface->open(args);
}
bool Set(const Interface *interface, void *args)
{
    return interface->set(args);
}

bool Get(const Interface *interface, void *args)
{
    return interface->get(args);
}

bool Close(const Interface *interface, void *args)
{
    return interface->close(args);
}