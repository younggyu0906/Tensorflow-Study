class Point {
	private int px, py;		// 2차원 공간에서의 점 x, y
	
	public void set(int x, int y) {	// 좌표를 설정하는 메소드
		px = x;
		py = y;
	}
	public void print() {			// 좌표를 출력하는 메소드
		System.out.println("(" + px + ", " + py + ")");
	}
}

public class Ch08_Pro04 {
	public static void main(String[] args) {
		Point p1 = new Point();		// 객체 생성
		p1.set(15, 13);				// 좌표 설정
		p1.print();					// 좌표 출력
	} 
}