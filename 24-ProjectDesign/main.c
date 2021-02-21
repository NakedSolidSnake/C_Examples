#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "FileOperation/fileoperation.h"
#include "Algorithm/Filters/PID/pid.h"
#include "rtos/tasks.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//const uint8_t *dev_name = (uint8_t *)"Bluetooth";
//const uint8_t *dev_name = (uint8_t *)"Keyboard";
//const uint8_t *dev_name = (uint8_t *)"LCD16";
//const uint8_t *dev_name = (uint8_t *)"Serial";
//const uint8_t *dev_name = (uint8_t *)"Zigbee";
//const uint8_t *dev_name = (uint8_t *)"ADC";
//const uint8_t *dev_name = (uint8_t *)"LCD_Graphics";
const uint8_t *dev_name = (uint8_t *)"TIMER";

void Test_PID(void);
void Test_Tasks(void);

int main(int argc, char *argv[]) {
	
	/*uint8_t handle = device_open(dev_name);
	device_close(handle);	
	handle = device_open(dev_name);
	device_close(handle);
	handle = device_open(dev_name);
	device_close(handle);
	handle = device_open(dev_name);
	device_close(handle);*/
	
//	uint8_t handle = device_open(dev_name);
//	device_close(handle);
//	handle = device_open(dev_name);
//	device_close(handle);
//	handle = device_open(dev_name);
//	device_close(handle);
//	handle = device_open(dev_name);
//	device_write(handle, NULL, 0);
//	device_read(handle, NULL, 0);
//	device_ioctl(handle, 1, NULL);
//	device_close(handle);
	
	Test_Tasks();
//	Test_PID();
	while(1);
	return 0;
}

void Test_PID(void)
{
	int i;
	float resul = 0.0F;
	PID_Parameters param = {
			1.0F,
			1.0F,
			1.0F
	};

	PID_Init(&param);

//	for(i = 0; i < 10; i++)
//	{
//		resul = PID_P(10.0F, resul);
//		printf("P resul = %.2f\n", resul);
//
//	}
//
//	for(i = 0; i < 10; i++)
//	{
//		resul = PID_PI(10.0F, resul);
//		printf("PI - resul = %.2f\n", resul);
//
//	}
//
//	for(i = 0; i < 10; i++)
//	{
//		resul = PID_PD(10.0F, resul);
//		printf("PD - resul = %.2f\n", resul);
//	}

	for(i = 0; i < 10; i++)
	{
		resul = PID_PID(10.0F, resul);
		printf("PID - resul = %.2f\n", resul);
	}
}

void Test_Tasks(void)
{
	Tasks_Init();
}
