import java.util.Scanner;
import java.io.File;
import java.util.Arrays;

public class NameScores {
	public static void main(String[] args) {
		if (args.length < 1) {
			System.err.println("Args: input_file");
			System.exit(1);
		}
		Scanner nameFile = null;
		try {
			nameFile = new Scanner(new File(args[0]));
		}
		catch (java.io.FileNotFoundException e) {
			System.err.println("File \"" + args[1] + "\" not found.");
			System.exit(1);
		}

		String[] nameLines = nameFile.nextLine().trim().replace("\"", "").split(",");
		//I'm very sure you could do the replace and split in one method, but I
		//can't figure out how.
		Arrays.sort(nameLines);
		int[] values = new int[nameLines.length];
		int total = 0;
		for (int i = 0; i < nameLines.length; i++) {
			for(char c : nameLines[i].toCharArray())
				values[i] += c - '@'; // 'A' - 1 == '@'
			values[i] *= (i + 1);
			total += values[i];
		}
		System.out.println("Total value of all names: " + total);
	}
}
