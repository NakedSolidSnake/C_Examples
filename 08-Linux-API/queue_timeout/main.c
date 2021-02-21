#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue/queue.h>
#include <util/util.h>


int main(int argc, char const *argv[])
{
    queue_st queue;
    int queue_id = queue_init(123);
    int ret;
    TimeMeas_t *t = createTimeMeas();
    if(!t)
        return EXIT_FAILURE;
    

    if (queue_id < 0)
    {
        exit(EXIT_FAILURE);
    }  

    queue.queueType = 1;

    while (1)
    {
        printf("Waiting alarm...\n");
        getStartTime(t);
        ret = queue_recv(queue_id, &queue, sizeof(queue.bData), 5000);
        if (ret < 0)
        {
        }
        getFinishTime(t);
        long long resul = getDiffMeas(t);
        printf("time diff %lld\n", resul);
    }
    return 0;
}
