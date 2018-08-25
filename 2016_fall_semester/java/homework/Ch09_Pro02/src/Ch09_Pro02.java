class Plane {		// 비행기를 나타내는 Plane 클래스
	private String manufacsture;	// 제작사
	private String model;			// 모델
	private int maxPassanger;		// 최대 승객수
	private static int planes;		// 생성된 비행기의 개수
	
	// 모든 필드에 대한 접근자와 설정자
	public String getManufacsture() { return manufacsture; }
	public void setManufacsture(String manufacsture) { this.manufacsture = manufacsture; }
	public String getModel() { return model; }
	public void setModel(String model) { this.model = model; }
	public int getMaxPassanger() { return maxPassanger; }
	public void setMaxPassanger(int maxPassanger) { this.maxPassanger = maxPassanger; }
	public static int getPlanes() { return planes; }	// 정적변수 planes 값을 반환하는 정적 메소드
	
	public Plane() {			// 필드를 초기화 하지 않는 생성자
		++planes;
	}
	public Plane(String man) {	// 제작사 필드를 초기화 하는 생성자
		manufacsture = man;
		++planes;
	}
	public Plane(String man, String mod) {	// 제작사, 모델을 초기화 하는 생성자
		manufacsture = man;
		model = mod;
		++planes;
	}
	public Plane(String man, String mod, int pas) {	// 모든 필드를 초기화 하는 생성자
		manufacsture = man;
		model = mod;
		maxPassanger = pas;
		++planes;
	}
	public void print() {	// 출력 메소드
		System.out.printf("제조사 : %s, 모델 : %s, 최대승객수 : %d\n", manufacsture, model, maxPassanger);
	}
}
public class Ch09_Pro02 {
	public static void main(String[] args) {	// 비행기 클래스 테스트
		System.out.println("비행기 수 : " + Plane.getPlanes());		// 비행기 수 출력
		// 객체 생성
		Plane p1 = new Plane();		
		Plane p2 = new Plane("Air Bus");
		Plane p3 = new Plane("Air Taxi", "A380");
		Plane p4 = new Plane("Air train", "A381", 500);
		System.out.println("비행기 수 : " + Plane.getPlanes());		// 비행기 수 출력
		// 설정자를 이용하여 p1 객체 설정
		p1.setManufacsture("Air Plane");
		p1.setModel("A382");
		p1.setMaxPassanger(300);
		// 객체 출력
		p1.print();
		p2.print();
		p3.print();
		p4.print();
	}
}
