/* include *******************************************************************************************/
#include "adc.h"
#include <stdio.h>

/* defines *******************************************************************************************/
#define RET_OK 1

/* structures ****************************************************************************************/
typedef struct adc_ctx{
	uint8_t init;
	uint8_t ioctl_list;
}Adc_ctx;

/* typedefs ******************************************************************************************/

typedef void (*AdcIoctl)(void *parameter);

/* private functions *********************************************************************************/
static void adc_getValue(void *args);
/* If you remove this comment remove init function from open and comment the follow function*/
/* with this, the compiler will resolve the call of all init functions */
//static void adc_init(const void *context) __attribute__((constructor));
static void adc_init(const void *context);

/* ioctl functions entry *****************************************************************************/
AdcIoctl adc_ioctl_functions[] = {
		adc_getValue
};

/* global variables **********************************************************************************/
static Adc_ctx ad_ctx = {
	.init = 0,
	.ioctl_list = sizeof(adc_ioctl_functions)/sizeof(adc_ioctl_functions[0])
};

/* private functions implementation ******************************************************************/
static void adc_getValue(void *args)
{
	printf("adc_getValue\n");
}

static void adc_init(const void *context)
{	
	ADC_Descriptor  *adc_descriptor = context;
	if(!ad_ctx.init)
	{
		printf("ADC initialized\n");
		ad_ctx.init = 1;
	}	
}

/* public functions implementation *******************************************************************/
int8_t  adc_open (const void *context)
{
	ADC_Descriptor  *adc_descriptor = context;
	adc_init(context);
	printf("ADC openned\n");
	return RET_OK;
}

int32_t adc_write(const void *context, const void *buffer_write, uint32_t size)
{
	ADC_Descriptor  *adc_descriptor = context;
	printf("ADC write\n");
	return RET_OK;
}

int32_t adc_read (const void *context, void *buffer_read, uint32_t *size)
{
	ADC_Descriptor  *adc_descriptor = context;
	printf("ADC read\n");
	return RET_OK;
}

int8_t  adc_ioctl(const void *context, uint8_t command, void *args)
{
	ADC_Descriptor  *adc_descriptor = context;
	printf("ADC ioctl\n");
	if(command < ad_ctx.ioctl_list){
		(*adc_ioctl_functions[command])(args);
		return RET_OK;
	}
	return -1;
}

int8_t  adc_close(const void *context)
{
	ADC_Descriptor  *adc_descriptor = context;
	printf("ADC close\n");
	return RET_OK;
}
