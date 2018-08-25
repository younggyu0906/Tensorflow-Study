import java.util.Scanner;
public class Pro06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			int total = 0, count = 0, grade;
			
			Scanner in = new Scanner(System.in);
			while(true) {
				System.out.print("Enter score : ");
				grade = in.nextInt();
				if (grade < 0)
					break;
				total += grade;
				count++;
			}
			System.out.println("Average : " + (total / count));
	}

}
