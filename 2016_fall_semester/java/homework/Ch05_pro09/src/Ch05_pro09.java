import java.util.Scanner;

public class Ch05_pro09 {

	public static void main(String[] args) {
		double force, area, pressure;
		Scanner input = new Scanner(System.in);
		
		System.out.print("��ü�� �־��� ���� �Է��Ͻÿ� : ");
		force = input.nextDouble();	// ��ü�� �־��� ��
		System.out.print("��ü�� ������ �Է��Ͻÿ� : ");
		area = input.nextDouble();	// ��ü�� ����
		
		pressure = force / area;	// �з� = �� / ����
		System.out.println("�з��� ����� " + pressure + " �Դϴ�.");
	}
}
