#ifndef __TASK_KBD_H
#define __TASK_KBD_H

#include <stdint.h>

int8_t Task_KBD_Start(void);
int8_t Task_KBD_Wait_Finish(void);
int8_t Task_KBD_Destroy(void);

#endif