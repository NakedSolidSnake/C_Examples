#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_cond_t is_zero;
pthread_mutex_t mutex;
int shared_data = 32767;

void *thread_function(void *arg)
{
    while (shared_data > 0)
    {
        pthread_mutex_lock(&mutex);
        --shared_data;
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }    

    printf("Send signal to main.\n");
    pthread_cond_signal(&is_zero);
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread_ID;
    void *exit_status;
    int i;

    pthread_cond_init(&is_zero, NULL);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread_ID, NULL, thread_function, NULL);

    pthread_mutex_lock(&mutex);
    while (shared_data != 0){
        printf("wait thread signal.\n");
        pthread_cond_wait(&is_zero, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    printf("Waiting thread finishes.\n");
    pthread_join(thread_ID, &exit_status);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&is_zero);
    
    
    return 0;
}
