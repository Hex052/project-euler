#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
  _   _       _    __          __        _    _
 | \ | |     | |   \ \        / /       | |  (_)
 |  \| | ___ | |_   \ \  /\  / /__  _ __| | ___ _ __   __ _ 
 | . ` |/ _ \| __|   \ \/  \/ / _ \| '__| |/ / | '_ \ / _` |
 | |\  | (_) | |_     \  /\  / (_) | |  |   <| | | | | (_| |
 |_| \_|\___/ \__|     \/  \/ \___/|_|  |_|\_\_|_| |_|\__, |
                                                       __/ |
                                                      |___/
***/

int main(int argc, char const *argv[]) {
//initializing the array
	unsigned int primes[10004];
	int pcount = 0, test = 2;
	memset(primes, 0, 10001 * sizeof(int));
	primes[0] = 2, primes[1] = 3;
//
	while (!(primes[6])){
		pcount = 0;
		while (!(primes[pcount])){
			if (!(test % primes[pcount])) {
				primes[++pcount] = test;
				break;
			}
			pcount++;
		}
		test++;
	}

	printf("\n%i", primes[10000]);
	return 0;
}
