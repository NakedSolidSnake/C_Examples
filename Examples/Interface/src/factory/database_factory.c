#include <stdlib.h>
#include <database_factory.h>
#include <file_base.h>
#include <mysql_base.h>

const Interface file_base = 
{
    .init  = File_init,
    .open  = File_open,
    .set   = File_set,
    .get   = File_get,
    .close = File_close
};


const Interface mysql_base = 
{
    .init  = Database_init,
    .open  = Database_open,
    .set   = Database_set,
    .get   = Database_get,
    .close = Database_close
};



Interface *Factory_build_type(Database_type type)
{
    Interface *i = NULL;

    if(type == File_type)
    {
        i = &file_base;
    }

    else if(type == MySQL_type)
    {
        i = &mysql_base;
    }

    return i;
}