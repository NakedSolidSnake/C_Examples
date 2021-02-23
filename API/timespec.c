#include <stdio.h> 
#include <time.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include <unistd.h>
#include <stdlib.h>

///////////////////////////////////
// measure elapsed real time using the "clock_gettime" call. 
// This is one of the most accurate ways to measure wallclock time.
///////////////////////////////////

// struct timespec {                                                                                     
//    time_t   tv_sec;        /* seconds */                                                             
//    long     tv_nsec;       /* nanoseconds */                                                         
// }; 

int compare(struct timespec *start, struct timespec *end, struct timespec *offset);


void main (int argc, char *argv[]) { 
    struct timespec start, finish, offset; 
    time_t t;

    if(argc != 2)
    {
        fprintf(stderr, "Error must tem a parameter time.:\nUsage: ./%s <time microseconds>.\n", argv[0]);
        return 1;
    }

    // clock_gettime(CLOCK_REALTIME, &start); 
    clock_gettime(CLOCK_MONOTONIC, &start); 
    

    t = (long int)atoll(argv[1]);

    
    offset.tv_sec = (t / 1000000000) ;
    offset.tv_nsec = (t % 1000000000);

    // chew up some CPU time    

    do
    {
        // clock_gettime(CLOCK_REALTIME, &finish);
        clock_gettime(CLOCK_MONOTONIC, &finish); 
    }while(compare(&start, &finish, &offset));


    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
} 

int compare(struct timespec *start, struct timespec *end, struct timespec *offset)
{
    double _start = (double)start->tv_sec + (double)start->tv_nsec/(double)1000000000;
    double _end = (double)end->tv_sec  + (double)end->tv_nsec /(double)1000000000;
    double _offset = (double)offset->tv_sec  + (double)offset->tv_nsec /(double)1000000000;

    return ((_start + _offset) > _end);
}