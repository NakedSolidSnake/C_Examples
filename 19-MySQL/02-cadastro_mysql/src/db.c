#include <db.h>
#include <stdio.h>
#include <stdlib.h>

#include "mysql.h"

static MYSQL connection;

static void error_handle(int *error)
{
  if( error == NULL)
  {
    mysql_close(&connection);
    fprintf(stderr, "Connection Error %d: %s\n", 
        mysql_errno(&connection), mysql_error(&connection));
  }
}

int initdb(const char *hostname, const char *username, const char *password, const char *database)
{
  int *ret = NULL;
  mysql_init(&connection);

  ret = mysql_real_connect(&connection, hostname, username, password, database, 0, NULL, 0);
  error_handle(ret);
  return *ret;
}

int insertdb(char *(*insert)(void *data), void *data)
{
  int ret = -1; 
  if(!insert){
    return -1;
  }

  if(!data){
    return -1;
  }

  ret = mysql_query(&connection, insert(data));
  error_handle(&ret);
  
  return ret;
}

int deletedb(char *(*delete)(void *data), void *data)
{
  int *ret = NULL;
  
  if(!delete){
    return -1;
  }

  if(!data){
    return -1;
  }

  ret = mysql_query(&connection, delete(data));
  error_handle(ret);

  return *ret;
}

int updatedb(char *(*update)(void *data),void *data)
{
  int *ret = NULL;
  
  if(!update){
    return -1;
  }

  if(!data){
    return -1;
  }

  ret = mysql_query(&connection, update(data));
  error_handle(ret);
  return *ret;
}

int closedb(void){
  mysql_close(&connection);
  return 0;
}
