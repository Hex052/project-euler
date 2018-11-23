#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include <errno.h>

unsigned long long primearr[10240]; //Longer because

//Add toAdd to the list of primes
unsigned addPrime(const unsigned long long toAdd){
	unsigned len = 0;
	while (primearr[len])
		len++;
	//len should now be the total number of primes in the array. (add a NULL)

	primearr[len] = toAdd;
	primearr[++len] = 0;
	return len;
}

bool isprime(const unsigned long long i) {
	unsigned index = 0;
	unsigned long long val;
	const unsigned long long rooti = (unsigned long long)sqrtl((long double)i);

	if (i < 2)
		return true;
	while (true) {
		val = primearr[index];
		if (val == 0) {
			//TODO something other than break. Insert more primes?
			break;
		}
		if (val > rooti) {
			//val is greater than the sqrt of i, and so all possible values
			//have been checked
			return true;
		}
		if (! (i % val)) {
			//i is evenly divisible by val
			return false;
		}
		index++;
	}
	//If we get here, then all val is smaller than rooti, and as far as
	//we can tell, i is prime.
	return true;
}

int main(int argc, char const *argv[]) {
	unsigned long long test = 3;
	unsigned len = 1;
	//Initialize list of primes
	primearr[0] = 2; primearr[1] = 0;

	//Fill list of primes up to len
	do {
		if (isprime(test)) {
			len = addPrime(test);
		}
		test++;
	} while (len <= 10001);

	printf("%llu\n",primearr[10000]);

	return 0;
}
