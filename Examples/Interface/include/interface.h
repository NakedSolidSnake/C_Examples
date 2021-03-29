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

bool Init(const Interface *interface, void *args);
bool Open(const Interface *interface, void *args);
bool Set(const Interface *interface, void *args);
bool Get(const Interface *interface, void *args);
bool Close(const Interface *interface, void *args);

#endif /* INTERFACE_H_ */
