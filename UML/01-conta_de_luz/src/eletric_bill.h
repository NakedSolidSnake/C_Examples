#ifndef ELETRIC_BILL_H_
#define ELETRIC_BILL_H_

#include <time.h>

typedef struct 
{
    struct tm read_date;
    int read_number;
    int kw_used;
    double value_to_pay;
    struct tm pay_day;
    double average_use;
} eletric_bill_t;

eletric_bill_t eletric_bill_create (int read_number, int kw_used, double value_to_pay, double average_use);
void eletric_bill_info (const eletric_bill_t *bill);

#endif /* ELETRIC_BILL_H_ */
