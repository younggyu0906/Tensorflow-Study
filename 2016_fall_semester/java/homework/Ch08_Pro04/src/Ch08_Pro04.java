class Point {
	private int px, py;		// 2���� ���������� �� x, y
	
	public void set(int x, int y) {	// ��ǥ�� �����ϴ� �޼ҵ�
		px = x;
		py = y;
	}
	public void print() {			// ��ǥ�� ����ϴ� �޼ҵ�
		System.out.println("(" + px + ", " + py + ")");
	}
}

public class Ch08_Pro04 {
	public static void main(String[] args) {
		Point p1 = new Point();		// ��ü ����
		p1.set(15, 13);				// ��ǥ ����
		p1.print();					// ��ǥ ���
	} 
}