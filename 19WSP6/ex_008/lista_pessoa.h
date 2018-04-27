#ifndef _LISTA_PESSOA_H
#define _LISTA_PESSOA_H

#include "pessoa.h"


#include <stdio.h>
#include <stdlib.h>

struct no_t {
	struct no_t * ant;
	pessoa val;
	struct no_t * prox;
};

typedef struct no_t no;

no * cria_lista(const pessoa * p);
no * cria_lista_1();
no * ins_apos(no * _corrente, const pessoa * p);
no * ins_apos_1(no * _corrente);
int percorre_lista(no * lista, int(*f)(no *));
int imprime_no(no * p);
no * ins_antes(no * _corrente, const pessoa * p);
no * ins_antes_1(no * _corrente);
void exclui_no(no **corrente);



#endif