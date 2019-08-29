#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

//prototypes
//bool is_pandigital(string const &str);

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch



	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}
