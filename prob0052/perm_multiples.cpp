#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

#include "../general/digits.h"

#define MAX_MULT 6
#define DIGIT_BASE 10
#define MAX_FIND 10

//prototypes
bool comparedigitcount(int const *a, int const *b, int const base);

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	unsigned num = 1, multiplier, prod;
	//! The total of the digits in num
	unsigned digit_tot;
	//! The digit count
	int count_num[DIGIT_BASE], count_prod[MAX_MULT+1][DIGIT_BASE];
	for (int found = 0; found < MAX_FIND; num++) {
		digit_tot = digitsum(num, DIGIT_BASE);
		for (multiplier = 2; multiplier <= MAX_MULT; multiplier++) {
			prod = num * multiplier;
			if (digit_tot != digitsum(prod, DIGIT_BASE)) {
				break;
			}
			if (multiplier == 2) {
				digitcount(num, DIGIT_BASE, count_num);
			}
			digitcount(prod, DIGIT_BASE, count_prod[multiplier]);
			if (!comparedigitcount(count_num, count_prod[multiplier], DIGIT_BASE)) {
				break;
			}
			else if (multiplier == MAX_MULT) {
				std::cout << num << '\t' << prod << '\n';
				found++;
			}
		}

	}


	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}

bool comparedigitcount(int const *a, int const *b, int const base) {
	for (int i = 0; i < base; i++)
		if (a[i] != b[i])
			return false;
	return true;
}
