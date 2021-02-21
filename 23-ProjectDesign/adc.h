#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>

int8_t  adc_open (const void *context);
int32_t adc_write(const void *context, const void *buffer_write, uint32_t size); 
int32_t adc_read (const void *context, void *buffer_read, uint32_t *size);
int8_t  adc_ioctl(const void *context, uint8_t command, void *args);
int8_t  adc_close(const void *context);

#endif 
