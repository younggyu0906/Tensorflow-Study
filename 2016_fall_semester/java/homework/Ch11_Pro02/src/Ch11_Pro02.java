class Person {
	protected String name, address, phone;
	
	public Person() {	// 디폴트 생성자
		name = null;
		address = null;
		phone = null;
	}
	public Person(String n, String a, String p) {	// 모든 필드를 초기화 하는 생성자
		name = n;
		address = a;
		phone = p;
	}
	// 각 필드의 접근자와 설정자
	public String getName()					{ return name; }
	public void setName(String name)		{ this.name = name; }
	public String getAddress()				{ return address; }
	public void setAddress(String address)	{ this.address = address; }
	public String getPhone()				{ return phone; }
	public void setPhone(String phone)		{ this.phone = phone; }
	
	public String toString() {	// toString 메소드 
		return "name : " + name + ", address : " + address + ", phone : " + phone;
	}
	
	public boolean equals(Object obj) {	// equals 메소드
		if (obj instanceof Person) {		// 동일 클래스의 객체인가?
			Person other = (Person)obj;		// Object를 Person으로 형변환
			if (name == other.name && address == other.address && phone == other.phone)
				return true;	// 모든 필드 비교하여 전부 같으면 true 반환
			else
				return false;
		}
		else return false;
	}
}

class Customer extends Person {
	private int cusNum, mileage;
	
	public Customer() {	// 디폴트 생성자
		super(null, null, null);
		cusNum = 0;
		mileage = 0;
	}
	public Customer(String n, String a, String p, int c, int m) {	// 모든 필드를 초기화 하는 생성자
		super(n, a, p);
		cusNum = c;
		mileage = m;
	}
	// 각 필드의 접근자와 설정자
	public int getCusNum() { return cusNum; }
	public void setCusNum(int cusNum) { this.cusNum = cusNum; }
	public int getMileage() { return mileage; }
	public void setMileage(int mileage) { this.mileage = mileage; }
	
	public String toString() {	// toString 메소드 재정의
		return super.toString() + ", cusNum : " + cusNum + ", mileage : " + mileage;
	}
	public boolean equals(Object obj) {	// equals 메소드 재정의
		if(obj instanceof Person) {
			if (super.equals(obj)) {	// 기반 클래스의 equals 호출해서 비교
				Customer other = (Customer)obj;
				if (cusNum == other.cusNum && mileage == other.mileage)
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
public class Ch11_Pro02 {
	public static void main(String[] args) {
		Person p[] = new Person[3];	// Person객체 배열 3개 생성
		p[0] = new Person("person1", "p1Add", "010-1234-5678");
		// 기반 클래스 Person에 파생 클래스 Customer 저장
		p[1] = new Customer();
		p[2] = new Customer("kim", "CheonAn", "010-1234-5678", 1, 100);
		
		for(int i = 0; i < p.length; i++)		// toString 메소드를 이용하여 객체 출력
			System.out.println(p[i].toString());
		System.out.println(p[1].equals(p[2]));	// p[1]객체와 [2] 객체 비교
		
		// p[1] 객체 설정
		p[1].setName("kim");
		p[1].setAddress("CheonAn");
		p[1].setPhone("010-1234-5678");
		((Customer)p[1]).setCusNum(1);
		((Customer)p[1]).setMileage(100);
		
		for(int i = 0; i < p.length; i++)		// toString 메소드를 이용하여 객체 출력
			System.out.println(p[i].toString());
		System.out.println(p[1].equals(p[2]));	// p[1]객체와 [2] 객체 비교
	}
}
