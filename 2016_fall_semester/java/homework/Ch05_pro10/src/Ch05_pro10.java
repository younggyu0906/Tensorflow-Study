import java.util.Scanner;

public class Ch05_pro10 {

	public static void main(String[] args) {
		double sBase, pBase, sHieght, pHieght;
		Scanner input = new Scanner(System.in);
		
		System.out.print("�������� �׸��� ���� : ");
		sBase = input.nextDouble();				// �������� �׸��� ���� AC
		System.out.print("�������� ���� : ");
		sHieght = input.nextDouble();			// �������� ���� BC
		System.out.print("�Ƕ�̵� �׸��� ���� : ");
		pBase = input.nextDouble();				// �Ƕ�̵� �׸��� ���� AE
		
		pHieght = (pBase * sHieght) / sBase;	// DE = AE * BC / AC
		System.out.println("�Ƕ�̵��� ���̴� " + pHieght + " �Դϴ�.");
	}
}
