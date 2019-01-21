package prob0026;

import general.Array;
import general.Factor;
import java.util.Arrays;
import java.util.ArrayList;

public class FractionDigitCycles {
	public static void main(String[] args) {
		int longest = 7, len = 6;
		int[] div = null;
		for (int i = 7; i < 1000; i += 2) {
			if (i % 5 == 0) {
				continue;
			}
			int num = 1, denom = i;
			//Discard all initial zeros
			while (num < denom) {
				num *= 10;
			}
			ArrayList<Integer> remainders = new ArrayList<>();
			int rem = num % denom;

			while (!remainders.contains(rem)) {
				remainders.add(rem);
				rem = (rem * 10) % denom;
			}

			if (rem == 0) {
				continue;
			}
			int currlen = remainders.size() - 1 - remainders.indexOf(rem);
			if (currlen > len) {
				System.out.printf("Longest:%d\tLength:%d\n",i,currlen);
				longest = i;
				len = currlen;
			}

		}
	}
}
