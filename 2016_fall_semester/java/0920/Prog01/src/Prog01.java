import java.util.Scanner;

public class Prog01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n1, n2, n3;
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter 3 numbers : ");
		n1 = in.nextInt();
		n2 = in.nextInt();
		n3 = in.nextInt();
		
		if (n1 > n2) {
			if (n1 > n3) {
				if(n2 > n3)
					System.out.println(n1 + ", " + n2 + ", " + n3);
				else
					System.out.println(n1 + ", " + n3 + ", " + n2);
			}
			else
				System.out.println(n3 + ", " + n1 + ", " + n2);
		}
		else {
			if (n2 > n3) {
				if (n1 > n3) {
					System.out.println(n2 + ", " + n1 + ", " + n3);
				}
				else {
					System.out.println(n2 + ", " + n3 + ", " + n1);
				}
			}
			else
				System.out.println(n3 + ", " + n2 + ", " + n1);
		}
	}

}
