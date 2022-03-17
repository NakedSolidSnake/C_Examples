#ifndef VIEW_BASE_H_
#define VIEW_BASE_H_

#include <stdbool.h>

typedef struct 
{
    void *object;
    void (*set_humidity_text) (void *object, const char *text);
    void (*set_temperature_text) (void *object, const char *text);
    void (*set_state) (void *object, bool state);
    void (*run) (void *object);
} view_base_t;

#endif /* VIEW_BASE_H_ */
