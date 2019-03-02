#include <iostream>
#include <vector>
#include <gmpxx.h>
#include "../general/primes.hpp"

using namespace std;

void rotate(unsigned long &x);
int contains(vector<mpz_class> const v, int i);
int contains(vector<unsigned long> const v, unsigned long const search);

int main(int argc, char const *argv[]) {
	vector<unsigned long> plist_v;
	int count = 0;
	plist_gen_stream("plist.txt", plist_v);
	for (int i = 0; plist_v[i] < 1000000; i++) {
		unsigned long current = plist_v[i];
		do {
			rotate(current);
			if (!contains(plist_v, current)) {
				goto circular_not_prime;
			}
		} while(current != plist_v[i]);
		count++;
		circular_not_prime:;
	}
	cout << count << endl;
}

int contains(vector<mpz_class> const v, int const search) {
	for (unsigned i = 0; i < v.size(); i++) {
		if (v[i] == search)
			return 1;
		if (v[i] > search)
			return 0;
	}
	return 0;
}
int contains(vector<unsigned long> const v, unsigned long const search) {
	for (unsigned i = 0; i < v.size(); i++) {
		if (v[i] == search)
			return 1;
		if (v[i] > search)
			return 0;
	}
	return 0;
}

void rotate(unsigned long &x) {
	int len = 0, least = x % 10, temp;
	temp = x /= 10;
	while (temp) {
		len++;
		least *= 10;
		temp /= 10;
	}
	x += least;
}
