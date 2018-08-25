import java.util.Scanner;

public class Ch05_pro03 {

	public static void main(String[] args) {
		int cm, feet;				// cm와 feet값을 저장할 변수 선언 int형
		double inch;				// inch를 저장할 변수 double형
		Scanner input = new Scanner(System.in);
		
		System.out.print("키를 입력하시오(정수, cm) : ");
		cm = input.nextInt();		// 키(cm)를 입력받음
		
		inch = cm / 2.54;			// cm단위를 inch로 환산
		if(inch < 12)				// 인치의 값이 12보다 작으면 피트로 환산 할 필요 없으므로 인치 값 출력
			System.out.print(cm + "cm는 " + inch + "입니다.");
		else {						// 인치의 값이 12보다 같거나 크면 피트로 환산
			feet = (int)(inch / 12); // 인치를 12로 나눈 몫 == 피트 , 피트는 int형이므로 inch를 int형으로 형변환한 후 연산
			inch = inch % 12;		// 인치를 12로 나눈 나머지 == 인치
			System.out.print(cm + "cm는 " + feet + "피트 " + inch + "인치 입니다.");
		}
	}
}
