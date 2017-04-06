import java.util.*;

public class ReverseWords {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		// Number of lines. nextLine returns the number of lines on a String.
		int nLines =  Integer.valueOf(sc.nextLine());

		for (int i = 1; i <= nLines ; i++) {

			// Gets a full line
			String line = sc.nextLine();
			
			// Lines splitted on spaces.
			String[] words = line.split(" ");

			// This string have all the words reversed
			String reversedLine = "";

			// Since we splitted the spaces, we have to add them again.
			for (int j = words.length-1; j >= 0; j--) {
				reversedLine += " " + words[j];
			}
			
			System.out.println("Case # " + i + ":" + reversedLine);
		}
	}
}
