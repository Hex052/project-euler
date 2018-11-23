#include <stdio.h>
#include <stdlib.h>

int *factors[25];

void primeFactorization(int num) {
	int i = 2, j = 0;
	while (num != 1){
		if (num % i == 0){
			num /= i;
			factors[j] = &i;
			j++;
		}
		i++;
	}
}

int main(int argc, char const *argv[]) {
//	int temp, a, b, c, palin;
//	for (a = 9; a >= 0; a--) {
//		for (b = 9; b >= 0; b--) {
//			for (c = 9; c >= 0; c--) {
//				palin = 100001 * a + 10010 * b + 1100 * c; //gives a palindromic number "abccba"
				primeFactorization(atoi(argv[1]));
//			}
//		}
//	}
	for (int i = 0; i < 25; i++) {
		printf("%i ", *factors[i]);
	}
	printf("\n");
	return 0;
}
