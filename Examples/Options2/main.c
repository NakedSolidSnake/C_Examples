#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>

typedef bool (*Group_cb)(char *command, void *args);

typedef struct 
{
    const char *name;
    bool is_set;
    int arg_index;
    Group_cb callback;
} Group;

bool MSAW_group(char *command, void *args)
{
    int id = *(int *)args;

     printf("MSAW :");

    if(command == NULL)
    {
        printf("Showing status\n");
    }

    else if(!strncmp(command, "volumes", strlen("volumes")))
    {
        if(id < 0)
        {
            printf("Show all volumes.\n");
        }
        else
        {
            printf("Show volume id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "info", strlen("info")))
    {
        if(id < 0)
        {
            printf("Show info.\n");
        }
        else
        {
            printf("Show info id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "parameters", strlen("parameters")))
    {
        if(id < 0)
        {
            printf("Show all volumes parameters.\n");
        }
        else
        {
            printf("Show volume parameters id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "ssr", strlen("ssr")))
    {
        if(id < 0)
        {
            printf("Show all volumes ssr.\n");
        }
        else
        {
            printf("Show volume ssr id: %d.\n", id);
        }
    }

    else 
    {
        printf("Option not available\n");
    }

    return true;
}

bool STCA_group(char *command, void *args)
{
    int id = *(int *)args;
    printf("STCA: ");
    if(command == NULL)
    {
        printf("Showing status\n");
    }

    else if(!strncmp(command, "volumes", strlen("volumes")))
    {
        if(id < 0)
        {
            printf("Show all volumes.\n");
        }
        else
        {
            printf("Show volume id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "info", strlen("info")))
    {
        if(id < 0)
        {
            printf("Show info.\n");
        }
        else
        {
            printf("Show info id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "parameters", strlen("parameters")))
    {
        if(id < 0)
        {
            printf("Show all volumes parameters.\n");
        }
        else
        {
            printf("Show volume parameters id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "ssr", strlen("ssr")))
    {
        if(id < 0)
        {
            printf("Show all volumes ssr.\n");
        }
        else
        {
            printf("Show volume ssr id: %d.\n", id);
        }
    }

    else 
    {
        printf("Option not available\n");
    }

    return true;
}

bool APW_group(char *command, void *args)
{
    int id = *(int *)args;
    printf("APW: ");
    if(command == NULL)
    {
        printf("Showing status\n");
    }

    else if(!strncmp(command, "volumes", strlen("volumes")))
    {
        if(id < 0)
        {
            printf("Show all volumes.\n");
        }
        else
        {
            printf("Show volume id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "info", strlen("info")))
    {
        if(id < 0)
        {
            printf("Show info.\n");
        }
        else
        {
            printf("Show info id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "parameters", strlen("parameters")))
    {
        if(id < 0)
        {
            printf("Show all volumes parameters.\n");
        }
        else
        {
            printf("Show volume parameters id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "ssr", strlen("ssr")))
    {
        if(id < 0)
        {
            printf("Show all volumes ssr.\n");
        }
        else
        {
            printf("Show volume ssr id: %d.\n", id);
        }
    }

    else 
    {
        printf("Option not available\n");
    }

    return true;
}

bool APM_group(char *command, void *args)
{
   int id = *(int *)args;
    printf("APM: ");
    if(command == NULL)
    {
        printf("Showing status\n");
    }

    else if(!strncmp(command, "volumes", strlen("volumes")))
    {
        if(id < 0)
        {
            printf("Show all volumes.\n");
        }
        else
        {
            printf("Show volume id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "info", strlen("info")))
    {
        if(id < 0)
        {
            printf("Show info.\n");
        }
        else
        {
            printf("Show info id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "parameters", strlen("parameters")))
    {
        if(id < 0)
        {
            printf("Show all volumes parameters.\n");
        }
        else
        {
            printf("Show volume parameters id: %d.\n", id);
        }
    }

    else if(!strncmp(command, "ssr", strlen("ssr")))
    {
        if(id < 0)
        {
            printf("Show all volumes ssr.\n");
        }
        else
        {
            printf("Show volume ssr id: %d.\n", id);
        }
    }

    else 
    {
        printf("Option not available\n");
    }

    return true;
}


typedef enum 
{
    msaw_option = 500,
    stca_option,
    apw_option,
    apm_option
} Options;

void show_help(char *name) {
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\
            -h, --help          mostra essa tela e sai.\n\
            --msaw    seta o seu nome.\n\
            --stca    seta sua idade.\n\
            --apw     seta seu estado.\n\
            --apm     cadastra no banco de dados.\n", name) ;
    exit(-1) ;
}

void call_functions(Group *group, char **arguments);

static Group group[] = 
{
    {.name = "msaw", .is_set = false, .arg_index = 0, .callback = MSAW_group},
    {.name = "stca", .is_set = false, .arg_index = 0, .callback = STCA_group},
    {.name = "apw",  .is_set = false, .arg_index = 0, .callback = APW_group },
    {.name = "apm",  .is_set = false, .arg_index = 0, .callback = APM_group},
};

int main(int argc, char **argv) {
    int opt ;
    int resul;

    /* Variáveis que receberão os argumentos
     * das opções. */
    char *nome=NULL, *idade=NULL, *estado=NULL ;
    int flag_cadastrar = 0 ;

    int msaw_is_set = 0;
    int stca_is_set = 0;
    int apm_is_set = 0;
    int apw_is_set = 0;

    const struct option stopcoes[] = {
        {"help" , no_argument       , 0  , 'h'},
        {"msaw" , optional_argument , 0  ,  msaw_option},
        {"stca" , optional_argument , 0  ,  stca_option},
        {"apw"  , optional_argument , 0  ,  apw_option },
        {"apm"  , optional_argument , 0  ,  apm_option },
        {0      , 0                 , 0  , 0  },
    } ;

    if ( argc < 2 )
     show_help(argv[0]) ;

    while( (opt = getopt_long(argc, argv, "h", stopcoes, &resul)) > 0 )
    {
        // printf("option : %d.\n", opt);
        switch ( opt ) {
            case 'h': /* -h ou --help */
                show_help(argv[0]) ;
                break ;
            case msaw_option: 
                msaw_is_set = 1;
                group[0].is_set = true;
                group[0].arg_index = optind;
                break ;
            case stca_option: /* -i ou --idade */
                group[1].is_set = true;
                group[1].arg_index = optind;
                break ;
            case apw_option: /* -e ou --estado */
                group[2].is_set = true;
                group[2].arg_index = optind;
                break ;
            case apm_option: /* -c ou --cadastrar */
                group[3].is_set = true;
                group[3].arg_index = optind;
                break ;
            default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: `%c'\n", optopt) ;
                return -1 ;
        }
    }

    
    
    // printf("optind: %d\n", argc - optind);

    // int args_amount = 0;
    // char **arguments = NULL;

    // if ( argv[optind] != NULL ) {
    //     int i ;  

    //     args_amount = argc - optind;
    //     arguments = (char **)calloc(args_amount, sizeof(char *));      

    //     for(i=optind; argv[i] != NULL; i++)
    //     {
    //         arguments[i - optind] = argv[i];
    //     }
    // }

    // if(args_amount)
    // {
    //     for(int i = 0; i < args_amount; i++)
    //     {
    //         printf("%s\n", arguments[i]);
    //         call_functions(&group, arguments);
    //     }
    // }
    // else 
    // {
    //     call_functions(&group, NULL); 
    // }

    call_functions(&group, argv);

    // call_functions(&group, arguments);
    

    

    // if(arguments)
    //     free(arguments);

    return 0 ;
}
/* EOF */

void call_functions(Group *group, char **arguments)
{
    char *option = NULL;    
    int id = -1;

    // if(arguments != NULL)
    // {
    //     option = arguments[0];

    //     if(arguments[1] != NULL)
    //     {
    //         id = atoi(arguments[1]);
    //     }
    // }

    
    

    for(int i = 0; i < 4; i++)
    {
        if (group[i].is_set)
        {
            if (arguments[group[i].arg_index] != NULL)
            {
                option = arguments[group[i].arg_index];

                if (arguments[group[i].arg_index + 1] != NULL)
                {
                    id = atoi(arguments[group[i].arg_index + 1]);
                }
            }


            // printf("showing volumes %s\n", group[i].name);
            group[i].callback(option, &id);
        }
    }    
}