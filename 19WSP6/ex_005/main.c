#include <stdio.h>
#include <stdlib.h>

struct no_t {
	struct no_t * ant;
	int val;
	struct no_t * prox;
};

typedef struct no_t no;

no * cria_lista(int i);
int testa_cria_lista();

<<<<<<< HEAD
no * ins_apos(no * p, int i);
=======
no * ins_apos(no * _corrente, int i);
>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2
int testa_ins_apos();

int percorre_lista(no * lista, int(*f)(no *));
int testa_percorre_lista();

int imprime_no(no * p);
<<<<<<< HEAD
=======

no * ins_antes(no * _corrente, int i);
int testa_ins_antes();

void exclui_no(no **corrente);
int testa_exclui_no();
>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2


int main() {
	int _rc = 1;

	_rc = testa_cria_lista();
	if (_rc != 1) {
		printf("ERRO testa_cria_lista: %d\n", _rc);
		return 10;
	}

	_rc = testa_ins_apos();
<<<<<<< HEAD
	if (_rc != 1) {
		printf("ERRO testa_ins_apos: %d\n", _rc);
		return 20;
	}

	_rc = testa_percorre_lista();
	if (_rc != 1) {
		printf("ERRO testa_percorre_lista: %d\n", _rc);
=======
	if (_rc != 1) {
		printf("ERRO testa_ins_apos: %d\n", _rc);
>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2
		return 20;
	}

	_rc = testa_ins_antes();
	if (_rc != 1) {
		printf("ERRO testa_ins_antes: %d\n", _rc);
		return 30;
	}

	_rc = testa_percorre_lista();
	if (_rc != 1) {
		printf("ERRO testa_percorre_lista: %d\n", _rc);
		return 40;
	}

	return 0;
}

no * cria_lista(int i) {
	no * _rc = (no *)malloc(sizeof(no));
	if (_rc) {
		_rc->ant = _rc;
		_rc->val = i;
		_rc->prox = _rc;
	}
	return _rc;
}
int testa_cria_lista() {
	no * _lista = cria_lista(-81);
	if (_lista == NULL) {
		return -1;
	}

	if (_lista->ant != _lista) {
		return -2;
	}

	if (_lista->prox != _lista) {
		return -3;
	}

	if (_lista->val != -81) {
		return -4;
	}

	return 1;

}

no * ins_apos(no * _corrente, int i) {
	if (_corrente == NULL) {
		return NULL;
	}

	no * _novo = (no *)malloc(sizeof(no));
	_novo->val = i;
	if (_novo == NULL) {
		return NULL;
	}

	if (_corrente->prox == _corrente) {
		_corrente->ant = _novo;
		_novo->prox = _corrente;
	}
	else {
		_novo->prox = _corrente->prox;
		_corrente->prox->ant = _novo;
	}

	_novo->ant = _corrente;
	_corrente->prox = _novo;
	return _novo;
}

no * ins_apos_OLD(no * _corrente, int i) {
	if (_corrente == NULL) {
		return NULL;
	}

	no * _novo = (no *)malloc(sizeof(no));
	if (_novo) {
		_novo->val = i;

		_novo->ant = _corrente;
		_corrente->prox = _novo;

		_novo->prox = _corrente;
		_corrente->ant = _novo;
	}
	return _novo;
}
int testa_ins_apos() {

	no * _lista = cria_lista(-91);
	if (_lista == NULL) {
		return -1;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n1 = ins_apos(_lista, 2);
	if (_n1 == NULL) {
		return -2;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n2 = ins_apos(_n1, 7);
	if (_n2 == NULL) {
		return -3;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n3 = ins_apos(_lista, -3);
	if (_n3 == NULL) {
		return -4;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");


<<<<<<< HEAD
	
=======

>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2
	return 1;
}


int imprime_no(no * p) {
	if (p == NULL) {
		return -1;
	}

	printf("no = %p, ant = %p, val = %d, prox = %p\n", p, p->ant, p->val, p->prox);
	return 1;
}

int percorre_lista(no * lista, int(*f)(no *)) {
	if (lista == NULL) {
		return -1;
<<<<<<< HEAD
	}

	no * _aux = lista;
	int _rc = f(_aux);
	if (_rc != 1) {
		return _rc;
	}
		
	_aux = lista->prox;

	while (_aux != lista) {
		if (_aux == NULL) {
			return -2;
		}
		_rc = f(_aux);
		if (_rc != 1) {
			break;
		}
		_aux = _aux->prox;
	}

=======
	}

	no * _aux = lista;
	int _rc = f(_aux);
	if (_rc != 1) {
		return _rc;
	}

	_aux = lista->prox;

	while (_aux != lista) {
		if (_aux == NULL) {
			return -2;
		}
		_rc = f(_aux);
		if (_rc != 1) {
			break;
		}
		_aux = _aux->prox;
	}

>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2
	return _rc;
}

int testa_percorre_lista() {
	no * lista = cria_lista(14);
	if (lista == NULL) {
		return -1;
<<<<<<< HEAD
	}

	
	if (ins_apos(lista, -8) == NULL) {
		return -2;
	}

	int _rc = percorre_lista(lista, imprime_no);
	if (_rc != 1) {
		return _rc;
	}

	return 1;
}
=======
	}

	if (ins_apos(lista, -8) == NULL) {
		return -2;
	}

	int _rc = percorre_lista(lista, imprime_no);
	if (_rc != 1) {
		return _rc;
	}

	return 1;
}

no * ins_antes(no * _corrente, int i) {
	if (_corrente == NULL) {
		return NULL;
	}

	no * _novo = (no *)malloc(sizeof(no));
	if (_novo == NULL) {
		return NULL;
	}
	_novo->val = i;

	if (_corrente->prox == _corrente) {
		_corrente->prox = _novo;
		_novo->ant = _corrente;
	}
	else {
		_novo->ant = _corrente->ant;
		_corrente->ant->prox = _novo;
	}

	_novo->prox = _corrente;
	_corrente->ant = _novo;
	return _novo;
}

int testa_ins_antes() {
	printf("\n\ntesta_ins_antes\n");

	no * _lista = cria_lista(-91);
	if (_lista == NULL) {
		return -1;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n1 = ins_antes(_lista, 2);
	if (_n1 == NULL) {
		return -2;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n2 = ins_antes(_n1, 7);
	if (_n2 == NULL) {
		return -3;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");

	no * _n3 = ins_antes(_lista, -3);
	if (_n3 == NULL) {
		return -4;
	}
	percorre_lista(_lista, imprime_no);
	printf("*******\n\n");



	return 1;
}


void exclui_no(no **corrente) {
	(*corrente)->ant->prox = (*corrente)->prox;
	(*corrente)->prox->ant = (*corrente)->ant;

	free(*corrente);
	(*corrente) = NULL;
}

int testa_exclui_no() {


	return 1;
}
>>>>>>> 5557324d712b0c3ad3050d10ce9794a0036657c2
