#include <geladeira.h>
#include <televisao.h>
#include <aparelhosom.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    Geladeira geladeira;
    Televisao televisao;
    AparelhoSom aparelhoSom;
    char *abrir;

    Geladeira_constructor(&geladeira, "Baixo consumo", "Branca", 110);
    Televisao_constructor(&televisao, 110, 100, 42);
    AparelhoSom_constructor(&aparelhoSom, 110, 200, "Sony");

    /* Geladeira */
    Eletroeletronico_ligar(&geladeira);
    abrir = LinhaBranca_abrir(&geladeira);
    printf("%s", abrir);
    LinhaBranca_fechar(&geladeira);
    Eletroeletronico_desligar(&geladeira);
    free(abrir);

    /* Televisao */
    Eletroeletronico_ligar(&televisao);
    abrir = SomImagem_entrarStandyBy(&televisao);
    printf("%s\n", abrir);
    SomImagem_sairStandyBy(&televisao);
    Eletroeletronico_desligar(&televisao);
    Televisao_mudarCanal(&televisao);

    /* Aparelho de Som */
    Eletroeletronico_ligar(&aparelhoSom);
    abrir = SomImagem_entrarStandyBy(&aparelhoSom);
    printf("%s\n", abrir);
    SomImagem_sairStandyBy(&aparelhoSom);
    Eletroeletronico_desligar(&aparelhoSom);
    AparelhoSom_mudarEstacao(&aparelhoSom);

    return 0;
}
