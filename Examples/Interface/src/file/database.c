#include <interface.h>
#include <stdio.h>

static bool File_init(void *args)
{
    (void)args;
    printf("File Init.\n");
    return true;
}

static bool File_open(void *args)
{
    (void)args;
    printf("File Open.\n");
    return true;
}

static bool File_set(void *args)
{
    (void)args;
    printf("File Set.\n");
    return true;
}

static bool File_get(void *args)
{
    (void)args;
    printf("File Get.\n");
    return true;
}

static bool File_close(void *args)
{
    (void)args;
    printf("File Close.\n");
    return true;
}

const Interface interface = 
    {
        .init = File_init,
        .open = File_open,
        .set = File_set,
        .get = File_get,
        .close = File_close
    };