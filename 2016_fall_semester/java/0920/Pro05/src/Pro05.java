import java.util.Scanner;

public class Pro05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x, y, num;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter 2 numbers(Larger, smaller) : ");
		x = sc.nextInt();
		y = sc.nextInt();
		
		while (y != 0) {
			num = x % y;
			x = y;
			y = num;
		}
		System.out.println("Gcd is " + x);
	}

}
