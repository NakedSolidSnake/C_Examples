#ifndef PLUGIN_H_
#define PLUGIN_H_

#include "IDriver.h"

typedef struct 
{
    void *handle;
    IDriver *driver;
} Plugin;

typedef IDriver *(*Create_plugin)(void);

#endif /* PLUGIN_H_ */
