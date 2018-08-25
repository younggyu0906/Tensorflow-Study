/*
class Car extends Object {	// extends Object �� ���� ������ �����Ǿ��ִ�.
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
		
		System.out.println(sc1 == sc2);			// ���� ��ü�� �����ϴ��� ����
		System.out.println(sc1.equals(sc2));	// ��ü���� field�� ���� ���� ������ ����
		// Object Ŭ�������� �����ϴ� equals �޼ҵ�� ==�� ����Ѵ�. (false)
		// ����, ��ü�� ������ ���Ϸ��� equals �޼ҵ带 overriding �ؾ� �Ѵ�.
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
	public boolean equals(Object obj) {	// equals method�� Object ��ü�� �Ű������� �޴´�
		if (obj instanceof Car) {		// ���� Ŭ������ ��ü�ΰ�?
			Car other = (Car)obj;		// Object�� Car�� ����ȯ
			if (speed == other.speed && gear == other.gear && color == other.color)
										// ��� field ��
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
	public boolean equals(Object obj) {	// equals method�� Object ��ü�� �Ű������� �޴´�
		if (obj instanceof Car) {		// ���� Ŭ������ ��ü�ΰ�?
			Car other = (Car)obj;		// Object�� Car�� ����ȯ
			if (speed == other.speed && gear == other.gear && color == other.color)
										// ��� field ��
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
		// �Ļ�Ŭ������ epuals�� turbo �� �Ұ�
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
	public boolean equals(Object obj) {	// equals method�� Object ��ü�� �Ű������� �޴´�
		if (obj instanceof Car) {		// ���� Ŭ������ ��ü�ΰ�?
			Car other = (Car)obj;		// Object�� Car�� ����ȯ
			if (speed == other.speed && gear == other.gear && color == other.color)
										// ��� field ��
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
	public boolean equals(Object obj) {		// ��� Ŭ������ equals ȣ���ؼ� ��
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
// ��� Ŭ������ ��ü������ �Ļ���ü�� ������ �� �ִ�!!!!!

class Car {
	int speed;
	int gear;
	String color;
	
	public Car(int s, int g, String c) {
		speed = s;
		gear = g;
		color = c;
	}
	public boolean equals(Object obj) {	// equals method�� Object ��ü�� �Ű������� �޴´�
		if (obj instanceof Car) {		// ���� Ŭ������ ��ü�ΰ�?
			Car other = (Car)obj;		// Object�� Car�� ����ȯ
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
	public boolean equals(Object obj) {		// ��� Ŭ������ equals ȣ���ؼ� ��
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
		
		System.out.println(sc1);		// �ڵ����� toSting() ȣ��
	}
}
// ��� Ŭ������ ��ü������ �Ļ���ü�� ������ �� �ִ�!!!!!
