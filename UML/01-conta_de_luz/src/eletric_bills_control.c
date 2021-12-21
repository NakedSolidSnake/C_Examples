#include "eletric_bills_control.h"
#include <string.h>
#include <stdlib.h>

bool eletric_bills_control_init (eletric_bills_control_t *control)
{
    bool status = false;
    if (control)
    {
        memset (control, 0, sizeof (eletric_bills_control_t));
        status = true;
    }

    return status;
}

bool eletric_bills_control_destroy (eletric_bills_control_t *control)
{
    bool status = false;

    if (control)
    {
        status = true;
    }

    return status;
}

bool eletric_bills_control_add (eletric_bills_control_t *control, eletric_bill_t *eletric_bill)
{
    bool status = false;
    if (eletric_bill && control && control->bills_amount < BILLS_LEN)
    {
        // eletric_bill->read_date = 
        memcpy (&control->list[control->bills_amount], eletric_bill, sizeof (eletric_bill_t));
        control->bills_amount++;                
        status = true;
    }

    return status;
}

eletric_bill_t *eletric_bills_control_get_lesser_bill (const eletric_bills_control_t *control)
{
    eletric_bill_t *el_bill = NULL;
    
    double avg = control->list[0].average_use;
    
    for (int i = 1; i < control->bills_amount; i++)
    {
        if (avg > control->list[i].average_use)
        {
            avg = control->list[i].average_use;
            el_bill = &control->list[i];
        }
    }

    return el_bill;
}

eletric_bill_t *eletric_bills_control_get_greater_bill (const eletric_bills_control_t *control)
{
    eletric_bill_t *el_bill = NULL;
    
    double avg = control->list[0].average_use;
    
    for (int i = 1; i < control->bills_amount; i++)
    {
        if (avg < control->list[i].average_use)
        {
            avg = control->list[i].average_use;
            el_bill = &control->list[i];
        }
    }

    return el_bill;
}