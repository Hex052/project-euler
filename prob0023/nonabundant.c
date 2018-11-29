#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
	int abundants[8192], len = 0;
	long unsigned total = 0;
	char absums[28213];
	memset(&(abundants[0]), 0, sizeof(int)*8192);
	memset(&(absums[0]), 1, sizeof(char)*28213);
	
	//Determine which are abundant
	for (int i = 2; i < 28123; i++) {
		int *divs = divisors(i), divsum = arrsum(divs) - i;
		if (divsum > i)
			abundants[len++] = i;
		free(divs);
	}
	//Determine which can be made up of sums of abundants
	for (int i = 0; abundants[i] + abundants[i+1] < 28123; i++) {
		for (int j = i; abundants[i] + abundants[j] < 28123; j++) {
			absums[abundants[i] + abundants[j]] = 0;
		}
	}
	//Turn the array of bools into a total
	for (int i = 1; i < 28123; i++) {
		if (absums[i])
			total += i;
	}
	printf("%lu\n", total);
	return 0;
}
