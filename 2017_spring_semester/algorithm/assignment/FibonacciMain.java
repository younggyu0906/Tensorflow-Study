import java.util.*;

public class FibonacciMain {
	private static final double MILLISEC = 1000000.00;
	private static final double MICROSEC = 1000.00;
	
	public static void main(String[] args) {
		int num = 49;
		  
		long startTime = System.nanoTime(); 
		long result = iterativeFibonacci(num);
		long endTime = System.nanoTime();
		System.out.println("[Iterative Fibonacci]");
		System.out.println("Num " + num + " : Fibonacci Number " + result);
		System.out.format("Elapsed Time:  %8d nano sec.\n", endTime - startTime);
		System.out.format("Elapsed Time:  %8.3f micro sec.\n", (double)nanoSecToMicroSec(endTime - startTime));
		System.out.format("Elapsed Time:  %8.3f milli sec.\n", (double)nanoSecToMillSec(endTime - startTime));
		
		startTime = System.nanoTime(); 
		result = recursiveFibonacci(num);		
		endTime = System.nanoTime();
		System.out.println("[Recursive Fibonacci]");
		System.out.println("Num " + num + " : Fibonacci Number " + result);
		System.out.format("Elapsed Time:  %8d nano sec.\n", endTime - startTime);
		System.out.format("Elapsed Time:  %8.3f micro sec.\n", (double)nanoSecToMicroSec(endTime - startTime));
		System.out.format("Elapsed Time:  %8.3f milli sec.\n", (double)nanoSecToMillSec(endTime - startTime));
	}
	
	public static long iterativeFibonacci(int num) {
		return 0L;
	}
	
	public static long recursiveFibonacci(int num) {
		return 0L;
	}

	public static double nanoSecToMicroSec(long nanoSec) {
		return nanoSec / MICROSEC;
	}
	
	public static double nanoSecToMillSec(long nanoSec) {
		return nanoSec / MILLISEC;
	}
}