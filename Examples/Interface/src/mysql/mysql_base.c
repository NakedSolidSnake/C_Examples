#include <stdio.h>
#include <mysql_base.h>

bool Database_init(void *args)
{
    (void)args;
    printf("Database Init.\n");
    return true;
}

bool Database_open(void *args)
{
    (void)args;
    printf("Database Open.\n");
    return true;
}

bool Database_set(void *args)
{
    (void)args;
    printf("Database Set.\n");
    return true;
}

bool Database_get(void *args)
{
    (void)args;
    printf("Database Get.\n");
    return true;
}

bool Database_close(void *args)
{
    (void)args;
    printf("Database Close.\n");
    return true;
}