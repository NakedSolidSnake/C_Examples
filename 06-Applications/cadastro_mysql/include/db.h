#ifndef _DB_H
#define _DB_H



int initdb(const char *hostname, const char *username, const char *password, const char *database);
int insertdb(char *(*insert)(void *data), void *data);
int deletedb(char *(*delete)(void *data), void *data);
int updatedb(char *(*update)(void *data), void *data);
int closedb(void);

#endif
