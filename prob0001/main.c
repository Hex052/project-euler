#include <stdio.h>

int main(int argc, char const *argv[]) {
	int total = 0;
	for (int i = 1; i < 1000; i++) {
		if (!(i % 3) || !(i % 5))
			total += i;
	}
	printf("%d\n", total);
	return 0;
}
