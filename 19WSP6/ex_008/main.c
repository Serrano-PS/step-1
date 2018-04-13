#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50 + 1 // +1 para o \0, no final de uma string
#define MAS 'M'
#define FEM 'F'
#define TAM_BUF 63

#define freep(p) free(p); p = NULL; 

typedef unsigned short int idade; // int 4 bits, short 2 bits, unsigned й sem pontuaзгo
typedef double salario;

struct pessoa_t {
	char m_nome[TAM_NOME];
	idade m_idade;
	salario m_salario;
	char m_sexo;	
};

typedef struct pessoa_t pessoa;

int obtem_pessoa(pessoa * p);
int inicializa_pessoa(pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo);
int imprime_pessoa(pessoa *p1);
int imprime_pessoas(pessoa *p, int tam);
int grava_pessoa(const pessoa * p, FILE * file);

int main(int argc, char ** argv) {
	if (argc != 2) {
		printf("Falta o nome do arquivo\n");
		return 10;
	}

	//printf("nome do pgm = %s, nome do arquivo = %s\n", argv[0], argv[1]);

	pessoa p;
	obtem_pessoa(&p);
	imprime_pessoa(&p);

	
	FILE * file = NULL;
	// abrir o arquivo

	grava_pessoa(&p, file);

	// fecha o arquivo
	
	return 0;
}


int obtem_pessoa(pessoa * p) {
	char _nome[TAM_NOME];
	int _idade;
	salario _salario;
	char _sexo[2];

	printf("\nQual o nome? ");
	scanf("%s", _nome);

	printf("\nQual a idade? ");
	scanf("%d", &_idade);

	printf("\nQual o salario? ");
	scanf("%lf", &_salario);

	printf("\nQual o sexo? ");
	scanf("%s", _sexo);

	return inicializa_pessoa(p, _nome, _idade, _salario, _sexo[0]);
}


int inicializa_pessoa(pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo) {
	if (p == NULL) {
		return -1;
	}

	memset(p->m_nome, '\0', TAM_NOME);
	p->m_idade = 0;
	p->m_salario = 0.0;
	p->m_sexo = 'I';


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

	if ((p_sexo != 'M') && (p_sexo != 'F')) {
		return -8;
	}

	// parâmetros OK

	strcpy(p->m_nome, p_nome);
	p->m_idade = p_idade;
	p->m_salario = p_salario;
	p->m_sexo = p_sexo;

	return 1;

}

int imprime_pessoa(pessoa *p1) {
	printf("Nome: = %s, ", p1->m_nome);
	printf("Idade: = %d, ", p1->m_idade);
	printf("Salario: = %lf, ", p1->m_salario);
	printf("Sexo: = %c\n", p1->m_sexo);
	return 1;
}

int imprime_pessoas(pessoa *p, int tam) {
	if (p == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	pessoa *end = p + tam;

	for (pessoa * aux = p; aux != end; ++aux) {
		imprime_pessoa(aux);
	}

	return 1;
}

int grava_pessoa(const pessoa * p, FILE * file) {
	char buf[TAM_BUF];

	memset(buf, ' ', TAM_BUF);

	strcpy(buf, p->m_nome);

	char buf_idade[4];
	memset(buf_idade, '\0', 4);
	sprintf(buf_idade, "%03d", p->m_idade);
	printf("%s\n", buf_idade);

	memcpy(buf + 50, buf_idade, strlen(buf_idade));

	return 1;
}

