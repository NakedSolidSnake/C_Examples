#include <carro.h>
#include <moto.h>
#include <onibus.h>
#include <caminhao.h>

int main(int argc, char *argv[])
{
    Caminhao caminhao;
    Caminhao_constructor(&caminhao, "Mercedes", "Bi-trem", 1000);
    

    Carro carro;
    Carro_constructor(&carro, "Ford", "Fusion", 4);

    Onibus onibus;
    Onibus_constructor(&onibus, "Mercedes", "Escolar", 24);

    Moto moto;
    Moto_constructor(&moto, "harley-davidson", "Iron 883", 883);

    Veiculo_abastecer(&caminhao);
    Veiculo_abastecer(&carro);
    Veiculo_abastecer(&onibus);
    Veiculo_abastecer(&moto);

    return 0;
}
