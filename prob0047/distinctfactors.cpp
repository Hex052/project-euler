#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <cmath>

//prototypes
bool fourdistinctfactors(unsigned int num);

//global variables
std::set<unsigned int> pset;
std::set<unsigned int>::iterator pbegin, pend;

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	std::ifstream nplist("plist.txt");
	unsigned int extr;
	while (!nplist.eof()) {
		nplist >> extr;
		pset.insert(extr);
	}
	nplist.close();
	pbegin = pset.begin();
	pend = pset.end();

	auto load_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(load_time - start_time);
	std::cerr << "Load took " << nanos.count() << " ns\n\n";


	//Stores as a bit field the results of the last tests
	unsigned char primes = 0;
	for (unsigned int i = *pbegin + 1; i < 259373; i++) {
		primes <<= 1;
		if (pset.count(i)) {
			//Skip primes, we are looking for composites.
			// primes |= 0;
			// Don't need to or in a 0, left shift already does that
			continue;
		}

		// If the last three weren't prime
		if ((primes & 0b1110) == 0b1110) {
			if (fourdistinctfactors(i)) {
				primes |= 1;
				if (fourdistinctfactors(i-1) && fourdistinctfactors(i-2) && fourdistinctfactors(i-3)) {
					std::cout << i << '\t' << i-3 << '\n';
					break;
				}
			}
			//Don't OR in 1, as did not have 4 distinct factors, despite being prime
			continue;
		}
		else {
			primes |= 1;
		}
	}

	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	// nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - load_time);
	std::cerr << "\nSearch took " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - load_time).count() << " ns\n"
	// nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	"Execution took " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count() << " ns\n";
	return 0;
}

bool fourdistinctfactors(unsigned int num) {
	unsigned int count = 0;

	for (auto prime = pbegin; num >= *prime; prime++) {
		if (num % *prime == 0) {
			count++;
			if (count == 4) {
				return true;
			}
			do {
				num /= *prime;
			} while (num % *prime == 0);
		}
	}

	return false;
}
