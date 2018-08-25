// Set은 List와 유사하지만 순서는 상관 없고 동일한 원소를 가질 수 없다

import java.util.HashSet;		// HashCode()에 의한 순서
import java.util.TreeSet;		// alphabet 순서
import java.util.LinkedHashSet;	// 입력 순서

public class Pro01_Set {
	public static void main(String[] args) {
		LinkedHashSet<String> set = new LinkedHashSet<>();
		
		set.add("Milk");
		set.add("Bread");
		set.add("Butter");
		set.add("Cheese");
		set.add("Ham");
		set.add("Ham");		// 모든 set은 중복을 허요하지 않는다/
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
