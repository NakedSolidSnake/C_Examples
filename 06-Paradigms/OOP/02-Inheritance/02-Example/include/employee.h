#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

typedef struct employee Employee_t;

Employee_t *Employee_new(const char * const name, const int age);
void Employee_delete(Employee_t *employee);

char *Employee_getName(const Employee_t *employee);
int Employee_getAge(const Employee_t *employee);

char *Employee_toString(const Employee_t *employee);

#endif