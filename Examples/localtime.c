#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
   time_t rawtime;
   struct tm *info, resul;
   time( &rawtime );
   info = localtime_r( &rawtime , &resul);
   printf("Current local time and date: %s", asctime(info));
   return(0);
}