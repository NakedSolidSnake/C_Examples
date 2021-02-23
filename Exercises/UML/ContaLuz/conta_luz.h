#ifndef __CONTA_LUZ_H
#define __CONTA_LUZ_H

#include <time.h>

typedef struct 
{
    time_t dataLeitura;
    int numeroLeitura;
    int kilowattGasto;
    double valorPagar;
    time_t dataPagamento;
    double mediaConsumo;
}ContaLuz;

int cadastrarConta(ContaLuz *contaLuz);
char *verificaMesMenorConsumo(const ContaLuz *contaLuz);
char *verificaMesMaiorConsumo(const ContaLuz *contaLuz);


#endif