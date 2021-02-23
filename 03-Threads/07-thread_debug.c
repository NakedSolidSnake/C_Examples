#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MSG_MAX_LEN     100

void *sum(void *args);
void *print(void *args);

typedef struct
{
    char message[MSG_MAX_LEN];
    int printTimes;
}data_t;

int main(int argc, char const *argv[])
{
    void *sumRet;
    long long result;

    pthread_t thread_sum, thread_print;
    long limit = 10000000000;
    data_t data = 
    {
        .message = "My message",
        .printTimes = 20
    };

    pthread_create(&thread_print, NULL, print, &data);
    pthread_create(&thread_sum, NULL, sum, &limit);

    pthread_join(thread_print, NULL);
    pthread_join(thread_sum, &sumRet);

    if(sumRet){
        result = *(long long *)sumRet;
        free(sumRet);
        printf("Sum Total: %lld.\n", result);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}


void *sum(void *args)
{
    long limit = *(long *)args;
    long long *sum = (long long *)malloc(sizeof(long long));
    if(!sum){
        printf("Error cannot malloc.\n");
        return NULL;
    }

    *sum = 0;

    for (long i = 0; i < limit; i++)
    {
        *sum += i;
    }

    return (void *)sum;
}

void *print(void *args)
{
    data_t *data = (data_t *)args;
    
    for (int i = 0; i < data->printTimes; i++)
    {
        printf("print message %s (%d/%d).\n" , data->message, i + 1, data->printTimes);
        sleep(1);
    }
    
    return NULL;    
}
