
import java.util.*;

class Student {
	String grade;
	String name;
	public Student(String g, String n) {
		grade = g;
		name = n;
	}
	public String toString() {
		return grade + ", " + name;
	}
}
public class Pro05_Map {
	public static void main(String[] args) {
		// HashMap<String, Student> hm = new HashMap<>();
		LinkedHashMap<String, Student> hm = new LinkedHashMap<>();
		hm.put("3", new Student("Freshman", "lee"));
		hm.put("1", new Student("Sophomore", "Kim"));
		hm.put("2", new Student("Junior", "Park"));
		hm.put("2", new Student("Senior", "Choi"));	// key 값이 같으면 overwriting
		System.out.println(hm.size());
		System.out.println(hm.isEmpty());
		System.out.println(hm.containsKey("1"));
		System.out.println(hm); // hashcode
		
		hm.remove("2");
		System.out.println(hm);
		hm.put("4", new Student("Senior", "Choi"));
		System.out.println(hm);
		System.out.println(hm.get("3"));// value return, 없으면 null return
		
		for(String key : hm.keySet()) {
			System.out.println(key + ", " + hm.get(key));
		}
		for(Map.Entry<String, Student> s : hm.entrySet()) {
			String key = s.getKey();
			Student value = s.getValue();
			System.out.println("Key = " + key + ", value = " + value);
		}
	}
}
