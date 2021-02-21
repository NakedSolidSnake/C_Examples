#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("app running pid: %d\n",  getpid());

  printf("arguments received: ");
  for(int i = 0; i < (argc - 1); i++)
  {
    printf("%s ", argv[i + 1]);
  }
  
  printf("\n");
}
