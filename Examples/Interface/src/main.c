#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

static bool Database_init(void *args)
{
    (void)args;
    printf("Database Init.\n");
    return true;
}

static bool Database_open(void *args)
{
    (void)args;
    printf("Database Open.\n");
    return true;
}

static bool Database_set(void *args)
{
    (void)args;
    printf("Database Set.\n");
    return true;
}

static bool Database_get(void *args)
{
    (void)args;
    printf("Database Get.\n");
    return true;
}

static bool Database_close(void *args)
{
    (void)args;
    printf("Database Close.\n");
    return true;
}


int main(int argc, char *argv[])
{
    Interface interface = 
    {
        .init = Database_init,
        .open = Database_open,
        .set = Database_set,
        .get = Database_get,
        .close = Database_close
    };

    Config(&interface);

    Init(NULL);

    Open(NULL);

    Set(NULL);

    Get(NULL);

    Close(NULL);

    return 0;
}
