import java.util.Scanner;

public class Ch06_pro09 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char calculation; //무슨 연산을 할 지 선택한 값을 저장할 변수
		double num1, num2, answer; //연산할 숫자1, 2, 계산 값을 저장할 변수
		String str;
		Scanner input = new Scanner(System.in);
		
		while(true) {
			System.out.println("*************");
			System.out.println("+   Add");
			System.out.println("-   Subtract");
			System.out.println("*   Multiply");
			System.out.println("/   Divide");
			System.out.println("Q   Quit");
			System.out.println("*************");
			System.out.print("연산을 선택하시오 : ");
			str = input.next();
			calculation = str.charAt(0);  //string으로 입력받아서 0번째 문자열을 char에 저장
			
			if(calculation == 'q' || calculation == 'Q') { //q, Q가 입력되면 무한루프 종료
				break;
			}

			System.out.print("두 수를 공백으로 분리하여 입력하시오 : ");
			num1 = input.nextDouble();
			num2 = input.nextDouble();

			switch(calculation) {
				case '+': // +연산
					answer = num1 + num2;
					System.out.println(answer);
					break;
				case '-': // -연산
					answer = num1 - num2;
					System.out.println(answer);
					break;
				case '*': // *연산
					answer = num1 * num2;
					System.out.println(answer);
					break;
				case '/': // /연산
					if(num2 == 0) { // 0으로 나눌 경우
						System.out.println("0으로 나눌 수 없습니다. 다시 입력하시오.");
					}
					else { // 0으로 나누는 경우가 아닐 경우
						answer = num1 / num2;
						System.out.println(answer);
					}
					break;
				default: //입력된 연산자가 +, -, *, /가 아닌경우
					System.out.println("잘못된 입력입니다. 다시 입력하시오.");
					break;
			}
		}
	}
}
