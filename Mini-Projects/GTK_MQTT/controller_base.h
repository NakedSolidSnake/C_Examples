#ifndef CONTROLLER_BASE_H_
#define CONTROLLER_BASE_H_

#include <stdbool.h>

typedef struct 
{
    void *object;
    bool (*on_bt_on_off_toggled) (void *object, bool state);
} controller_base_t;

#endif /* CONTROLLER_BASE_H_ */
