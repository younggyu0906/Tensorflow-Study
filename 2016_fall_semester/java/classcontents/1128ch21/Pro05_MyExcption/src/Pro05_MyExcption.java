import java.util.Scanner;
// if else ������ ����ϸ� ���� �ڵ�� ���� ������ ���׹��� ���̰� �Ǿ� ���� ��ƴ�.
// try catch ������ ����ϸ� ���� �ڵ�� ���������� �����ȴ�!
// �Լ����� ���� ó���ϴ� ���
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
			System.out.println("�и� 0�Դϴ�.\n");
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		System.out.println("Result is " + result);
	}
}
*/
// �Լ����� exception��ü�� ������ ��� // ���� ����ó���ϱ� ����
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
			System.out.println("�и� 0�Դϴ�.\n");
			System.out.println(e.getMessage());
			e.printStackTrace();
		} catch (Exception e) {	// exception�� �ֻ��� Ŭ�����̱� ������ ������ ���� �� �� ���ܸ� ��´�!! (������ġ)
			System.out.println(e.getMessage());
		}
		System.out.println("Result is " + result);
	}
}