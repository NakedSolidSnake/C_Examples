/*
 * driver_adc.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_ADC_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_ADC_H_

/*< include >*******************************************************************************************/
#include <types.h>
#include <IDriver.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  adc_init (const void *descriptor);
int8_t  adc_open (const void *descriptor);
int32_t adc_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t adc_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  adc_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  adc_close(const void *descriptor);

const Driver adc_driver = {
		.init  = adc_init,
		.open  = adc_open,
		.write = adc_write,
		.read  = adc_read,
		.ioctl = adc_ioctl,
		.close = adc_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_ADC_H_ */
