#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "controller_base.h"
#include "view_base.h"
#include <MQTTClient.h>

#define MQTT_ADDRESS   "localhost"
#define CLIENTID       "MQTTCClientID"

#define MQTT_SUBSCRIBE_HUMIDITY_TOPIC      "home/humidity/1"
#define MQTT_SUBSCRIBE_TEMPERATURE_TOPIC   "home/temperature/1"

#define MQTT_PUBLISH_ENABLE                 "home/1/enable"

typedef struct 
{
    controller_base_t base;
    view_base_t *view;
    MQTTClient client;
} controller_t;

typedef struct 
{
    view_base_t *view;
} controller_args_t;

bool controller_init (controller_t *controller);
bool controller_open (controller_t *controller, controller_args_t *args);
bool controller_exec (controller_t *controller);
bool controller_close (controller_t *controller);

#endif /* CONTROLLER_H_ */
