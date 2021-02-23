#include <veiculo.h>
#include <string.h>

void Veiculo_constructor(Veiculo *veiculo, const char *marca, const char *modelo)
{
    strncpy(veiculo->marca, marca, MARCA_LEN);
    strncpy(veiculo->modelo, modelo, MODELO_LEN);
}

void Veiculo_abastecer(void *veiculo)
{
    ((Veiculo*)veiculo)->abastecer(veiculo);
}

char * Veiculo_getMarca(void *veiculo)
{
    return ((Veiculo*)veiculo)->marca;
}

char * Veiculo_getModelo(void *veiculo)
{
    return ((Veiculo*)veiculo)->modelo;
}