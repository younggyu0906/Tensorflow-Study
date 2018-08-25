class Person implements Comparable{
	private String name;
	private int height;
	
	Person() {	// 디폴트 생성자
		name = null;
		height = 0;
	}
	Person(String n, int h) { 	// 모든 필드를 초기화 하는 생성자
		name = n;
		height = h;
	}
	// 각 필드의 접근자와 설정자
	public String getName() { return name; }
	public void setName(String name) { this.name = name; }
	public int getHeight() { return height; }
	public void setHeight(int height) { this.height = height; }

	public int compareTo(Object obj) {	// compareTo메소드 구현
		Person other = (Person)obj;
		if (this.height > other.height)
			return 1;
		else if (height < other.height)
			return -1;
		else
			return 0;
	}
	
	public String getMaximum(Person[] array) {	// 키가 가장 큰 사람의 이름을 반환하는 메소드
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
