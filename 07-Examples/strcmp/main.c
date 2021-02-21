#include <stdio.h>
#include <string.h>

char str[] = "go 10\n";

void str_analise(char *str)
{  
  char delim[] = " ";
  int len = strlen(str);
  str[len - 1] = '\0';
  char *ptr = strtok(str, delim);
  if(strcmp(str, "go") == 0)
    printf("str: %s\n", str);
  else
    printf("%s.\n", str);
}

int main(){
  str_analise(str);
  return 0;
}
