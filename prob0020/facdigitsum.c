#include <stdio.h>
#include <gmp.h>

int main(int argc, char const *argv[]) {
	char *digitstr = NULL;
	int i = 0, sum = 0;
	mpz_t factorial;
	mpz_init(factorial);
	mpz_fac_ui(factorial, (unsigned long int)100);
	digitstr = mpz_get_str(NULL, 10, factorial);
	while (digitstr[i]) {
		sum += digitstr[i++] - '0';
	}
	printf("%d\n", sum);
	mpz_clear(factorial);
	return 0;
}
