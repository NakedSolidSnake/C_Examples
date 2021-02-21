#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sum
{

  long long limit;
  long long result;
}sum_t;


void *thread(void *args)
{
  sum_t *s = (sum_t *)args;
  long long sum = 0;
  for(int i = 0; i < s->limit; i++)
  {
    sum += s->limit; 
  }
  s->result = sum;
  pthread_exit(0);
}

int main(int argc, char *argv[])
{
  if(argc < 2)
    return -1;
  int thread_amount = argc - 1; 
  pthread_t threads[thread_amount];

  sum_t sums[thread_amount];

  for(int i = 0; i < thread_amount; i++)
  {
    sums[i].limit = atoll(argv[i + 1]);
    pthread_create(&threads[i], NULL, thread, &sums[i] );
  }

  for(int i = 0; i < thread_amount ; i++)
  {
  
    pthread_join(threads[i], NULL);
    printf("Sum  = %lld\n", sums[i].result);
  }
  return EXIT_SUCCESS;
}
