
public class Pro01_Ch22_Box<T> {	// T : Ÿ�� �Ű�����(��ü ������ Ÿ�� ����)
	private T data;
	
	public void set(T d) {
		data = d;
	}
	public T get() {
		return data;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Pro01_Ch22_Box<String> b = new Pro01_Ch22_Box<String>();
		Pro01_Ch22_Box<String> b = new Pro01_Ch22_Box<>();	// Java 7 ���� ������ ȣ�⿡ Ÿ���μ� ���� ����
		b.set("Hello World");
		System.out.println(b.get());
		String str = b.get();
		
		Pro01_Ch22_Box<Integer> i = new Pro01_Ch22_Box<>();
		i.set(100);
		System.out.println(i.get());
		Integer num = i.get();
		int n = i.get();
		System.out.println(n);
	}

}
