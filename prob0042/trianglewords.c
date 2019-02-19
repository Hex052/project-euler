#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
int lettersum(char const *str);
int is_triangle(int const val);

int main(int argc, char const *argv[]) {
	char *wordarr[] = { //A *really* cheaty way of doing this. I got tired of splitting strings.
#include "p042_words.txt"
	, NULL};

	FILE *log = NULL;
	if (argc > 1) {
		log = fopen(argv[1], "w");
	}

	int val, tricount = 0;
	for (int i = 0; wordarr[i] != NULL; i++) {
		// printf("1\n");
		val = lettersum(wordarr[i]);
		if (is_triangle(val)) {
			tricount++;
		}
		if (log != NULL) fprintf(log, "%s %d\n", wordarr[i], val);
	}
	printf("%d\n", tricount);

	return 0;
}

int lettersum(char const *str) {
	int tot = 0;
	if (str == NULL)
		return 0;
	while (*str) {
		tot += (*str) - '@';
		str++;
	}
	return tot;
}
int is_triangle(int const val) {
	switch (val) {
		case 1:
		case 3:
		case 6:
		case 10:
		case 15:
		case 21:
		case 28:
		case 36:
		case 45:
		case 55:
		case 66:
		case 78:
		case 91:
		case 105:
		case 120:
		case 136:
		case 153:
		case 171:
		case 190:
			return 1;
		default:
			return 0;
	}
}
