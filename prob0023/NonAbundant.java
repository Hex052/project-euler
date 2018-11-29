package prob0023;

import java.lang.Math;
import java.util.Arrays;
public class NonAbundant {
	protected static int[] copyArray(int[] in, int newSize) {
		int[] out = new int[newSize];
		System.arraycopy(in, 0, out, 0, (newSize > in.length ? in.length : newSize));
		return out;
	}
	public static int[] properDivisors(int num) {
		int root = (int)Math.sqrt((double)num);
		int[] out = {1};
		for (int i = 2; i <= root; i++) {
			if (num % i == 0) {
				if (i * i == num) {
					out = copyArray(out, out.length + 1);
					out[out.length-1] = i;
				}
				else {
					out = copyArray(out, out.length + 2);
					out[out.length-1] = i;
					out[out.length-2] = num / i;
				}
			}
		}
		Arrays.sort(out);
		return out;
	}
	protected static void printarr(int[] in) {
		System.out.print("[ " + in[0]);
		for (int i = 1; i < in.length; i++)
			System.out.print(" , " + in[i]);
		System.out.println(" ]");
	}

	public static void main(String[] args) {
		int[] abundants = new int[0];
		int nextAbundant = 0;
		//Build list of abundants
		for (int i = 2; i <= 28123; i++) {
			int[] divisors = properDivisors(i);
			int sum = 0;
			for (int div : divisors)
				sum += div;
			if (sum > i) {
				if (nextAbundant == abundants.length)
					abundants = copyArray(abundants, abundants.length + 100);
				abundants[nextAbundant++] = i;
				//System.out.print(i + " "); printarr(divisors);
			}
		}

		//Determine which vales are sums of
		boolean[] isSum = new boolean[28124];
		for (int i = 0; i < nextAbundant; i++) {
			for (int j = i; abundants[i] + abundants[j] <= 28123; j++) {
				isSum[abundants[i] + abundants[j]] = true;
			}
		}

		//Total those not representable as a sum
		int total = 0;
		for (int i = 1; i < 28124; i++)
			if (!(isSum[i]))
				total += i;
		System.out.println("Total of positive integers that cannot be represented" +
			" as a sum of abundant numbers: " + total);
	}
}
