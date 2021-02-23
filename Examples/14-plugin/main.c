#include "Plugin.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

//gcc -g3 -O0 -o plugin main.c -ldl

typedef struct 
{
    const char *lib_name;
} Devices;

const Devices devices[] = 
{
    {.lib_name = "./LED/led.so"},
    {.lib_name = "./Button/button.so"}
};

int main(int argc, char *argv[])
{

    Plugin plugins[2] = {0};
    char *error;

    for(int i = 0; i < 2; i++)
    {
        plugins[i].handle = dlopen(devices[i].lib_name, RTLD_LAZY);
        if (!plugins[i].handle)
        {
            fputs(dlerror(), stderr);
            exit(1);
        }

         Create_plugin create_plugin =  dlsym(plugins[i].handle, "create_plugin");
         plugins[i].driver = create_plugin();
    }

    for(int i = 0; i < 2; i++)
    {   
        IDriver *driver = plugins[i].driver;   
        printf("%s.\n", driver->device_name());
        driver->device_init();
        driver->device_write(1);
        printf("state %d.\n", driver->device_read());
        driver->device_deinit();
    }

    for(int i = 0; i < 2; i++)
    {        
        dlclose(plugins[i].handle);      
    }
     
    return 0;
}
