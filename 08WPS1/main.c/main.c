#include <stdio.h>

#define TAM_MATRIZ 4

typedef int (*visitor) (int *) ;

void percorre_matriz(int *m, int tam, visitor f) {
	int * _end = m + tam;
	for (int * _p = m; _p != _end; ++_p) {
		if (f(_p) != 1) {
			break;
		}
	}
}

int f1(int * p);
int f2(int * p);
int f3(int * p);
int f4(int * p);

int main() {

	int matriz[TAM_MATRIZ] = { -56, 82, 9, 17 };
	visitor f = f1;
	percorre_matriz(matriz, TAM_MATRIZ, f);

	f = f2;
	percorre_matriz(matriz, TAM_MATRIZ, f);

	f = f3;
	percorre_matriz(matriz, TAM_MATRIZ, f);

	f = f4;
	percorre_matriz(matriz, TAM_MATRIZ, f);
	percorre_matriz(matriz, TAM_MATRIZ, f2);

	return 0;
}

int f1(int * p) {
	printf("p = %d\n", *p);
	return 1;
}

int f2(int * p) {
	printf("O valor eh... %d!!!!\n", *p);
	return 1;
}

int f3(int * p) {
	if ( ((*p) % 2) == 0) {
		printf("%d e multiplo de 2\n", *p);
		return 0;
	}
	return 1;
}

int f4(int * p) {
	(*p)++;
	return 1;
}