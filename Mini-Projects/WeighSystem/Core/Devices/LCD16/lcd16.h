#ifndef _LCD16_H
#define _LCD16_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct Lcd16_Descriptor{
	uint8_t id;
	const uint8_t *lcd16_name;
}Lcd16_Descriptor;

/* public functions **********************************************************************************/
int8_t  lcd16_open (const void *context);
int32_t lcd16_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t lcd16_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  lcd16_ioctl(const void *context, uint8_t command, void *args);
int8_t  lcd16_close(const void *context);

#endif
