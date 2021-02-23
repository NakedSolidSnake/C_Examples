#include <controller.h>
#include <student.h>
#include <view.h>

static Student retrieveStudentFromDatabase(void);

int main(int argc, char *argv[])
{
    Student model = retrieveStudentFromDatabase();

    StudentController(model, printStudentDetails);

    updateView();

    setStudentName("John");

    updateView();

    return 0;
}

static Student retrieveStudentFromDatabase(void)
{
    Student student =
    {
        .name = "Cristiano Silva de Souza", .rollNo = "10"
    };

    return student;
}