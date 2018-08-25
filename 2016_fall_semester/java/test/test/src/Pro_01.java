import java.util.Scanner;

public class Pro_01 {
	public static void main(String[] args) {
		String name;
		int age;
		Scanner in = new Scanner(System.in);
		/*
		System.out.print("이름 : ");
		name = (in.nextLine());
		System.out.print("나이 : ");
		age = (in.nextInt());
		*/	
		System.out.print("나이 : ");
		age = (in.nextInt());
		
		in.nextLine();  //키보드 버퍼의 엔터키 소멸(숫자를 입력한 후의 엔터키)
		//in.skip("\r\n"); //엔터소멸
		
		System.out.print("이름 : ");
		name = (in.nextLine());
	
		System.out.println("이름은 " + name + "이고 나이는 " + age + "입니다");
		
		in.close();
	}
}