#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extrai_nome_pgm_1(char * path, char * nome);
char * extrai_nome_pgm_2(char * path);

/*
Retorna o indice onde começa o nome do pgm dentro de argv[0]
    0123456789ABC 
Ex: c:\a\pgm0.exe

Vai retornar 5

*/
int pos_inicio_nome(char * path);

/*
Copiar os caracteres de 'path' desde 'pos' até 'strlen(path)' 
para 'dest'
*/
void substr(char * path, int ini, int fim, char * dest);

int main(int argc, char * * argv) {

	/*printf("argc = %d, argv[0] = %s\n", argc, argv[0]);*/

	if (argc != 4) {

		/*
		char nome[20 + 1];
		memset(nome, '\0', 20 + 1);
		extrai_nome_pgm(argv[0], nome);

		printf("Sintaxe: %s <inteiro> <double> <string>\n"
		, nome);
		*/

		/* NÃO SE DEVE FAZER!!!

		char * nome = extrai_nome_pgm_2(argv[0]);

		printf("Sintaxe: %s <inteiro> <double> <string>\n"
				, nome);

		free(nome);
		
		*/

		/*
		int pos = pos_inicio_nome(argv[0]);
		char * dest = (char *)malloc(strlen(argv[0]) - pos + 1);
		substr(argv[0], pos, strlen(argv[0]), dest);
		printf("Sintaxe: %s <inteiro> <double> <string>\n"
				, nome);
		free(dest);
		*/
		return 1;
	}

	for (int i = 1; i < argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	int i = atoi(argv[1]);

	double d = atof(argv[2]);

	printf("i = %d, d = %0*lf\n", i, 2, d);

	return 0;
}
