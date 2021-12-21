#include "eletric_bills_control.h"
#include "eletric_bill.h"

int main (int argc, char *argv[])
{

    eletric_bills_control_t control;

    eletric_bills_control_init (&control);

    eletric_bill_t bill_sept = eletric_bill_create (10, 1500, 15.0, 35.0);
    eletric_bill_t bill_oct = eletric_bill_create (10, 1500, 45.0, 85.0);
    eletric_bill_t bill_nov = eletric_bill_create (10, 1500, 9.0, 15.0);

    eletric_bills_control_add (&control, &bill_sept);
    eletric_bills_control_add (&control, &bill_oct);
    eletric_bills_control_add (&control, &bill_nov);

    eletric_bill_t *less = eletric_bills_control_get_lesser_bill (&control);
    eletric_bill_info (less);

    eletric_bill_t *greater = eletric_bills_control_get_greater_bill (&control);
    eletric_bill_info (greater);

    return 0;
}