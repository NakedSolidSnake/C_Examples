#ifndef HW_INTERFACE_H_
#define HW_INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    void (*init)(void);
    void (*wait)(int seconds);
    void (*set)(uint8_t state);
} Interface;

bool run_toogle_led(Interface *interface, int _delay);

#endif /* HW_INTERFACE_H_ */
