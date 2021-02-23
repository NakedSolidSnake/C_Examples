#ifndef __TASK_BLUETOOTH_H
#define __TASK_BLUETOOTH_H

#include <stdint.h>

int8_t Task_Bluetooth_Start(void);
int8_t Task_Bluetooth_Wait_Finish(void);
int8_t Task_Bluetooth_Destroy(void);

#endif