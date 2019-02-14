#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[]) {
	chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();
	//Start timer

	int count[1001];
	fill(count, count + 1001, 0);

	for (int l_side = 1; l_side < 500; l_side++) {
		for (int s_side = 1; s_side < l_side; s_side++) {
			int hypot = sqrt(l_side * l_side + s_side * s_side), perim = hypot + s_side + l_side;
			if (perim > 1000 || l_side*l_side + s_side*s_side != hypot*hypot)
				//If perimeter too big or if not actually a right triangle
				continue;
			// cout << '{' << l_side << ',' << s_side << ',' << hypot << "} " << perim << endl;
			// 	In total, this prints 517 lines with these line uncommented.
			// 	You should pipe this to less if you change this
			count[perim]++;
		}
	}
	int largest_count = 0, largest = 0;
	for (int i = 1; i <= 1000; i++) {
		// if (count[i])
		// 	cout << i << ' ' << count[i] << endl;
		// See above statement
		if (count[i] > largest_count) {
			largest_count = count[i];
			largest = i;
		}
	}
	cout << "Largest:" << largest << " Count:" << largest_count << endl;


	//Stop timer
	chrono::high_resolution_clock::time_point stop_time = chrono::high_resolution_clock::now();
	auto micros = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
	cerr << "\nExecution took " << micros.count() << " us\n";
	return 0;
}
