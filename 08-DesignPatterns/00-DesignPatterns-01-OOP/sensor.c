/*
 * sensor.c
 *
 *  Created on: 19 de abr de 2019
 *      Author: solid
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"



void static Sensor_Init(Sensor * const me)
{
	printf("Initialized.\n");
}

void static Sensor_Cleanup(Sensor * const me)
{
	printf("Cleaned.\n");
}

int Sensor_getFilterFrequency(const Sensor * const me)
{
	return me->filterFrequency;
}

void Sensor_setFilterFrequency(Sensor * const me, int p_filterFrequency)
{
	me->filterFrequency = p_filterFrequency;
}

int Sensor_getUpdateFrequency(const Sensor * const me)
{
	return me->updateFrequency;
}

void Sensor_setUpdateFrequency(Sensor * const me, int p_updateFrequency)
{
	me->updateFrequency = p_updateFrequency;
}

int Sensor_getValue(const Sensor * const me)
{
	return me->value;
}

Sensor * Sensor_create(void)
{
	Sensor * s = (Sensor *)malloc(sizeof(Sensor));

	if(s != NULL)
		Sensor_Init(s);

	return s;
}

void Sensor_Destroy(Sensor * const me)
{
	if(me != NULL)
		Sensor_Cleanup(me);

	free(me);
}
