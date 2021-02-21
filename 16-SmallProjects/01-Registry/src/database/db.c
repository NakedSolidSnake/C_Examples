#include <database/db.h>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

static MYSQL connection;

static void error_handle(MYSQL *error)
{
  if( error == NULL)
  {
    mysql_close(&connection);
    fprintf(stderr, "Connection Error %d: %s\n", 
        mysql_errno(&connection), mysql_error(&connection));
  }
}

int initdb(Database_params_t *config)
{
  MYSQL *ret = NULL;

  if (mysql_library_init(0, NULL, NULL)) {
    fprintf(stderr, "could not initialize MySQL client library\n");
    return -1;
  }
   
  ret = mysql_init(&connection);
  if(ret == NULL)
    return -1;

  ret = mysql_real_connect(&connection, config->hostname, config->username, config->password, config->database, 0, NULL, 0);
  error_handle(ret);
  return (ret == NULL) ? -1 : 0;
}

int selectdb(IDatabase_driver *driver, void *data)
{
  int ret = 0; 

  if(!driver || !driver->select){
    return -1;
  }

  ret = mysql_query(&connection, driver->select(data));
  if(ret)
    return -1;
  
  MYSQL_RES *result = mysql_store_result(&connection);
  if (result == NULL)
    return -1;

  int num_fields = mysql_num_fields(result);
  int num_rows = mysql_affected_rows(&connection);

  
  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
      driver->retrieve(row, num_fields);      
  } 

  mysql_free_result(result);
  closedb(); 

  return ret;
}

int insertdb(IDatabase_driver *driver, void *data)
{
  int ret = 0; 

  if(!driver || !driver->insert){
    return -1;
  }

  ret = mysql_query(&connection, driver->insert(data));  
  
  return ret;
}

int deletedb(IDatabase_driver *driver, void *data)
{
  int ret = 0;
  
  if(!driver || !driver->delete){
    return -1;
  }

  ret = mysql_query(&connection, driver->delete(data));
  
  return ret;
}

int updatedb(IDatabase_driver *driver,void *data)
{
  int ret = 0;
  
  if(!driver || !driver->update){
    return -1;
  }

  ret = mysql_query(&connection, driver->update(data));
  
  return ret;
}

int closedb(void){
  mysql_close(&connection);
  mysql_library_end();
  return 0;
}
