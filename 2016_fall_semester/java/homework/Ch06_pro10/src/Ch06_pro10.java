import java.util.Scanner;

public class Ch06_pro10 {

	public static void main(String[] args) {
		long a = 0, b = 1, c;	// 피보나치 수열의 세 항
		int i;					// 반복문을 하기 위한 변수
		int num = 0;			// 출력 할 피보나치 수열의 항의 수, 0으로 초기화하여 if문 안에서 입력받음
		Scanner input = new Scanner(System.in);
		
		while(true) {
			if(num < 3) {		// 3이상일 경우부터 피보나치수열을 출력하기 위한 조건, 3이하이면 다시 입력을 받는다
				System.out.print("출력할 피보나치 수열의 항의 수를 입력하시오(3이상) : ");
				num = input.nextInt();
			}
			else {
				System.out.print(a + " " + b);	// 첫째, 둘째항 출력
				for(i = 2; i < num; i++) {		// 셋째항 부터는 for문에서 출력
					c = a + b;					// c에  a + b값 저장
					a = b;						// a에는 b의 값을 저장
					b = c;						// b에는 c의 값을 저장
					System.out.print(" " + c);	// c값 출력
				}
				break;
			}
		}
	}
}
