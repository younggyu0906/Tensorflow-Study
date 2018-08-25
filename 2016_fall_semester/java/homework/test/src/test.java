/*
class Car extends Object {	// extends Object 을 쓰지 않으면 생략되어있다.
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
}
public class Pro01_Equltest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car sc1 = new Car(100, 3, "Red");
		Car sc2 = new Car(100, 3, "Red");
		
		System.out.println(sc1 == sc2);			// 동일 객체를 참조하는지 여부
		System.out.println(sc1.equals(sc2));	// 객체들의 field가 같은 값을 갖는지 여부
		// Object 클래스에서 제공하는 equals 메소드는 ==를 사용한다. (false)
		// 따라서, 객체의 내용을 비교하려면 equals 메소드를 overriding 해야 한다.
	}
}
*/
/*
class Car {
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
	public boolean equals(Object obj) {	// equals method는 Object 객체를 매개변수로 받는다
		if (obj instanceof Car) {		// 동일 클래스의 객체인가?
			Car other = (Car)obj;		// Object를 Car로 형변환
			if (speed == other.speed && gear == other.gear && color == other.color)
										// 모든 field 비교
				return true;
			else
				return false;
		}
		else return false;
	}
}
public class Pro01_Equltest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car sc1 = new Car(100, 3, "Red");
		Car sc2 = new Car(100, 3, "Red");
		
		System.out.println(sc1 == sc2);
		System.out.println(sc1.equals(sc2));
	}
}
*/
/*
class Car {
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
	public boolean equals(Object obj) {	// equals method는 Object 객체를 매개변수로 받는다
		if (obj instanceof Car) {		// 동일 클래스의 객체인가?
			Car other = (Car)obj;		// Object를 Car로 형변환
			if (speed == other.speed && gear == other.gear && color == other.color)
										// 모든 field 비교
				return true;
			else
				return false;
		}
		else return false;
	}
}
class SportsCar extends Car {
		boolean turbo;
	public SportsCar(int s, int g, String c, boolean t) {
		super(s, g, c);
		turbo = t;
	}
}
public class Pro01_Equltest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car sc1 = new SportsCar(100, 3, "Red", true);
		Car sc2 = new SportsCar(100, 3, "Red", false);
		
		System.out.println(sc1 == sc2);
		System.out.println(sc1.equals(sc2));
		// 파생클래스에 epuals가 turbo 비교 불가
	}
}

public class Pro01_Equltest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SportsCar sc1 = new Car(100, 3, "Red");
		SportsCar sc2 = new Car(100, 3, "Red");
		
		System.out.println(sc1 == sc2);
		System.out.println(sc1.equals(sc2));
	}
}
*/
/*
class Car {
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
	public boolean equals(Object obj) {	// equals method는 Object 객체를 매개변수로 받는다
		if (obj instanceof Car) {		// 동일 클래스의 객체인가?
			Car other = (Car)obj;		// Object를 Car로 형변환
			if (speed == other.speed && gear == other.gear && color == other.color)
										// 모든 field 비교
				return true;
			else
				return false;
		}
		else return false;
	}
}
class SportsCar extends Car {
		boolean turbo;
	public SportsCar(int s, int g, String c, boolean t) {
		super(s, g, c);
		turbo = t;
	}
	public boolean equals(Object obj) {		// 기반 클래스의 equals 호출해서 비교
		if(obj instanceof SportsCar) {
			if (super.equals(turbo)) {
				SportsCar other = (SportsCar)obj;
				if (turbo == other.turbo)
					return true;
				else
					return false;
			}
			return
					false;
		}
		return
				false;
	}
}
	
public class Pro01_Equltest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SportsCar sc1 = new SportsCar(100, 3, "Red", true);
		SportsCar sc2 = new SportsCar(100, 3, "Red", true);
		
		System.out.println(sc1 == sc2);
		System.out.println(sc1.equals(sc2));
	}
}
*/
// 기반 클래스의 객체변수는 파생객체를 참조할 수 있다!!!!!

class Car {
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
	public boolean equals(Object obj) {	// equals method는 Object 객체를 매개변수로 받는다
		if (obj instanceof Car) {		// 동일 클래스의 객체인가?
			Car other = (Car)obj;		// Object를 Car로 형변환
			if (speed == other.speed && gear == other.gear && color == other.color)
				return true;
			else
				return false;
		}
		else return false;
	}
	public String toString() {
		return speed + ", " + gear + ", " + color;
	}
}
class SportsCar extends Car {
		boolean turbo;
	public SportsCar(int s, int g, String c, boolean t) {
		super(s, g, c);
		turbo = t;
	}
	public boolean equals(Object obj) {		// 기반 클래스의 equals 호출해서 비교
		if(obj instanceof SportsCar) {
			if (super.equals(obj)) {
				SportsCar other = (SportsCar)obj;
				if (turbo == other.turbo)
					return true;
				else
					return false;
			}
			return
					false;
		}
		return
				false;
	}
	public String toStrong() {
		return super.toString() + ", " + turbo;
	}
}
	
public class test {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SportsCar sc1 = new SportsCar(100, 3, "Red", true);
		SportsCar sc2 = new SportsCar(100, 3, "Red", true);
		
		System.out.println(sc1 == sc2);
		System.out.println(sc1.equals(sc2));
		
		System.out.println(sc1);		// 자동으로 toSting() 호출
	}
}
// 기반 클래스의 객체변수는 파생객체를 참조할 수 있다!!!!!
