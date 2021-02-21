#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char *arg[])
{
  MYSQL myconnection;
  int res;

  mysql_init(&myconnection);

  if(mysql_real_connect(&myconnection, "localhost", "cssouza", "senha",
                                "test", 0, NULL, 0)){
    printf("Connection success\n");
    res = mysql_query(&myconnection, "UPDATE children SET AGE = 4 WHERE fname = 'Ann'");

    if(!res){
      printf("Inserted %lu rows\n", 
             (unsigned long)mysql_affected_rows(&myconnection));
    }
    else{
      fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&myconnection), 
              mysql_error(&myconnection));
    }

    mysql_close(&myconnection);
  }
  else{
    fprintf(stderr, "Connection failed\n");
    if(mysql_errno(&myconnection)){
      fprintf(stderr, "Connection error %d: %s\n",
              mysql_errno(&myconnection), mysql_error(&myconnection));
    }
  }


  return EXIT_SUCCESS;
}
