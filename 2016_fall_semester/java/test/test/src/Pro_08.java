import java.util.Scanner;
/*
public class Pro_08 {
	public static void main(String[] args) {
		int diameter = 150_000_000;
		int lightspeed = 300_000;
		
		System.out.println("거리 " + diameter / lightspeed);
	}
}*/


public class Pro_08 {
	public static void main(String[] args) {
		double distance = 1.5e8;//대문자도 가능(1.5E8)
		double speed = 3.0e5;
		double time = distance / speed;
		
		System.out.println("Time : " + time + "sec");
	}
}
