#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <graphics.h>
#include <context.h>

// typedef struct {
//     double x;
//     double y;
// } Point;

// typedef struct {
//     Point points[4];
// } Square;

// typedef struct {
//     Point point;
// } Track;

const Point airspace[] =
    {
        [0] = {.x = -100.0, .y = -100.0},
        [1] = {.x = 100.0, .y = -100.0},
        [2] = {.x = 100.0, .y = 100.0},
        [3] = {.x = -100.0, .y = 100.0},
};

const Point volume[] = 
    {
        [0] = {.x = 20.0, .y = -10.0},
        [1] = {.x = 20.0, .y = 30.0},
        [2] = {.x = 40.0, .y = 30.0},
        [3] = {.x = 40.0, .y = -10.0},
    };

// void delay_100ms(void);

// bool is_inside(Track *track);
// bool is_inside_airspace(Track *track);

// void *move(void *args)
// {
//     // Point *points = (Point *)args;

//     Track track = {
//         .point = {.x = 0.0, .y = 0.5}
//     };

//     while(1)
//     {
//         if(is_inside_airspace(&track) == false)
//             pthread_cancel(pthread_self());

//         if(is_inside(&track))
//             printf("Alert: Aircraft position: %lf %lf\n", track.point.x += 0.1, track.point.y);
//         else
//             printf("Aircraft position: %lf %lf\n", track.point.x += 0.1, track.point.y);        
//         delay_100ms();
//     }

//     return NULL;
// }

int main(int argc, char *argv[])
{

    Context context =
        {
            .airspace =
            {
                    .points = &airspace, .points_amount = 4
            },
            .volume =
            {
                    .points = &volume, .points_amount = 4
            },
            .track = 
            {
                .position =
                {
                    .x = 0.0,
                    .y = 0.5
                },
                .initial_position = 
                {
                    .x = 0.0,
                    .y = 0.5
                }
            },
            .is_a_colision = false,
            .is_inside_airspace = false
        };

    Graphics_Init(argc, argv);
    Graphics_Run(&context);
    // pthread_t track;    
    // pthread_create(&track, NULL, move, NULL);

    // pthread_join(track, NULL);


    return 0;
}

// void delay_100ms(void)
// {
//     usleep(1000 * 100);
// }

// bool is_inside(Track *track)
// {
//     bool ret = false;
//     if( track->point.x >= 2.0 &&
//         track->point.x <= 4.0 &&
//         track->point.y >= 0.0 &&
//         track->point.y <= 2.0)
//         ret = true;

//     return ret;
// }

// bool is_inside_airspace(Track *track)
// {
//     bool ret = false;
//     if( track->point.x >= -10.0 &&
//         track->point.x <= 10.0 &&
//         track->point.y >= -10.0 &&
//         track->point.y <= 10.0)
//         ret = true;

//     return ret;
// }