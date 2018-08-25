import java.util.Scanner;

public class Pro_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final double PI = 3.1415926535;
		double rad, hei, vol;
		Scanner input = new Scanner(System.in);
		
		System.out.print("원기둥의 반지름 : ");
		rad = (input.nextDouble());
		System.out.print("원기둥의 높이 : ");
		hei = (input.nextDouble());
		
		vol = rad * rad * hei * PI;
		System.out.println("원기둥의 부피는 " + vol + "입니다.");
		
		input.close();
	}

}
