#include <pthread.h>
#include <tasks.h>

int main(int argc, char const *argv[])
{
    pthread_t thread;

    pthread_create(&thread, NULL, work, NULL);

    pthread_join(thread, NULL);

    return 0;
}
