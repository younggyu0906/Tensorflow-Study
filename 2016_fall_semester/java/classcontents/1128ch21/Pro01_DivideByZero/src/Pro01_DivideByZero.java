import java.util.Scanner;
/*
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("���� �Է� : ");
		int x = sc.nextInt();
		System.out.print("�и� �Է� : ");;
		int y = sc.nextInt();
		int result = x / y;
		System.out.println("Result : " + result);
		
		sc.close();
	}
}
*/
// Exception�� �߻��� �� �ִ� �ڵ带 try ���� �ȿ� �ִ´�
// catch ������ exception�� ��
/*
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int result = 0;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("���� �Է� : ");
		int x = sc.nextInt();
		System.out.print("�и� �Է� : ");;
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
//finally block�� option
public class Pro01_DivideByZero {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int result = 0;
		Scanner sc = new Scanner(System.in);

		System.out.print("���� �Է� : ");
		int x = sc.nextInt();
		System.out.print("�и� �Է� : ");;
		int y = sc.nextInt();
		try {
			result = x / y;
		} catch (ArithmeticException e) {
			System.out.println("Can not divide by 0");
		} finally {	// exception �߻��ϰ� ���ϰ� finally block ����
			System.out.println("Program reaches here");
			System.out.println("Result : " + result);
		}
		System.out.println("���α׷� ����");

		sc.close();
	}
}