class Dog {		// �������� ��Ÿ���� Ŭ����
	private String name;	// �������� �̸�
	private String breed;	// �������� ����
	private int age;		// �������� ����
	
	// �������� �̸��� ���̸� �ʱ�ȭ�ϴ� ������
	public Dog (String name, int age) {
		this.name = name;
		this.breed = null;	// �ʱ�ȭ ���� ���� �ʵ带 null�� �ʱ�ȭ
		this.age = age;
	}
	
	// �������� �̸�, ����, ���̸� �ʱ�ȭ�ϴ� ������
	public Dog (String name, String bread, int age) {
		this.name = name;
		this.breed = bread;
		this.age = age;
	}
	
	public void print() {	// �������� ����ϴ� ��� �޼ҵ�
		System.out.println("name : " + name + ", breed : " + breed + ", age : " + age);
	}
}

public class Ch09_Pro01 {
	public static void main(String[] args) {
		Dog d1 = new Dog("d1", 2);	// Dog��ü ����, �������� �̸��� ���̸� �ʱ�ȭ
		Dog d2 = new Dog("d2", "��ũ���׸���", 3);	// Dog��ü ����, �������� �̸�, ����, ���� �ʱ�ȭ
		
		d1.print();	// d1 ���
		d2.print();	// d2 ���
	}
}
