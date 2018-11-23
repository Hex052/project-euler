#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	a^2 + b^2 = c^2 AND a + b + c = 1000
	so:
	500000 = a * b - 1000 * a - 1000 * b
*/

int main(int argc, char const *argv[]) {
	for (int a = 1; a < 500; a++){
		for (int b = 1; b < 500; b++){
			if ((a * b) - (1000 * a) - (1000 * b) + 500000 == 0){
				printf("%i", a * b * (1000 - a - b));
				return 0;
			}
			printf("%i\n", a + b);
		}
	}

	return 0;
}
