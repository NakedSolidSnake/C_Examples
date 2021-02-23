#ifndef _ADC_H
#define _ADC_H

/* include *******************************************************************************************/
#include <stdint.h>

/* defines *******************************************************************************************/

/* enumerations **************************************************************************************/

/* structures ****************************************************************************************/
typedef struct ADC_Descriptor{
	uint8_t id;
	const uint8_t *ad_name;
}ADC_Descriptor;

/* public functions **********************************************************************************/
int8_t  adc_open (const void *context);
int32_t adc_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t adc_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  adc_ioctl(const void *context, uint8_t command, void *args);
int8_t  adc_close(const void *context);

#endif 
