#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define _1MS      1000
#define _1S       (1000 * 1000)
void sig_handler(int num);

//int analise_time(time_t t);
int analise_time(int t);


static int analise = 0;

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  //time_t t_proc;
  int t_proc;
  signal(SIGINT, sig_handler);
  t_proc = time(0);

  while(1)
  {
    if(analise)
    {
      analise_time(t_proc);
      analise = 0;
      t_proc = time(0);
    }
  }
  return 0;
}

//int analise_time(time_t t)
int analise_time(int t)
{
  double time_dif_ms;
  //time_t current = time(0);
  int current = time(0);

  //printf("t = %ld\n", t);
  //printf("current = %ld\n", current);
  printf("t = %ld\n", t);
  printf("current = %ld\n", current);
  time_dif_ms = difftime(current, t) ;  //change to ms
  
  if(time_dif_ms >  10)
    printf("Passou do tempo");
  else
    printf("Atualizado \n");
  printf("diff = %lf\n", time_dif_ms);
  return 0;
}

void sig_handler(int num)
{
  (void)num;
 analise = 1; 
}
