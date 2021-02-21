#ifndef __VEICULO_H
#define __VEICULO_H

#define MARCA_LEN    80
#define MODELO_LEN   80

typedef void (*Abastecer)(void *veiculo);

typedef struct 
{
    char marca[MARCA_LEN];
    char modelo[MODELO_LEN]; 
    Abastecer abastecer;
}Veiculo;

void Veiculo_constructor(Veiculo *veiculo, const char *marca, const char *modelo);
void Veiculo_abastecer(void *veiculo);
char * Veiculo_getMarca(void *veiculo);
char * Veiculo_getModelo(void *veiculo);

#endif