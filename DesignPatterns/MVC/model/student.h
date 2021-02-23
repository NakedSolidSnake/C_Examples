#ifndef STUDENT_H_
#define STUDENT_H_

#define MAX_NAME_LEN    80
#define MAX_ROLLNO_LEN  80

typedef struct 
{
    char name[MAX_NAME_LEN + 1];
    char rollNo[MAX_ROLLNO_LEN + 1];
} Student;

char *Student_getRollNo(const Student *student);
char *Student_getName(const Student *student);

void Student_setRollNo(Student *student, const char *rollNo);
void Student_setName(Student *student, const char *name);

#endif /* STUDENT_H_ */
