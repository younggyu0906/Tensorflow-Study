import java.util.Scanner;

public class Ch05_pro09 {

	public static void main(String[] args) {
		double force, area, pressure;
		Scanner input = new Scanner(System.in);
		
		System.out.print("물체에 주어진 힘을 입력하시오 : ");
		force = input.nextDouble();	// 물체에 주어진 힘
		System.out.print("물체의 면적을 입력하시오 : ");
		area = input.nextDouble();	// 물체의 면적
		
		pressure = force / area;	// 압력 = 힘 / 면적
		System.out.println("압력의 세기는 " + pressure + " 입니다.");
	}
}
