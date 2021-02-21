#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "MQTTClient.h"

#define STATE_ON "on"
#define STATE_OFF "off"

#define ADDRESS     "localhost"
#define CLIENTID    "555333"

#define TANK_CAPACITY 1000

#define TANK_LEVEL_TOPIC    "/tank/level"
#define TANK_PUMP_TOPIC     "/tank/pump"
#define TANK_SINK_TOPIC     "/tank/sink"
#define TANK_SENSORS_TOPIC  "/tank/sensors"

#define TANK_PUMP_CONTROL_TOPIC   "/tank/control/pump"
#define TANK_SINK_CONTROL_TOPIC   "/tank/control/sink"

typedef void *(*TaskExecute)(void *args);

typedef struct
{
    union
    {
        struct
        {
            unsigned char levelGround : 1;
            unsigned char levelFirst : 1;
            unsigned char levelSecond : 1;
            unsigned char levelThird : 1;
            unsigned char levelFull : 1;
            unsigned char notUsed : 3;
        };

        unsigned char sensor;
    };
} Sensors;

typedef struct
{
    Sensors sensors;
    int level;
    int pump;
    int sink;
} TankParams;

typedef struct
{
    pthread_t thread;
    const char *taskName;
    TaskExecute task;
} TaskTable;

void *taskSensor(void *args);
void *taskLCD(void *args);
void *taskWaterPump(void *args);
void *taskWaterFlow(void *args);
void *taskSinkControl(void *args);
void *taskPublish(void *args);

static const char *getState(int state);
static void publish(MQTTClient client, char* topic, char* payload);
static int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message);

static void publishTankLevel(MQTTClient client);
static void publishTankPump(MQTTClient client);
static void publishTankSink(MQTTClient client);
static void publishTankSensors(MQTTClient client);

static void applyCommand(const char *topicName, const char *payload);


static TankParams tankParams;

int main()
{

    memset(&tankParams, 0, sizeof(TankParams));

    TaskTable taskTable[] =
        {
            {.thread = -1, .taskName = "task sensor"      , .task = taskSensor},
            {.thread = -1, .taskName = "task LCD"         , .task = taskLCD},
            {.thread = -1, .taskName = "task Water Flow"  , .task = taskWaterFlow},
            {.thread = -1, .taskName = "task Sink Control", .task = taskSinkControl},
            {.thread = -1, .taskName = "task Publish"     , .task = taskPublish},
        };

    int items = sizeof(taskTable) / sizeof(taskTable[0]);

    for (int i = 0; i < items; i++)
    {
        pthread_create(&taskTable[i].thread, NULL, taskTable[i].task, NULL);
        pthread_setname_np(taskTable[i].thread, taskTable[i].taskName);
    }

    for (int i = 0; i < items; i++)
    {
        pthread_join(taskTable[i].thread, NULL);
    }
}

void *taskSensor(void *args)
{
    printf("Task Sensor is created.\n");
    while (1)
    {
        switch (tankParams.level)
        {
        case 0 ... 200:
            tankParams.sensors.levelGround = 1;
            tankParams.sensors.levelFirst  = 1;
            tankParams.sensors.levelSecond = 1;
            tankParams.sensors.levelThird  = 1;
            tankParams.sensors.levelFull   = 1;
            tankParams.pump = 1;
            break;

        case 201 ... 400:
            tankParams.sensors.levelGround = 0;
            tankParams.sensors.levelFirst  = 1;
            tankParams.sensors.levelSecond = 1;
            tankParams.sensors.levelThird  = 1;
            tankParams.sensors.levelFull   = 1;
            
            break;

        case 401 ... 600:
            tankParams.sensors.levelGround = 0;
            tankParams.sensors.levelFirst  = 0;
            tankParams.sensors.levelSecond = 1;
            tankParams.sensors.levelThird  = 1;
            tankParams.sensors.levelFull   = 1;

            break;

        case 601 ... 800:
            tankParams.sensors.levelGround = 0;
            tankParams.sensors.levelFirst  = 0;
            tankParams.sensors.levelSecond = 0;
            tankParams.sensors.levelThird  = 1;
            tankParams.sensors.levelFull   = 1;
            break;

        case 801 ... 999:
            tankParams.sensors.levelGround = 0;
            tankParams.sensors.levelFirst  = 0;
            tankParams.sensors.levelSecond = 0;
            tankParams.sensors.levelThird  = 0;
            tankParams.sensors.levelFull   = 1;
            break;

        case TANK_CAPACITY:
            tankParams.sensors.levelGround = 0;
            tankParams.sensors.levelFirst  = 0;
            tankParams.sensors.levelSecond = 0;
            tankParams.sensors.levelThird  = 0;
            tankParams.sensors.levelFull   = 0;
            tankParams.pump = 0;
            break;

        default:
            break;
        }
        usleep(10000);
    }

    return NULL;
}

