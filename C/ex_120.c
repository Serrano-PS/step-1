#include <stdio.h>
/*
Declare uma função 'f1' que tem os argumentos inteiro 'i' e double 'd', e retorne a divisão de 'd' por 'i'. Na definição de 'f1', imprima os valores de 'i', 'd' e do resultado da divisão.

Declare uma função 'f2' que tem como argumentos inteiro 'i', um double 'd', e um ponteiro para double 'r'. 'f2' deve retorna -1 se 'i' for 0. Caso contrário 'r' deverá conter o resultado da divisão de 'd' por 'i', e 'f2' deve retornar 1. Na definição de 'f2', imprima os valores de 'i', 'd', 'r', da área endereçada por 'r' antes e depois do cálculo.

Declare na função 'main' as variáveis inteira i1 com valor 10, inteira i2 com valor 0, double 'g1' com valor 2.5, double 'g2'e double 'g3'. Chame 'f1' como 'i1' e 'g1', e imprima os valores de 'i1', 'g1', e o resultado da execução de 'f1'. Execute 'f2' com 'i1', 'g1' e 'g2'. Imprima os valores de 'i1', 'g1', 'g2' e o endereço de 'g2'. Compare o conteúdo de 'r' e o endereço de 'g2'. Chame 'f2' com 'i2' e 'g1' e 'g3', e imprima os valroes de 'i1', 'g1', 'g3' e o endereço de 'g3'.

*/


double f1(int i, double d);

int f2(int i, double d, double * r);

double f1(int i, double d) {
    return d/i;
}

int f2(int i, double d, double * r) {
    if (i == 0) {
        return -1;
    }

    (*r) = d/i;

    printf("i = %d, d = %lf, r = %p, *r = %lf\n", i, d, r, *r);

    return 1;
}

int main () {
    int i1 = 10;
    int i2 = 0;
    double g1 = 2.5;
    double g2;
    double g3;


    if (f2(i1, g1, &g2) == 1) {
        printf ("i1 = %d, g1 = %lf, g2 = %lf, &g2 = %p\n", i1, g1, g2, &g2);
    }
    else {
        printf("Erro em f2 com i1\n");
    }

    if (f2(i2, g1, &g3) == 1) {
        printf ("i1 = %d, g1 = %lf, g3 = %lf, &g3 = %p\n", i2, g1, g3, &g3);
    }
    else {
        printf("Erro em f2 com i2\n");
    }
}

