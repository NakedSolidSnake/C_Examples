#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <jsmn.h>

#define BSIZE   0x3000  //4096 bytes

static void fail(int test, const char *format, ...)
{
  if(test)
  {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    exit(EXIT_FAILURE);
  }
}

static int jsoneq(const char *json, jsmntok_t *tok, const char *s){

  if(tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start && 
      strncmp(json + tok->start,s , tok->end - tok->start) == 0){
    return 0;
  }
  return -1;
}

static void parse_page(const char *buf, int size)
{
  int r;
  int i;
  jsmn_parser p;
  jsmntok_t t[BSIZE];

  if (size == 0)
    return ;

  jsmn_init(&p);

  r = jsmn_parse(&p, buf, strlen(buf), t, sizeof(t)/sizeof(t[0]));
  if(r < 0)
  {
    printf("Failed to parse JSON: %d\n", r);
    return ;
  }

  if(r < 1 || t[0].type != JSMN_OBJECT){
    printf("Object expected.\n");
    return;
  }


  for(i == 0; i < r; i++){
    if(jsoneq(buf, &t[i], "userId") == 0){
      printf("- User ID: %.*s", t[i + 1].end - t[i + 1].start, buf + t[i + i].start);
      i++;
    }
    if(jsoneq(buf, &t[i], "id") == 0){
      printf("- ID: %.*s", t[i + 1].end - t[i + 1].start, buf + t[i + i].start);
      i++;
    }
    if(jsoneq(buf, &t[i], "title") == 0){
      printf("- title: %.*s", t[i + 1].end - t[i + 1].start, buf + t[i + i].start);
      i++;
    }
    if(jsoneq(buf, &t[i], "body") == 0){
      printf("- Body: %.*s", t[i + 1].end - t[i + 1].start, buf + t[i + i].start);
      i++;
    }
  }

}

static void get_page(int s, const char *host, const char *page)
{
  char *msg;

  //const char *format = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: fetch.c\r\n\r\n";
  const char *format = "GET /%s HTTP/1.1\r\nHost: %s\r\nContent-type: application/json\r\n\r\n";


  int status ;

  status = asprintf(&msg, format, page, host);
  printf("%s", msg);

  fail(status == -1 || !msg, "asprintf failed.\n");

  status = send(s, msg, strlen(msg), 0);

  fail(status == -1, "send failed: %s\n", strerror(errno));

  while(1)
  {
    int bytes;

    char buf[BSIZE + 10];

    bytes = recvfrom(s, buf, BSIZE, 0, 0, 0);

    if(bytes == 0)
      break;

    fail(bytes == -1, "%s\n", strerror(errno));
    buf[bytes] = '\0';

  //  printf("%s", buf);
    const char *pBuf = strstr(buf, "{");
    parse_page(pBuf, strlen(buf));
  }

  free(msg);
}

int main(int argc, char *argv[])
{

  struct addrinfo hints, *res, *res0;
  int error;

  int s;

  //const char *host = "www.lemoda.net";
  const char *host = "jsonplaceholder.typicode.com";

  memset(&hints, 0, sizeof(hints));

  hints.ai_family = PF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  error = getaddrinfo(host, "http", &hints, &res0);

  fail(error, gai_strerror(error));

  s = -1;

  for(res = res0; res; res->ai_next)
  {
    s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    fail(s < 0, "socket: %s\n", strerror(errno));

    if(connect(s, res->ai_addr, res->ai_addrlen) < 0){
      fprintf(stderr, "connect: %s\n", strerror(errno));
      close(s);
      exit(EXIT_FAILURE);
    }
    break;
  }

  if(s != -1){
    get_page(s, host, "posts/1");
  }

  freeaddrinfo(res0);
  return EXIT_SUCCESS;
}
