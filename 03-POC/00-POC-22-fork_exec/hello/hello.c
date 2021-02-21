#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  int loop = 0;
  if (argc > 1)
  {
    loop = argc - 1;
  }
  else
  {
    exit(1);
  }

  for (int i = 0 ; i < loop; i++)
  {
    int num = atoi(argv[i + 1]);
    printf("arg %d is %d\n", i + 1, num);
    sleep(1);
  }

  raise(SIGCHLD);
  return 0;
}
