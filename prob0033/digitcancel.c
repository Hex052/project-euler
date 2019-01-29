#include <stdio.h>
#include <stdlib.h>

#define tens(i) i/10
#define ones(i) i%10

int main(int argc, char const *argv[]) {
	FILE* logfile = NULL;
	if (argc > 1) {
		logfile = fopen(argv[1], "w");
	}
	for (int denom = 11; denom < 100; denom++) {

		for (int num = 10; num < denom; num++) {
			if (ones(num) == 0  && ones(denom) == 0) {
				continue;
			}
			if (ones(num) == ones(denom)) {
				if (tens(num) == tens(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),ones(denom));
					continue;
				}
				if (logfile) fprintf(logfile, "%d/%d = %d/%d\n",num,denom,ones(num),ones(denom));
			}
			else if (ones(num) == tens(denom)) {
				if (tens(num) == ones(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),ones(denom));
					continue;
				}
				if (logfile) fprintf(logfile, "%d/%d = %d/%d\n",num,denom,ones(num),tens(denom));
			}
			else if (tens(num) == ones(denom)) {
				if (ones(num) == tens(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),ones(denom));
					continue;
				}
				if (logfile) fprintf(logfile, "%d/%d = %d/%d\n",num,denom,tens(num),ones(denom));
			}
			else if (tens(num) == tens(denom)) {
				if (ones(num) == ones(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),ones(denom));
					continue;
				}
				if (logfile) fprintf(logfile, "%d/%d = %d/%d\n",num,denom,tens(num),tens(denom));
			}
		}
	}
	return 0;
}
