#include <stdio.h>
#include <signal.h>
#include <wait.h>

int val = 10;

void handler(int sig)
{
   val += 5;
}

int main(int argc, char *argv[])
{
   pid_t pid;

   signal(SIGCHLD, handler);
   pid = fork();
   if(pid == 0)
   {
      val -= 3;
      exit(0);
   }

   waitpid(pid, NULL, 0);
   printf("val = %d\n", val);
   exit(0);
}
