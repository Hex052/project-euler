#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <math.h>
//#include <errno.h>

int main(int argc, char const *argv[]) {
	int a, b, c, num1, num2, pal;
	for (a = 9; a >= 0; a--) {
		for (b = 9; b >= 0; b--) {
			for (c = 9; c >= 0; c--) {
				pal = 100001 * a + 10010 * b + 1100 * c;
				for (num1 = 999; num1 >= 100; num1--) {
					num2 = pal / num1;
					if (num2 >= 100 && num2 <=999 && num1 * num2 == pal) {
						printf("%i %i\n", num1, num2);
					}
				}
			}
		}
	}

	return 0;
}
