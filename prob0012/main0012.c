#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

long long unsigned factors[600] = {};

long long unsigned addFactor(const long long unsigned toAdd, long long unsigned len){
	while (factors[len])
		len++;
	//len should now be the total number of primes in the array. (add a NULL)

	factors[len++] = toAdd;
	return len;
}

int main(int argc, char const *argv[]) {
	long long unsigned triangle = 0, i = 1, len = 0, rtri;
	while (!(factors[500])) {
		triangle += i++;
		rtri = (long long unsigned)sqrtl((long double)triangle);
		memset(factors, 0, 600 * sizeof(long long unsigned));
		len = 0;
		for (long long unsigned j = 1; j <= rtri; j++) {
			if(!(triangle % j)) {
				len = addFactor(triangle / j, len);
				if (triangle / j != j)
					len = addFactor(j, len);
			}
		}
	}
	printf("%llu\n", triangle);
	return 0;
}
