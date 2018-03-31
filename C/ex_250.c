/*
Escreva um progama que:

1 - Crie uma função genérica de percurso da matriz, chamada 'percorre', que recebe como parâmetro uma função do tipo 'void (*)(double *)'.

2 - Crie uma função 'f1' do tipo 'void (*)(double *)' que deve mudar o sinal do 'double *' se ele for negativo.

3 - Crie uma função 'f2' do tipo 'void (*)(double *)' que deve imprimir o valor do double *' se ele for maior que 30.

4 - Crie uma função 'f3' do tipo 'void (*)(double *)' que deve imprimir o valor do double *'.


5 - Na função 'main', declare e defina uma matriz de 'double' de 10 elementos.

6 - Chame a função 'percorre' passando 'f3' como parâmetro.

7 - Chame a função 'percorre' passando 'f2' como parâmetro.

8 - Chame a função 'percorre' passando 'f1' como parâmetro.

9 - Chame a função 'percorre' passando 'f3' como parâmetro.

10 - Chame a função 'percorre' passando 'f2' como parâmetro.
*/



#include <stdio.h>

#define TAM_MATRIZ 10

/* 1 */
void percorre(double * m, int tam, void (*f)(double *));

/* 2 */
void f1(double *d);

/* 3 */
void f2(double *d);

/* 4 */
void f3(double *d);


int main() {

    /* 5 */
    double matriz[TAM_MATRIZ] = {9.3, -78.4, 0.11, 104.82, -4.61
                                 , 3.14, 90.21, 13.21,-34.2, 2.01 };

    /* 6 */
    printf("\n\nf3\n");
    percorre(matriz, TAM_MATRIZ, f3);


    /* 7 */
    printf("\n\nf2\n");
    percorre(matriz, TAM_MATRIZ, f2);

    /* 8 */
    printf("\n\nf1\n");
    percorre(matriz, TAM_MATRIZ, f1);

    /* 9 */
    printf("\n\nf3\n");
    percorre(matriz, TAM_MATRIZ, f3);

    /* 10 */
    printf("\n\nf2\n");
    percorre(matriz, TAM_MATRIZ, f2);

    return 0;
}



void percorre(double * m, int tam, void (*f)(double *)) {

    double * _end = m + tam;

    for (double * _d = m; _d != _end; ++_d) {
        f(_d);
    }
}


void f1(double *d) {
    if ( (*d) < 0) {
        *d = (*d) * -1;
    }
}

void f2(double *d) {
    if ( (*d) > 30.0) {
        printf("%lf eh maior que 30\n", *d);
    }
}

void f3(double *d) {
    printf("%lf\n", *d);
}
