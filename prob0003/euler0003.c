//compile with -lm
#include <stdio.h>

int main(void){
	long int euler = 600851475143;
	int i = 2, largestFactor;
	printf("600851475143 = 1");
	while (euler != 1){
		if (euler % i == 0){
			largestFactor = i;
			euler /= i;
			printf(" * %i", largestFactor);
		}
		i++;
	}
	printf("\nLargest Prime Factor: %i\n", largestFactor);
	return 0;
}
