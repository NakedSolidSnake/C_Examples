#include <semaphore.h>

int shared;

sem_t binary_sem;  //mutex

void *thread_function(void *arg)
{
    sem_wait(&binary_sem);
    //use shared resource
    sem_signal(&binary_sem);
}

int main(int argc, char const *argv[])
{
    sem_init(&binary_sem,0, 1);

    sem_wait(&binary_sem);
    //use shared resource
    sem_signal(&binary_sem);

    //join threads

    sem_destroy(&binary_sem);
    
    return 0;
}
