// generic Ŭ������ Ÿ�� �Ű������� Ŭ���� �̸� �ڿ� ���δ�
// generic �޼����� Ÿ�� �Ű������� ��ȯ�� �տ� ���δ�

public class Ch22_Prog4 {
	public <T> void print(T obj) {
		System.out.println(obj.getClass().getName());
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ch22_Prog4 t = new Ch22_Prog4();
		
		t.print(10);// auto boxing
		t.print(new Double(10.5));
		t.print(t);
	}
}
