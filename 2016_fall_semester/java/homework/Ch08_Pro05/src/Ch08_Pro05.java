class Employee {
	private String name;	// 이름
	private String phone;	// 전화번호
	private int salary;		// 연봉
	
	public String getName()				{ return name; }			// name getter
	public void setName(String name)	{ this.name = name; }		// name setter
	public String getPhone()			{ return phone; }			// phone getter
	public void setPhone(String phone)	{ this.phone = phone; }		// phone setter
	public int getSalary()				{ return salary; }			// salary getter
	public void setSalary(int salary)	{ this.salary = salary; }	// salary setter
	public void print() {	// 출력 메소드
		System.out.println("Name : " + name + "\nPhone : " + phone + "\nSalary : " + salary);
	}
}

public class Ch08_Pro05 {
	public static void main(String[] args) {
		Employee e1 = new Employee();	// 객체 생성
		e1.setName("Kim");			// 이름 설정
		e1.setPhone("010-1234-5678"); // 전화번호 설정
		e1.setSalary(5632168);		// 연봉 설정
		e1.print();		// 출력
	}
}
