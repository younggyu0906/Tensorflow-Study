import java.util.Scanner;

//사용자 정의 예외, Exception 클래스 상속받음
class NotFoundException extends Exception {
	public NotFoundException() {
		super("Not Found Exception");	// 예외 메시지
	}
}

public class Ch21_Pro03 {
	public static void main(String[] args) {
		int array[] = {0, 1, 2, 3, 4};			// 배열 생성
		Scanner in = new Scanner(System.in);
		System.out.print("Enter number : ");
		int num = in.nextInt();	// 찾으려는 수 입력받음
		
		try {	// 예외가 발생할 수 있는 코드
			searchArray(array, num);
		} catch (NotFoundException e) {			// 예외처리
			System.out.println(e.getMessage());	// 콘솔에 오류 메시지 출력
			e.printStackTrace();				// 오류가 발생한 정보 출력
		}
	}
	// 배열의 요소를 찾는 정적 메소드
	public static void searchArray(int a[], int num) throws NotFoundException {
		for(int i = 0; i < a.length; i++) {
			if(a[i] == num) {	// 배열에 찾으려는 요소가 있으면 출력 후 리턴
				System.out.println("Search success!!\na[" + i + "] = " + a[i]);
				return;
			}
		}
		// 찾으려는 수가 배열에 없으면 예외 발생시키고 던짐
		throw new NotFoundException();
	}
}
