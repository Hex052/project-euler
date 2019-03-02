#include <fstream>
#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

//prototypes
bool is_triangular(int num);
bool is_pentagonal(int num);
bool is_hexagonal(int num);

int main(int argc, char const *argv[]) {
	auto start_time = chrono::high_resolution_clock::now();
	//Start stopwatch

	for (long i = 286; i ; i++) {
		long long unsigned tri = (i*i + i)/2;
		if (is_pentagonal(tri) && is_hexagonal(tri)) {
			cout << tri << endl;
			break;
		}
	}


	//Stop stopwatch
	auto stop_time = chrono::high_resolution_clock::now();
	auto nanos = chrono::duration_cast<chrono::nanoseconds>(stop_time - start_time);
	cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}


bool is_triangular(int num) {
	double n = (-1 + sqrt(1 + (8*(double)num))) / 2.0;
	return (n == (int)n);
}
bool is_pentagonal(int num) {
	double n = (1 + sqrt(1 + (24*(double)num))) / 6.0;
	return (n == (int)n);
}
bool is_hexagonal(int num) {
	double n = (1 + sqrt(1 + (8*(double)num))) / 4.0;
	return (n == (int)n);
}
