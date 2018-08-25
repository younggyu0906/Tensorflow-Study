class Dice {
	private int face;		// 주사위의 윗면의 수를 저장 할 변수
	
	public void roll() {	// 주사위를 굴리는 메소드
		face = (int)(Math.random() * 6) + 1; // 1-6의 난수를 얻어 face에 저장
		System.out.println(face);
	}
}

public class Ch08_Pro03 {
	public static void main(String[] args) {
		Dice d1 = new Dice();		// 객체 생성
		
		for(int i = 0; i < 10; i++) { // 주사위를 10회 굴림
			d1.roll();
		}
	}
}