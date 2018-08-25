// Ÿ�� �Ű������� �������� ������ �� �ִ�.

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
		
		// generic class�� ��ü �������� �Ķ���͸� �����ϸ� ��� �Ķ���͸� Object�� �����Ѵ�
		// Java5 ������ ���ƴ� ���α׷��鰡�� ȣȯ���� �����ϱ� ����.
		// �̰��� raw type�̶�� �Ѵ�.
		OrderedPair p4 = new OrderedPair("Hello", 10);	// �̷��� ���� ����
		System.out.println(p4.getKey());
		System.out.println(p4.getValue());
	}
}
