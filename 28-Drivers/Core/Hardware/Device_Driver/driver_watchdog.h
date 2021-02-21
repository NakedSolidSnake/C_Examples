/*
 * driver_watchdog.h
 *
 *  Created on: 13 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_WATCHDOG_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_WATCHDOG_H_


/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  watchdog_init (const void *descriptor);
int8_t  watchdog_open (const void *descriptor);
int32_t watchdog_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t watchdog_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  watchdog_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  watchdog_close(const void *descriptor);

const Driver watchdog_driver = {
		.init  = watchdog_init,
		.open  = watchdog_open,
		.write = watchdog_write,
		.read  = watchdog_read,
		.ioctl = watchdog_ioctl,
		.close = watchdog_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_WATCHDOG_H_ */
