import java.util.Scanner;

public class Ch06_pro10 {

	public static void main(String[] args) {
		long a = 0, b = 1, c;	// �Ǻ���ġ ������ �� ��
		int i;					// �ݺ����� �ϱ� ���� ����
		int num = 0;			// ��� �� �Ǻ���ġ ������ ���� ��, 0���� �ʱ�ȭ�Ͽ� if�� �ȿ��� �Է¹���
		Scanner input = new Scanner(System.in);
		
		while(true) {
			if(num < 3) {		// 3�̻��� ������ �Ǻ���ġ������ ����ϱ� ���� ����, 3�����̸� �ٽ� �Է��� �޴´�
				System.out.print("����� �Ǻ���ġ ������ ���� ���� �Է��Ͻÿ�(3�̻�) : ");
				num = input.nextInt();
			}
			else {
				System.out.print(a + " " + b);	// ù°, ��°�� ���
				for(i = 2; i < num; i++) {		// ��°�� ���ʹ� for������ ���
					c = a + b;					// c��  a + b�� ����
					a = b;						// a���� b�� ���� ����
					b = c;						// b���� c�� ���� ����
					System.out.print(" " + c);	// c�� ���
				}
				break;
			}
		}
	}
}
