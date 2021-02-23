/*
 * driver_template.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TEMPLATE_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TEMPLATE_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  template_init (const void *descriptor);
int8_t  template_open (const void *descriptor);
int32_t template_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t template_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  template_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  template_close(const void *descriptor);

const Driver template_driver = {
		.init  = template_init,
		.open  = template_open,
		.write = template_write,
		.read  = template_read,
		.ioctl = template_ioctl,
		.close = template_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_TEMPLATE_H_ */
