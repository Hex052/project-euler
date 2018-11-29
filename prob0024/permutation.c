#include <stdio.h>

void swapchar(char *a, char *b) { //pointers to single characters, not to strings.
	char k = *a;
	*a = *b;
	*b = k;
	return;
}
int main(int argc, char const *argv[]) {
	char perm[] = "0123456789";
	int N = 10;
	int i, j;
	for (int count = 1; count < 1000000; count++) {
		i = N - 1; j = N;

		while (perm[i - 1] >= perm[i]) {
			i--;
		}
		while (perm[j - 1] <= perm[i - 1]) {
			j--;
		}

		swapchar(&perm[i - 1], &perm[j - 1]);
		i++; j = N;

		while (i < j) {
			swapchar(&perm[i - 1], &perm[j - 1]);
			i++;
			j--;
		}
	}


	printf("%s\n", perm);
	return 0;
}

/*
 * This is an algorithm copied from
 * https://www.mathblog.dk/project-euler-24-millionth-lexicographic-permutation/
 * Understood through use of a deubugger. Solved with pen-and-paper first, though
 * I wanted to understand an algorithm, as that was probably the point of the problem.
 */
