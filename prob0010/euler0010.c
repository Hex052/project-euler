#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//seive of eratothenes

int main(int argc, char const *argv[]) {
	unsigned long int sum = 0;
	int isPrime = 1;
	for (double upto = 2; upto < 2000000; upto++){
		isPrime = 1;
		for (int factor = 2; factor < sqrt(upto); factor++){
			if (upto % factor == 0){
				isPrime = 0;
				break;
			}
		}
		if(isPrime){
			sum += upto;
			printf("%i is prime\n", upto);
		}
	}
	printf("sum: %li", sum);
	return 0;
}
