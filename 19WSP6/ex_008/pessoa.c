

#include "pessoa.h"


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
	memset(buf, '\0', TAM_BUF);

	// copia o nome para o início do buffer
	//	strcpy(buf, p->m_nome);
	memcpy(buf, p->m_nome, strlen(p->m_nome) + 1);

	// formata a idade com 3 dígitos, preenchidos com 0 à esquerda
	char buf_idade[4];
	memset(buf_idade, '\0', 4);
	sprintf(buf_idade, "%03d", p->m_idade);
	printf("%s\n", buf_idade);

	// copia a idade formatada para o buffer
	memcpy(buf + TAM_NOME, buf_idade, strlen(buf_idade) + 1);

	// formata o salário no formato 999999.99, preenchidos com 0 à esquerda
	char buf_salario[9 + 1];
	memset(buf_salario, '\0', 10);
	sprintf(buf_salario, "%09.2lf", p->m_salario);

	// copia o salário formatado para o buffer
	memcpy(buf + TAM_NOME + strlen(buf_idade) + 1, buf_salario, strlen(buf_salario) + 1);

	// copia o sexo
	buf[TAM_NOME + strlen(buf_idade) + 1 + strlen(buf_salario) + 1] = p->m_sexo;

	if (fwrite(buf, 1, TAM_BUF, file) != TAM_BUF) {
		return -3;
	}

	fflush(file);

	return 1;
}


int inicializa_pessoa_1(pessoa *p, const char * p_buf) {

	int rc = 1;
	if (!p) {
		return -1;
	}



	memset(p->m_nome, '\0', TAM_NOME);
	const char * _c2 = p_buf;
	strcpy(p->m_nome, _c2);

	_c2 += TAM_NOME;

	p->m_idade = atoi(_c2);

	_c2 += 4;
	p->m_salario = atof(_c2);

	_c2 += 10;
	p->m_sexo = *_c2;

	//memset(p->m_nome, '\0', TAM_NOME);
	//char * _c1 = &(p->m_nome[0]);
	//const char * _c2 = p_buf;
	//while (1) {
	//	if ((*_c2) == ' ') {
	//		break;
	//	}
	//	if ((_c2 - p_buf) == TAM_NOME - 1) {
	//		break;
	//	}
	//	*_c1 = * _c2;
	//	++_c1;
	//	++_c2;
	//}
	//printf("nome = %s\n", p->m_nome);

	//while ((*_c2) == ' ') { ++_c2; }

	//// idade 
	//char _buf_idade[4];
	//memset(_buf_idade, '\0', 4);
	//for (int i = 0; i < 3; ++i) {
	//	_buf_idade[i] = *_c2;
	//	++_c2;
	//}
	//printf("idade s = %s\n", _buf_idade);
	//p->m_idade = atoi(_buf_idade);
	//printf("idade i = %d\n", p->m_idade);

	//// salario
	//char _buf_salario[10];
	//memset(_buf_salario, '\0', 10);
	//for (int i = 0; i < 9; ++i) {
	//	_buf_salario[i] = *_c2;
	//	++_c2;
	//}
	//printf("salario s = %s\n", _buf_salario);
	//p->m_salario = atof(_buf_salario);
	//printf("salario f = %lf\n", p->m_salario);

	////++_c2;
	//p->m_sexo = *_c2;
	//printf("sexo = %c\n", p->m_sexo);
	return 1;

}

int copia_pessoa(pessoa * to, const pessoa * from) {

	if (!to) {
		return -1;
	}

	if (!from) {
		return -2;
	}

	strcpy(to->m_nome, from->m_nome);
	to->m_idade = from->m_idade;
	to->m_salario = from->m_salario;
	to->m_sexo = from->m_sexo;
	return 1;

}

int le_pessoa(pessoa * to, FILE * file) {
	if (file == NULL) { return -1; }
	if (to == NULL) { return -2; }

	char buf[TAM_BUF];
	memset(buf, '\0', TAM_BUF);
	int reads = fread(buf, 1, TAM_BUF, file);
	
	if (feof(file)) { return 0; }

	if (reads != TAM_BUF) { return -3; }

	if (inicializa_pessoa_1(to, buf) != 1) { return -4; }

	return 1;

}