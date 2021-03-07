#include <interface.h>
#include <stdlib.h>

static const  Interface *__interface = NULL;

bool Config(const Interface *interface)
{
    bool is_initialized = true;
    if(!interface)
        is_initialized = false;
    else if (!interface->init)  
        is_initialized = false;
    else if(!interface->open)  
        is_initialized = false;
    else if(!interface->set)  
        is_initialized = false;
    else if(!interface->get)  
        is_initialized = false;
    else if(!interface->close)  
        is_initialized = false;   

    __interface = interface;

    return is_initialized;
}

bool Init(void *args)
{
    return __interface->init(args);
}

bool Open(void *args)
{
    return __interface->open(args);
}

bool Set(void *args)
{
    return __interface->set(args);
}

bool Get(void *args)
{
    return __interface->get(args);
}

bool Close(void *args)
{
    return __interface->close(args);
}