package ConnectFour;

//Undo 클래스.  Undo할 보드 위치를 저장
public class Location { // 이름바꾸기
	public int i, j; // 보드 위치  (X, Y 좌표)

	// 생성자
	public Location(int i, int j) {
		this.i = i;
		this.j = j;
	}
}