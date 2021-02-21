#ifndef __CAR_H
#define __CAR_H

#define MAX_NAME    32

typedef struct car
{
    char name[MAX_NAME];
    double speed;
    double fuel;
}car_t;

void car_construct(car_t *, const char *);
void car_destruct(car_t *);
void car_accelerate(car_t *);
void car_brake(car_t *);
void car_refuel(car_t *, double);


#endif