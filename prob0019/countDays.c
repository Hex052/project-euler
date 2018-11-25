#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int daycount[7], month, year, days, day = 2;
	memset(&daycount, 0, 12*7*sizeof(int));
	for (year = 1901; year <= 2000; year++) {
		for (month = 0; month < 12; month++) {
			switch (month) {
				case 3: //Apr
				case 5: //Jun
				case 8: //Sep
				case 10: //Nov
					days = 30;
					break;
				case 1: //Feb
					if (year % 4 == 0)
						days = 29;
					else
						days = 28;
					break;
				default:
					days = 31;
					break;
			}
			for (int first = 1; days > 0; days--) {
				if (first == 1) {
					daycount[day]++;
					first--;
				}
				day++;
				day %= 7;
			}
		}
	}
	printf("Sundays on the 1st in the 20th century: %d\n", daycount[0]);
	return 0;
}
