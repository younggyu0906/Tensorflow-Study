import java.util.Scanner;

public class Ch05_pro03 {

	public static void main(String[] args) {
		int cm, feet;				// cm�� feet���� ������ ���� ���� int��
		double inch;				// inch�� ������ ���� double��
		Scanner input = new Scanner(System.in);
		
		System.out.print("Ű�� �Է��Ͻÿ�(����, cm) : ");
		cm = input.nextInt();		// Ű(cm)�� �Է¹���
		
		inch = cm / 2.54;			// cm������ inch�� ȯ��
		if(inch < 12)				// ��ġ�� ���� 12���� ������ ��Ʈ�� ȯ�� �� �ʿ� �����Ƿ� ��ġ �� ���
			System.out.print(cm + "cm�� " + inch + "�Դϴ�.");
		else {						// ��ġ�� ���� 12���� ���ų� ũ�� ��Ʈ�� ȯ��
			feet = (int)(inch / 12); // ��ġ�� 12�� ���� �� == ��Ʈ , ��Ʈ�� int���̹Ƿ� inch�� int������ ����ȯ�� �� ����
			inch = inch % 12;		// ��ġ�� 12�� ���� ������ == ��ġ
			System.out.print(cm + "cm�� " + feet + "��Ʈ " + inch + "��ġ �Դϴ�.");
		}
	}
}
