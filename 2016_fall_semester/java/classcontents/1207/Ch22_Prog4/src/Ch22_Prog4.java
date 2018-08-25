// generic 클래스의 타입 매개변수는 클래스 이름 뒤에 붙인다
// generic 메서드의 타입 매개변수는 반환형 앞에 붙인다

public class Ch22_Prog4 {
	public <T> void print(T obj) {
		System.out.println(obj.getClass().getName());
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ch22_Prog4 t = new Ch22_Prog4();
		
		t.print(10);// auto boxing
		t.print(new Double(10.5));
		t.print(t);
	}
}
