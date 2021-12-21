#ifndef ELETRIC_BILLS_CONTROL_H_
#define ELETRIC_BILLS_CONTROL_H_

#include "eletric_bill.h"
#include <stdbool.h>

#define BILLS_LEN    10

typedef struct 
{
    eletric_bill_t list[BILLS_LEN];
    int bills_amount;
} eletric_bills_control_t;

bool eletric_bills_control_init (eletric_bills_control_t *control);
bool eletric_bills_control_destroy (eletric_bills_control_t *control);
bool eletric_bills_control_add (eletric_bills_control_t *control, eletric_bill_t *eletric_bill);
eletric_bill_t *eletric_bills_control_get_lesser_bill (const eletric_bills_control_t *control);
eletric_bill_t *eletric_bills_control_get_greater_bill (const eletric_bills_control_t *control);

#endif /* ELETRIC_BILLS_CONTROL_H_ */
