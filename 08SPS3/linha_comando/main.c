#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obtem_indices(const char * path, int * i_barra, int * i_ponto);
void copia_nome(const char * path, char * dest, int i_barra, int i_ponto);
void sintaxe(const char * path);

int main(int argc, char * * argv) {

	if (argc != 4) {
		sintaxe(argv[0]);
		return 1;
	}
	
	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	int i = atoi(argv[1]);	
	printf("i = %d\n", i);

	double d = atof(argv[2]);
	printf("d = %lf\n", d);

	return 0;
}


void obtem_indices(const char * path, int * i_barra, int * i_ponto) {
	int len = strlen(path);

	for (int i = len - 1; i > 0; --i) {
		if (path[i] == '.') {
			*i_ponto = i;
		}
		if (path[i] == '\\') {
			*i_barra = i + 1;
			break;
		}
	}
}

void copia_nome(const char * path, char * dest, int i_barra, int i_ponto) {
	int len = i_ponto - i_barra;
	for (int i = 0; i < len; ++i) {
		dest[i] = path[i_barra + i];
	}
	dest[len] = '\0';
}

void sintaxe(const char * path) {
	int i_ponto = -1;
	int i_barra = 1;

	obtem_indices(path, &i_barra, &i_ponto);

	if ((i_barra == -1) || (i_ponto == -1)) {
		printf("Erro obtendo indices do nome do programa\n");
		return;
	}

	int len = i_ponto - i_barra + 1;
	char * nome = (char *)malloc(len);
	if (nome == NULL) {
		printf("Erro alocando nome do programa");
		return;
	}

	copia_nome(path, nome, i_barra, i_ponto);

	printf("Sintaxe: %s <int> <double> <string> \n", nome);
	printf("\tonde <int> eh isso\n");
	printf("\tonde <double> eh aquilo\n");
	printf("\tonde <string> eh aquilo-outro\n");

	free(nome);
	nome = NULL;
}