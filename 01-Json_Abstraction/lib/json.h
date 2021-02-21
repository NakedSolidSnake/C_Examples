#ifndef JSON_H_
#define JSON_H_

#include <stdbool.h>

#define getItems(x)(sizeof(x) / sizeof(x[0]))

typedef enum 
{
    eType_Int,
    eType_Double,
    eType_String,
    eType_Boolean,
    eType_Object
} eType;

typedef struct
{
    const char *token;
    void *data;
    eType type;
    void *child;
    int size;
} IHandler;

bool getJsonFromFile(const char *filename, void *buffer, size_t b_size);
bool processJson(void *buffer, const IHandler *ihandler_list, size_t ihandler_size);

#endif /* JSON_H_ */
