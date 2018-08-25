import java.util.Scanner;
// if else 구문을 사용하면 정상 코드와 에러 구문이 뒤죽박죽 섞이게 되어 보기 어렵다.
// try catch 구문을 사용하면 정상 코드와 에러구문이 구별된다!
// 함수에서 직접 처리하는 방법
/*
class MyException extends Exception {
	public MyException() {
		super("This is my exception");
	}
}
public class Pro05_MyExcption {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter numerator : ");
		int x = sc.nextInt();
		System.out.print("Enter denominator : ");
		int y = sc.nextInt();
		divide(x, y);
	}
	
	public static void divide(int x, int y) {
		int result = 0;
		
		try {
			if (y == 0)
				throw new MyException();
			result = x / y;
		} catch (MyException e) {
			System.out.println("분모가 0입니다.\n");
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		System.out.println("Result is " + result);
	}
}
*/
// 함수에서 exception객체를 던지는 방법 // 여러 예외처리하기 쉽다
/*
class MyException extends Exception {
	public MyException() {
		super("This is my exception");
	}
}
public class Pro05_MyExcption {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter numerator : ");
		int x = sc.nextInt();
		System.out.print("Enter denominator : ");
		int y = sc.nextInt();
		try {
			divide(x, y);
		} catch (MyException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
	
	public static void divide(int x, int y) throws MyException {
		if (y == 0)
			throw new MyException();
		else
			System.out.println(x / y);	
	}
}*/
class MyException extends Exception {
	public MyException() {
		super("This is my exception");
	}
}
public class Pro05_MyExcption {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter numerator : ");
		int x = sc.nextInt();
		System.out.print("Enter denominator : ");
		int y = sc.nextInt();
		divide(x, y);
	}
	
	public static void divide(int x, int y) {
		int result = 0;
		
		try {
			if (y == 0)
				throw new MyException();
			result = x / y;
		} catch (MyException e) {
			System.out.println("분모가 0입니다.\n");
			System.out.println(e.getMessage());
			e.printStackTrace();
		} catch (Exception e) {	// exception이 최상위 클래스이기 때문에 위에서 잡지 못 한 예외를 잡는다!! (안전장치)
			System.out.println(e.getMessage());
		}
		System.out.println("Result is " + result);
	}
}