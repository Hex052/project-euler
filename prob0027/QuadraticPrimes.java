package prob0027;

import general.Factor;
import java.io.PrintWriter;

class QuadraticPrimes {
	public static void main(String[] args) {
		boolean log = false;
		PrintWriter logFile = null;
		if (args.length > 0) {
			try {
				logFile = new PrintWriter(args[0]);
				log = true;
			}
			catch (Exception e) {
				log = false;
			}
		}
		else
			System.err.println("All attempts may be written to a log file, passed as an argument.");

		int longestA = 1, longestB = 41, longestRun = 0; //preloaded with list
		int bindex = 0, b, a, n;
		try { //I don't particularly care about the errors in this case.
			for (b = (int)Factor.getPrime(bindex); b < 1000 ; b = (int)Factor.getPrime(++bindex)) {
				for (a = 2 - b; a < b - 1; a += 2) {
					//Start testing with values of n, which can start at 2 (see solve.md)
					int length = 0;
					n = 0;
					while (Factor.isPrime(n*n + a*n + b)) {
						n++; length++;
					}
					if (log) {
						logFile.printf("Length: %3d\ta: %3d\tb: %3d\tProduct: %d\n", n, a, b, a*b);
					}
					if (n >= longestRun) {
						System.out.printf("New longest: %3d\ta: %3d\tb: %3d\tProduct: %d\n", n, a, b, a*b);
						longestRun = n;
						longestA = a;
						longestB = b;
					}
				}
				logFile.flush();
			}
		}
		catch (Exception e) {
			System.err.println("Something threw an error: Exception as follows:");
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}
}
