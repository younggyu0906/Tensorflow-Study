import java.util.Scanner;

//����� ���� ����, Exception Ŭ���� ��ӹ���
class NotFoundException extends Exception {
	public NotFoundException() {
		super("Not Found Exception");	// ���� �޽���
	}
}

public class Ch21_Pro03 {
	public static void main(String[] args) {
		int array[] = {0, 1, 2, 3, 4};			// �迭 ����
		Scanner in = new Scanner(System.in);
		System.out.print("Enter number : ");
		int num = in.nextInt();	// ã������ �� �Է¹���
		
		try {	// ���ܰ� �߻��� �� �ִ� �ڵ�
			searchArray(array, num);
		} catch (NotFoundException e) {			// ����ó��
			System.out.println(e.getMessage());	// �ֿܼ� ���� �޽��� ���
			e.printStackTrace();				// ������ �߻��� ���� ���
		}
	}
	// �迭�� ��Ҹ� ã�� ���� �޼ҵ�
	public static void searchArray(int a[], int num) throws NotFoundException {
		for(int i = 0; i < a.length; i++) {
			if(a[i] == num) {	// �迭�� ã������ ��Ұ� ������ ��� �� ����
				System.out.println("Search success!!\na[" + i + "] = " + a[i]);
				return;
			}
		}
		// ã������ ���� �迭�� ������ ���� �߻���Ű�� ����
		throw new NotFoundException();
	}
}
