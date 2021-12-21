#include "eletric_bill.h"
#include <stdlib.h>
#include <time.h>
// #include <stdbool.h>

static void eletric_bill_get_time_now (eletric_bill_t *el)
{
    time_t rawtime;
    // struct tm resul;
    time (&rawtime);
    localtime_r (&rawtime, &el->read_date);
    el->pay_day = el->read_date;
    el->pay_day.tm_mday += 15; 
}

eletric_bill_t eletric_bill_create (int read_number, int kw_used, double value_to_pay, double average_use)
{
    eletric_bill_t eletric_bill = 
    {
        .read_number = read_number,
        .kw_used = kw_used,
        .value_to_pay = value_to_pay,
        .average_use = average_use,
        .read_date = NULL,
        .pay_day = NULL
    };

    eletric_bill_get_time_now (&eletric_bill);

    return eletric_bill;
}

void eletric_bill_info (const eletric_bill_t *bill)
{
    printf ("Read Number: %d, KW: %d, Value: %.2lf, AVG: %.2lf, Date: %s, Pay until: %s\n",
             bill->read_number,
             bill->kw_used,
             bill->value_to_pay,
             bill->average_use,
             asctime(&bill->read_date),
             asctime(&bill->pay_day) );
}