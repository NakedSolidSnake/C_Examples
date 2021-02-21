/*
 * driver_eeprom.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_EEPROM_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_EEPROM_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  eeprom_init (const void *descriptor);
int8_t  eeprom_open (const void *descriptor);
int32_t eeprom_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t eeprom_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  eeprom_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  eeprom_close(const void *descriptor);

const FileDriver eeprom_driver = {
		.init  = eeprom_init,
		.open  = eeprom_open,
		.write = eeprom_write,
		.read  = eeprom_read,
		.ioctl = eeprom_ioctl,
		.close = eeprom_close
};

#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_EEPROM_H_ */
