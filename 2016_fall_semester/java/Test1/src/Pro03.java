import java.util.Scanner;

public class Pro03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double rad, vol;
		final double PI = 3.1415926535;
		
		Scanner input = new Scanner(System.in);
		System.out.print("Enter radius : ");
		rad = input.nextDouble();
		vol = 4.0 / 3.0 * PI * rad * rad * rad;//����/���� = ����, ���� �ϳ��� �Ǽ�������!!!
		
		System.out.println("Volume is " + vol);
		System.out.printf("Volume : %.2f\n", vol);
		
		System.out.println(4 / 3);
		System.out.println(4.0 / 3.0);
		System.out.println(4.0 / 3);
		System.out.println((double)4 / 3);
		
		input.close();
	}

}
