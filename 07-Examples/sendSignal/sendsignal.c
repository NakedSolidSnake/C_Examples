#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
    exit(1);
  }

  int pid = atoi(argv[1]);

  kill(pid, SIGUSR1);

  return EXIT_SUCCESS;
}
