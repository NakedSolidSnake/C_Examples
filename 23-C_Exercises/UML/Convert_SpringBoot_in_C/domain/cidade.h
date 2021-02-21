/**
 * @file cidade.h
 * @author Cristiano Silva de Souza (cristianosstec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CIDADE_H_
#define CIDADE_H_

typedef struct 
{
    int id;
    const char *nome;
    Estado estado;
} Cidade;
#endif /* CIDADE_H_ */
