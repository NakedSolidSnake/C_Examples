# Protegendo a regra de negócio de dependências por plataformas

## Introdução
Todo o projeto possui sua regra de negócio, e essa regra de negócio deve ser independente da plataforma utilizada, o que normalmente não acontece durante o ciclo de vida de um produto, sendo, reduzindo os custos utilizando plataformas de baixo custo, ou até mesmo escolhendo uma plataforma que possua mais recursos para que o produto se torne diferenciado frente a concorrência. Mas para blindar o projeto de possíveis dependências geradas pela utilização de uma plataforma específica, sempre devemos pensar nessas plataformas em um meio de viabilizar o projeto e não deixar que o projeto dependa da plataforma. Uma frase bastante conhecida é Programe para uma interface e não para uma implementação.

## Definindo a interface
Para exemplificar de forma prática vamos criar uma regra de negócio bem simples como piscar um LED dentro de um certo intervalo de tempo.

Para que essa regra de negócio funcione em qualquer tipo de plataforma devemos identificar as caracteristicas que variam entre as plaformas para que possamos criar uma interface encapsulando essas variações, nesse exemplo precisamos de um mecanismo que espere por em determinado periodo de tempo, uma inicialização para que possa ser configurado as dependências da plataforma, e por fim um mecanismo que nos permita mudar o estado lógico do LED. Com essas caracteristicas podemos definir como vai ser a interface

```c
typedef struct 
{
    void (*init)(void);
    void (*wait)(uint16_t seconds);
    void (*set)(uint8_t state);
} hw_interface;
```
As assinaturas da interface não são rigidas no primeiro momento, mas deve ter em mente que uma vez que ganhar maturidade, é estritamente importante evitar mudá-las, para que no futuro não comprometa implementações legadas.

## Implementando a regra de negócio
Com a interface definida podemos implementar a regra de negócio, dessa forma blindando contra as nuances de uma determinada plataforma.

```c
bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds);
```

Essa função é responsável por processar a alternância do LED baseada no atraso fornecido pelo parâmetro __delay_, dito isso podemos ver como fica a implementação dessa função

```c
bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds)
{
    bool is_init = hw_is_initialized(interface);
    uint8_t state = 0;
    
    if(is_init)
    {
        interface->init();

        while(true)
        {
            interface->wait(_delay);
            interface->set(state);
            state ^= 0x01;
        }
    }    
}
```
Aqui temos uma função privada que verifica se todos os ponteiros de função foram inicializados, caso estejam todos devidamente configurados retorna um true indicando que tudo ocorreu bem, no if verificamos o retorno e caso verdadeiro chama o init que é responsável pelas configurações iniciais da plaforma, e em seguida temos o while que é coração da regra de negócio onde se aguarda um tempo e aplica o estado do LED, em seguida complementa o valor e segue assim até a eternidade finita. Dessa forma garantimos que a regra de negócio irá funcionar independente da plaforma, ficando a cargo da plataforma a implementação das funções do contrato fornecida pela interface para garantir o funcionamento, e isolando as espeficidades da plataforma no próprio main

Para simular esse exemplo iremos usar a plataforma PC(Personal Computer) rodando um Linux como sistema operacional, e o módulo Arduino 

# Portando para o PC
No primeiro caso (PC) para preencher a interface analisamos quais funções podem atender os requisitos do contrato para o caso do atraso temos o sleep, para o init temos o printf, e finalmente para o set temos um printf imprimindo o valor do estado recebido, ficando o resultado da implementação 

```c
static void pc_init(void)
{
    printf("Init.\n");
}
```

```c
static void pc_wait(int seconds)
{
    sleep(seconds);
}
```

```c
static void pc_set(uint8_t state)
{
    printf("state = %d\n", state);
}
```

Com isso podemos assinar o contrato pois as funções respeitam as assinaturas fornecidas pela interface ficando dessa forma

```c
hw_interface interface = 
{
   .init = pc_init,
   .wait = pc_wait,
   .set = pc_set
};
```

Uma vez a interface preechida podemos executar a função que possui a regra de negócio propriamente dita

