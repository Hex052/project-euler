#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define fifth(i) i*i*i*i*i

int main(int argc, char const *argv[]) {
	FILE* logfile = NULL;
	if (argc > 1) {
		logfile = fopen(argv[1], "w");
	}
	unsigned grandtot = 0;
	for (unsigned j = 2; j < 354294; j++) {
		unsigned tot = 0, curr = j;
		while (curr) {
			unsigned digit = curr%10;
			tot += fifth(digit);
			curr /= 10;
		}
		if (logfile) {
			fprintf(logfile, "num:%d pow:%d\n", j, tot);
		}
		if (tot == j) {
			printf("%d\n", j);
			grandtot += tot;
		}
	}
	printf("Grand Total: %d\n", grandtot);
	return 0;
}
