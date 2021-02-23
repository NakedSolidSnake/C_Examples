#include <string.h>
#include <stdio.h>

typedef struct 
{
    char *string;
} Strings;

int main () {
   char str[80] = "/department/OnGetDeparment";
   const char s[2] = "/";
   char *token;
   int id = 0;
   Strings strings[10] = {0};
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
    //   printf( " %s\n", token );
      strings[id++].string = token;    
      token = strtok(NULL, s);
   }

   for(int i = 0; i < id; i++)
   {
         printf( " %s\n", strings[i].string );
   }
   
   return(0);
}