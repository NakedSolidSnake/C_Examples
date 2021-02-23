#include "student.h"
#include <string.h>

char *Student_getRollNo(const Student *student)
{
    return student->rollNo;
}

char *Student_getName(const Student *student)
{
    return student->name;
}

void Student_setRollNo(Student *student, const char *rollNo)
{
    memset(student->rollNo, 0, sizeof(student->rollNo));
    strncpy(student->rollNo, rollNo, sizeof(student->rollNo));
}   

void Student_setName(Student *student, const char *name)
{
    memset(student->name, 0, sizeof(student->name));
    strncpy(student->name, name, sizeof(student->name));
}