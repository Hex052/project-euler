#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	long unsigned index = 1000;
	int len = 0;
	char* fibstr = NULL;
	mpz_t fib1, fib2;
	mpz_inits(fib1, fib2, NULL);

	mpz_fib2_ui(fib1, fib2, (long unsigned)index);
	fibstr = mpz_get_str(NULL, 10, fib1);
	len = strlen(fibstr);

	while (len < 1000) {
		mpz_add(fib2, fib1, fib2);
		mpz_swap(fib1, fib2);
		index++;
		free(fibstr);
		fibstr = mpz_get_str(NULL, 10, fib1);
		len = strlen(fibstr);
	}
	//free(fibstr);

	printf("%s\n%d %lu\n", fibstr, len, index);
	return 0;
}
