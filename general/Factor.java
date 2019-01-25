package general;

import general.Array;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.lang.Math;
import java.util.ArrayList;
import java.lang.Math;
import java.util.ArrayList;
import java.util.Arrays;


//Things to do with factoring (sensibly).
public class Factor {

	//A list of primes, and whether it has been initialized
	protected static ArrayList<Long> primes = new ArrayList<>();
	protected static boolean primesFilled = false;
	//The list of primes that starts this.
	protected static File plist = new File("plist.txt");

	//Extends primes to target number
	public static void growPrimes(long target) throws IOException {
		if (! primesFilled) {
			growPrimesLen(200);
		}
		for (long i = primes.get(primes.size() - 1) + 2; i <= target; i += 2) {
			if (isPrime(i)) {
				primes.add(i);
			}
		}
	}
	//Grows primes to the specified size. This one actually throws FileNotFoundException.
	public static void growPrimesLen(int index) throws FileNotFoundException, IOException {
		if (!primesFilled) {
			if (!plist.exists() || !plist.isFile()) {
				throw new FileNotFoundException("The plist file \""+plist.getPath()+"\"does not exist!");
			}
			FileReader frd = new FileReader(plist);
			BufferedReader linebuffer = new BufferedReader(frd);
			String line;
			while ((line = linebuffer.readLine()) != null) {
				primes.add(Long.parseLong(line));
			}
			frd.close();
			linebuffer.close();
			primesFilled = true;
		}
		for (long i = primes.get(primes.size() - 1); primes.size() < index; i += 2) {
			if (isPrime(i)) {
				primes.add(i);
			}
		}
	}

	//Returns true if num is prime, false otherwise.
	public static boolean isPrime(long num) throws IOException {
		long target = (long)Math.sqrt((double)num);
		if (primes.size() == 0 || primes.get(primes.size() - 1) < (long)Math.sqrt((double)num)) {
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
	//Return prime factors
	public static long[] primeFactors(long num) throws IOException{
		if (num == 1) {
			return (new long[] {1});
		}
		if ((long)Math.sqrt((double)num) > primes.get(primes.size() - 1))
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
	//Return the proper divisors (excluding num)
	public static int[] properDivisors(int num) {
		int[] out = divisors(num);
		return Array.copyArray(out, out.length - 1);
	}
	
	//Set the plist file used
	public static void setPlist(File f) {
		plist = f;
	}
	public static void setPlist(String s) {
		plist = new File(s);
	}

	//Get whole list of primes
	public static ArrayList<Long> getPrimeList() {
		return primes;
	}
	//Get prime at a position (0-indexed)
	public static long getPrime(int index) throws IOException {
		if (index >= primes.size()) {
			growPrimes(index);
		}
		return primes.get(index);
	}
}
