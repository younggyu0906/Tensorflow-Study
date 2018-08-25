class Box {		// 상자를 나타내는 Box 클래스
	private int width, column, height;	// 상자의 가로, 세로, 높이
	private boolean empty;	// 상자가 비어있는지, 아닌지의 변수
	// 각 필드의 접근자와 설정자
	public int getWidth() { return width; }
	public void setWidth(int width) { this.width = width; }
	public int getColumn() { return column; }
	public void setColumn(int column) { this.column = column; }
	public int getHeight() { return height; }
	public void setHeight(int height) { this.height = height; }
	public boolean isEmpty() { return empty; }
	public void setEmpty(boolean empty) { this.empty = empty; }
	
	public Box() {	// 가로, 세로, 높이를 초기화 하지 않는 생성자
		empty = true;
	}
	public Box(int w, int c, int h) {	// 가로, 세로, 높이를 초기화 하는 생성자
		width = w;
		column = c;
		height = h;
		empty = true;
	}
	public void print() {	// 상자의 상태를 출력하는 출력 메소드
		System.out.println(width + ", " + column + ", " + height + ", " + empty);
	}
}

public class Ch09_Pro03 {
	public static void main(String[] args) {
		Box b1 = new Box();			// Box 객체 생성
		Box b2 = new Box(2, 3, 4);	// Box 객체 생성
		// b1 객체 설정
		b1.setHeight(5);
		b1.setWidth(6);
		b1.setColumn(7);
		b1.setEmpty(false);
		
		b1.print();	// b1 출력
		b2.print();	// b2 출력
	}
}
