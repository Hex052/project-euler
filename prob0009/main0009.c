#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int a, b, c;
	for (a = 1; a < 500; a++) {
		b = (-500000 / (1000 - a)) + 1000;
		c = 1000 - a - b;
		if (a*a + b*b == c*c) {
			printf("a = %i  b = %i  c = %i   abc = %i\n", a, b, c, a * b * c);
		}
	}
	return 0;
}
