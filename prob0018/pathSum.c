#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

#define ROWS 15
#define NUM_CHARS_PER_INT 3

//Read next line from file and return an array of integers.
//Relys on the integers all being the same amount of characters wide.
int *readline(FILE *in) {
	size_t len = 80;
	char *line = NULL, *cp = NULL;
	int charsRead, *out;
	if (feof(in))
		return NULL;
	if ((charsRead = getline(&line, &len, in)) == -1) {
		fprintf(stderr, "Could not allocate memory\n");
		exit(2);
	}
	cp = line;
	out = malloc(sizeof(int) * charsRead / NUM_CHARS_PER_INT);
	for (int i = 0; i < charsRead / NUM_CHARS_PER_INT; i++) {
		out[i] = atoi(strtok(cp, " \n"));
		cp = NULL;
	}
	free(line);
	return out;
}

int main(int argc, char const *argv[]) {
	FILE *input_file, *output_file = NULL;
	if (argc < 2 || argc > 3) {
		fprintf(stderr, "Arguments: input_file [output_file]\n" "If no output file is given, no o");
		exit(1);
	}
	if (argc == 3)
		output_file = fopen(argv[2], "w");
	input_file = fopen(argv[1], "r");
	if (input_file == NULL || (output_file == NULL && argc == 3)) {
		fprintf(stderr, "Couldn't open file\n");
		exit(1);
	}

	int *triangle[ROWS];
	for (int i = 0; i < ROWS; i++) {
		triangle[i] = readline(input_file);
	}


	if (output_file)
		fprintf(output_file, "%d\n", triangle[0][0]);
	for (int i = 1, j = 0; i < ROWS; i++, j = 0) {
		for (;;) {
			if (j == 0)
				triangle[i][j] += triangle[i-1][j];
			else if (j == i) {
				triangle[i][j] += triangle[i-1][j-1];
				if (output_file)
					fprintf(output_file, "%d\n", triangle[i][j]);
				break;
			}
			else if (triangle[i-1][j] > triangle[i-1][j-1])
				triangle[i][j] += triangle[i-1][j];
			else
				triangle[i][j] += triangle[i-1][j-1];
			if (output_file)
				fprintf(output_file, "%d ", triangle[i][j]);
			j++;
		}
	}
	int largest = 0;
	for (int i = 0; i < ROWS; i++) {
		if (triangle[ROWS-1][i] > largest)
			largest = triangle[ROWS-1][i];
	}
	printf("The largest path sums to %d\n", largest);

	fclose(input_file);
	if (output_file)
		fclose(output_file);
	return 0;
}
