#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

int ctoi(char const c) {
	if (c > '9' || c < '0')
		return -1;
	else
		return c - '0';
}

int main(int argc, char const *argv[]) {
	mpz_t num;
	char* str = NULL;
	unsigned long total = 0;
	mpz_init_set_si(num, 1);
	mpz_mul_2exp(num, num, (mp_bitcnt_t)1000);
	str = mpz_get_str(str, 10, num);
	printf("%s\n", str);
	for (int i = 0; str[i]; i++) {
		total += ctoi(str[i]);
	}
	printf("%lu\n", total);
	return 0;
}
