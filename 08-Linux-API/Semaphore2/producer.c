#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore/semaphore.h>
#include <signal.h>

static void closeApp(int s);
static int end = 0;

int main(int argc, char *argv[])
{
    sema_t sema = {
        .id = -1,
        .sema_count = 1,
        .state = LOCKED,
        .master = MASTER
    };

    signal(SIGINT, closeApp);

    semaphore_init(&sema, 1234);

    while(end == 0)
    {
        if(semaphore_lock(&sema) == 0){
            printf("Waiting press any button.\n");
            getchar();
            semaphore_unlock(&sema);
        }
    }

    semaphore_destroy(&sema);
    exit(EXIT_SUCCESS);
}

static void closeApp(int s)
{
    end = 1;
}