#include "lista_pessoa.h"



no * cria_lista(const pessoa * p) {
	no * _rc = cria_lista_1();
	if (_rc) {
		copia_pessoa(&(_rc->val), p);
	}
	return _rc;
}

no * cria_lista_1() {
	no * _rc = (no *)malloc(sizeof(no));
	if (_rc) {
		_rc->ant = _rc;
		_rc->prox = _rc;
	}
	return _rc;
}

no * ins_apos(no * _corrente, const pessoa * p) {
	no * _novo = ins_apos_1(_corrente);
	if (_novo) {
		copia_pessoa(&(_novo->val), p);
	}
	return _novo;
}

no * ins_apos_1(no * _corrente) {
	if (_corrente == NULL) {
		return NULL;
	}

	no * _novo = (no *)malloc(sizeof(no));
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

int imprime_no(no * p) {
	if (p == NULL) {
		return -1;
	}

	//printf("no = %p, ant = %p, val = %d, prox = %p\n", p, p->ant, p->val, p->prox);
	imprime_pessoa(&(p->val));
	return 1;
}

int percorre_lista(no * lista, int(*f)(no *)) {
	if (lista == NULL) {
		return -1;
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

	return _rc;
}


no * ins_antes(no * _corrente, const pessoa * p) {

	no * _novo = ins_antes_1(_corrente);
	if (_novo) {
		copia_pessoa(&(_novo->val), p);
	}
	return _novo;
}

no * ins_antes_1(no * _corrente) {
	if (_corrente == NULL) {
		return NULL;
	}

	no * _novo = (no *)malloc(sizeof(no));
	if (_novo == NULL) {
		return NULL;
	}

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


void exclui_no(no **corrente) {
	(*corrente)->ant->prox = (*corrente)->prox;
	(*corrente)->prox->ant = (*corrente)->ant;

	free(*corrente);
	(*corrente) = NULL;
}