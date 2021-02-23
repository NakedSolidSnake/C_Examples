#ifndef __DATABASE_H
#define __DATABASE_H


typedef struct{
    int listItems;
    char **list;
}Request_t;

typedef struct{
    int listsAmount;
    Request_t *l;
}Data_t;

typedef char *(*Insert)(void *object);
typedef char *(*Update)(void *object);
typedef char *(*Select)(void);
typedef char *(*Delete)(void *object);

typedef struct{
    const char *hostname;
    const char *username;
    const char *password;
    const char *datbase_name;
}DatabaseInfo_t;

int DATABASE_init(const DatabaseInfo_t *database);
int DATABASE_insert(Insert insert, void *object);
int DATABASE_update(Update update, void *object);
int DATABASE_select(Select select, Data_t **object);
int DATABASE_selectFree(Data_t **object);
int DATABASE_delete(Delete delete, void *object);




#endif