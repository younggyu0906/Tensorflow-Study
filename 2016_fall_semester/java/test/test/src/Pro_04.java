import java.util.Scanner;

public class Pro_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final double PI = 3.1415926535;
		double rad, hei, vol;
		Scanner input = new Scanner(System.in);
		
		System.out.print("������� ������ : ");
		rad = (input.nextDouble());
		System.out.print("������� ���� : ");
		hei = (input.nextDouble());
		
		vol = rad * rad * hei * PI;
		System.out.println("������� ���Ǵ� " + vol + "�Դϴ�.");
		
		input.close();
	}

}
