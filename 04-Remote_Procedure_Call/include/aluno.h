#ifndef __ALUNO_H
#define __ALUNO_H

#define MAX_NOME_LEN    80
#define MAX_CURSO_LEN   80

typedef struct
{
    int id;
    char nome[MAX_NOME_LEN];
    int matricula;
    unsigned char idade;
    char curso[MAX_CURSO_LEN];
}Aluno_t;


#endif