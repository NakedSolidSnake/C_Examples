/*
 * pid.c
 *
 *  Created on: 05/11/2018
 *      Author: csouza
 */

#include "pid.h"

typedef struct PID_Context{
	PID_Parameters params;
	float error;
	float proportional;
	float integral;
	float derivative;
	float last_error;
	int8_t init;
}PID_Context;

static PID_Context pid_context = {
		.params = {0.0F, 0.0F, 0.0F},
		.error = 0.0F,
		.proportional = 0.0F,
		.integral = 0.0F,
		.derivative = 0.0F,
		.last_error = 0.0F,
		.init = -1
};

int8_t PID_Init(PID_Parameters *params)
{
	if(params)
	{
		pid_context.params.kd = params->kd;
		pid_context.params.kp = params->kp;
		pid_context.params.ki = params->ki;
		pid_context.init = 0;
		return 0;
	}
	return -1;
}

int8_t PID_IsInitialized(void)
{
	return pid_context.init;
}

int8_t PID_SetConstants(float kp, float ki, float kd)
{
	pid_context.params.kd = kd;
	pid_context.params.kp = kp;
	pid_context.params.ki = ki;
	return 0;
}

int8_t PID_GetConstants(float *kp, float *ki, float *kd)
{
	*kd = pid_context.params.kd;
	*kp = pid_context.params.kp;
	*ki = pid_context.params.ki;
	return 0;
}


float PID_P  (float setPoint, float currentValue)
{
	float resul_filter = 0.0F;
	if(pid_context.init >= 0)
	{
		pid_context.error = setPoint - currentValue;
		resul_filter = pid_context.params.kp * pid_context.error;
	}

	return resul_filter;
}

float PID_PD (float setPoint, float currentValue)
{
	float resul_filter = 0.0F;

	if(pid_context.init >= 0)
	{
		pid_context.error = setPoint - currentValue;
		pid_context.derivative = pid_context.error - pid_context.last_error;
		resul_filter = (pid_context.params.kp * pid_context.error) + (pid_context.params.kd * pid_context.derivative);
		pid_context.last_error = pid_context.error;
	}

	return resul_filter;
}

float PID_PI (float setPoint, float currentValue)
{
	float resul_filter = 0.0F;

	if(pid_context.init >= 0)
	{

		pid_context.error = setPoint - currentValue;
		pid_context.integral = pid_context.integral + pid_context.error;
		resul_filter = (pid_context.params.kp * pid_context.error) + (pid_context.params.ki * pid_context.integral);
	}

	return resul_filter;
}

float PID_PID(float setPoint, float currentValue)
{
	float resul_filter = 0.0F;

	if(pid_context.init >= 0)
	{
		pid_context.error = setPoint - currentValue;
		pid_context.derivative = pid_context.error - pid_context.last_error;
		pid_context.integral = pid_context.integral + pid_context.error;
		resul_filter = (pid_context.params.kp * pid_context.error) + (pid_context.params.ki * pid_context.integral) + (pid_context.params.kd * pid_context.derivative);
		pid_context.last_error = pid_context.error;
	}

	return resul_filter;
}
