import java.util.Scanner;

public class Ch06_pro09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char calculation; //���� ������ �� �� ������ ���� ������ ����
		double num1, num2, answer; //������ ����1, 2, ��� ���� ������ ����
		String str;
		Scanner input = new Scanner(System.in);
		
		while(true) {
			System.out.println("*************");
			System.out.println("+   Add");
			System.out.println("-   Subtract");
			System.out.println("*   Multiply");
			System.out.println("/   Divide");
			System.out.println("Q   Quit");
			System.out.println("*************");
			System.out.print("������ �����Ͻÿ� : ");
			str = input.next();
			calculation = str.charAt(0);  //string���� �Է¹޾Ƽ� 0��° ���ڿ��� char�� ����
			
			if(calculation == 'q' || calculation == 'Q') { //q, Q�� �ԷµǸ� ���ѷ��� ����
				break;
			}

			System.out.print("�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ");
			num1 = input.nextDouble();
			num2 = input.nextDouble();

			switch(calculation) {
				case '+': // +����
					answer = num1 + num2;
					System.out.println(answer);
					break;
				case '-': // -����
					answer = num1 - num2;
					System.out.println(answer);
					break;
				case '*': // *����
					answer = num1 * num2;
					System.out.println(answer);
					break;
				case '/': // /����
					if(num2 == 0) { // 0���� ���� ���
						System.out.println("0���� ���� �� �����ϴ�. �ٽ� �Է��Ͻÿ�.");
					}
					else { // 0���� ������ ��찡 �ƴ� ���
						answer = num1 / num2;
						System.out.println(answer);
					}
					break;
				default: //�Էµ� �����ڰ� +, -, *, /�� �ƴѰ��
					System.out.println("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻÿ�.");
					break;
			}
		}
	}
}
