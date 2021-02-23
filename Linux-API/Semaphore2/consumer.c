#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore/semaphore.h>

int main(int argc, char *argv[])
{
    int count = 0;

    sema_t sema = {
        .id = -1,
        .sema_count = 1,
        .state = LOCKED,
        .master = SLAVE
    };

    semaphore_init(&sema, 1234);    

    while(1)
    {
        if (semaphore_lock(&sema) == 0)
        {
            printf("Take a resource %d\n", count++);

            semaphore_unlock(&sema);
        }
        else
        {
            usleep(100);    
        }
    }

    exit(EXIT_SUCCESS);
}
