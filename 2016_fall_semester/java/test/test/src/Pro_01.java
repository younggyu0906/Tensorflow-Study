import java.util.Scanner;

public class Pro_01 {
	public static void main(String[] args) {
		String name;
		int age;
		Scanner in = new Scanner(System.in);
		/*
		System.out.print("�̸� : ");
		name = (in.nextLine());
		System.out.print("���� : ");
		age = (in.nextInt());
		*/	
		System.out.print("���� : ");
		age = (in.nextInt());
		
		in.nextLine();  //Ű���� ������ ����Ű �Ҹ�(���ڸ� �Է��� ���� ����Ű)
		//in.skip("\r\n"); //���ͼҸ�
		
		System.out.print("�̸� : ");
		name = (in.nextLine());
	
		System.out.println("�̸��� " + name + "�̰� ���̴� " + age + "�Դϴ�");
		
		in.close();
	}
}