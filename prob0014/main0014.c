#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


int main(int argc, char const *argv[]) {
	long unsigned longest = 0, length = 0;
	for (long unsigned i = 3; i < 1000000; i++) {
		long unsigned curr = i, currlen = 1;
		while (curr != 1) {
			if (curr % 2 == 0)
				curr /= 2;
			else
				curr = (3 * curr) + 1;
			currlen++;
		}
		if (currlen > length) {
			length = currlen;
			longest = i;
			printf("Chain of length %ld starting at %ld\n", length, longest);
		}
	}
	return 0;
}
