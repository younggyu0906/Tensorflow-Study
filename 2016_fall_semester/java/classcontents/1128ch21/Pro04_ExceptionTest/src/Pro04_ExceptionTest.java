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
// IOException을 호출 method에 전달하는 방법
public class Pro04_ExceptionTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println(readString());
		} catch (IOException e) {
			System.out.println(e.getMessage());	// exception으 해결하기 위한 도구
			e.printStackTrace();
		}
	}
	// 반드시 throws 뒤에 exception 종류를 나열한다
	public static String readString() throws IOException {
		byte[] buf = new byte[10];
		System.out.println("Enter string : ");
		System.in.read(buf);	//byte 배열에 키보드 입력 저장
		return new String(buf);	//byte 배열을 String으로 변환
	}
}
