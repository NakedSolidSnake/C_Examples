#include "adc.h"

#include <stdio.h>

#define RET_OK 1

typedef struct adc_ctx{
	uint8_t init;
}Adc_ctx;

static Adc_ctx ad_ctx = {
	.init = 0
};

static void adc_init(const void *context);


static void adc_init(const void *context)
{	
	if(!ad_ctx.init)
	{
		printf("ADC initialized\n");
		ad_ctx.init = 1;
	}	
}



int8_t  adc_open (const void *context)
{
	adc_init(context);
	printf("ADC openned\n");
	return RET_OK;
}

int32_t adc_write(const void *context, const void *buffer_write, uint32_t size)
{
	printf("ADC write\n");
}

int32_t adc_read (const void *context, void *buffer_read, uint32_t *size)
{
	printf("ADC read\n");
}

int8_t  adc_ioctl(const void *context, uint8_t command, void *args)
{
	printf("ADC ioctl\n");
	return RET_OK;
}

int8_t  adc_close(const void *context)
{
	printf("ADC close\n");
	return RET_OK;
}
