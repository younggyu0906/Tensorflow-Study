import java.util.*;

public class Pro02_Lotto {
	public static void main(String[] args) {
		Random rand = new Random();
		HashSet<Integer> set = new HashSet<Integer>();
		int count = 0;
		int num;
		
		while (count < 6) {
			num = rand.nextInt(45) + 1;
			while (!set.add(num))	// num이 있으면 false 리턴
				num = rand.nextInt(45) + 1;
			count++;
		}
		System.out.println(set);
	}
}
