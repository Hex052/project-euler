#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include <errno.h>

unsigned long long primearr[160000]; //Longer because

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
	unsigned long long test = 3, primesum = 0;
	unsigned len = 1;
	FILE *plist = fopen("plist.txt","w+");
	//Initialize list of primes
	primearr[0] = 2; primearr[1] = 0;
	fprintf(plist, "2\n");

	do {
		if (isprime(test)) {
			len = addPrime(test);
			primesum += test;
			fprintf(plist, "%llu\n", test);
		}
		if (test % 1000)
			printf("test = %llu  primesum = %llu\n", test, primesum);
		test++;
	} while (test < 2000000);

	printf("%llu\n",primesum);
	fclose(plist);

	return 0;
}
