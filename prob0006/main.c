#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	long long sum = 5050*5050;
	for (int i = 1; i <= 100; i++)
		sum -= i*i;

	printf("%lli\n", sum);
	return 0;
}
