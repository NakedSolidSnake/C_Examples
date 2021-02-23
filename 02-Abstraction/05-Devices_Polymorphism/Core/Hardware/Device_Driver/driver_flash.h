/*
 * driver_flash.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_FLASH_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_FLASH_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  flash_init (const void *descriptor);
int8_t  flash_open (const void *descriptor);
int32_t flash_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t flash_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  flash_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  flash_close(const void *descriptor);

const FileDriver flash_driver = {
		.init  = flash_init,
		.open  = flash_open,
		.write = flash_write,
		.read  = flash_read,
		.ioctl = flash_ioctl,
		.close = flash_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_FLASH_H_ */
