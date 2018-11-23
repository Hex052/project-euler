#include <stdio.h>

int main(int argc, char const *argv[]) {
	unsigned int count = 0, total = 0, fibarr[50];
	fibarr[0] = 1; fibarr[1] = 2;
	printf("[ 1, 2");
	for (int i = 2; i < 36; i++) {
		fibarr[i] = fibarr[i-1] + fibarr[i-2];
		printf(", %d", fibarr[i]);
	}
	puts("]\n");

	for (int i = 0; fibarr[i] < 4000000; i++) {
		if (!(fibarr[i] % 2)) {
			total += fibarr[i];
		}
		count++;
	}
	printf("\nTotal, count:\n%d, %d\n", total, count);
	return 0;
}
