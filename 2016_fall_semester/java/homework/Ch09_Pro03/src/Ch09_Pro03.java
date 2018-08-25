class Box {		// ���ڸ� ��Ÿ���� Box Ŭ����
	private int width, column, height;	// ������ ����, ����, ����
	private boolean empty;	// ���ڰ� ����ִ���, �ƴ����� ����
	// �� �ʵ��� �����ڿ� ������
	public int getWidth() { return width; }
	public void setWidth(int width) { this.width = width; }
	public int getColumn() { return column; }
	public void setColumn(int column) { this.column = column; }
	public int getHeight() { return height; }
	public void setHeight(int height) { this.height = height; }
	public boolean isEmpty() { return empty; }
	public void setEmpty(boolean empty) { this.empty = empty; }
	
	public Box() {	// ����, ����, ���̸� �ʱ�ȭ ���� �ʴ� ������
		empty = true;
	}
	public Box(int w, int c, int h) {	// ����, ����, ���̸� �ʱ�ȭ �ϴ� ������
		width = w;
		column = c;
		height = h;
		empty = true;
	}
	public void print() {	// ������ ���¸� ����ϴ� ��� �޼ҵ�
		System.out.println(width + ", " + column + ", " + height + ", " + empty);
	}
}

public class Ch09_Pro03 {
	public static void main(String[] args) {
		Box b1 = new Box();			// Box ��ü ����
		Box b2 = new Box(2, 3, 4);	// Box ��ü ����
		// b1 ��ü ����
		b1.setHeight(5);
		b1.setWidth(6);
		b1.setColumn(7);
		b1.setEmpty(false);
		
		b1.print();	// b1 ���
		b2.print();	// b2 ���
	}
}
