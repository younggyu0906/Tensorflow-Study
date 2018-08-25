// Set�� List�� ���������� ������ ��� ���� ������ ���Ҹ� ���� �� ����

import java.util.HashSet;		// HashCode()�� ���� ����
import java.util.TreeSet;		// alphabet ����
import java.util.LinkedHashSet;	// �Է� ����

public class Pro01_Set {
	public static void main(String[] args) {
		LinkedHashSet<String> set = new LinkedHashSet<>();
		
		set.add("Milk");
		set.add("Bread");
		set.add("Butter");
		set.add("Cheese");
		set.add("Ham");
		set.add("Ham");		// ��� set�� �ߺ��� ������� �ʴ´�/
		set.remove("Ham");
		System.out.println(set);
		System.out.println(set.size());
		
		String[] sample = {"Java", "is", "fun", "Java", "easy?"};
		
		for (int i = 0; i < sample.length; i++)
			if(!set.add(sample[i]))
				System.out.println(sample[i] + "is already in set");
		System.out.println(set);
	}
}
