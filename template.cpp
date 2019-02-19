#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//prototypes
//bool is_pandigital(string const &str);

int main(int argc, char const *argv[]) {
	auto start_time = chrono::high_resolution_clock::now();
	//Start stopwatch



	//Stop stopwatch
	auto stop_time = chrono::high_resolution_clock::now();
	auto nanos = chrono::duration_cast<chrono::nanoseconds>(stop_time - start_time);
	cerr << "\nExecution took " << nanos.count() << " ns\n";

	return 0;
}
