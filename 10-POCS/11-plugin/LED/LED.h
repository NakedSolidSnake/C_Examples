#ifndef LED_H_
#define LED_H_

#include "../IDriver.h"

IDriver *create_plugin(void);
char *LED_name(void);
int LED_init(void);
int LED_write(unsigned char state);
int LED_read(void);
int LED_deinit(void);

#endif /* LED_H_ */
