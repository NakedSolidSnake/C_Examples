#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;
int shared_data;

void *thread_function(void *arg)
{
    long i;

    for ( i = 0; i < 102400 * 10240; i++)
    {
        pthread_mutex_lock(&lock);
        shared_data++;
        pthread_mutex_unlock(&lock);
    }
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread_ID;
    void *exit_status;
    int i;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread_ID, NULL, thread_function, NULL);

    for ( i = 0; i < 10; i++)    
    {
        sleep(1);
         pthread_mutex_lock(&lock);
        printf("\rShared integer's value = %d\n", shared_data);
        pthread_mutex_unlock(&lock);

    }

    printf("\n");    

    pthread_join(thread_ID, &exit_status);
    pthread_mutex_destroy(&lock);
    return 0;
}
