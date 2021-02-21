#include "Repository.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysql.h"

#define  BUFSIZE        4092

static MYSQL connection;

static void Open_DB(const char *hostname, const char *username, const char *password, const char *database);
static void Close_DB(void);

void Repository_GetAllProducts(Product **products)
{
    const char *query = "select * from tutorials_tbl";

    if(products)
    {
        Open_DB("localhost", "cssouza", "senha", "alura_loja");
        mysql_query(&connection, query);

        MYSQL_RES *result = mysql_store_result(&connection);
        if (result == NULL)
            return -1;

        int num_fields = mysql_num_fields(result);
        int num_rows = mysql_affected_rows(&connection);

        *products = (Product *)malloc(sizeof(Product) * num_rows);

        MYSQL_ROW row;
        int i = 0;

        while ((row = mysql_fetch_row(result)))
        {
            (*products)[i].id = atoi(row[0]);
            strncpy((*products)[i].name, row[1], NAME_LEN);
            strncpy((*products)[i].description, row[2], DESCRIPTION_LEN);
            (*products)[i].price = atof(row[3]);
            (*products)[i].quantity = atoi(row[4]);
            i++;
        } 

        mysql_free_result(result);

        Close_DB();
    }
}

void Repository_Free(Product **products)
{
    if(products)
    {
        if(*products)
        {
            free(*products);
        }
    }
}

void Repository_InsertProduct(Product *product)
{
    char query_format[BUFSIZE];
    const char *query = "INSERT INTO tutorials_tbl (nome, descricao, preco, quantidade) values(\"%s\", \"%s\", %lf, %d)";
    Open_DB("localhost", "cssouza", "senha", "alura_loja");
    snprintf(query_format, sizeof(query_format), query, product->name, product->description, product->price, product->quantity);
    mysql_query(&connection, query_format);
    Close_DB();
}

void Repository_DeleteProduct(int id)
{
    const char *query = "DELETE FROM tutorials_tbl Where id = %d";
}

Product Repository_EditProduct(int id)
{
    const char *query = "select * from tutorials_tbl where id = %d";
}

void Repository_UpdateProduct(Product *product)
{
    const char *query = "UPDATE  tutorials_tbl set preco=%lf where id = %d";
}

static void Open_DB(const char *hostname, const char *username, const char *password, const char *database)
{
    MYSQL *ret = NULL;
    
    if (mysql_library_init(0, NULL, NULL))
    {
        fprintf(stderr, "could not initialize MySQL client library\n");
        return -1;
    }

    ret = mysql_init(&connection);
    if (ret == NULL)
        return -1;

    if(mysql_real_connect(&connection, hostname, username, password, database, 0, NULL, 0) != NULL)
    {
        printf("Opened sucessufully.\n");
    }    
}

static void Close_DB(void)
{
    mysql_close(&connection);
}