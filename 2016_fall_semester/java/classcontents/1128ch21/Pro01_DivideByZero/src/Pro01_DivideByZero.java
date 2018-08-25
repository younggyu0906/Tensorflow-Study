import java.util.Scanner;
/*
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("분자 입력 : ");
		int x = sc.nextInt();
		System.out.print("분모 입력 : ");;
		int y = sc.nextInt();
		int result = x / y;
		System.out.println("Result : " + result);
		
		sc.close();
	}
}
*/
// Exception이 발생할 수 있는 코드를 try 블락 안에 넣는다
// catch 블락에 exception이 발
/*
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int result = 0;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("분자 입력 : ");
		int x = sc.nextInt();
		System.out.print("분모 입력 : ");;
		int y = sc.nextInt();
		try {
			result = x / y;
		} catch (ArithmeticException e) {
			System.out.println("Can not divide by 0");
		}
		System.out.println("Program reaches here");
		System.out.println("Result : " + result);
		
		sc.close();
	}
}
*/
//finally block은 option
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int result = 0;
		Scanner sc = new Scanner(System.in);

		System.out.print("분자 입력 : ");
		int x = sc.nextInt();
		System.out.print("분모 입력 : ");;
		int y = sc.nextInt();
		try {
			result = x / y;
		} catch (ArithmeticException e) {
			System.out.println("Can not divide by 0");
		} finally {	// exception 발생하건 안하건 finally block 실행
			System.out.println("Program reaches here");
			System.out.println("Result : " + result);
		}
		System.out.println("프로그램 종료");

		sc.close();
	}
}