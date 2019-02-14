#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

int digit_count(int i);
int digit_pos(int i, const int pos);

int main(int argc, char const *argv[]) {
	auto start_time = chrono::high_resolution_clock::now();
	//Start stopwatch

	int prod = 1;
	for (int goal = 1, pos = 0, i = 1; goal <= 1000000; i++) {
		int digits = digit_count(i);
		if (pos + digits >= goal) {
			int digit = digit_pos(i, goal-pos-1);
			prod *= digit;
			cout << setw(7) << goal << ' ' << digit << ' ' << setw(4) << std::right << prod << ' ' << i << endl;
			goal *= 10;
		}
		pos += digits;
	}




	//Stop stopwatch
	auto stop_time = chrono::high_resolution_clock::now();
	auto micros = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
	cerr << "\nExecution took " << micros.count() << " us\n";
	return 0;
}



int digit_count(int i) {
	int dig = 0;
	while (i) {
		dig++;
		i /= 10;
	}
	return dig;
}
int digit_pos(int i, const int pos) {
	return to_string(i)[pos] - '0';
}
