#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  int process1 = -1;
  int process2 = -1;

  char *proc1[] = {
      "/home/cssouza/launcher/bin/process",
      "i am process 1",
      "5",
      NULL,
  };

  char *proc2[] = {
      "/home/cssouza/launcher/bin/process", "i am process 2", "3",NULL};

  printf("Running other programming.\n");

  process1 = fork();
  if (process1 == 0)
  {
    if (execvp(proc1[0], proc1))
    {
      printf("Error launch %s.\n", proc1[0]);
      return EXIT_FAILURE;
    }
  }

  process2 = fork();
  if (process2 == 0)
  {
    if (execvp(proc2[0], proc2))
    {
      printf("Error launch %s.\n", proc2[0]);
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}
