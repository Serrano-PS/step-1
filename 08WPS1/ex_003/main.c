#include <stdio.h>

#define TAM_MATRIZ 4

int preenche_matriz(int * m, int tam);
int f1(int *m, int tam);
int f2(int *m, int tam);

int main() {
	int m[TAM_MATRIZ];
	int rc = 1;

	rc = preenche_matriz(m, TAM_MATRIZ);
	if (rc != 1) {
		printf("Erro preenchendo matriz: %d\n", rc);
		return 10;
	}

	rc = f1(m, TAM_MATRIZ);
	if (rc != 1) {
		printf("Erro imprimindo usando []: %d\n", rc);
		return 20;
	}

	rc = f2(m, TAM_MATRIZ);
	if (rc != 1) {
		printf("Erro imprimindo usando endereco: %d\n", rc);
		return 30;
	}

	return 0;
}


int preenche_matriz(int * m, int tam) {

	if (m == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	for (int i = 0; i < tam; ++i) {
		printf("Entre com o valor do %d-esimo elemento ", i + 1);
		scanf("%d", &m[i]);
	}

	return 1;
}


int f1(int *m, int tam) {
	if (m == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	for (int i = tam - 1; i >= 0; --i) {
		printf("m[%d] = %d\n", i, m[i]);
	}

	return 1;
}


int f2(int *m, int tam) {
	if (m == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	int * end = m - 1;
	int i = tam - 1;
	for (int * aux = m + tam - 1; aux != end; --aux) {
		printf("m[%d] = %d\n", i, *aux);
		--i;
	}

	return 1;
}