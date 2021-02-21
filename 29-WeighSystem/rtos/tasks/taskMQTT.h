#ifndef __TASK_MQTT_H
#define __TASK_MQTT_H

#include <stdint.h>

int8_t Task_MQTT_Start(void);
int8_t Task_MQTT_Wait_Finish(void);
int8_t Task_MQTT_Destroy(void);

#endif