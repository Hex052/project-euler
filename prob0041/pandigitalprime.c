#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int is_pandigital(char *str, int len);
void ignore_until_len(FILE* stream, char delim, int target, char **str, size_t *str_len, size_t *chars_read);

int main(int argc, char const *argv[]) {
	char *str = NULL, delim = '\n', *largest = NULL;
	FILE *pstream;
	size_t chars_read, str_len;

	//Check for either 2 or 3 arguments
	if (argc < 2 || argc > 3) {
		fprintf(stderr,
		"Usage: %s file [delim]\n"
		"File must be a list of primes which are separated by \\n by default.\n"
		"These are assumed to be in ascending order.\n"
		, argv[0]);
		exit(1);
	}

	//Open the file and check for existance
	pstream = fopen(argv[1], "r");
	if (pstream == NULL) {
		fprintf(stderr,
		"ERROR: The file %s does not exist.\n"
		"Usage: %s file [delim]\n"
		"File must be a list of primes which are separated by \\n by default.\n"
		"These are assumed to be in ascending order.\n"
		, argv[1], argv[0]);
		exit(1);
	}

	//Set delim (optionally)
	if (argc == 3) {
		if (argv[2][1]) {
			fprintf(stderr,
			"ERROR: The delimiter must be a single character.\n"
			"Usage: %s file [delim]\n"
			"File must be a list of primes which are separated by \\n by default.\n"
			"These are assumed to be in ascending order.\n"
			, argv[0]);
			exit(1);
		}
		delim = argv[2][0];
	}

	//Process file
	do {
		chars_read = getdelim(&str, &str_len, delim, pstream);
		if (chars_read <= 0 || chars_read >= 9)
			break;
		while (chars_read == 2 || chars_read == 3 || chars_read == 4
			|| chars_read == 6 || chars_read == 7) { //All these divisible by 3
			ignore_until_len(pstream, delim, chars_read + 1, &str, &str_len, &chars_read);
		}
		str[--chars_read] = 0;
		if (!is_pandigital(str, chars_read))
			continue;
		free(largest);
		largest = str;
		str_len = 0;
		printf("%s\n", largest);
	} while (chars_read < 10); //No 9-digit pandigital primes, since all are divisible by 3


	printf("\nLargest: %s\n", largest);

	return 0;
}

int is_pandigital(char *str, int len) {
	if (str == NULL)
		return 0;
	bool contained[10] = {0,0,0,0,0,0,0,0,0,0};
	while (*str) {
		if (*str > '0' + len || *str <= '0')
			return 0;
		if (contained[*str - '0'])
			return 0;
		contained[*str - '0'] = 1;
		str++;
	}
	return 1;
}
void ignore_until_len(FILE* stream, char delim, int target, char **str, size_t *str_len, size_t *chars_read) {
	while (*chars_read != target) {
		*chars_read = getdelim(str, str_len, delim, stream);
	}
}
