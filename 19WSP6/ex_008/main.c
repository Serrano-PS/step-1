#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pessoa.h"
#include "lista_pessoa.h"

int le_arq_pessoas(const char * p_file_name, no * * lista);
int listar(const no * lista);
int inserir(const char * p_file, no * lista);
int pesquisar(const no * lista);

int main(int argc, char ** argv) {
	int rc = 1;

	if (argc != 2) {
		printf("Falta o nome do arquivo\n");
		rc = 10; goto out;
	}

	// recuperando as pessoas no arquivo
	no * lista = NULL;
	rc = le_arq_pessoas(argv[1], &lista);
	if (rc != 1) {
		printf("Nao leu o arquivo: %d\n", rc);
		rc = 30; goto out;
	}

	int op = -1;
	rc = 1;
	while (1) {
		printf("Escolha uma opcao: \n");
		printf("\t1 - Listar\n");
		printf("\t2 - Inserir\n");
		printf("\t3 - Pesquisar\n");
		printf("\t0 - Sair\n");
		scanf("%d", &op);
		switch (op) {
		case 0:
			return 0;
		case 1:
			rc = listar(lista);
			if (rc != 1) {
				return rc;
			}
			break;
		case 2:
			rc = inserir(argv[1], lista);
			if (rc != 1) {
				return rc;
			}
			break;
		case 3:
			rc = pesquisar(lista);
			if (rc != 1) {
				return rc;
			}
			break;
		default:
			printf("%d nao eh opcao valida\n", op);
		}
	}

out:
	return (rc == 1 ? 0 : rc);
}



int le_arq_pessoas(const char * p_file_name, no * * lista) {
	int rc = 1;

	FILE * file = fopen(p_file_name, "r");

	if (file == NULL) { rc = -1; goto out; }

	*lista = cria_lista_1();
	if ((*lista) == NULL) { rc = -2; goto out; }

	rc = le_pessoa(&((*lista)->val), file);
	if (rc == 0) {
		exclui_no(lista);
		rc = 1;
		goto out;
	}
	if (rc != 1) {
		exclui_no(lista);
		goto out;
	}

	while (1) {

		no *_novo = ins_antes_1(*lista);
		if (_novo == NULL) { rc = -3; goto out; }

		rc = le_pessoa(&(_novo->val), file);
		if (rc == 0) { exclui_no(&_novo); rc = 1; goto out; }
		if (rc != 1) { exclui_no(&_novo); rc = -4;  goto out; }
	}
out:
	if (file) {
		fclose(file);
	}
	return rc;
}


int listar(const no * lista) {
	return 1;
}

int inserir(const char * p_file, no * lista) {
	return 1;
}

int pesquisar(const no * lista) {
	return 1;
}
