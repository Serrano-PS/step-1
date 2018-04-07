#include <stdio.h>
#include <string.h>

#define TAM_NOME 50+1
#define TAM_CEP 9+1
#define BUF 252

typedef double salario;

typedef struct pessoa
{
	char nome[TAM_NOME];
	int idade;
	char cep[TAM_CEP];
	salario _salario;
}pessoa;

//percorre o vetor executando uma funçao
void percorre(pessoa * p, int tam, void(*f)(pessoa * a));

//percorre o vetor executando uma funçao de comparaçao. retorna 1 se encontrou ou 0 caso n
int percorre_cmp(pessoa * p, int tam, void * alvo, int(*f)(pessoa * a, void * b));

//preenche dados da pessoa. Retorna <0 caso tenha erro
int inicializa_pessoa(pessoa * p, char * nome, int idade, char * cep, salario sal);

//capta pessoa do teclado
void capta_pessoa(pessoa *p);

//copia dados de p2 em p1, retorna 1 caso tenha sucesso e <1 caso n
int copia_pessoa(pessoa *p1, pessoa *p2);

//imprime a pessoa
void imprime_pessoa(pessoa *p);

//verifica se o nome digitado e valido. Retorna 1 caso sim, e <1 caso n
int verifica_nome(char * nome, int tam);

//verifica se o cep digitado e valido, o "tam" e o tamanho do cep e o "pos" e a posiçao do '-'. Retorna 1 caso sim, e <1 caso n
int verifica_cep(char * cep, int tam, int pos);

//Compara idade da pessoa. Retorna 1 caso encontre, 0 caso n, <1 caso erro
int cmp_idade_pessoa(pessoa * p, void * alvo);

//Compara salario da pessoa. Retorna 1 caso encontre, 0 caso n, <1 caso erro
int cmp_salario_pessoa(pessoa * p, void * alvo);

int main()
{
	pessoa * p = NULL;
	int a = 13, b = 21, tam;
	double c = 450.8, d = 110;

	printf("Digite a quantidade de pessoas: ");
	scanf("%d%*c", &tam);

	p = (pessoa*)malloc(tam * sizeof(pessoa));

	if (p == NULL)
	{
		printf("\nEspaço de memoria insuficiente...");
		return 1;
	}

	percorre(p, tam, capta_pessoa);
	percorre(p, tam, imprime_pessoa);

	if (percorre_cmp(p, tam, &a, cmp_idade_pessoa))
		printf("\nPessoa com idade %d encontrada!!\n", a);

	if (percorre_cmp(p, tam, &b, cmp_idade_pessoa))
		printf("\nPessoa com idade %d encontrada!!\n", b);

	if (percorre_cmp(p, tam, &c, cmp_salario_pessoa))
		printf("\nPessoa com idade %.2lf encontrada!!\n", c);

	if (percorre_cmp(p, tam, &d, cmp_salario_pessoa))
		printf("\nPessoa com idade %.2lf encontrada!!\n", d);

	free(p);
	p = NULL;

	return 0;
}

int inicializa_pessoa(pessoa * p, char * nome, int idade, char * cep, salario sal)
{
	if (p == NULL)
		return -1;

	if (nome == NULL)
		return -2;

	if (cep == NULL)
		return -3;

	if (strlen(nome) > TAM_NOME)
		return -4;

	if (strlen(cep) > TAM_CEP)
		return -5;

	if (idade < 0 || sal < 0)
		return -6;

	p->idade = idade;
	strcpy(p->nome, nome);
	strcpy(p->cep, cep);
	p->_salario = sal;

	return 1;
}

void capta_pessoa(pessoa *p)
{
	char cont[BUF];
	int idade = 0;
	double sal = 0;
	char cep[TAM_CEP], nome[TAM_NOME];

	do {
		memset(cont, '\0', 252);
		printf("\nDigite o nome da pessoa: ");
		gets_s(cont, BUF);
		if (verifica_nome(cont, TAM_NOME - 1) != 1)
			printf("\nDigito para nome invalido!!");

	} while (verifica_nome(cont, TAM_NOME - 1) != 1);

	strcpy(nome, cont);

	do {

		printf("\nDigite a idade da pessoa: ");
		scanf("%d%*c", &idade);

		if (idade<0)
			printf("\nDigito para idade invalido!!");

	} while (idade<0);

	do {
		memset(cont, '\0', 252);
		printf("\nDigite o cep da pessoa: ");
		gets_s(cont, BUF);

		if (verifica_cep(cont, TAM_CEP - 1, 5) != 1)
			printf("\nDigito para cep invalido!!");

	} while (verifica_cep(cont, TAM_CEP - 1, 5) != 1);

	strcpy(cep, cont);

	do {

		printf("\nDigite o salario da pessoa: ");
		scanf("%lf%*c", &sal);

		if (sal<0)
			printf("\nDigito para salario invalido!!");

	} while (sal<0);

	inicializa_pessoa(p, nome, idade, cep, sal);
}

int copia_pessoa(pessoa *p1, pessoa *p2)
{
	if (p2 == NULL)
		return -1;

	strcpy(p1->nome, p2->nome);
	strcpy(p1->cep, p2->cep);

	p1->idade = p2->idade;
	p1->_salario = p2->_salario;

	return 1;
}

void imprime_pessoa(pessoa *p)
{
	printf("\nNome: %s\nIdade: %d\nCEP: %s\nSalario: %.2f\n", p->nome, p->idade, p->cep, p->_salario);
}

int verifica_nome(char * nome, int tam)
{
	if (nome == NULL)
		return -1;

	if ((int)strlen(nome) > tam)
		return -2;

	return 1;
}

int verifica_cep(char * cep, int tam, int pos)
{
	if (cep == NULL)
		return -1;

	if ((int)strlen(cep) != tam)
		return -2;

	for (int i = 0; i < tam; i++)
	{
		if (i == pos) {
			if (cep[i] != '-')
				return -4;
		}
		else {
			if (cep[i] != '0' && cep[i] != '1' && cep[i] != '2' && cep[i] != '3' && cep[i] != '4' && cep[i] != '5' && cep[i] != '6' && cep[i] != '7' && cep[i] != '8' && cep[i] != '9')
				return -3;
		}
	}

	return 1;
}

void percorre(pessoa * p, int tam, void(*f)(pessoa * a))
{

	for (pessoa * i = p; i < p + tam; i++)
		f(i);

}

int percorre_cmp(pessoa * p, int tam, void * alvo, int(*f)(pessoa * a, void * b))
{

	for (pessoa * i = p; i < p + tam; i++)
		if (f(i, alvo) == 1)
			return 1;

	return 0;
}

int cmp_idade_pessoa(pessoa * p, void * alvo)
{

	int idade = *((int*)alvo);

	if (idade == p->idade)
		return 1;

	return 0;
}

int cmp_salario_pessoa(pessoa * p, void * alvo)
{

	double salario = *((double*)alvo);

	if (salario == p->_salario)
		return 1;

	return 0;
}

