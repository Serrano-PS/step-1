#ifndef _PESSOA_H
#define _PESSOA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TAM_NOME 50 + 1// +1 para o \0, no final de uma string
#define MAS 'M'
#define FEM 'F'
#define TAM_BUF 63 + 1 + 1 + 1

#define freep(p) free(p); p = NULL; 

typedef unsigned short int idade; // int 4 bits, short 2 bits, unsigned й sem pontuaзгo
typedef double salario;

struct pessoa_t {
	char m_nome[TAM_NOME];
	idade m_idade;
	salario m_salario;
	char m_sexo;
};

typedef struct pessoa_t pessoa;

/*
Esta fç obtem do usuário valores para a pessoa em '*p'
*/
int obtem_pessoa(pessoa * p);
int inicializa_pessoa(pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo);

// p_buf tem o formato 50c + 999 + 999999.99 + M/F
int inicializa_pessoa_1(pessoa *p, const char * p_buf);
int imprime_pessoa(pessoa *p1);
int imprime_pessoas(pessoa *p, int tam);
int grava_pessoa(const pessoa * p, FILE * file);
int copia_pessoa(pessoa * to, const pessoa * from);
int le_pessoa(pessoa * to, FILE * file);

#endif

