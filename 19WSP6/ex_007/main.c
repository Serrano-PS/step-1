#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define filename "C:/Users/Admin/Documents/canellas@itstep.org/step/C/teste.txt"

int main()
{
	FILE* fp = fopen(filename, "a+");
	if (!fp) {
		printf("Nao consegui abrir o arquivo");
		return 10;
	}

	char * txt0 = "OLA de novo mais uma vez, e so, mais uma, e outra !!!";

	int len = strlen(txt0);

	if (fwrite(txt0, len, 1, fp) != 1) {
		printf("Nao consegui escrever no arquivo");
		fclose(fp);
		return 20;
	}

	fflush(fp);

	fseek(fp, 0, SEEK_SET);

	char buf[10 + 1];
	int rc = fread(buf, 1, 10, fp);
	while ( (rc != EOF) && (rc != 0)) {
		buf[rc] = '\0';
		printf("%s\n", buf);
		rc = fread(buf, 1, 10, fp);
	}


	fclose(fp);
	fp = NULL;


	return 0;
}