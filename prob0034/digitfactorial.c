#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned fact(const unsigned in) {
	int running = 1;
	for (unsigned i = in; i >= 2; i--) {
		running *= i;
	}
	return running;
}

int main(int argc, char const *argv[]) {
	char* str_out = malloc(sizeof(char) * 240);
	FILE* logfile = NULL;
	unsigned grand_tot = 0;
	if (argc > 1) {
		logfile = fopen(argv[1], "w");
	}
	for (unsigned i = 10; i <= 2540160; i++) {
		unsigned curr = i, digit, digit_fact;
		char digit_str[12];
		unsigned tot = 0;
		str_out[0] = 0;
		while (curr) {
			digit = curr % 10;
			curr /= 10;
			//if (!digit)
			//	continue;
			digit_fact = fact(digit);
			tot += digit_fact;
			if (curr)
				snprintf(digit_str, 12, "%u + ", digit_fact);
			else
				snprintf(digit_str, 12, "%u", digit_fact);
			strncat(str_out, digit_str, 240);
		}
		if (tot != i) {
			if (logfile) fprintf(logfile, "%u != %s\n", i, str_out);
		}
		else {
			grand_tot += tot;
			printf("%u = %s\n", i, str_out);
		}
	}
	fprintf(stderr, "Grand Total: %u\n", grand_tot);
	return 0;
}
