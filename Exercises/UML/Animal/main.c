#include <cachorro.h>
#include <vaca.h>
#include <gato.h>
#include <animal.h>

int main(int argc, char *argv[])
{

    Cachorro cachorro;
    Gato gato;
    Vaca vaca;

    Cachorro_constructor(&cachorro, 2, 10, "Doce");
    Gato_constructor(&gato, 4, 5, "Linda");
    Vaca_constructor(&vaca, 15, 200, "Mimosa");

    Animal_som(&cachorro);
    Animal_som(&gato);
    Animal_som(&vaca);
    
    return 0;
}