void *taskLCD(void *args)
{
    printf("Task LCD is created.\n");
    while (1)
    {
        printf("Tank Level %d Liters.\n", tankParams.level);
        printf("Pump State %s.\n", getState(tankParams.pump));
        printf("Sink State %s.\n", getState(tankParams.sink));
        printf("Sensors.\n");
        printf("------------------------------------\n");
        printf("Sensor Ground: %s\n", getState(tankParams.sensors.levelGround));
        printf("Sensor First:  %s\n", getState(tankParams.sensors.levelFirst));
        printf("Sensor Second: %s\n", getState(tankParams.sensors.levelSecond));
        printf("Sensor Third:  %s\n", getState(tankParams.sensors.levelThird));
        printf("Sensor Full:   %s\n", getState(tankParams.sensors.levelFull));
        sleep(1);
        system("clear");
    }

    return NULL;
}

void *taskWaterFlow(void *args)
{
    printf("Task Water Flow is created.\n");
    while (1)
    {

        if(tankParams.sink)
        {
            if((tankParams.level--) <= 0)
                tankParams.level = 0;
        }

        if(tankParams.pump)
        {
            if((tankParams.level+=5) > TANK_CAPACITY)
                tankParams.level = TANK_CAPACITY;
        }

        usleep(100000);
    }

    return NULL;
}

void *taskSinkControl(void *args)
{
    while(1)
    {
        scanf("%d", &tankParams.sink);
        sleep(1);
    }
}

void *taskPublish(void *args)
{
    MQTTClient client;
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    MQTTClient_setCallbacks(client, NULL, NULL, on_message, NULL);

    int rc;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }

    MQTTClient_subscribe(client, TANK_SINK_CONTROL_TOPIC, 0);
    MQTTClient_subscribe(client, TANK_PUMP_CONTROL_TOPIC, 0);

    while(1)
    {
        publishTankLevel(client);
        publishTankPump(client);
        publishTankSink(client);
        publishTankSensors(client);
        sleep(1);
    }
}

static const char *getState(int state)
{
    const char *p = NULL;
    if (state == 0)
        p = STATE_OFF;
    else if (state == 1)
        p = STATE_ON;

    return p;
}

static void publish(MQTTClient client, char* topic, char* payload) {
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(pubmsg.payload);
    pubmsg.qos = 0;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000L);    
}

static int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message) {    
    char* payload = message->payload;
    applyCommand(topicName, payload);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

static void publishTankLevel(MQTTClient client)
{
    char buffer[10] = {0};
    memset(buffer, 0, 10);
    snprintf(buffer, 10, "%d", tankParams.level);
    publish(client, TANK_LEVEL_TOPIC, buffer);
}

static void publishTankPump(MQTTClient client)
{
    char buffer[10] = {0};
    snprintf(buffer, 10, "%d", tankParams.pump);
    publish(client, TANK_PUMP_TOPIC, buffer);
}

static void publishTankSink(MQTTClient client)
{
    char buffer[10] = {0};
    snprintf(buffer, 10, "%d", tankParams.sink);
    publish(client, TANK_SINK_TOPIC, buffer);
}

static void publishTankSensors(MQTTClient client)
{
    char buffer[10] = {0};
    int sensors = 0;

    sensors |= (tankParams.sensors.levelGround << 0);
    sensors |= (tankParams.sensors.levelFirst  << 1);
    sensors |= (tankParams.sensors.levelSecond << 2);
    sensors |= (tankParams.sensors.levelThird  << 3);
    sensors |= (tankParams.sensors.levelFull   << 4);

    snprintf(buffer, 10, "%X", sensors);
    publish(client, TANK_SENSORS_TOPIC, buffer);
}

static void applyCommand(const char *topicName, const char *payload)
{
    if(strncmp(topicName, TANK_SINK_CONTROL_TOPIC, strlen(TANK_SINK_CONTROL_TOPIC) - 1) == 0){
        tankParams.sink = atoi(payload);
    }else if(strncmp(topicName, TANK_PUMP_CONTROL_TOPIC, strlen(TANK_PUMP_CONTROL_TOPIC) - 1) == 0){
        tankParams.pump = atoi(payload);
    }
}