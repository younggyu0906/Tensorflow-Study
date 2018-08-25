// ���� ������ �ſ� ����
// ���� : list ���� ÷�ڸ� �̿��� ���� ����
// ���� : list �߰��� ����, ������ ��� list ��ü ����

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
		
		for (int i = 0; i < list.size(); i++) // for loop�� �̿��� ���
			System.out.println(list.get(i));
		System.out.println();
		
		Iterator<String> e = list.iterator(); // Iterator�� �̿��� ��� // �̷��� �ִٴ� �͸� �˾ƵѰ�
		String s;
		while (e.hasNext()) {
			s = (String)e.next();	// Object�� �����ϱ� ������ ����ȯ �ʿ�
			System.out.println(s);
		}
		System.out.println();
		
		for (String str : list)	// Iterator interface�� ������ for-each loop
			System.out.println(str);
		System.out.println();
		
		System.out.println(list); 	// println�� ����� ��� ���
		
		System.out.println(list.indexOf("Bread")); 	// ������ -1 ����
		System.out.println(list.indexOf("Apple"));
		System.out.println(list.lastIndexOf("Apple"));
	}
}
