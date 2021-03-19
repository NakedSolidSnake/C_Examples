#ifndef HW_INTERFACE_H_
#define HW_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    void (*init)(void);
    void (*wait)(uint16_t seconds);
    void (*set)(uint8_t state);
} hw_interface;

bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds);

#ifdef __cplusplus
}
#endif

#endif /* HW_INTERFACE_H_ */
