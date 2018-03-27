#include <stdio.h>
#include <stdlib.h>

struct no_t {
	struct no_t * ant;
	int val;
	struct no_t * prox;
};

typedef struct no_t no;

no * cria_lista(int i);
int test_cria_lista();

no * ins_apos(no * p, int i);
int test_ins_apos();


int main() {
	int _rc = 1;

	_rc = test_cria_lista();
	if (_rc != 1) {
		printf("ERRO test_cria_lista: %d\n", _rc);
		return 10;
	}

	_rc = test_ins_apos();
	if (_rc != 1) {
		printf("ERRO test_ins_apos: %d\n", _rc);
		return 20;
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

int test_cria_lista() {
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
	if (_novo) {
		_novo->val = i;

		_novo->ant = _corrente;
		_corrente->prox = _novo;

		_novo->prox = _corrente;
		_corrente->ant = _novo;
	}
	return _novo;
}


int test_ins_apos() {

	no * _lista = cria_lista(-91);
	if (_lista == NULL) {
		return -1;
	}

	no * _novo = ins_apos(_lista, 2);
	if (_novo == NULL) {
		return -2;
	}
	if (_novo->val != 2) {
		return -3;
	}
	if (_novo->ant != _lista) {
		return -4;
	}
	if (_lista->prox != _novo) {
		return -7;
	}
	if (_novo->prox != _lista) {
		return -5;
	}
	if (_lista->ant != _novo) {
		return -6;
	}

	
	return 1;
}