/*
 * sensor.h
 *
 *  Created on: 19 de abr de 2019
 *      Author: solid
 */

#ifndef SENSOR_H_
#define SENSOR_H_

typedef struct Sensor Sensor;

struct Sensor{
	int filterFrequency;
	int updateFrequency;
	int value;
};

int Sensor_getFilterFrequency(const Sensor * const me);

void Sensor_setFilterFrequency(Sensor * const me, int p_filterFrequency);

int Sensor_getUpdateFrequency(const Sensor * const me);

void Sensor_setUpdateFrequency(Sensor * const me, int p_updateFrequency);

int Sensor_getValue(const Sensor * const me);

Sensor * Sensor_create(void);

void Sensor_Destroy(Sensor * const me);




#endif /* SENSOR_H_ */
