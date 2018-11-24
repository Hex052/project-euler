#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *twodigits[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(int argc, char const *argv[]) {
	int total = 0;
	for (int i = 1, temp = 1; i <= 1000; i++, temp = i) {
		int curr;
		if (temp == 1000) {
			total += strlen("onethousand"); //one thousand
			continue;
		}
		if (temp / 100) {
			curr = (temp / 100) % 10;
			total += strlen(ones[curr]) + strlen("hundred");
			if (temp % 100)
				total += 3;
		}
		if ((curr = temp % 100)) {
			if (curr >= 20 || curr == 10)
				total += strlen(tens[curr / 10]);
			else if (curr >= 11) {
				total += strlen(twodigits[(curr-10) % 10]);
				continue;
			}
			if ((curr = curr % 10)) {
				total += strlen(ones[curr]);
			}
		}
	}
	printf("%d\n", total);
	return 0;
}
