import java.util.Scanner;
public class Prog05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x, result;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter number : ");
		x = sc.nextInt();
		if(x > 0) {
			result = 7 * x + 2;
		}
		else {
			result = (int)(Math.pow(x, 3)) - 9 * x + 2;//Mate는 더블타입리턴
		}
		System.out.println("Result : " + result);
	}

}
