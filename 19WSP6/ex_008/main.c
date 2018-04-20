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

// p_buf tem o formato 50c + 999 + 999999.99 + M/F
int inicializa_pessoa_1(pessoa *p, const char * p_buf);
int imprime_pessoa(pessoa *p1);
int imprime_pessoas(pessoa *p, int tam);
int grava_pessoa(const pessoa * p, FILE * file);
int le_todo_arquivo_e_imprime_cada_buffer(FILE * file);

int main(int argc, char ** argv) {
	int rc = 1;

	FILE * file = NULL;

	if (argc != 2) {
		printf("Falta o nome do arquivo\n");
		rc = 10; goto out;
	}
	// abrir o arquivo
	file = fopen(argv[1], "a+");
	if (file == NULL) {
		printf("Não abriu %s\n", argv[1]);
		rc = 20; goto out;
	}


	// recuperando as pessoas no arquivo
	rc = le_todo_arquivo_e_imprime_cada_buffer(file);
	if (rc != 1) {
		printf("Nao leu o arquivo: %d\n", rc);
		rc = 30; goto out;
	}


	// http://en.cppreference.com/w/c/io/fread

	//// obtendo novas pessoas
	//pessoa p;
	//rc = obtem_pessoa(&p);
	//if (rc != 1) {
	//	printf("Nao obteve pessoa: %d\n", rc);
	//	rc = 40; goto out;
	//}

	//rc = grava_pessoa(&p, file);
	//if (rc != 1) {
	//	printf("Nao gravou pessoa: %d\n", rc);
	//	rc = 40; goto out;
	//}

out:
	// fecha o arquivo
	if (file != NULL) {
		fclose(file);
	}
	return (rc == 1 ? 0 : rc);
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

	if (p == NULL) {
		return -1;
	}

	if (file == NULL) {
		return -2;
	}

	char buf[TAM_BUF];

	// inicializa o buffer que vai conter a 'pessoa' com brancos
	memset(buf, ' ', TAM_BUF);

	// copia o nome para o início do buffe
//	strcpy(buf, p->m_nome);
	memcpy(buf, p->m_nome, strlen(p->m_nome));

	// formata a idade com 3 dígitos, preenchidos com 0 à esquerda
	char buf_idade[4];
	memset(buf_idade, '\0', 4);
	sprintf(buf_idade, "%03d", p->m_idade);
	printf("%s\n", buf_idade);
	
	// copia a idade formatada para o buffer
	memcpy(buf + TAM_NOME - 1, buf_idade, strlen(buf_idade));

	// formata o salário no formato 999999.99, preenchidos com 0 à esquerda
	char buf_salario[9 + 1];
	memset(buf_salario, '\0', 10);
	sprintf(buf_salario, "%09.2lf", p->m_salario);

	// copia o salário formatado para o buffer
	memcpy(buf + TAM_NOME - 1 + strlen(buf_idade), buf_salario, strlen(buf_salario));

	// copia o sexo
	buf[TAM_NOME - 1 + strlen(buf_idade) + strlen(buf_salario)] = p->m_sexo;

	if (fwrite(buf, 1, TAM_BUF, file) != TAM_BUF) {
		return -3;
	}

	fflush(file);

	return 1;
}

int le_todo_arquivo_e_imprime_cada_buffer(FILE * file) {
	int rc = 1;

	if (file == NULL) { rc = -1; goto out; }

	char buf[TAM_BUF + 1];
	memset(buf, '\0', TAM_BUF + 1);
	int reads = fread(buf, 1, TAM_BUF, file);
	pessoa _pessoa;
	while (!feof(file)) {
		if ((inicializa_pessoa_1(&_pessoa, buf)) != 1) { rc = -3; goto out; }	
		if (reads == TAM_BUF) {
			printf("buf = %s\n", buf);
		}
		else { rc = -2; goto out; }
		reads = fread(buf, 1, TAM_BUF, file);
	}
out:
	return rc;
}

int inicializa_pessoa_1(pessoa *p, const char * p_buf) {

	int rc = 1;
	if (!p) {
		return -1;
	}

	if (strlen(p_buf) != TAM_BUF) {
		return -2;
	}

	memset(p->m_nome, '\0', TAM_NOME);
	char * _c1 = &(p->m_nome[0]);
	const char * _c2 = p_buf;
	while (1) {
		if ((*_c2) == ' ') {
			break;
		}
		if ((_c2 - p_buf) == TAM_NOME - 1) {
			break;
		}
		*_c1 = * _c2;
		++_c1;
		++_c2;
	}
	printf("nome = %s\n", p->m_nome);

	while ((*_c2) == ' ') { ++_c2; }

	// idade 
	char _buf_idade[4];
	memset(_buf_idade, '\0', 4);
	for (int i = 0; i < 3; ++i) {
		_buf_idade[i] = *_c2;
		++_c2;
	}
	printf("idade s = %s\n", _buf_idade);
	p->m_idade = atoi(_buf_idade);
	printf("idade i = %d\n", p->m_idade);

	// salario
	char _buf_salario[10];
	memset(_buf_salario, '\0', 10);
	for (int i = 0; i < 9; ++i) {
		_buf_salario[i] = *_c2;
		++_c2;
	}
	printf("salario s = %s\n", _buf_salario);
	p->m_salario = atof(_buf_salario);
	printf("salario f = %lf\n", p->m_salario);

	//++_c2;
	p->m_sexo = *_c2;
	printf("sexo = %c\n", p->m_sexo);
	return 1;

}