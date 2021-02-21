/*
 * driver_i2c.h
 *
 *  Created on: 15 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_I2C_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_I2C_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  i2c_init (const void *descriptor);
int8_t  i2c_open (const void *descriptor);
int32_t i2c_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t i2c_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  i2c_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  i2c_close(const void *descriptor);

const Driver i2c_driver = {
		.init  = i2c_init,
		.open  = i2c_open,
		.write = i2c_write,
		.read  = i2c_read,
		.ioctl = i2c_ioctl,
		.close = i2c_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_I2C_H_ */
