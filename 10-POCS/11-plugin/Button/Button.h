#ifndef BUTTON_H_
#define BUTTON_H_

#include "../IDriver.h"

IDriver *create_plugin(void);

char *BUTTON_name(void);
int BUTTON_init(void);
int BUTTON_write(unsigned char state);
int BUTTON_read(void);
int BUTTON_deinit(void);

#endif /* BUTTON_H_ */
