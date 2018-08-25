import java.util.Scanner;

public class Pro02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			String month;
			int monthNumber;
			
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter month : ");
			month = sc.next();
			switch (month) {
				case "january" : monthNumber = 1; break;
				case "february" : monthNumber = 2; break;
				case "march" : monthNumber = 3; break;
				default  : monthNumber = 0; break;
			}
			System.out.println(monthNumber);
	}

}
