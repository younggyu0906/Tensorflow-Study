import java.util.Scanner;

public class Pro03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			int fruit;
			
			Scanner in = new Scanner(System.in);
			System.out.print("Enter number : ");
			fruit = in.nextInt();
			
			switch (fruit) {
				case 1 : System.out.println("Apple");
						break;
				case 2 : System.out.println("Pear");
				case 3 : System.out.println("Banana");
						break;
				default : System.out.println("fruit");
			}
	}

}
