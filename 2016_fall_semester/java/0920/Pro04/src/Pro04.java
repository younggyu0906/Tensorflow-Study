import java.util.Scanner;

public class Pro04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, i;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("단을 입력하시오 : ");
		n = sc.nextInt();
		
		i = 1;
		while (i <= 9) {
			System.out.println(n + " * " + i + " = " + n * i);
			//연산식은 () 사용
			i++;
		}
		i = 1;
		do {
			System.out.println(n + " * " + i + " = " + n * i);
			i++;
		} while (i <= 9);
		
		for (i = 1; i <= 9; i++) {
			System.out.println(n + " * " + i + " = " + n * i);
		}
	}

}
