/*
 * driver_serial.h
 *
 *  Created on: 7 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SERIAL_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SERIAL_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  serial_init (const void *descriptor);
int8_t  serial_open (const void *descriptor);
int32_t serial_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t serial_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  serial_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  serial_close(const void *descriptor);

const FileDriver serial_driver = {
		.init  = serial_init,
		.open  = serial_open,
		.write = serial_write,
		.read  = serial_read,
		.ioctl = serial_ioctl,
		.close = serial_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_SERIAL_H_ */
