#ifndef CORE_DEVICES_TIMERS_TIMERS_H_
#define CORE_DEVICES_TIMERS_TIMERS_H_

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct Timer_Descriptor{
	uint8_t id;
	const uint8_t *timer_name;
}Timer_Descriptor;

/* public functions **********************************************************************************/
int8_t  timer_open (const void *context);
int32_t timer_write(const void *context, const void *buffer_write, uint32_t size);
int32_t timer_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  timer_ioctl(const void *context, uint8_t command, void *args);
int8_t  timer_close(const void *context);


#endif /* CORE_DEVICES_TIMERS_TIMERS_H_ */
