/*
 * pid.h
 *
 *  Created on: 05/11/2018
 *      Author: csouza
 */

#ifndef PID_H_
#define PID_H_

#include <stdint.h>

typedef struct PID_Params{
	float kp;
	float ki;
	float kd;
}PID_Parameters;

int8_t PID_Init(PID_Parameters *params);

int8_t PID_IsInitialized(void);
int8_t PID_SetConstants(float kp, float ki, float kd);
int8_t PID_GetConstants(float *kp, float *ki, float *kd);

float PID_P  (float setPoint, float currentValue);
float PID_PD (float setPoint, float currentValue);
float PID_PI (float setPoint, float currentValue);
float PID_PID(float setPoint, float currentValue);

#endif /* PID_H_ */
