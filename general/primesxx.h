#ifndef header_primesxx
#define header_primesxx
#include <vector>
#include <fstream>
#include <gmpxx.h>


using namespace std;
void plist_gen_stream(string str, vector<mpz_class> &v);
void plist_gen_stream(ifstream &stream, vector<mpz_class> &v);
void plist_gen_stream(string str, vector<unsigned long> &v);
void plist_gen_stream(ifstream &stream, vector<unsigned long> &v);
bool is_prime(unsigned long const i, vector<unsigned long> &v);



void plist_gen_stream(string str, vector<mpz_class> &v) {
	ifstream stream(str);
	plist_gen_stream(stream, v);
	stream.close();
}
void plist_gen_stream(ifstream &stream, vector<mpz_class> &v) {
	string line;
	while (getline(stream, line)) {
		mpz_class next(line);
		v.push_back(next);
	}
}
void plist_gen_stream(string str, vector<unsigned long> &v) {
	ifstream stream(str);
	plist_gen_stream(stream, v);
	stream.close();
}
void plist_gen_stream(ifstream &stream, vector<unsigned long> &v) {
	string line;
	while (getline(stream, line)) {
		v.push_back(stoul(line));
	}
}

bool is_prime(unsigned long const i, vector<unsigned long> &v) {
	for (int j = 0; v[j] <= i; j++) {
		// if (l % i == 0)
		// 	return false;
		if (i == v[j])
			return true;
	}
	return false;
}


#endif
