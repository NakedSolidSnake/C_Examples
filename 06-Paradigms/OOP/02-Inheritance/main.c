#include <stdio.h>

#define MAX_NAME_LEN    80
#define MAX_RGM_LEN     20

typedef struct
{
    char name[MAX_NAME_LEN];
    int age;
}person_t;

typedef struct 
{
    person_t person;
    char rgm[MAX_RGM_LEN];
    int semester;
}student_t;


int main(int argc, char const *argv[])
{
    student_t student;

    person_t *pPerson = (person_t *)&student;
    student_t * pStudent = (student_t *)&student;

    printf("Address pointer person_t %p.\n", pPerson);
    printf("Address pointer student_t %p.\n", pStudent);

    return 0;
}
