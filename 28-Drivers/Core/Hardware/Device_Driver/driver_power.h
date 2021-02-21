/*
 * driver_power.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_POWER_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_POWER_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  power_init (const void *descriptor);
int8_t  power_open (const void *descriptor);
int32_t power_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t power_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  power_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  power_close(const void *descriptor);

const Driver power_driver = {
		.init  = power_init,
		.open  = power_open,
		.write = power_write,
		.read  = power_read,
		.ioctl = power_ioctl,
		.close = power_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_POWER_H_ */
