import java.util.*;

public class SearchMain {
	private static final double MILLISEC = 1000000.00;
	private static final double MICROSEC = 1000.00;
	
	static int[] s = null; 
	static int num, key;
	
	public static void main(String[] args) {
		num = 1000;
		  
		Random r = new Random();
		s = new int[num];
		for (int i = 0; i < num; i++) {
			s[i] = r.nextInt(num);
		}
		key = r.nextInt(num);
		
		for (int i = 0; i < num; i++) {
			System.out.print(s[i] + " ");
		}
		System.out.println("\nKey Value: " + key + "\n");
		
		long startTime = System.nanoTime(); 
		int location = sequentialSearch();
		long endTime = System.nanoTime();
		System.out.println("[Sequential Search Result]");
		System.out.println("Key value " + key + ": location " + location);
		System.out.format("Elapsed Time:  %8d nano sec.\n", endTime - startTime);
		System.out.format("Elapsed Time:  %8.3f micro sec.\n", (double)nanoSecToMicroSec(endTime - startTime));
		System.out.format("Elapsed Time:  %8.3f milli sec.\n", (double)nanoSecToMillSec(endTime - startTime));
		System.out.println();
		
		Arrays.sort(s);
		for (int i = 0; i < num; i++) {
			System.out.print(s[i] + " ");
		}
		System.out.println("\nKey Value: " + key + "\n");
		
		startTime = System.nanoTime(); 
		location = binarySearch();
		endTime = System.nanoTime();
		System.out.println("[Binary Search Result]");
		System.out.println("Key value " + key + ": location " + location);
		System.out.format("Elapsed Time:  %8d nano sec.\n", endTime - startTime);
		System.out.format("Elapsed Time:  %8.3f micro sec.\n", (double)nanoSecToMicroSec(endTime - startTime));
		System.out.format("Elapsed Time:  %8.3f milli sec.\n", (double)nanoSecToMillSec(endTime - startTime));
		System.out.println();
		
		startTime = System.nanoTime(); 
		location = recursiveBinarySearch(0, num);
		endTime = System.nanoTime();
		System.out.println("[Recursive Binary Search Result]");
		System.out.println("Key value " + key + ": location " + location);
		System.out.format("Elapsed Time:  %8d nano sec.\n", endTime - startTime);
		System.out.format("Elapsed Time:  %8.3f micro sec.\n", (double)nanoSecToMicroSec(endTime - startTime));
		System.out.format("Elapsed Time:  %8.3f milli sec.\n", (double)nanoSecToMillSec(endTime - startTime));
	}
	
	public static int sequentialSearch() {
		return 0;
	}
	
	public static int binarySearch() {
		return 0;
	}
	
	public static int recursiveBinarySearch(int low, int high) {
		return 0;
	}
	
	public static double nanoSecToMicroSec(long nanoSec) {
		return nanoSec / MICROSEC;
	}
	
	public static double nanoSecToMillSec(long nanoSec) {
		return nanoSec / MILLISEC;
	}
}