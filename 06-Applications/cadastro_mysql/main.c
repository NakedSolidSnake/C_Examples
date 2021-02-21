#include <stdio.h>
#include <db.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN   1024
char query[BUF_LEN];

typedef struct people{
  char fname[29];
  int age;
}people_t;

char *insert(void *data);
char *delete(void *data);
char *update(void *data);

int main()
{
  int ret = -1;
  people_t p = {
    .fname = "Cristiano Silva",
    .age = 32
  } ;

  initdb("localhost", "cssouza", "senha", "test");

  ret = insertdb(insert, (void *)&p);
  if(ret != 0){
    fprintf(stderr, "Error\n");
  }

  printf("Success!\n");
  
  return 0;
}

char *insert(void *data)
{
  people_t *p;
  if(!data){
    return -1;
  } 
  p = (people_t *)data;
  memset(query, 0, sizeof(query));
  snprintf(query, sizeof(query), "insert into children(fname, age) values ('%s', %d)",
            p->fname, p->age);
  return query;
}

char *delete(void *data)
{
  if(!data){
    return -1;
  } 
  memset(query, 0, sizeof(query));

  return NULL;
}

char *update(void *data)
{
  if(!data){
    return -1;
  } 
  memset(query, 0, sizeof(query));

  return NULL;
}

