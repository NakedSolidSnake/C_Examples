#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char *arg[])
{
  MYSQL my_connection;

  mysql_init(&my_connection);

  if(mysql_real_connect(&my_connection, "localhost", "cssouza", "wrongpass", "test",
                        0, NULL, 0)){
    printf("Connection success\n");
    mysql_close(&my_connection);
  }
  else
  {
    fprintf(stderr, "Connection failed\n");
    if(mysql_errno(&my_connection)){
      fprintf(stderr, "Connection Error %d: %s\n", 
          mysql_errno(&my_connection), mysql_error(&my_connection));
    }
  }

  return EXIT_SUCCESS;
}
