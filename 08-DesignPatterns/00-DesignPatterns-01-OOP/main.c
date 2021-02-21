/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

int main(void) {
	Sensor *p_Sensor0, *p_Sensor1;

	p_Sensor0 = Sensor_create();
	p_Sensor1 = Sensor_create();

	p_Sensor0->value = 99;
	p_Sensor1->value = -1;

	printf("Sensor 0 current value = %d\n", Sensor_getValue(p_Sensor0));
	printf("Sensor 1 current value = %d\n", Sensor_getValue(p_Sensor1));

	Sensor_Destroy(p_Sensor0);
	Sensor_Destroy(p_Sensor1);

	return EXIT_SUCCESS;
}