```c
if (hw_run_toogle_led(&interface, 1) == false)
    printf("Error.\n");
```

Essa função não deve retornar em caso de sucesso, assim podemos ver o output alterando o estado do LED atráves do printf.

```bash
Init.
state = 0
state = 1
state = 0
```

# Portando para o Arduino
O exemplo do Arduino foi desenvolvido usando o eclipse.

Agora o mesmo exemplo portado e preechido com as funções do Arduino, para atender os requisitos do contrato para o caso do atraso temos o delay( essa função está milisegundos é necessário multiplicar por 1000 para ter a base em segundos ), para o init temos o pinMode, e finalmente para o set temos um digitalWrite que altera o LED com valor recebido, ficando o resultado da implementação 

```c
static void arduino_init(void)
{
	pinMode(13, OUTPUT);
}
```
```c
static void arduino_wait(int seconds)
{
    delay(seconds * 1000);
}
```
```c
static void arduino_set(uint8_t state)
{
    digitalWrite(13, state);
}
```
Declaramos a interface e preenchemos com as funções do arduino

```c
hw_interface interface =
{
   .init = arduino_init,
   .wait = arduino_wait,
   .set  = arduino_set
};
```

no setup não precisamos preencher nada, ai realizamos a chamada da função run_toogle_led na função loop

```c
void loop() {
	hw_run_toogle_led(&interface, 1);
}
```

Como resultado o LED presente na placa irá ficar piscando.

## Listagem Completa
### hw_interface.h
```c
#ifndef HW_INTERFACE_H_
#define HW_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    void (*init)(void);
    void (*wait)(uint16_t seconds);
    void (*set)(uint8_t state);
} hw_nterface;

bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds);
#ifdef __cplusplus
}
#endif

#endif /* HW_INTERFACE_H_ */

```
### hw_interface.c
```c
#include "hw_interface.h"

static bool hw_is_initialized(Interface *interface);

bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds)
{
    bool is_init = hw_is_initialized(interface);
    uint8_t state = 0;
    
    if(is_init)
    {
        interface->init();

        while(true)
        {
            interface->wait(_delay);
            interface->set(state);
            state ^= 0x01;
        }
    }

    return is_init;    
}

static bool hw_is_initialized(Interface *interface)
{
    bool is_config = true;

    if(!interface ||
       !interface->init || 
       !interface->wait ||
       !interface->set)
       {
           is_config = false;
       }
        
    return is_config;

}

```
### main.cpp (Arduino)
```c
#include <Arduino.h>
#include "hw_interface.h"


/* Functions to use in the interface */
static void arduino_init(void);
static void arduino_wait(int seconds);
static void arduino_set(uint8_t state);

hw_interface interface =
   {
       .init = arduino_init,
       .wait = arduino_wait,
       .set  = arduino_set
   };

void setup() {

}

void loop() {
    hw_run_toogle_led(&interface, 1);
}

static void arduino_init(void)
{
    pinMode(13, OUTPUT);
}

static void arduino_wait(int seconds)
{
    delay(seconds * 1000);
}

static void arduino_set(uint8_t state)
{
    digitalWrite(13, state);
}

```
### main.c (PC)
```c
#include "hw_interface.h"
#include <stdio.h>
#include <unistd.h>

/* Functions to use in the interface */
static void pc_init(void);
static void pc_wait(uint16_t seconds);
static void pc_set(uint8_t state);

int main(void)
{
    hw_interface interface = 
    {
        .init = pc_init,
        .wait = pc_wait,
        .set = pc_set
    };

    if (hw_run_toogle_led(&interface, 1) == false)
        printf("Error.\n");
}

static void pc_init(void)
{
    printf("Init.\n");
}

static void pc_wait(int seconds)
{
    sleep(seconds);
}

static void pc_set(uint8_t state)
{
    printf("state = %d\n", state);
}
```


## Conclusão 

O uso da interface garante que a regra de negócio não sofrerá alterações por caracteristicas externas, como hardware, estrutura de dados e API's, sendo necessário que esses componentes externos a regra de negócio respeitem a interface, assim resolvendo essas variações através de funções padronizadas, facilitando a intercambiação de recursos usados no projeto.
