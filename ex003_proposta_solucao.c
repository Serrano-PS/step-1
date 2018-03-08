
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TAM_PESSOA 50

typedef unsigned short int idade;
typedef double salario;
enum sexo { M, F };

struct pessoa {
	char m_nome[TAM_PESSOA+1];
	idade m_idade;
	enum sexo m_sexo;
	salario m_salario;
};

void imprime_pessoa(const struct pessoa * p) {

	printf("Nome = %s, idade = %d, sexo = %s, salario = %lf\n"
			, p->m_nome
			, p->m_idade
			, (p->m_sexo = M ? "masculino" : "feminino")
			, p->m_salario);

}
/*
void inicializa_pessoa(struct pessoa * p, char * p_nome
		, idade p_idade
		, enum sexo p_sexo
		, salario p_salario) {


	strcpy(p->m_nome, p_nome);
	p->m_idade = p_idade;
	p->m_sexo = p_sexo;
	p->m_salario = p_salario;
}
*/

int main() {

	{
		struct pessoa p1;

		strcpy(p1.m_nome, "Joao das Couves");
		p1.m_idade = 32;
		p1.m_sexo = M;
		p1.m_salario = 4590.13;
		imprime_pessoa(&p1);
	}

	{

	}

	return 0;

}




