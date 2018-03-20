#include <stdio.h>

/*
Declare e defina uma função 'f1' que receba como parâmetro um inteiro 'i', 
e retorne o resto da divisão por 3.

Declare e defina uma função 'f2' que receba como parâmetros um inteiro 'i' 
e um ponteiro para double 'd', e retorne um inteiro.
Se 'i' for maior que 75, 'f2' deve retornar -1. Caso contrário, 'd' 
deverá conter o resto da divisão de 'i' por 3, 'f2' deve retornar 1.
Imprima os valores 'i', 'd' e '*d'.

Escreva uma função 'main' que declare e defina um inteiro 'k' com 11, 
declare um double 'u', e um double 'v'.
'u' receberá o retorno de 'f1', tendo 'k' como parâmetro.
Passe 'k' e 'v' como parâmetros para 'f2'.
Imprima os valores de 'i', 'u', 'v' e '&v'.
*/

/*
Declare e defina uma função 'f1' que receba como parâmetro um inteiro 'i', 
e retorne o resto da divisão por 3.
*/

int f1(int i);

int f1(int i) {
	return i % 3;
}

/*Declare e defina uma função 'f2' que receba como parâmetros um inteiro 'i' 
e um ponteiro para double 'd', e retorne um inteiro.
Se 'i' for maior que 75, 'f2' deve retornar -1. Caso contrário, 'd' 
deverá conter o resto da divisão de 'i' por 3, 'f2' deve retornar 1.
Imprima os valores 'i', 'd' e '*d'.
*/

int f2(int i, double * d);

int f2(int i, double * d) {
	if (i > 75) {
		return -1;
	}

	(*d) = i % 3;

	printf("i = %d, d = %p, *d = %lf\n", i, d, *d);

	return 1;
}

int main() {
	/*int k = 11;
	double * v = k;
	print("*v = %lf", *v);
*/

	int k = 11;
	double v;
	
	if (f2(k, &v) == -1) {
		printf("ERRRO em f2");
		return 1;
	}

	printf("v = %lf", v);

	return 0;
}





