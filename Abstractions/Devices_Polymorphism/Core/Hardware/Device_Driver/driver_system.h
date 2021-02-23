/*
 * driver_system.h
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SYSTEM_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SYSTEM_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  system_init (const void *descriptor);
int8_t  system_open (const void *descriptor);
int32_t system_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t system_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  system_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  system_close(const void *descriptor);

const FileDriver system_driver = {
		.init  = system_init,
		.open  = system_open,
		.write = system_write,
		.read  = system_read,
		.ioctl = system_ioctl,
		.close = system_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SYSTEM_H_ */
