/**
 * @file categoria.h
 * @author Cristiano Silva de Souza (cristianosstec@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CATEGORIA_H_
#define CATEGORIA_H_

typedef struct 
{
    int id;
    const char *nome;
    Produto *produtos;
} Categoria;

#endif /* CATEGORIA_H_ */
