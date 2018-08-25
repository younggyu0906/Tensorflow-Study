import java.io.IOException;
/*
public class Pro04_ExceptionTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(readString());
	}
	public static String readString() {
		byte[] buf = new byte[10];
		System.out.println("Enter string : ");
		try {
			System.in.read(buf);
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
		return new String(buf);
	}
}
*/
// IOException�� ȣ�� method�� �����ϴ� ���
public class Pro04_ExceptionTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println(readString());
		} catch (IOException e) {
			System.out.println(e.getMessage());	// exception�� �ذ��ϱ� ���� ����
			e.printStackTrace();
		}
	}
	// �ݵ�� throws �ڿ� exception ������ �����Ѵ�
	public static String readString() throws IOException {
		byte[] buf = new byte[10];
		System.out.println("Enter string : ");
		System.in.read(buf);	//byte �迭�� Ű���� �Է� ����
		return new String(buf);	//byte �迭�� String���� ��ȯ
	}
}
