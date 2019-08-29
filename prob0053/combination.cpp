#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

#include <gmpxx.h>

//prototypes
//bool is_pandigital(string const &str);

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	mpz_class fac_arr[100];
	for (int i = 0; i < 100; i++) {
		mpz_fac_ui(fac_arr[i].get_mpz_t(), i+1);
	}

	//Told that the first that exceeds 1000000 is 23
	int count = 0;
	for (int r, n = 23; n <= 100; n++) {
		for (r = 1; r < n; r++) {
			if (fac_arr[n-1] / fac_arr[r-1] / fac_arr[n-r-1] > 1000000) {
				count++;
			}
		}
	}

	std::cout << count << '\n';

	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}
