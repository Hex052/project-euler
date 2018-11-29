package general;

import general.Array;
import java.util.Arrays;
import java.lang.Math;
public class Factor {
	//Things to do with factoring (sensibly).

	//A list of primes
	public static long[] primes = {2,3,5,7,11,13,17,19,23};
	private static int endPrimePos = primes.length - 1;

	//Extends primes to target
	public static void growPrimes(long target) {
		primes = Array.copyArray(primes, primes.length + 500);
		if (primes.length < 9) {//Somehow, if this was truncated as something teeny
			long[] temp = {2,3,5,7,11,13,17,19,23};
			primes = temp;
			endPrimePos = primes.length - 1;
		}
		for (long i = primes[endPrimePos] + 2; i <= target; i += 2) {
			if (isPrime(i)) {
				primes[++endPrimePos] = i;
			}
		}
		primes = Array.copyArray(primes, endPrimePos + 1);
	}

	//Returns true if num is prime, false otherwise.
	public static boolean isPrime(long num) {
		long target = (long)Math.sqrt((double)num);
		if (primes.length == 0 || primes[endPrimePos] < (long)Math.sqrt((double)num)) {
			growPrimes(num);
		}
		for (long i : primes) {
			if (i > target)
				return true;
			if (num % i == 0)
				return false;
		}
		return false;
	}

	//Return the proper divisors (excluding num)
	public static int[] properDivisors(int num) {
		int[] out = divisors(num);
		return Array.copyArray(out, out.length - 1);
	}

	//Return all divisors
	public static int[] divisors(int num) {
		//TODO Refactor so it copies the array less frequently.
		int root = (int)Math.sqrt((double)num);
		int[] out = {1, num};
		for (int i = 2; i <= root; i++) {
			if (num % i == 0) {
				if (i * i == num) {
					out = Array.copyArray(out, out.length + 1);
					out[out.length-1] = i;
				}
				else {
					out = Array.copyArray(out, out.length + 2);
					out[out.length-1] = i;
					out[out.length-2] = num / i;
				}
			}
		}
		Arrays.sort(out);
		return out;
	}
	public static long[] divisors(long num) {
		//TODO Refactor so it copies the array less frequently.
		long root = (long)Math.sqrt((double)num);
		long[] out = {1, num};
		for (long i = 2; i <= root; i++) {
			if (num % i == 0) {
				if (i * i == num) {
					out = Array.copyArray(out, out.length + 1);
					out[out.length-1] = i;
				}
				else {
					out = Array.copyArray(out, out.length + 2);
					out[out.length-1] = i;
					out[out.length-2] = num / i;
				}
			}
		}
		Arrays.sort(out);
		return out;
	}

	//Return prime factors
	public static long[] primeFactors(long num) {
		if (num == 1) {
			return (new long[] {1});
		}
		if ((long)Math.sqrt((double)num) > primes[endPrimePos])
			growPrimes(num);
		long[] out = new long[50];
		int currPos = 0;
		for (long i : primes) {
			//System.out.println("Factoring " + num + " into prime factors");
			if (num == 0 || num == 1)
				break;
			while (num % i == 0) {
				if (currPos == out.length) {
					out = Array.copyArray(out, out.length + 50);
				}
				out[currPos++] = i;
				num /= i;
			}
		}
		out = Array.copyArray(out, currPos);
		//Arrays.sort(out);

		return out;
	}
}
