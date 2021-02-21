#include <server/server_tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jsmn.h>

#define MAX_LEN  10
#define CLEAR     0
#define SET       1


typedef int (*cb)(char *buffer, int *size);

static int receive(char *buffer, int size);
static int send(char *buffer, int *size);

static int sendPage(char *buffer, int *size);
static int insertData(char *buffer, int *size);
static int deleteData(char *buffer, int *size);
static int updateData(char *buffer, int *size);

static int jsoneq(const char *json, jsmntok_t *tok, const char *s);

typedef struct 
{
  char method[MAX_LEN];
  int size;
  cb call_method;  
  int set;
}method_t;


static method_t methods[] = 
{
  {.method = "GET"   , .size = 3, .call_method = sendPage  , .set = 0},
  {.method = "POST"  , .size = 4, .call_method = insertData, .set = 0},
  {.method = "DELETE", .size = 6, .call_method = deleteData, .set = 0},
  {.method = "PUT"   , .size = 3, .call_method = updateData, .set = 0}
};

int main()
{

  Server_t s = {
      .socket = -1,
      .port = "3404",
      .cb.recv = receive,
      .cb.send = send};

  Server_init(&s);
  printf("Running on port: %s\n", s.port);
  Server_exec(&s);
}

static int receive(char *buffer, int size)
{  
  printf("%*s\n", 6, buffer);

  for(int i = 0; i < sizeof(methods)/sizeof(methods[0]); i++){
    if(!strncmp(methods[i].method, buffer, methods[i].size)){
      methods[i].set = SET;
      return 0;
    }
  }
  //send error
  return 1;
}

static int send(char *buffer, int *size)
{

  for(int i = 0; i < sizeof(methods)/sizeof(methods[0]); i++){
    if(methods[i].set == SET){
      methods[i].set = CLEAR;
      methods[i].call_method(buffer, size);
      return 0;
    }
  }

  return 1;  
}

/* Treat GET method */
static int sendPage(char *buffer, int *size)
{
  FILE *fd = fopen("../../public/index.html", "r");
  if(fd == NULL){
    return 1;
  }

  fseek(fd, 0, SEEK_END);
  int filesize = ftell(fd);  
  rewind(fd);

  char rdBuffer[filesize + 1];

  fread(rdBuffer, 1, filesize, fd);

  rdBuffer[filesize] = 0;
  // printf("%s\n", rdBuffer);

  fclose(fd);

  memset(buffer, 0, MAX_BUFFER_SEND_RECV);
  sprintf(buffer, "HTTP/1.1 200 OK\r\n"
                  "Connection: close\r\n"
                  "Content-Length: %u\r\n"
                  "Content-Type: %s\r\n"
                  "\r\n"
                  "%s",
                   filesize, "text/html", rdBuffer);
  *size = strlen(buffer);
  return 0;
}

/* Treat POST method */
static int insertData(char *buffer, int *size)
{

  //trata json
  int r;
  jsmn_parser p;
  jsmntok_t t[128];

  char *q = strstr(buffer, "\r\n\r\n");
  char *data = (q + 4);

  jsmn_init(&p);
  r = jsmn_parse(&p, data, strlen(data), t,
                 sizeof(t) / sizeof(t[0]));
  if (r < 0) {
    printf("Failed to parse JSON: %d\n", r);
    return 1;
  }

  if (r < 1 || t[0].type != JSMN_OBJECT) {
    printf("Object expected\n");
    return 1;
  }

  int i;

  for (i = 1; i < r; i++) {
    if (jsoneq(data, &t[i], "name") == 0) {
      /* We may use strndup() to fetch string value */
      printf("- User: %.*s\n", t[i + 1].end - t[i + 1].start,
             data + t[i + 1].start);
      i++;
    }else {
      printf("Unexpected key: %.*s\n", t[i].end - t[i].start,
             data + t[i].start);
    }
  }
  
  //send ok
  printf("Called post method.\nData: %s\n", data);
  memset(buffer, 0, MAX_BUFFER_SEND_RECV);
  sprintf(buffer, "HTTP/1.1 200 OK\r\n"
                  "Connection: close\r\n"                 
                  "\r\n");
  *size = strlen(buffer); 

  return 0;
}

static int deleteData(char *buffer, int *size)
{
  printf("DELETE called.\n");

  memset(buffer, 0, MAX_BUFFER_SEND_RECV);
  sprintf(buffer, "HTTP/1.1 200 OK\r\n"
                  "Connection: close\r\n"                 
                  "\r\n");
  *size = strlen(buffer); 
  return 0;
}

static int updateData(char *buffer, int *size)
{
  printf("PUT called.\n");
  
  memset(buffer, 0, MAX_BUFFER_SEND_RECV);
  sprintf(buffer, "HTTP/1.1 200 OK\r\n"
                  "Connection: close\r\n"                 
                  "\r\n");
  *size = strlen(buffer); 
  return 0;
}

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
  if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
      strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
    return 0;
  }
  return -1;
}