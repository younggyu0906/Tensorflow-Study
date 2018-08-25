// Collections class�� collection Ŭ�����鿡 ���� �پ��� �Լ��� �����Ѵ�

import java.util.*;

public class Pro06_Collections {
	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<>();
		
		for (int i = 10; i > 0; i--)
			list.add(i);
		System.out.println(list);
		Collections.sort(list);
		System.out.println(list);
		
		int index = Collections.binarySearch(list, 3);	// ������ �Ǿ�� Ž�� ����
		System.out.println(index);
		
		Collections.reverse(list);
		System.out.println(list);
		
		Collections.swap(list, 1, 2);
		System.out.println(list);
		
		Collections.shuffle(list);
		System.out.println(list);
		
		System.out.println(Collections.min(list));
		System.out.println(Collections.max(list));
	}
}