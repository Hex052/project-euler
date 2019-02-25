#include <stdio.h>
#include <stdlib.h>

void swapchar(char *a, char *b) { //pointers to single characters, not to strings.
	char k = *a;
	*a = *b;
	*b = k;
	return;
}
int str3_toi(char *str) {
	return ((*str - '0') * 100) + ((*(str+1) - '0') * 10) + (*(str + 2) - '0');
}

int main(int argc, char const *argv[]) {
	char perm[] = "0123456789";
	int primes[] = {2,2,3,5,7,11,13,17,19};
	long sum = 0, num;
	int N = 10;
	int i, j;
	int divisible;
	for (int count = 0; count < 3628800; count++) {
		i = N - 1; j = N;

		while (perm[i - 1] >= perm[i]) {
			i--;
		}
		while (perm[j - 1] <= perm[i - 1]) {
			j--;
		}

		swapchar(&perm[i - 1], &perm[j - 1]);
		i++; j = N;

		while (i < j) {
			swapchar(&perm[i - 1], &perm[j - 1]);
			i++;
			j--;
		}

		/* Check for divisiblility */
		num = strtol(perm, NULL, 10);
		divisible = 1;
		for (int i = 1; i <= 7; i++) {
			if (str3_toi(perm + i) % primes[i] != 0) {
				divisible = 0;
				break;
			}
		}
		if (divisible) {
			sum += num;
			printf("Found %ld\n", num);
		}
	}
	printf("Sum: %ld\n", sum);
}

/* Essentially copied from problem 24 */
