public class Ch06_pro06 {
	public static void main(String[] args) {
		boolean primeNumber;			// �Ҽ����� �ƴ����� ���� ���� ������ ����
		
		for(int i = 2; i <= 100; i++) {	// 2���� 100���� �Ҽ����� �ƴ����� �Ǻ�
			primeNumber = true;			// true�� �ʱ�ȭ
			for(int j = 2; j < i; j++) { 
				if(i % j == 0) { // i�� 2���� i-1���� ������ �������� 0�̸� �Ҽ��� �ƴ�
					primeNumber = false;
					break;
				}
				else
					continue;
			}
			if(primeNumber)		// i�� �Ҽ��� �� i ��� 
				System.out.print(i + " ");
			else
				continue;
		}
	}
}