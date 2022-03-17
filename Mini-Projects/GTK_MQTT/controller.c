#include "controller.h"
#include <string.h>

static bool controller_on_bt_on_off_toggled (void *object, bool state);

static bool mqtt_init (controller_t *controller);
static void mqtt_publish(MQTTClient client, char* topic, char* payload);
static int mqtt_on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message);

bool controller_init (controller_t *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        memset (controller, 0, sizeof (controller_t));

        controller->base.object = controller;
        controller->base.on_bt_on_off_toggled = controller_on_bt_on_off_toggled;

        status = true;
    }

    return status;
}

bool controller_open (controller_t *controller, controller_args_t *args)
{
    bool status = false;

    if (controller != NULL)
    {
        controller->view = args->view;

        status = mqtt_init (controller);
    }

    return status;
}

bool controller_exec (controller_t *controller)
{
    controller->view->run (controller->view->object);
    return true;
}

bool controller_close (controller_t *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        memset (controller, 0, sizeof (controller_t));        
        status = true;
    }

    return status;
}

static bool controller_on_bt_on_off_toggled (void *object, bool state)
{
    controller_t *controller = (controller_t *)object;
    
    mqtt_publish (controller->client, MQTT_PUBLISH_ENABLE, state ? "1" : "0");
    return state;
}

static bool mqtt_init (controller_t *controller)
{
    bool status = false;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    MQTTClient_create(&controller->client, MQTT_ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(controller->client, (void *)controller->view, NULL, mqtt_on_message, NULL);

    if (MQTTClient_connect(controller->client, &conn_opts) == MQTTCLIENT_SUCCESS)
    {
        MQTTClient_subscribe(controller->client, MQTT_SUBSCRIBE_HUMIDITY_TOPIC, 0);
        MQTTClient_subscribe(controller->client, MQTT_SUBSCRIBE_TEMPERATURE_TOPIC, 0);
        status = true;        
    }

    return status;
}

static void mqtt_publish(MQTTClient client, char* topic, char* payload)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
 
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(pubmsg.payload);
    pubmsg.qos = 0;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000L);
}

static int mqtt_on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    view_base_t *base = (view_base_t *)context;

    base->set_state (base->object, true);

    if (strcmp (MQTT_SUBSCRIBE_HUMIDITY_TOPIC, topicName) == 0)
    {
        base->set_humidity_text (base->object, message->payload);
    }

    else if (strcmp (MQTT_SUBSCRIBE_TEMPERATURE_TOPIC, topicName) == 0)
    {
        base->set_temperature_text (base->object, message->payload);
    }

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;  
}