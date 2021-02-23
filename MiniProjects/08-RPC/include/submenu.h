#ifndef __SUBMENU_H
#define __SUBMENU_H

#include <aluno.h>

#define QUERY_LEN 8192

int insert_student(void);
int update_student(void);
int delete_student(void);
int list_students(void);
int quit_application(void);

Aluno_t *Aluno_new(void);


#endif