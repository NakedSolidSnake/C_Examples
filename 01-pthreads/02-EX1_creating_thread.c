#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS     10

void *thread_function(void *arg)
{
    int incoming = *(int *)arg;

    for (int i = 0; i < 5; i++)
    {
        printf("Hello world! (thread:%d)\n", incoming);
    }    

    return NULL;
}

int main(int argc, char const *argv[])
{
    
    void *exit_status;
    int values[THREADS];
    

    pthread_t thread[THREADS];

    for (int i = 0; i < THREADS; i++)
    {
        values[i] = i;
        pthread_create(&thread[i], NULL, thread_function, &values[i]);
    }
    


    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(thread[i], &exit_status);    
    }
     

    
    return 0;
}
