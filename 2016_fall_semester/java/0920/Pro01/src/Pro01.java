import java.util.Scanner;

public class Pro01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			int number;
			
			Scanner scan = new Scanner(System.in);
			System.out.print("Enter number : ");
			number = scan.nextInt();
			switch (number) {
				case 0 : System.out.println("����"); break;
				case 1 : System.out.println("�ϳ�"); break;
				case 2 : System.out.println("��"); break;
				default : System.out.println("����"); break;
			}
	}
}
