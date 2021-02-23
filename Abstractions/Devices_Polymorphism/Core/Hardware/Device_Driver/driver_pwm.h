/*
 * driver_pwm.h
 *
 *  Created on: 17 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_PWM_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_PWM_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  pwm_init (const void *descriptor);
int8_t  pwm_open (const void *descriptor);
int32_t pwm_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t pwm_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  pwm_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  pwm_close(const void *descriptor);

const FileDriver pwm_driver = {
		.init  = pwm_init,
		.open  = pwm_open,
		.write = pwm_write,
		.read  = pwm_read,
		.ioctl = pwm_ioctl,
		.close = pwm_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_PWM_H_ */
