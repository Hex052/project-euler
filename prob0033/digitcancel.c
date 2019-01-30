#include <stdio.h>
#include <stdlib.h>

#define tens(i) (i/10)
#define ones(i) (i%10)

int isprime(const int in) {
	switch (in) {
		case 11:
		case 13:
		case 17:
		case 19:
		case 23:
		case 29:
		case 31:
		case 37:
		case 41:
		case 43:
		case 47:
		case 53:
		case 59:
		case 61:
		case 67:
		case 71:
		case 73:
		case 79:
		case 83:
		case 89:
		case 97:
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

int main(int argc, char const *argv[]) {
	FILE* logfile = NULL;
	if (argc > 1) {
		logfile = fopen(argv[1], "w");
	}
	for (int denom = 12; denom < 100; denom++) {
		if (isprime(denom))
			continue;
		for (int num = 10; num < denom; num++) {
			if (isprime(num))
				continue;
			if (ones(num) == 0  && ones(denom) == 0) {
				continue;
			}
			if (ones(num) == ones(denom)) {
				//Using tens/tens
				if (tens(num) >= tens(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,tens(num),tens(denom));
					continue;
				}
				fprintf(stdout, "%d/%d = %d/%d\n",num,denom,tens(num),tens(denom));
			}
			if (ones(num) == tens(denom)) {
				//Using tens/ones
				if (tens(num) >= ones(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,tens(num),ones(denom));
					continue;
				}
				fprintf(stdout, "%d/%d = %d/%d\n",num,denom,tens(num),ones(denom));
			}
			if (tens(num) == ones(denom)) {
				//Using ones/tens
				if (ones(num) >= tens(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),tens(denom));
					continue;
				}
				fprintf(stdout, "%d/%d = %d/%d\n",num,denom,ones(num),tens(denom));
			}
			if (tens(num) == tens(denom)) {
				//Using ones/ones
				if (ones(num) >= ones(denom)) {
					if (logfile) fprintf(logfile, "%d/%d != %d/%d\n",num,denom,ones(num),ones(denom));
					continue;
				}
				fprintf(stdout, "%d/%d = %d/%d\n",num,denom,ones(num),ones(denom));
			}
		}
	}
	return 0;
}
