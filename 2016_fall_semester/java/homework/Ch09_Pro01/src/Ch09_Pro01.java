class Dog {		// 강아지를 나타내는 클래스
	private String name;	// 강아지의 이름
	private String breed;	// 강아지의 종류
	private int age;		// 강아지의 나이
	
	// 강아지의 이름과 나이를 초기화하는 생성자
	public Dog (String name, int age) {
		this.name = name;
		this.breed = null;	// 초기화 되지 않은 필드를 null로 초기화
		this.age = age;
	}
	
	// 강아지의 이름, 종류, 나이를 초기화하는 생성자
	public Dog (String name, String bread, int age) {
		this.name = name;
		this.breed = bread;
		this.age = age;
	}
	
	public void print() {	// 강아지를 출력하는 출력 메소드
		System.out.println("name : " + name + ", breed : " + breed + ", age : " + age);
	}
}

public class Ch09_Pro01 {
	public static void main(String[] args) {
		Dog d1 = new Dog("d1", 2);	// Dog객체 생성, 강아지의 이름과 나이를 초기화
		Dog d2 = new Dog("d2", "요크셔테리어", 3);	// Dog객체 생성, 강아지의 이름, 나이, 종류 초기화
		
		d1.print();	// d1 출력
		d2.print();	// d2 출력
	}
}
