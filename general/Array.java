package general;

import java.util.Arrays;
public class Array {
	//Things to make working with array slightly easier.

	// Returns intersection of sorted arrays A and B
	// Intersection: Things in a and b
	public static int[] intersection(int[] arrA, int[] arrB) {
		int[] out = new int[(arrA.length > arrB.length) ? arrA.length : arrB.length];
		int len = 0, i = 0, j = 0;
		while (i < arrA.length && j < arrB.length) {
			if (arrA[i] == arrB[i]) {
				out[len++] = arrA[i];
				i++; j++;
			}
			else if (arrA[i] < arrB[j]) {
				i++;
			}
			else {
				j++;
			}
		}

		if (len != out.length) {
			//out contains intersection, but padded on end.
			out = copyArray(out, len);
		}
		return out;
	}
	public static long[] intersection(long[] arrA, long[] arrB) {
		long[] out = new long[(arrA.length > arrB.length) ? arrA.length : arrB.length];
		int len = 0, i = 0, j = 0;
		while (i < arrA.length && j < arrB.length) {
			if (arrA[i] == arrB[j]) {
				out[len++] = arrA[i];
				i++; j++;
			}
			else if (arrA[i] < arrB[j]) {
				i++;
			}
			else {
				j++;
			}
		}

		if (len != out.length) {
			//out contains intersection, but padded on end.
			out = copyArray(out, len);
		}
		return out;
	}

	// Returns union of sorted arrays A and B
	// Union: Objects from both a and b
	//TODO Write union method

	//Copy from the start of the array in to a new array of length newSize
	//TODO Refactor so isn't essentially duplicated twice
	public static int[] copyArray(int[] in, int newSize) {
		int[] out = new int[newSize];
		System.arraycopy(in, 0, out, 0, (newSize > in.length ? in.length : newSize));
		return out;
	}
	public static long[] copyArray(long[] in, int newSize) {
		long[] out = new long[newSize];
		System.arraycopy(in, 0, out, 0, (newSize > in.length ? in.length : newSize));
		return out;
	}

	//Prints an array to stdout
	public static void printarr(long[] in) {
		System.out.print("[ " + in[0]);
		for (int i = 1; i < in.length; i++)
			System.out.print(" , " + in[i]);
		System.out.println(" ]");
	}
	public static void printarr(int[] in) {
		System.out.print("[ " + in[0]);
		for (int i = 1; i < in.length; i++)
			System.out.print(" , " + in[i]);
		System.out.println(" ]");
	}
}
