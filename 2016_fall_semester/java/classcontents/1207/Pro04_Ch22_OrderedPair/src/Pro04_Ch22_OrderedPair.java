// 타입 매개변수는 여러개를 지정할 수 있다.

class OrderedPair<K, V> {	// Key, Value
	private K key;
	private V value;
	
	public OrderedPair(K k, V v) {
		key = k;
		value = v;
	}
	public K getKey() {
		return key;
	}
	public V getValue() {
		return value;
	}
}
public class Pro04_Ch22_OrderedPair {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		OrderedPair<String, Integer> p1 = new OrderedPair<>("Even", 8);
		OrderedPair<String, String> p2 = new OrderedPair<>("hello", "world");
		
		System.out.println(p1.getKey());
		System.out.println(p1.getValue());
		
		System.out.println(p2.getKey());
		System.out.println(p2.getValue());
		
		// generic class의 객체 생성에서 파라메터를 생략하면 모든 파라메터를 Object로 간주한다
		// Java5 이전에 성됐던 프로그램들가의 호환성을 유지하기 위함.
		// 이것을 raw type이라고 한다.
		OrderedPair p4 = new OrderedPair("Hello", 10);	// 이렇게 쓰지 말것
		System.out.println(p4.getKey());
		System.out.println(p4.getValue());
	}
}
