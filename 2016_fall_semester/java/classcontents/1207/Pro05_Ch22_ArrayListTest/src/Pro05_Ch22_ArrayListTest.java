// 가변 길이의 매열 구현
// 장점 : list 원소 첨자를 이용한 빠른 접근
// 단점 : list 중간에 삽입, 삭제할 경우 list 전체 변경

import java.util.*;

public class Pro05_Ch22_ArrayListTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> list = new ArrayList<>();
		
		list.add("Milk");
		list.add("Bread");
		list.add("Butter");
		list.add(1, "Apple");
		list.set(2, "Grape");
		list.remove(3);
		list.add("Apple");
		
		for (int i = 0; i < list.size(); i++) // for loop를 이용한 출력
			System.out.println(list.get(i));
		System.out.println();
		
		Iterator<String> e = list.iterator(); // Iterator를 이용한 출력 // 이런게 있다는 것만 알아둘것
		String s;
		while (e.hasNext()) {
			s = (String)e.next();	// Object를 리턴하기 때문에 형변환 필요
			System.out.println(s);
		}
		System.out.println();
		
		for (String str : list)	// Iterator interface를 개선한 for-each loop
			System.out.println(str);
		System.out.println();
		
		System.out.println(list); 	// println을 사용한 출력 방법
		
		System.out.println(list.indexOf("Bread")); 	// 없으면 -1 리턴
		System.out.println(list.indexOf("Apple"));
		System.out.println(list.lastIndexOf("Apple"));
	}
}
