#include <stdio.h>
#include <stdlib.h>
#include "json.h"

typedef struct 
{
    char *ssid;
    char *password;
} NetworkConfig;

typedef struct 
{
    char *hostname;
    char *username;
    char *password;
    char *database;
} DatabaseConfig;

typedef struct 
{
    char *led_topic;
    char *button_topic;
} Topic;

typedef struct 
{
    char *user;
    char *password;
    Topic topic;
} MQTT;

typedef struct 
{
    NetworkConfig network;
    DatabaseConfig database;
    MQTT mqtt;
    int dummy;
} Config;




static Config config = {0};

static IHandler iMQTTSub[] = 
    {
        {.token = "led",     .data = &config.mqtt.topic.led_topic,     .type = eType_String, .child = NULL},
        {.token = "button",  .data = &config.mqtt.topic.button_topic,  .type = eType_String, .child = NULL},
    };

static IHandler iMQTT[] = 
    {
        {.token = "user",     .data = &config.mqtt.user,     .type = eType_String, .child = NULL},
        {.token = "password", .data = &config.mqtt.password, .type = eType_String, .child = NULL},
        {.token = "topic",    .data = &config.mqtt.topic,    .type = eType_Object, .child = iMQTTSub, .size = getItems(iMQTTSub)},
    };

static IHandler iNetwork[] = 
    {
        {.token = "ssid",     .data = &config.network.ssid,     .type = eType_String, .child = NULL},
        {.token = "password", .data = &config.network.password, .type = eType_String, .child = NULL},
    };

static IHandler iDatabase[] = 
    {
        {.token = "hostname", .data = &config.database.hostname, .type = eType_String, .child = NULL},
        {.token = "username", .data = &config.database.username, .type = eType_String, .child = NULL},
        {.token = "password", .data = &config.database.password, .type = eType_String, .child = NULL},
        {.token = "database", .data = &config.database.database, .type = eType_String, .child = NULL},
    };

static IHandler iConfig[] = 
    {
        {.token = "network",  .data = &config.network,  .type = eType_Object,  .child = iNetwork,  .size = getItems(iNetwork)},
        {.token = "database", .data = &config.database, .type = eType_Object,  .child = iDatabase, .size = getItems(iDatabase)},
        {.token = "mqtt",     .data = &config.mqtt,     .type = eType_Object,  .child = iMQTT,     .size = getItems(iMQTT)},
        {.token = "dummy",    .data = &config.dummy,    .type = eType_Int,     .child = NULL}
    };


int main(int argc, char **argv) {
	
	char buffer[1024];

    if(!getJsonFromFile("properties.json", buffer, 1024)){
        return EXIT_FAILURE;
    }

    processJson(buffer, iConfig, getItems(iConfig));

    printf("Network:\nssid: %s\npassword: %s\n\n", config.network.ssid, config.network.password);
    printf("Database:\nhostname: %s\nusername: %s\npassword: %s\ndatabase: %s\n\n",
                                                                                 config.database.hostname,
                                                                                 config.database.username,
                                                                                 config.database.password,
                                                                                 config.database.database);
    printf("MQTT:\nuser: %s\npassword: %s\n\tTopic:\n\t\tled: %s\n\t\tbutton: %s\n\n",
                                                                                     config.mqtt.user,
                                                                                     config.mqtt.password,
                                                                                     config.mqtt.topic.led_topic,
                                                                                     config.mqtt.topic.button_topic);
}






