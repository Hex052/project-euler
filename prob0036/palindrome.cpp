#include <iostream>

#define lowbit(i) i & 1 ? '1' : '0'

using namespace std;

bool is_palindrome(string str);

int main(int argc, char const *argv[]) {
	int total = 0;
	for (int i = 1; i < 1000000; i += 2) {
		string bin(1, lowbit(i));
		int work = i >> 1;
		while (work) {
			bin.insert(bin.begin(),lowbit(work));
			work >>= 1;
		}

		if (is_palindrome(bin) && is_palindrome(to_string(i))) {
			cout << i << ' ';
			cout << bin << endl;
			total += i;
		}
	}
	cout << "Total: "<< total << endl;
	return 0;
}

bool is_palindrome(string str) {
	for (int start = 0, end = str.size() - 1; start < end; start++, end--) {
		if (str[start] != str[end]) {
			return false;
		}
	}
	return true;
}
