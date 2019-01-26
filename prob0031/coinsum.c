#include <stdio.h>

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; //In pence

int sum(const int index, const int runtot) {
	if (runtot == 200) {
		return 1;
	}
	else if (runtot > 200) {
		return 0;
	}
	int tot = 0;
	for (int i = index; i < 8; i++) {
		tot += sum(i,runtot + coins[i]);
	}
	return tot;
}

int main(int argc, char const *argv[]) {
	printf("Total possibilities: %d\n", sum(0,0));
	return 0;
}
