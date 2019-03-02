#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "../general/primes.hpp"

using namespace std;
#define CHAR_ARR_LEN 10

bool prime_left_truncate(char *c, vector<unsigned long> &v);
bool prime_right_truncate(char *c, vector<unsigned long> &v);

int main(int argc, char const *argv[]) {
	//11 is the 4th prime
	int count = 0, total = 0;
	char str[CHAR_ARR_LEN] = "3797";
	//Fill prime arr, then rewind for use.
	ifstream plist_stream("plist.txt");
	vector<long unsigned> plist_v;
	plist_gen_stream(plist_stream, plist_v);
	plist_stream.clear();
	plist_stream.seekg(0);

	//discard first 4 primes
	for (int i = 0; i < 4; i++)
		plist_stream.ignore(10, '\n');

	for (int i = 0; count != 11; i++) {
		plist_stream.getline(str, CHAR_ARR_LEN);
		if (!(prime_left_truncate(str, plist_v) && prime_right_truncate(str, plist_v)))
			continue;

		count++;
		cout << str << endl;
		total += strtoul(str, NULL, 10);
	}
	cout << "Total : " << total << endl;
	return 0;
}

//Return true if all are prime
bool prime_left_truncate(char *c, vector<unsigned long> &v) {
	for (char *ptr = c; *ptr != '\0'; ptr++) {
		if (!is_prime(strtoul(ptr, NULL, 10), v)) {
			return false;
		}
	}
	return true;
}
bool prime_right_truncate(char *c, vector<unsigned long> &v) {

	for (unsigned long i = strtoul(c, NULL, 10); i > 0; i /= 10) {
		if (!is_prime(i, v)) {
			return false;
		}
	}
	return true;
}
