#include <interface.h>
#include <stdio.h>

bool File_init(void *args)
{
    (void)args;
    printf("File Init.\n");
    return true;
}

bool File_open(void *args)
{
    (void)args;
    printf("File Open.\n");
    return true;
}

bool File_set(void *args)
{
    (void)args;
    printf("File Set.\n");
    return true;
}

bool File_get(void *args)
{
    (void)args;
    printf("File Get.\n");
    return true;
}

bool File_close(void *args)
{
    (void)args;
    printf("File Close.\n");
    return true;
}