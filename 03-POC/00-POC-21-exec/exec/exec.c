#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *args[] = {"./app" , "arg1", "arg2", NULL};

  execvp(args[0], args);

}
