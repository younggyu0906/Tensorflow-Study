import java.util.Scanner;

public class Pro04 {
		public static void main(String[] args) {
		double celsius, fahrenheit;
	
		Scanner input = new Scanner(System.in);
		System.out.print("ȭ���� �Է��Ͻÿ� : ");
		fahrenheit = input.nextDouble();
		celsius = 5.0 / 9 * (fahrenheit - 32);//����/���� = ����, ���� �ϳ��� �Ǽ�������!!!
	
		System.out.println("������ " + celsius);
		input.close();
	}
}
