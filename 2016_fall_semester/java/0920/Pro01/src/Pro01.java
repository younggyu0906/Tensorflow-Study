import java.util.Scanner;

public class Pro01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			int number;
			
			Scanner scan = new Scanner(System.in);
			System.out.print("Enter number : ");
			number = scan.nextInt();
			switch (number) {
				case 0 : System.out.println("없음"); break;
				case 1 : System.out.println("하나"); break;
				case 2 : System.out.println("둘"); break;
				default : System.out.println("많음"); break;
			}
	}
}
