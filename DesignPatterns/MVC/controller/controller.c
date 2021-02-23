#include "controller.h"
#include <string.h>

static Student _model;
static IView _view;

void StudentController(Student model, IView view)
{
    _model = model;
    _view  = view;
}

void setStudentName(const char *name)
{
    memset(_model.name, 0, sizeof(_model.name));
    strncpy(_model.name, name, sizeof(_model.name));
}

char *getStudentName(void)
{
    return _model.name;
}

void setStudentRollNo(const char *rollNo)
{
    memset(_model.rollNo, 0, sizeof(_model.rollNo));
    strncpy(_model.rollNo, rollNo, sizeof(_model.rollNo));
}

char *getStudentRollNo(void)
{
    return _model.rollNo;
}

void updateView(void)
{
    _view(getStudentName(), getStudentRollNo());
}