#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// criar um funзгo "imprime-pessoa" que imprime para a saнda padrгo os valores dos campos de uma variavel, "pessoa"
/*%s - char*
%d - int
%lf - double
%c - char
%f - float
*/

/* 2018.03.20 - 
	Perguntar ao usuário quantas 'pessoa' ele quer criar, e para cada uma delas,
	perguntar quais os valores dos campos. Ao final, imprimir o conjunto de pessoas.
*/

//static const unsigned short int TAM_NOME = 50 + 1;
#define TAM_NOME 75 + 1 // +1 para o \0, no final de uma string
#define MAS 'M'
#define FEM 'F'
#define NUM_AVALS 12
#define NUM_PESSOAS 3

#define freep(p) free(p); p = NULL; 

typedef unsigned short int idade; // int 4 bits, short 2 bits, unsigned й sem pontuaзгo
typedef double salario;

struct pessoa_t {
	char m_nome[TAM_NOME];
	idade m_idade;
	salario m_salario;
	char m_sexo;
	//float m_avaliacoes[NUM_AVALS];
} ;

typedef struct pessoa_t pessoa;

int obtem_pessoa(pessoa * p);
void testa_obtem_pessoa();


int imprime_pessoa(pessoa *p1);
int imprime_pessoa_1(pessoa *p1);
int imprime_pessoa_2(pessoa *p1);
int inicializa_pessoa(pessoa *p, char * p_nome, idade p_idade, salario p_salario, char p_sexo);
int imprime_pessoas(pessoa *p, int tam);
int percorre_pessoas(pessoa * p, int tam, int(*f)(pessoa *));

pessoa * busca_pessoa(pessoa * p, int tam, pessoa * filtro
						, int(*cmp)(pessoa * filtro, pessoa * corrente));
int cmp_idade_igual(pessoa * filtro, pessoa * corrente);

int obtem_num_pessoas();

int main() {

	//Perguntar ao usuário quantas 'pessoa' ele quer criar, e para cada uma delas,
	//	perguntar quais os valores dos campos.Ao final, imprimir o conjunto de pessoas.

	int num_pessoas = obtem_num_pessoas();

	pessoa * pessoas = (pessoa *)malloc(num_pessoas * sizeof(pessoa));
	if (pessoas == NULL) {
		printf("ERRO alocacao\n");
		return 10;
	}

	//for (int i = 0; i < num_pessoas; ++i) {
	//	obtem_pessoa(&pessoas[i]);
	//}
	int rc = percorre_pessoas(pessoas, num_pessoas, obtem_pessoa);
	if ( rc != 1) {
		printf("ERRO preenchimento: %d\n", rc);
		return 20;
	}

	rc = percorre_pessoas(pessoas, num_pessoas, imprime_pessoa);
	if (rc != 1) {
		printf("ERRO impressao: %d\n", rc);
		return 20;
	}

	freep(pessoas); // {free(pessoas); pessoas=NULL;}
	

	//pessoa pessoas[NUM_PESSOAS];

	//inicializa_pessoa(&(pessoas[0]), "Jose das Couves", 20, 3678.45, MAS);
	//inicializa_pessoa(&(pessoas[1]), "Maria Efigenia", 31, 4017.83, FEM);
	//inicializa_pessoa(&(pessoas[2]), "Bebeto de Freitas", 68, 20527.34, MAS);

	//{
	//	pessoa filtro;
	//	filtro.m_idade = 31;

	//	pessoa * achada = busca_pessoa(pessoas, NUM_PESSOAS, &filtro, cmp_idade_igual);

	//	if (achada != NULL) {
	//		imprime_pessoa_1(achada);
	//	}
	//	else {
	//		printf("Niguem com %d anos\n", filtro.m_idade);
	//	}
	//}


	//{
	//	pessoa filtro;
	//	filtro.m_idade = 50;

	//	pessoa * achada = busca_pessoa(pessoas, NUM_PESSOAS, &filtro, cmp_idade_igual);

	//	if (achada != NULL) {
	//		imprime_pessoa_1(achada);
	//	}
	//	else {
	//		printf("Niguem com %d anos\n", filtro.m_idade);
	//	}
	//}

	//{
	//	testa_obtem_pessoa();
	//}

	//imprime_pessoa_1(busca_pessoa(pessoas, NUM_PESSOAS, "Bebeto de Freitas"));

	//percorre_pessoas(pessoas, NUM_PESSOAS, imprime_pessoa);
	//imprime_pessoas(pessoas, NUM_PESSOAS);


	return 0;
}
int imprime_pessoa(pessoa *p1) {
	printf("Nome: =[%s]\n ", p1->m_nome);
	printf("Idade: = [%d]\n", p1->m_idade);
	printf("Salario: =  [%lf]\n", p1->m_salario);
	printf("Sexo: = [%c]\n", p1->m_sexo);
	//printf("Avaliaзao: = [%f]\n", p1->m_avaliacoes);
	return 1;
}

int imprime_pessoa_1(pessoa *p1) {
	printf("Nome: = %s, ", p1->m_nome);
	printf("Idade: = %d, ", p1->m_idade);
	printf("Salario: = %lf, ", p1->m_salario);
	printf("Sexo: = %c\n", p1->m_sexo);
	//printf("Avaliaзao: = [%f]\n", p1->m_avaliacoes);
	return 1;
}

int imprime_pessoa_2(pessoa *p1) {
	if (p1->m_idade > 25) {
		imprime_pessoa_1(p1);
	}
	return 1;
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

pessoa * busca_pessoa(pessoa * p, int tam, pessoa * filtro
					, int (*cmp)(pessoa * filtro, pessoa * corrente)) {
	if (p == NULL) { return NULL; }

	if (tam <= 0) { return NULL; }

	pessoa *end = p + tam;

	for (pessoa * aux = p; aux != end; ++aux) {
		if (cmp(filtro, aux) == 1) {
			return aux;
		}
	}
	return NULL;
}

int cmp_idade_igual(pessoa * filtro, pessoa * corrente) {
	if (filtro == NULL) { return -1; }

	if (corrente == NULL) { return -2; }

	return (filtro->m_idade == corrente->m_idade ? 1 : 0);
}

int percorre_pessoas(pessoa * p, int tam, int(*f)(pessoa *)) {

	if (p == NULL) {
		return -1;
	}

	if (tam <= 0) {
		return -2;
	}

	pessoa *end = p + tam;

	int rc = 1;
	for (pessoa * aux = p; aux != end; ++aux) {
		rc = f(aux);
		if (rc != 1) {
			return rc;
		}
	}

	return 1;
}
int obtem_pessoa(pessoa * p) {
	char _nome[TAM_NOME];
	int _idade;
	salario _salario;
	char _sexo[2];

	printf("\nQual o nome? ");
	scanf("%s", _nome);

	printf("\nQual a idade? ");
	scanf("%d", &_idade );

	printf("\nQual o salario? ");
	scanf("%lf", &_salario);

	printf("\nQual o sexo? ");
	scanf("%s", _sexo);

	return inicializa_pessoa(p, _nome, _idade, _salario, _sexo[0]);
}

void testa_obtem_pessoa() {
	pessoa _p;

	if (obtem_pessoa(&_p) != 1) {
		printf("ERRO obtendo pessoa\n");
	}
	else {
		imprime_pessoa(&_p);
	}
}

int obtem_num_pessoas() {
	return 3;
}

