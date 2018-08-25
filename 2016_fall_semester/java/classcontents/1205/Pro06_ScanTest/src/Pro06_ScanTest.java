import java.io.*;
import java.util.*;

public class Pro06_ScanTest {
	public static void main(String[] args) {
		Scanner sc = null;
		try {
			sc = new Scanner(new BufferedReader(new FileReader("input.txt")));
//			sc = new Scanner(new FileReader("input.txt"));
			while (sc.hasNext())
				System.out.println(sc.next());
			if(sc != null)
				sc.close();
		} catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
	}
}
