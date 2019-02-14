#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_pandigital(string &str);

int main(int argc, char const *argv[]) {
	int largest = 0;
	string str;
	for (int i = 1; i < 9999; i++) { //99991998 is 9999*1 concat 9999*2
		str = to_string(i) + to_string(i * 2);
		for (int j = 3; str.size() < 10; j++) {
			if (is_pandigital(str)) { //checks for length 9
				int num = stoi(str);
				largest = num; //Don't need to check if larger since i is always increasing.
				cout << str << endl;
				break;
			}
			str += to_string(i * j);
		}
	}
	cout << "Largest: " << largest << endl;
	return 0;
}

bool is_pandigital(string const &str) {
	if (str.size() != 9)
		return false;
	bool nums[10] = {0,0,0,0,0,0,0,0,0,0};
	for (char c : str) {
		if (nums[c - '0']) {
			return false;
		}
		nums[c - '0'] = true;
	}
	if (nums[0]) //So far only guarenteed unique numbers, not that there was no zero
		return false;
	return true;
}
