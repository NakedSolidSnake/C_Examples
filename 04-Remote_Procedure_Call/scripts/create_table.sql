CREATE DATABASE aluno;

USE aluno;

CREATE TABLE alunos(
    id          int(4) AUTO_INCREMENT,
    nome        varchar(255) NOT NULL, 
    matricula   int NOT NULL,
    idade       int NOT NULL, 
    curso       varchar(80) NOT NULL,
    PRIMARY KEY (id)
);
