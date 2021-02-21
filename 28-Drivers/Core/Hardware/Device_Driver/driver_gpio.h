/*
 * driver_gpio.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_GPIO_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_GPIO_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  gpio_init (const void *descriptor);
int8_t  gpio_open (const void *descriptor);
int32_t gpio_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t gpio_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  gpio_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  gpio_close(const void *descriptor);

const Driver gpio_driver = {
		.init  = gpio_init,
		.open  = gpio_open,
		.write = gpio_write,
		.read  = gpio_read,
		.ioctl = gpio_ioctl,
		.close = gpio_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_GPIO_H_ */
