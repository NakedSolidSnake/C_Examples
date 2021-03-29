#ifndef DATABASE_FACTORY_H_
#define DATABASE_FACTORY_H_

#include <interface.h>

typedef enum 
{
    File_type,
    MySQL_type
} Database_type;

Interface *Factory_build_type(Database_type type);

#endif /* DATABASE_FACTORY_H_ */
