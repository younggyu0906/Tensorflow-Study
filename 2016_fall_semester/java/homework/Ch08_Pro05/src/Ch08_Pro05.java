class Employee {
	private String name;	// �̸�
	private String phone;	// ��ȭ��ȣ
	private int salary;		// ����
	
	public String getName()				{ return name; }			// name getter
	public void setName(String name)	{ this.name = name; }		// name setter
	public String getPhone()			{ return phone; }			// phone getter
	public void setPhone(String phone)	{ this.phone = phone; }		// phone setter
	public int getSalary()				{ return salary; }			// salary getter
	public void setSalary(int salary)	{ this.salary = salary; }	// salary setter
	public void print() {	// ��� �޼ҵ�
		System.out.println("Name : " + name + "\nPhone : " + phone + "\nSalary : " + salary);
	}
}

public class Ch08_Pro05 {
	public static void main(String[] args) {
		Employee e1 = new Employee();	// ��ü ����
		e1.setName("Kim");			// �̸� ����
		e1.setPhone("010-1234-5678"); // ��ȭ��ȣ ����
		e1.setSalary(5632168);		// ���� ����
		e1.print();		// ���
	}
}
