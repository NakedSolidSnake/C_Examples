#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <student.h>

typedef void (*IView)(const char *name, const char *roll);

void StudentController(Student model, IView view);

void setStudentName(const char *name);
char *getStudentName(void);

void setStudentRollNo(const char *rollNo);
char *getStudentRollNo(void);

void updateView(void);

#endif /* CONTROLLER_H_ */
