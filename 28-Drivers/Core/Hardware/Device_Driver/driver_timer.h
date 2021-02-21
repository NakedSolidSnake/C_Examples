/*
 * driver_timer.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TIMER_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TIMER_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  timer_init (const void *descriptor);
int8_t  timer_open (const void *descriptor);
int32_t timer_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t timer_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  timer_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  timer_close(const void *descriptor);

const Driver timer_driver = {
		.init  = timer_init,
		.open  = timer_open,
		.write = timer_write,
		.read  = timer_read,
		.ioctl = timer_ioctl,
		.close = timer_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TIMER_H_ */
