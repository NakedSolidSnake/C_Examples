#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef enum data_type
{
    DEFAULT = 0,
    INT,
    DOUBLE,
    CHAR,
    PCHAR
} data_type_t;

typedef struct data
{
    data_type_t type;
    void *data;
} data_t;

#define THREADS_MAX 3
#define MESG_MAX    60

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
    data_t *d = (data_t *)arg;
    char bMesg[MESG_MAX];
    
    pthread_mutex_lock(&mutex);
    switch (d->type)
    {
    case INT:
        snprintf(bMesg, MESG_MAX, "This is a int %d.", *(int *)d->data);
        break;

    case DOUBLE:
        snprintf(bMesg, MESG_MAX, "This is a double %lf.", *(double *)d->data);
        break;

    case PCHAR:
        snprintf(bMesg, MESG_MAX, "This is a char * %*s.", (int)strlen((char *)d->data), (char *)d->data);
        break;

    default:
        break;
    }    
    printf("%s\n", bMesg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char const *argv[])
{

    int num = 42;
    double pi = M_PI;
    const char *msg = "Cristiano Silva de Souza";

    data_t d[] =
        {
            {.type = INT, .data = &num},
            {.type = DOUBLE, .data = &pi},
            {.type = PCHAR, .data = (void *)msg},
        };

    pthread_t thread[THREADS_MAX];
    void *exit_status;
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREADS_MAX; i++)
    {
        pthread_create(&thread[i], NULL, thread_function, &d[i]);
    }

    for (int i = 0; i < THREADS_MAX; i++)
    {
        pthread_join(thread[i], &exit_status);
        (void)exit_status;
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
