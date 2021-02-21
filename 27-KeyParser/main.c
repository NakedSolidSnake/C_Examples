#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define SPLIT_CHR                                " ,.-"

typedef struct
{
    char ** mem ;
    uint16_t elementCount ;
    uint16_t elementSize ;
} context_t ;

void string_parsed(char *string, context_t * pCtx ) ;

void create_space(uint16_t str_amount, uint16_t str_max_len , context_t * pCtx );
void destroy_space( context_t * pCtx ) ;

void countCommand( context_t * pCtx , char * str , uint16_t * countOut , uint16_t * sizeOut );

int main ()
{
  char str[ 100 ] ;
  context_t ctx ;

    printf( "Cria espaço!\n") ;

    strcpy(str, "Voce nao conhece manowar");

    create_space( 5 , 10 , &ctx ) ;
    string_parsed(str, &ctx);

    for( int i = 0 ; ( *ctx.mem[ i ] ) && ( i < 5 ) ; i++ )
    {
        printf("ctx->mem[%d] -> \"%s\"\n" , i , ctx.mem[ i ] ) ;
    }

  destroy_space(&ctx);
  return 0;
}


void string_parsed(char *string, context_t * pCtx )
{
	char * token ;
    uint16_t idx = 0 ;
    size_t strSize ;

    printf( "string_parsed()\n" ) ;

	token = strtok( string, SPLIT_CHR ) ;
	while( ( token != NULL ) && ( idx < pCtx->elementCount ) )
	{
		printf( "\t\"%s\"\n",token );

        strSize = strlen( token ) ;
        if( strSize > pCtx->elementSize )
        {
            strSize = pCtx->elementSize ;
        }

        strcpy( pCtx->mem[ idx ] , token ) ;
		idx++ ;

		token = strtok( NULL , SPLIT_CHR ) ;
	}
}

void create_space( uint16_t  str_amount, uint16_t str_max_len , context_t * pCtx )
{
    printf( "create_space()\n" ) ;

    if( pCtx == NULL )
    {
        printf( "\tContext is null!\n" ) ;
        return ;
    }

    pCtx->elementCount = str_amount ;
    pCtx->elementSize  = str_max_len ;

    if( ( str_amount > 0 ) && ( str_max_len > 0 ) )
    {
        pCtx->mem = ( char ** ) malloc( sizeof(char *) * str_amount ) ;
        printf( "\tmalloc -> %d spaces -> %08Xh\n" , str_amount , pCtx->mem ) ;

        for(uint16_t i = 0; i < str_amount; i++)
        {
            size_t sizeMem = sizeof(char) * str_max_len ;
            pCtx->mem[i] = (char *)malloc(sizeMem);
            printf( "\tmalloc(%d) -> &pCtx->mem[%d] -> %08Xh\n" , sizeMem , i , ( unsigned long int ) pCtx->mem[i] ) ;
            memset( pCtx->mem[ i ] , 0 , sizeMem ) ;
        }
    }
    else
    {
        pCtx->mem = NULL ;
    }
}

void destroy_space( context_t * pCtx )
{
    printf( "destroy_space()\n" ) ;

    if( pCtx == NULL )
    {
        printf( "\tContext is null!\n" ) ;
        return ;
    }

	for(uint16_t i = 0; i < pCtx->elementCount; i++)
	{
        printf( "\tfree( pCtx->mem[ %d ] -> %08Xh )\n" , i , ( unsigned long int ) pCtx->mem[ i ] ) ;
		free( pCtx->mem[ i ] );
	}

    printf( "\tfree( pCtx->mem -> %08Xh )\n" , ( unsigned long int ) pCtx->mem ) ;
	free( pCtx->mem );
    pCtx->mem = NULL ;
}

void countCommand( context_t * pCtx , char * str , uint16_t * countOut , uint16_t * sizeOut )
{
	char * token ;
    uint16_t idx = 0 ;
    size_t strSize ;

    *countOut = 0 ;
    *sizeOut  = 0 ;

    printf( "string_parsed()\n" ) ;

	token = strtok( str, SPLIT_CHR ) ;
	while( ( token != NULL ) && ( idx < pCtx->elementCount ) )
	{
		printf( "\t\"%s\"\n",token );

        strSize = strlen( token ) ;
        if( strSize > *sizeOut )
        {
            *sizeOut = strSize ;
        }

        *countOut++ ;

		token = strtok( NULL , SPLIT_CHR ) ;
	}
}
