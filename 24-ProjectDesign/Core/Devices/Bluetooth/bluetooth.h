#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct Bluetooth_Descriptor{
	uint8_t id;
	const uint8_t *bluetooth_name;
}Bluetooth_Descriptor;

/* public functions **********************************************************************************/
int8_t  bluetooth_open (const void *context);
int32_t bluetooth_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t bluetooth_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  bluetooth_ioctl(const void *context, uint8_t command, void *args);
int8_t  bluetooth_close(const void *context);


#endif
