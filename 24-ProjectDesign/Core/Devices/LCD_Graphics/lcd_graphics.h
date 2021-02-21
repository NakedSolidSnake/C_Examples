#ifndef _LCD_GRAPHICS_H
#define _LCD_GRAPHICS_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct LcdGraphics_Descriptor{
	uint8_t id;
	const uint8_t *lcd_graphics_name;
}LcdGraphics_Descriptor;

/* public functions **********************************************************************************/
int8_t  lcd_graphics_open (const void *context);
int32_t lcd_graphics_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t lcd_graphics_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  lcd_graphics_ioctl(const void *context, uint8_t command, void *args);
int8_t  lcd_graphics_close(const void *context);

#endif
