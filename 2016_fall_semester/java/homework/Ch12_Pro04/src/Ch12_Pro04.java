class Person implements Comparable{
	private String name;
	private int height;
	
	Person() {	// ����Ʈ ������
		name = null;
		height = 0;
	}
	Person(String n, int h) { 	// ��� �ʵ带 �ʱ�ȭ �ϴ� ������
		name = n;
		height = h;
	}
	// �� �ʵ��� �����ڿ� ������
	public String getName() { return name; }
	public void setName(String name) { this.name = name; }
	public int getHeight() { return height; }
	public void setHeight(int height) { this.height = height; }

	public int compareTo(Object obj) {	// compareTo�޼ҵ� ����
		Person other = (Person)obj;
		if (this.height > other.height)
			return 1;
		else if (height < other.height)
			return -1;
		else
			return 0;
	}
	
	public String getMaximum(Person[] array) {	// Ű�� ���� ū ����� �̸��� ��ȯ�ϴ� �޼ҵ�
		Person max = new Person();
		max = array[0];
		for(int i = 0; i < array.length; i++) {
			if(array[i].compareTo(max) > 0) {
				max = array[i];
			}
		}
		return max.getName();
	}
}
public class Ch12_Pro04 {
	public static void main(String[] args) {
		Person p[] = new Person[4];
		p[0] = new Person("kim", 160);
		p[1] = new Person("lee", 170);
		p[2] = new Person("park", 180);
		p[3] = new Person();
		
		System.out.println(p[3].getMaximum(p));
	}
}
