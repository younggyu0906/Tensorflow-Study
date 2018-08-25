import java.util.Scanner;

public class Pro04 {
		public static void main(String[] args) {
		double celsius, fahrenheit;
	
		Scanner input = new Scanner(System.in);
		System.out.print("화씨를 입력하시오 : ");
		fahrenheit = input.nextDouble();
		celsius = 5.0 / 9 * (fahrenheit - 32);//정수/정수 = 정수, 둘중 하나는 실수여야함!!!
	
		System.out.println("섭씨는 " + celsius);
		input.close();
	}
}
