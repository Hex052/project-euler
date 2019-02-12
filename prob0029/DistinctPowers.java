package prob0029;

import java.util.ArrayList;
import java.math.BigInteger;

class DistinctPowers {


	public static void main(String[] args) {
		ArrayList<BigInteger> list = new ArrayList<>();
		for (int a = 2; a <= 100; a++) {
			for (int b = 2; b <= 100; b++) {
				BigInteger i = (new BigInteger(a + "")).pow(b);
				if (!list.contains(i))
					list.add(i);
			}
		}
		// for (BigInteger i : list) {
		// 	System.out.println(i.toString());
		// }
		System.out.println(list.size());
	}
}
