#include <stdio.h>
// #include <string.h>
#include <gmp.h>


int main(int argc, char const *argv[]) {
	mpz_t accum, pow, mod;
	mpz_init_set_si(accum, 10405071317);
	mpz_init_set_si(mod, 10000000000);
	mpz_init(pow);
	for (int i = 11; i <= 1000; i++) {
		if (i % 10 == 0)
			continue;
		mpz_set_si(pow, i);
		mpz_powm(pow, pow, pow, mod);
		mpz_add(accum, accum, pow);
		mpz_mod(accum, accum, mod);
	}
	char *str = mpz_get_str(NULL, 10, accum);
	printf("%s\n", str);
	return 0;
}
