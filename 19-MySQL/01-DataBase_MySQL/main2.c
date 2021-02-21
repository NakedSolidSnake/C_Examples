#include <mysql.h>
#include <stdio.h>

int main(int argc, char **argv)
{
   MYSQL *con = mysql_init(NULL);

   if(argc != 2){
      printf("Usage mysql [password]\n");
      return 1;
   }

   if(con == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
   }

   printf("%s\n", argv[1]);
   if(mysql_real_connect(con, "localhost", "root", argv[1], NULL, 0, NULL, 0) == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
   }

   if(mysql_query(con, "CREATE DATABASE testdb"))
   {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
   }

   mysql_close(con);
   exit(0);
}
