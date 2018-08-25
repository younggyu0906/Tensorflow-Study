// 일반 클래스의 메소드를 generic 메소드로 작성
class GenericMethod {
	public <E> void printArray(E[] array) {
		// 타입 매개변수는 반드시 수식자와 반환형 사이에 기술
		for (int i = 0; i < array.length; i++)
			System.out.println(array[i] + " ");
		System.out.println("\n");
	}
}
public class Pro03_Ch22_GenericMethodTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer[] intArray = {1, 2, 3, 4, 5, 6};
		Double[] dArray = {1.1, 2.2, 3.3, 4.4};
		Character[] cArray = {'H', 'e', 'l', 'l', 'o'};
		String[] sArray = {"lee", "kim", "choi"};	// 새로운 타입 추가 기능
	
		GenericMethod gm = new GenericMethod();
		gm.<Integer>printArray(intArray);	// 타입 생략 가능
		gm.printArray(dArray);
		gm.printArray(cArray);
		gm.printArray(sArray);
	}

}
