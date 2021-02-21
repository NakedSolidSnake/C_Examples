#ifndef __TASK_LOADCELL_H
#define __TASK_LOADCELL_H

#include <stdint.h>

int8_t Task_LoadCell_Start(void);
int8_t Task_LoadCell_Wait_Finish(void);
int8_t Task_LoadCell_Destroy(void);

#endif