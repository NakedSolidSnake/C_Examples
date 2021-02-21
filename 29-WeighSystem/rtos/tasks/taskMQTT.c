#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "taskMQTT.h"
#include "../../FileOperation/fileoperation.h"

static pthread_t thread_MQTT;

void *task_MQTT_Publish(void* args)
{
	static unsigned long count = 0;
	char buffer[100] = {0};

	while(1)
	{	
		printf("Publishing on Topic\n");
		sprintf(buffer, "mosquitto_pub -h localhost -t test -m %08u\n", count);		
		system(buffer);
		usleep(500000);
		count++;
	}
}

int8_t Task_MQTT_Start(void)
{
	return pthread_create(&thread_MQTT, NULL, task_MQTT_Publish, NULL);
}

int8_t Task_MQTT_Wait_Finish(void)
{
	return (int8_t)pthread_join(thread_MQTT, NULL);	
}

int8_t Task_MQTT_Destroy(void)
{
	return (int8_t)pthread_cancel(thread_MQTT);
}