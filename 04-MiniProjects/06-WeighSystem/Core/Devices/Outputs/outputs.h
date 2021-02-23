#ifndef _OUTPUTS_H
#define _OUTPUTS_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct Outputs_Descriptor{
	uint8_t id;
	const uint8_t *Outputs_name;
}Outputs_Descriptor;

/* public functions **********************************************************************************/
int8_t  outputs_open (const void *context);
int32_t outputs_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t outputs_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  outputs_ioctl(const void *context, uint8_t command, void *args);
int8_t  outputs_close(const void *context);

#endif
