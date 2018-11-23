#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include <errno.h>

unsigned long long *primearr = NULL;

//Add toAdd to the list of primes
void addPrime(const unsigned long long toAdd){
	unsigned len = 0;
	while (primearr[len])
		len++;
	//len should now be the total number of primes in the array. (add a NULL)
	{
		void* new = realloc(primearr, (len + 2) * sizeof(unsigned long long));
			//Added two, one NULL byte and one number to add
		if (new == NULL) {
			fputs("\nUnable to allocate memory", stderr);
			exit(1);
		}
		primearr = new;
	}
	primearr[len] = toAdd;
	primearr[len + 1] = 0;
	//printf("%u",len); //TODO remove debug
	return;
}

bool isprime(const unsigned long long i) {
	unsigned index = 0;
	unsigned long long val;
	const unsigned long long rooti = (unsigned long long)sqrtl((long double)i);

	if (i < 2)
		return true;
	//printf("%llu,%llu",primearr[0],primearr[1]); //TODO remove debug
	while (true) {
		val = primearr[index];
		//printf("%llu\n",val); //TODO remove debug
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
	//If we get here, then all val is smallter than rooti, and as far as
	//we can tell, i is prime.
	return true;
}

int main(int argc, char const *argv[]) {
	const unsigned long long target = 600851475143,
		rootTarget = (unsigned long long)sqrtl((long double)target);

	//Initialize list of primes
	primearr = malloc(2 * sizeof(unsigned long long));
	primearr[0] = 2; primearr[1] = 0;

	//Fill list of primes up to sqrtl(6long 00851475143)
	for (unsigned long long i = 3; i <= rootTarget; i+=2) {
		//printf("%llu\n",i); //TODo remove debug
		if (isprime(i)) {
			addPrime(i);
		}
	}

	//Check target for prime factors
	{
		bool first = true;
		unsigned long long workingTarget = target, rootWorkinTarget = rootTarget;
		printf("Prime factors of %llu:\n[", target);
		for (int i = 0; primearr[i] && primearr[i] <= rootWorkinTarget; i++) {
			//printf("%d : %llu : %llu : %llu\n", i, primearr[i], workingTarget, rootWorkinTarget); //TODO remove debug
			while (! (workingTarget % primearr[i])) {
				//While evenly divisible...
				workingTarget /= primearr[i];
				rootWorkinTarget = (unsigned long long)sqrtl((long double)workingTarget);
				if (!first)
					putchar(',');
				first = false;
				printf(" %llu ", primearr[i]);
			}
		}
		puts("]\n");
	}

	//printf("%lf\n%d\n",sqrtl((long double) target), (int)sqrtl((long double) target));

	return 0;
}
