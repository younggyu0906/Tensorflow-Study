import java.util.Scanner;

public class Pro_02 {

	public static void main(String[] args) {
		int n1, n2, max, min;
		Scanner input = new Scanner(System.in);
		
		System.out.print("정수를 입력하시오: ");
		n1 = (input.nextInt());
		System.out.print("정수를 입력하시오: ");
		n2 = (input.nextInt());
		
		if(n1 > n2) {
			max = n1;
			min = n2;
		}
		else {
			max = n2;
			min = n1;
		}
		System.out.println("큰수를 작은수로 나눈 몫은 " + (max / min) + "이고 나머지는 " + (max % min) + "입니다");
		
		max = (n1 > n2) ? n1 : n2;
		min = (n1 > n2) ? n2 : n1;
		System.out.println("큰수를 작은수로 나눈 몫은 " + (max / min) + "이고 나머지는 " + (max % min) + "입니다");
		
		max = Math.max(n1, n2);
		min = Math.min(n1, n2);
		System.out.println("큰수를 작은수로 나눈 몫은 " + (max / min) + "이고 나머지는 " + (max % min) + "입니다");

		input.close();
	}

}
