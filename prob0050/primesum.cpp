#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	std::cerr << "Expects file on stdin.\n";

	std::vector<int> list;
	list.reserve(78498);

	int num, longest = 953, len = 21, size, *arr, run_tot, run_len, pos;
	while (std::cin >> num, num < 1000000){
		list.push_back(num);
	}
	arr = list.data();
	size = list.size();

	for (int i = 0, j; i < size-len; i++) {
		run_tot = run_len = 0;
		j = i;
		if (i) /*if not the first*/ {
			j++;
			run_len++;
			run_tot = arr[i];
		}
		//Don't need to check if it's larger here, since we were given one larger than length 1
		do {
			//Increments by two since two odds add to an even, which isn't prime.
			//So, except on the first, the length must be odd.
			run_tot += arr[j] + arr[j+1];
			run_len += 2;
			j+=2;
			if (run_len > len && std::binary_search(list.begin(), list.end(), run_tot)) {
				longest = run_tot;
				len = run_len;
				pos = i;
				std::cout << "Found " << longest << " length " << len << " starting at " << i+1 << '\n';
			}
		} while (run_tot < 1000000 && j < size);
	}
	std::cerr << "\nLongest is " << longest << " starting at " << pos+1 << " and has length " << len << '\n';

	//Stop stopwatch
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nanos.count() << " ns\n";
	return 0;
}
