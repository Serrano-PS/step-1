#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	double d = 456.2451;

	char buf[9 + 1];
	memset(buf, '\0', 10);

	sprintf(buf, "%09.2lf", d);

	printf("buf = %s\n", buf);

	return 0;
}
