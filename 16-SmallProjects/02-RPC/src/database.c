#include <database.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"

typedef enum
{
    DB_UNITIALIZED,
    DB_INITIALIZED
} eDBState;

typedef struct
{
    MYSQL conn;
    eDBState state;
} DB_Context_t;

static DB_Context_t db = {
    .conn = NULL,
    .state = DB_UNITIALIZED};

int DATABASE_init(const DatabaseInfo_t *database)
{
    int *ret = NULL;
    mysql_init(&db.conn);

    ret = mysql_real_connect(&db.conn, database->hostname, database->username, database->password, database->datbase_name, 0, NULL, 0);
    // error_handle(ret);
    db.state = DB_INITIALIZED;
    return *ret;
}

int DATABASE_insert(Insert insert, void *object)
{
    int ret = -1;

    if (db.state == DB_UNITIALIZED)
        return -1;

    if (!insert)
    {
        return -1;
    }

    if (!object)
    {
        return -1;
    }

    ret = mysql_query(&db.conn, insert(object));
    //   error_handle(&ret);

    return ret;
}

int DATABASE_update(Update update, void *object)
{
    int ret = -1;

    if (db.state == DB_UNITIALIZED)
        return -1;

    if (!update)
    {
        return -1;
    }

    if (!object)
    {
        return -1;
    }

    ret = mysql_query(&db.conn, update(object));
    //   error_handle(&ret);

    return ret;
}

int DATABASE_select(Select select, Data_t **object)
{

     int ret = -1;

    if (db.state == DB_UNITIALIZED)
        return -1;

    if (!select)
    {
        return -1;
    }

    if (!object)
    {
        return -1;
    }

    if (mysql_query(&db.conn, select()))
    {
        // finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(&db.conn);

    if (result == NULL)
    {
        // finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    int num_rows = mysql_affected_rows(&db.conn);

        

    *object = (Data_t *)malloc(sizeof (Data_t));
    if(*object == NULL)
            return -1;

    (*object)->listsAmount = num_rows;
    (*object)->l = (Request_t *)malloc(sizeof(Request_t) * num_rows);   
    if((*object)->l == NULL){
            return -1;
            free(*object);
    }

    MYSQL_ROW row;
    int row_idx = 0;

    while ((row = mysql_fetch_row(result)))
    {   
        Request_t *d = &(*object)->l[row_idx];

        d->listItems = num_fields;
        d->list = (char **)malloc(sizeof(char *) * num_fields);  
         

        for (int i = 0; i < num_fields; i++)
        {
            int data_len = strlen(row[i]) + 1;
            d->list[i] = (char *)malloc(sizeof(char) * data_len);
            strncpy(d->list[i], row[i], data_len);
        }
        row_idx++;
    }

    mysql_free_result(result);
    mysql_close(&db.conn);
    return 0;
}

int DATABASE_selectFree(Data_t **object)
{
    if(*object == NULL)
        return -1;

    for(int i = 0; i <  (*object)->listsAmount; i++){
         Request_t *d = &(*object)->l[i];
         for(int j = 0; j < d->listItems; j++){
             free(d->list[j]);
         }

         free(d->list);
    }

    free((*object)->l);
    free(*object);
    return 0;
}

int DATABASE_delete(Delete delete, void *object)
{
    int ret = -1;

    if (db.state == DB_UNITIALIZED)
        return -1;

    if (!delete)
    {
        return -1;
    }

    if (!object)
    {
        return -1;
    }

    ret = mysql_query(&db.conn, delete(object));
    return ret;
    //   error_handle(&ret);
}