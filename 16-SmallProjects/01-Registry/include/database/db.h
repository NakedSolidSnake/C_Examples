#ifndef _DB_H
#define _DB_H

typedef char *(*Database_cb)(void *data);
typedef void (*Database_get)(char **data, int columns);

typedef struct
{
    Database_cb select;
    Database_cb insert;
    Database_cb delete;
    Database_cb update;
    Database_get retrieve;
}IDatabase_driver;

typedef struct
{
    char *hostname;
    char *username;
    char *password;
    char *database;
}Database_params_t;

int initdb(Database_params_t *config);
int selectdb(IDatabase_driver *driver, void *data);
int insertdb(IDatabase_driver *driver, void *data);
int deletedb(IDatabase_driver *driver, void *data);
int updatedb(IDatabase_driver *driver, void *data);
int closedb(void);

#endif
