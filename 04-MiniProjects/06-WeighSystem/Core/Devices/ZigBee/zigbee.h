#ifndef _ZIGBEE_H
#define _ZIGBEE_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct ZigBee_Descriptor{
	uint8_t id;
	const uint8_t *zigbee_name;
}ZigBee_Descriptor;

/* public functions **********************************************************************************/
int8_t  zigbee_open (const void *context);
int32_t zigbee_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t zigbee_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  zigbee_ioctl(const void *context, uint8_t command, void *args);
int8_t  zigbee_close(const void *context);

#endif
