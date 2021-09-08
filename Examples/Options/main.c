/*
 * [prog2.c]
 * Programa que exemplifica o uso da função
 * getopt_long().
 *
 * [Autor]
 * Marcos Paulo Ferreira (Daemonio)
 * undefinido gmail com
 * daemoniolabs.wordpress.com
 *
 * Ter Out  4 23:12:49 BRT 2011
 */

#include <stdio.h>
#include <stdlib.h>
/* para getopt_long() */
#include <getopt.h>

void show_help(char *name) {
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\
            -h, --help          mostra essa tela e sai.\n\
            -n, --nome=NOME     seta o seu nome.\n\
            -i, --idade=IDADE   seta sua idade.\n\
            -e, --estado=ESTADO seta seu estado.\n\
            -c, --cadastrar     cadastra no banco de dados.\n", name) ;
    exit(-1) ;
}

int main(int argc, char **argv) {
    int opt ;

    /* Variáveis que receberão os argumentos
     * das opções. */
    char *nome=NULL, *idade=NULL, *estado=NULL ;
    int flag_cadastrar = 0 ;

    /* Estrutura de opcoes. Veja que o último
     * elemento deve ser NULL. */
    const struct option stopcoes[] = {
        {"help"      , no_argument       , 0               , 'h'},
        {"nome"      , required_argument , 0               , 'n'},
        {"idade"     , required_argument , 0               , 'i'},
        {"estado"    , required_argument , 0               , 'e'},
        {"cadastrar" , no_argument       , &flag_cadastrar , 1  },
        {0           , 0                 , 0               , 0  },
    } ;

    if ( argc < 2 ) show_help(argv[0]) ;

    while( (opt = getopt_long(argc, argv, "hn:i:e:c", stopcoes, NULL)) > 0 ) {
        switch ( opt ) {
            case 'h': /* -h ou --help */
                show_help(argv[0]) ;
                break ;
            case 'n': /* -n ou --nome */
                nome = optarg ;
                break ;
            case 'i': /* -i ou --idade */
                idade = optarg ;
                break ;
            case 'e': /* -e ou --estado */
                estado = optarg ;
                break ;
            case 'c': /* -c ou --cadastrar */
                flag_cadastrar = 1 ;
                break ;
            default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: `%c'\n", optopt) ;
                return -1 ;
        }
    }

    printf("Seus dados: \n\
            Nome   : %s\n\
            Idade  : %s\n\
            Estado : %s\n", nome, idade, estado) ;

    printf("Dados gravados no banco de dados: ") ;
    if ( flag_cadastrar == 0 ) printf("NAO.\n") ;
    else printf("SIM.\n") ;

    /* Mostra os argumentos em excesso */
    if ( argv[optind] != NULL ) {
        int i ;

        puts("** Argumentos em excesso **") ;
        for(i=optind; argv[i] != NULL; i++) {
            printf("-- %s\n", argv[i]) ;
        }
    }

    return 0 ;
}
/* EOF */