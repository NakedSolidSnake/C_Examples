#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void *thread_function(void *arg)
{
    double *sum = (double *)malloc(sizeof(double));
    if(sum == NULL)
        return NULL;

    for(long i = 0; i < 100; i++)
    {
        *sum += pow(i, 2.0);
    }

    return (void *)sum;
}

int main(int argc, char const *argv[])
{
    pthread_t thread_ID;
    void *exit_status;
    double result;
    

    pthread_create(&thread_ID, NULL, thread_function, NULL);

    printf("Processing sum.\n");

    pthread_join(thread_ID, &exit_status);

    result = *(double *)exit_status;
    
    free(exit_status);

    printf("A total is %lf\n", result);
    return 0;
}
