/*
 * driver_usb.h
 *
 *  Created on: 16 de fev de 2019
 *      Author: solid
 */

#ifndef CORE_HARDWARE_DEVICE_DRIVER_DRIVER_USB_H_
#define CORE_HARDWARE_DEVICE_DRIVER_DRIVER_USB_H_

/*< include >*******************************************************************************************/
#include <IFileDriver.h>
#include <types.h>

/*< defines >*******************************************************************************************/

/*< enumerations >**************************************************************************************/

/*< structures >****************************************************************************************/


/*< public functions >**********************************************************************************/
int8_t  usb_init (const void *descriptor);
int8_t  usb_open (const void *descriptor);
int32_t usb_write(const void *descriptor, const void *buffer_write, uint32_t size);
int32_t usb_read (const void *descriptor, void *buffer_read, uint32_t size);
int8_t  usb_ioctl(const void *descriptor, uint8_t command, void *args);
int8_t  usb_close(const void *descriptor);

const FileDriver usb_driver = {
		.init  = usb_init,
		.open  = usb_open,
		.write = usb_write,
		.read  = usb_read,
		.ioctl = usb_ioctl,
		.close = usb_close
};


#endif /* CORE_HARDWARE_DEVICE_DRIVER_DRIVER_USB_H_ */
