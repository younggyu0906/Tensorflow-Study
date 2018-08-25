import java.util.Scanner;

public class Pro01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double mile, km;
		final double FACTOR = 1.609;
		
		Scanner input = new Scanner(System.in);
		System.out.print("마일을 입력하시오 : ");
		mile = input.nextDouble();
		km = mile * FACTOR;
		
		System.out.println(mile + "mile is " + km + " km");
		System.out.printf("%f mile is %f km\n", mile, km);
		
		input.close();
	}
}
