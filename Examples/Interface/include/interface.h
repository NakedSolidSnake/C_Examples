#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdbool.h>

typedef struct 
{
    bool (*init)(void *args);
    bool (*open)(void *args);
    bool (*set)(void *args);
    bool (*get)(void *args);
    bool (*close)(void *args);
} Interface;


bool Config(const Interface *interface);
bool Init(void *args);
bool Open(void *args);
bool Set(void *args);
bool Get(void *args);
bool Close(void *args);

#endif /* INTERFACE_H_ */
