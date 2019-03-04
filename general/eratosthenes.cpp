#include <fstream>
#include <iostream>
#include <chrono>
#include <deque>
#include <climits>

using namespace std;

//#define USE_DEQUE
/*
 * I tried it with a deque, and don't use it.
 * For 1 000 000 000 primes:
 *     using a deque took 532783291973 ns (8 min + 52.783 291 973 s)
 *     Using an array took 4657372415 ns (4.564 575 740 s)
 * I did test a vector as well, but I couldn't be bothered to wait for it
 * to finish for that many primes. On smaller tests, it was more efficient,
 * though. I still wouldn't recomend using it, as it was still far slower
 * than just an array.
 */

void get_num_exit_on_err(unsigned long long &num, string str, string name, int base);

int main(int argc, char const *argv[]) {
	auto start_time = std::chrono::high_resolution_clock::now();
	//Start stopwatch

	if (argc < 3 || argc > 4) {
		std::cerr << "Usage: " << argv[0] << " start end [file]\n"
		"Start and end must be positive, and end must be greater than start.\n"
		"Both are inclusive\n"
		"If no file is given, the list will be output on stdout.\n";
		exit(1);
	}
	long long unsigned start, end;
	ofstream file;
	bool file_open = false;

	/*
	* Get arguments
	*/
	get_num_exit_on_err(start, argv[1], "start", 10);
	get_num_exit_on_err(end, argv[2], "end", 10);
	if (start >= end) {
		std::cerr << "Usage: " << argv[0] << " start end [file]\n"
		<< "Start and end must be positive, and end must be greater than start.\n"
		<< "Both are inclusive\n";
		exit(1);
	}
	if ((file_open = (argc == 4))) {
		file.open(argv[3]);
		std::cerr << "Will write to \'" << argv[3] << "\'.\n";
	}
	else {
		std::cerr << "Will write to stdout.\n";
	}

	/*
	* Create array
	*/
	std::cerr << "Creating array... ";
	auto step_start_time = std::chrono::high_resolution_clock::now();
#ifdef USE_DEQUE
	deque<bool> sieve_list; //Apparently vector<bool> is broken. Yay.
	try /* Resize deque, catch bad_alloc */ {
		sieve_list.resize(end, true); //Assume alll are true by default
	}
	catch (bad_alloc e) {
		std::cerr << "Could not allocate space of size " << end << "\n"
		"Try reducing the size of the end, or freeing memory.\n";
		exit(2);
	}
#else
	bool *sieve_list = NULL;
	try {
		sieve_list = new bool[end];
		std::fill(sieve_list, sieve_list+end, true);
	}
	catch (exception e) {
		if (sieve_list == NULL) {
			std::cerr << "Could not allocate space of size " << end << "\n"
			"Try reducing the size of the end, or freeing memory.\n";
			exit(2);
		}
	}
#endif
	auto stop_time = std::chrono::high_resolution_clock::now();
	auto nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - step_start_time);
	std::cerr << "Done (" << nsec.count() << " ns)\n";

	/*
	* Sieve numbers
	*/
	std::cerr << "Starting sieve... ";
	step_start_time = std::chrono::high_resolution_clock::now();
	for (unsigned long long i = 2; i <= end; i++) {
		if (!sieve_list[i-1]) {
			continue;
		}
		for (unsigned long long j = (2*i) - 1; j < end; j += i) {
			sieve_list[j] = false;
		}
	}
	stop_time = std::chrono::high_resolution_clock::now();
	nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - step_start_time);
	std::cerr << "Done (" << nsec.count() << " ns)\n";


	/*
	* Print primes
	*/
	std::cerr << "Printing..." << (file_open ? ' ' : '\n');
	step_start_time = std::chrono::high_resolution_clock::now();
	if (file_open) /* Output to file */ {
		for (unsigned long long i = 1; i < end;) {
			if (i >= start && sieve_list[i])
				file << ++i << '\n';
			else
				i++;
		}
	}
	else /* Output to stdout */ {
		for (unsigned long long i = 1; i < end;) {
			if (i >= start && sieve_list[i])
				std::cout << ++i << '\n';
			else
				i++;
		}
	}
	stop_time = std::chrono::high_resolution_clock::now();
	nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - step_start_time);
	std::cerr << "Done (" << nsec.count() << " ns)\n";

	//Stop total stopwatch
	stop_time = std::chrono::high_resolution_clock::now();
	nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
	std::cerr << "\nExecution took " << nsec.count() << " ns\n";
	return 0;
}

void get_num_exit_on_err(unsigned long long &num, string str, string name, int base) {
	try {
		num = stoull(str, NULL, base);
	}
	catch (invalid_argument e) {
		std::cerr << "Usage: <program> start end [file]\n"
		"Argument \"" << name << "\" is not a valid number.\n"
		"Start and end must be positive, and end must be greater than start.\n"
		"Both are inclusive\n"
		"If no file is given, the list will be output on stdout.\n";
		exit(1);
	}
	catch (out_of_range e) {
		std::cerr << "Usage: <program> start end [file]\n"
		"Argument \"" << name << "\" is out of range for an unsigned long long (max:" << ULLONG_MAX <<").\n"
		"Start and end must be positive, and end must be greater than start.\n"
		"Both are inclusive\n"
		"If no file is given, the list will be output on stdout.\n";
		exit(1);
	}
}
