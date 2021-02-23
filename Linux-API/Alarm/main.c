#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int num)
{
  printf("Alarmed.\n");
  alarm(3);
}

int main()
{
   signal(SIGALRM, signal_handler);
   alarm(2);

   while(1)
   {
     printf("Waiting for alarm\n");
     sleep(1);
   }
}
