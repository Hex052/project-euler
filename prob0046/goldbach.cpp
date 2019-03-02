#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include "../general/primesxx.h"

using namespace std;

//prototypes
bool is_goldbach(unsigned int num, vector<long unsigned> &v);
bool twicesquare(unsigned int num);

int main(int argc, char const *argv[]) {
	auto start_time = chrono::high_resolution_clock::now();
	//Start stopwatch

	ifstream plist_stream("plist.txt");
	vector<long unsigned> plist_v;
	plist_gen_stream(plist_stream, plist_v);
	plist_stream.clear();
	plist_stream.close();

	//Stop stopwatch
	auto stop_time = chrono::high_resolution_clock::now();
	auto nanos = chrono::duration_cast<chrono::nanoseconds>(stop_time - start_time);
	cerr << "\nTook " << nanos.count() << " ns to read primes\n";


	for (unsigned int comp = 37; comp > 30; comp += 2) {
		if (is_prime(comp, plist_v))
			continue;
		if (!is_goldbach(comp, plist_v)) {
			cout << "Found " << comp << endl;
			break;
		}
	}

	//Stop stopwatch
	stop_time = chrono::high_resolution_clock::now();
	nanos = chrono::duration_cast<chrono::nanoseconds>(stop_time - start_time);
	cerr << "\nExecution took " << nanos.count() << " ns\n";

	return 0;
}

bool is_goldbach(unsigned int num, vector<long unsigned> &v) {
	for (unsigned i = 0; v[i] < num; i++) {
		if (twicesquare(num - v[i])) {
			return true;
		}
	}
	return 0;
}
bool twicesquare(unsigned int num) {
	unsigned int test;
	for (unsigned i = 1; ; i++) {
		test = 2*i*i;
		if (test == num)
			return true;
		if (test > num)
			return false;
	}
}
