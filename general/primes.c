#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef h_primes
#define  h_primes

FILE* plist_file = NULL;
unsigned long long* plist_arr = NULL;
size_t plist_len = 0;

int isprime(const unsigned long long num) {
	const long long numroot = (unsigned long long)sqrtl((long double)num);
	if (num < 2)
		return 0;
	if (plist_len == 0)
	for (unsigned i = 0; i < plist_len; i++) {
		if (plist_arr[i] > numroot)
			//Only need to check up to the square root of num
			return 1;
		if (!(num % plist_arr[i]))
			return 0;
	}
	return 1;
}

void plist_gen_target(const unsigned long long num) {

}
//Fill the array from the file
void plist_gen_file(void) {
	if (!plist_file) return;
	free(plist_arr);
	plist_len = 0;

	char *line = NULL; size_t n = 0; int len;
	while ((len = getline(&line, &n, plist_file))) {
		unsigned long long num_from_file = strtoull(line, NULL, 10);
		if (!num_from_file) continue;
		plist_arr = realloc(plist_arr, (plist_len + 1) * sizeof(unsigned long long));
		if (plist_arr == NULL) {
			fprintf(stderr, "Reallocating memory failed\n");
			exit(1);
		}
		plist_arr[plist_len++] = num_from_file;
	}
	free(line);
}
void plist_gen_len(const unsigned long long num) {

}

#endif
