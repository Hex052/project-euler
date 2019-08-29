#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

#include <gmpxx.h>

#define MAX_POWERS 100

//prototypes
int strdigitsum(char *str);

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	char str[256];
	int maxsum = 1, currsum;
	mpz_class num;

	for (int a = 2, b; a < MAX_POWERS; a++) {
		num = a; // Assign here, and multiply at end of for loop by a again. Faster than repeated powers.
		// std::cout << a << '\n';
		for (b = 1; b < MAX_POWERS; b++, num *= a) {
			// mpz_ui_pow_ui(num.get_mpz_t(), a, b);
			mpz_get_str(str, 10, num.get_mpz_t());
			currsum = strdigitsum(str);
			// std::cout << a << '\t' << b << '\t' << currsum << '\t' << str << '\n';
			if (currsum > maxsum) {
				maxsum = currsum;
				std::cout << maxsum << '\n';
			}
		}
	}

	// mpz_get_str(str, base, op);

	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}


int strdigitsum(char *str) {
	int sum = 0;
	if (str == NULL) {
		return 0;
	}
	while (*str) {
		sum += *str - '0';
		str++;
	}
	return sum;
}
