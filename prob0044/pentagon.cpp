/*
 * I had no idea where the upper limit was, so I just tried a large upper bound
 * until I got a result (in this case only one result).
 * But hey, it works.
 */
#include <fstream>
#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

//prototypes
long long pentagon_num(int n);
bool is_pentagonal(int num);

int main(int argc, char const *argv[]) {
	auto start_time = chrono::high_resolution_clock::now();
	//Start stopwatch

	long long diff = 0;
	for (int i = 2; i < 10000; i++) {
		long long p1 = pentagon_num(i), p2;
		for (int j = 1; j < i; j++) {
			p2 = pentagon_num(j);
			if (is_pentagonal(p1 - p2) && is_pentagonal(p1 + p2)) {
				if (diff == 0) {
					diff = p1 - p2;
					cout << "P1: " << p1 << " (" << i << ") P2: " << p2 << " (" << j << ") Differance: " << diff << endl;
				}
				else if (p1 - p2 < diff) {
					diff = p1 - p2;
					cout << "P1: " << p1 << " (" << i << ") P2: " << p2 << " (" << j << ") Differance: " << diff << endl;
				}
			}
		}
	}

	cout << diff << endl;

	//Stop stopwatch
	auto stop_time = chrono::high_resolution_clock::now();
	auto nanos = chrono::duration_cast<chrono::nanoseconds>(stop_time - start_time);
	cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}


long long pentagon_num(int n) {
	return (n * (3*n - 1)/2);
}
bool is_pentagonal(int num) {
	double n = (1 + sqrt(1 + (24*(double)num))) / 6.0;
	return (n == (int)n);
}
