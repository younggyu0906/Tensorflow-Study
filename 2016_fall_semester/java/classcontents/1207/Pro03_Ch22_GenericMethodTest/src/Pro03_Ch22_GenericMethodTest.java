// �Ϲ� Ŭ������ �޼ҵ带 generic �޼ҵ�� �ۼ�
class GenericMethod {
	public <E> void printArray(E[] array) {
		// Ÿ�� �Ű������� �ݵ�� �����ڿ� ��ȯ�� ���̿� ���
		for (int i = 0; i < array.length; i++)
			System.out.println(array[i] + " ");
		System.out.println("\n");
	}
}
public class Pro03_Ch22_GenericMethodTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer[] intArray = {1, 2, 3, 4, 5, 6};
		Double[] dArray = {1.1, 2.2, 3.3, 4.4};
		Character[] cArray = {'H', 'e', 'l', 'l', 'o'};
		String[] sArray = {"lee", "kim", "choi"};	// ���ο� Ÿ�� �߰� ���
	
		GenericMethod gm = new GenericMethod();
		gm.<Integer>printArray(intArray);	// Ÿ�� ���� ����
		gm.printArray(dArray);
		gm.printArray(cArray);
		gm.printArray(sArray);
	}

}
