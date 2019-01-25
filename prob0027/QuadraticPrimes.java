package prob0027;

import general.Factor;

class QuadraticPrimes {
	public static void main(String[] args) {
		int longestA = 1, longestB = 41, longestRun = 0; //preloaded with list
		int bindex = 0, b, a, n;
		try { //I don't particularly care about the errors in this case.
			for (b = (int)Factor.getPrime(bindex); b < 1000 ; b = (int)Factor.getPrime(++bindex)) {
				for (a = 1 - b; a < b - 1; a += 2) {
					//Start testing with values of n, which can start at 2 (see solve.md)
					int length = 2;
					n = 2;
					while (Factor.isPrime(n*n + a*n + b)) {
						n++; length++;
					}
					if (n >= longestRun) {
						System.out.printf("New longest: %d\ta: %d\tb: %d\tProduct: %d\n", n, a, b, a*b);
						longestRun = n;
						longestA = a;
						longestB = b;
					}
				}
			}
		}
		catch (Exception e) {
			System.err.println("Something threw an error: Exception as follows:");
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}
}
