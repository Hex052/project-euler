#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

//Returns a zero-terminated int array of divisors
int *divisors(int const num) {
	int len = 3, *list = malloc(len * sizeof(int));
	int const root = (int)sqrt((double)num);
	list[0] = 1; list[1] = num;
	for (int i = 2; i <= root; i++) {
		if (num % i == 0) {
			if (num / i != i) { //Two different factors
				len += 2;
				list = realloc(list, len * sizeof(int));
				if (list == NULL) {
					fprintf(stderr, "Error allocating memory\n");
					exit(1);
				}
				list[len-3] = i;
				list[len-2] = num / i;
			}
			else { // i * i == num
				len += 1;
				list = realloc(list, len * sizeof(int));
				if (list == NULL) {
					fprintf(stderr, "Error allocating memory\n");
					exit(1);
				}
				list[len-2] = i;
			}
		}
	}
	list[len-1] = 0;
	return list;
}
int arrsum(int const *arr) {
	int sum = 0;
	for (int i = 0; arr[i]; i++) {
		sum += arr[i];
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int amicablesum = 0;
	for (int i = 2; i < 10000; i++) {
		int *divs = divisors(i);
		int divsum = arrsum(divs) - i;
		free(divs);
		if (divsum != i) {
			divs = divisors(divsum);
			if (i == arrsum(divs) - divsum) {
				amicablesum += divsum;
				printf("Pair: %d and %d\n", i, divsum);
			}
			free(divs);
		}
	}
}
