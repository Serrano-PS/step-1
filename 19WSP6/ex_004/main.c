#include <stdio.h>
#include <string.h>
// criar um funзгo "imprime-pessoa" que imprime para a saнda padrгo os valores dos campos de uma variavel, "struct pessoa"
/*%s - char*
%d - int
%lf - double
%c - char
%f - float
*/



//static const unsigned short int TAM_NOME = 50 + 1;
#define TAM_NOME 75 + 1 // +1 para o \0, no final de uma string
#define MAS 'M'
#define FEM 'F'
#define NUM_AVALS 12
#define NUM_PESSOAS 3

typedef unsigned short int idade; // int 4 bits, short 2 bits, unsigned й sem pontuaзгo
typedef double salario;

struct pessoa {
	char m_nome[TAM_NOME];
	idade m_idade;
	salario m_salario;
	char m_sexo;
	//float m_avaliacoes[NUM_AVALS];
};

void imprime_pessoa(struct pessoa *p1);
void imprime_pessoa_1(struct pessoa *p1);
int inicializa_pessoa(struct pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo);
int imprime_pessoas(struct pessoa *p, int tam);
int percorre_pessoas(struct pessoa * p, int tam, void(*f)(struct pessoa *));

int main() {
	struct pessoa pessoas[NUM_PESSOAS];

	inicializa_pessoa(&(pessoas[0]), "Jose das Couves", 45, 3678.45, MAS);
	inicializa_pessoa(&(pessoas[1]), "Maria Efigenia", 31, 4017.83, FEM);
	inicializa_pessoa(&(pessoas[2]), "Bebeto de Freitas ", 68, 20527.34, MAS);

	imprime_pessoas(pessoas, NUM_PESSOAS);

	void(*ip)(struct pessoa *) = imprime_pessoa_1;

	percorre_pessoas(pessoas, NUM_PESSOAS, ip);



	return 0;
}
void imprime_pessoa(struct pessoa *p1) {
	printf("Nome: =[%s]\n ", p1->m_nome);
	printf("Idade: = [%d]\n", p1->m_idade);
	printf("Salario: =  [%lf]\n", p1->m_salario);
	printf("Sexo: = [%c]\n", p1->m_sexo);
	//printf("Avaliaзao: = [%f]\n", p1->m_avaliacoes);
}

void imprime_pessoa_1(struct pessoa *p1) {
	printf("Nome: = %s, ", p1->m_nome);
	printf("Idade: = %d, ", p1->m_idade);
	printf("Salario: =  %lf, ", p1->m_salario);
	printf("Sexo: = %c\n", p1->m_sexo);
	//printf("Avaliaзao: = [%f]\n", p1->m_avaliacoes);
}

int inicializa_pessoa(struct pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo) {
	if (p == NULL) {
		return -1;
	}

	if (p_nome == NULL) {
		return -2;
	}

	if (strlen(p_nome) > TAM_NOME) {
		return -3;
	}

	if (p_idade < 18) {
		return -4;
	}

	if (p_idade > 100) {
		return -5;
	}

	if (p_salario < 300) {
		return -6;
	}

	if (p_salario > 30000) {
		return -7;
	}

	// parâmetros OK

	strcpy(p->m_nome, p_nome);
	p->m_idade = p_idade;
	p->m_salario = p_salario;
	p->m_sexo = p_sexo;

	return 1;

}

int imprime_pessoas(struct pessoa *p, int tam) {
	if (p == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	struct pessoa *end = p + tam;

	for (struct pessoa * aux = p; aux != end; ++aux) {

		imprime_pessoa(aux);

	}

	return 1;
}

int percorre_pessoas(struct pessoa * p, int tam, void (*f)(struct pessoa *) ){

	if (p == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	struct pessoa *end = p + tam;

	for (struct pessoa * aux = p; aux != end; ++aux) {
		f(aux);
	}
}