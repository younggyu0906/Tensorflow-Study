class Person {
	protected String name, address, phone;
	
	public Person() {	// ����Ʈ ������
		name = null;
		address = null;
		phone = null;
	}
	public Person(String n, String a, String p) {	// ��� �ʵ带 �ʱ�ȭ �ϴ� ������
		name = n;
		address = a;
		phone = p;
	}
	// �� �ʵ��� �����ڿ� ������
	public String getName()					{ return name; }
	public void setName(String name)		{ this.name = name; }
	public String getAddress()				{ return address; }
	public void setAddress(String address)	{ this.address = address; }
	public String getPhone()				{ return phone; }
	public void setPhone(String phone)		{ this.phone = phone; }
	
	public String toString() {	// toString �޼ҵ� 
		return "name : " + name + ", address : " + address + ", phone : " + phone;
	}
	
	public boolean equals(Object obj) {	// equals �޼ҵ�
		if (obj instanceof Person) {		// ���� Ŭ������ ��ü�ΰ�?
			Person other = (Person)obj;		// Object�� Person���� ����ȯ
			if (name == other.name && address == other.address && phone == other.phone)
				return true;	// ��� �ʵ� ���Ͽ� ���� ������ true ��ȯ
			else
				return false;
		}
		else return false;
	}
}

class Customer extends Person {
	private int cusNum, mileage;
	
	public Customer() {	// ����Ʈ ������
		super(null, null, null);
		cusNum = 0;
		mileage = 0;
	}
	public Customer(String n, String a, String p, int c, int m) {	// ��� �ʵ带 �ʱ�ȭ �ϴ� ������
		super(n, a, p);
		cusNum = c;
		mileage = m;
	}
	// �� �ʵ��� �����ڿ� ������
	public int getCusNum() { return cusNum; }
	public void setCusNum(int cusNum) { this.cusNum = cusNum; }
	public int getMileage() { return mileage; }
	public void setMileage(int mileage) { this.mileage = mileage; }
	
	public String toString() {	// toString �޼ҵ� ������
		return super.toString() + ", cusNum : " + cusNum + ", mileage : " + mileage;
	}
	public boolean equals(Object obj) {	// equals �޼ҵ� ������
		if(obj instanceof Person) {
			if (super.equals(obj)) {	// ��� Ŭ������ equals ȣ���ؼ� ��
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
		Person p[] = new Person[3];	// Person��ü �迭 3�� ����
		p[0] = new Person("person1", "p1Add", "010-1234-5678");
		// ��� Ŭ���� Person�� �Ļ� Ŭ���� Customer ����
		p[1] = new Customer();
		p[2] = new Customer("kim", "CheonAn", "010-1234-5678", 1, 100);
		
		for(int i = 0; i < p.length; i++)		// toString �޼ҵ带 �̿��Ͽ� ��ü ���
			System.out.println(p[i].toString());
		System.out.println(p[1].equals(p[2]));	// p[1]��ü�� [2] ��ü ��
		
		// p[1] ��ü ����
		p[1].setName("kim");
		p[1].setAddress("CheonAn");
		p[1].setPhone("010-1234-5678");
		((Customer)p[1]).setCusNum(1);
		((Customer)p[1]).setMileage(100);
		
		for(int i = 0; i < p.length; i++)		// toString �޼ҵ带 �̿��Ͽ� ��ü ���
			System.out.println(p[i].toString());
		System.out.println(p[1].equals(p[2]));	// p[1]��ü�� [2] ��ü ��
	}
}
