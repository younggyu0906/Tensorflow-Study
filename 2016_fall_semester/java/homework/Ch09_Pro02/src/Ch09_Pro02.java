class Plane {		// ����⸦ ��Ÿ���� Plane Ŭ����
	private String manufacsture;	// ���ۻ�
	private String model;			// ��
	private int maxPassanger;		// �ִ� �°���
	private static int planes;		// ������ ������� ����
	
	// ��� �ʵ忡 ���� �����ڿ� ������
	public String getManufacsture() { return manufacsture; }
	public void setManufacsture(String manufacsture) { this.manufacsture = manufacsture; }
	public String getModel() { return model; }
	public void setModel(String model) { this.model = model; }
	public int getMaxPassanger() { return maxPassanger; }
	public void setMaxPassanger(int maxPassanger) { this.maxPassanger = maxPassanger; }
	public static int getPlanes() { return planes; }	// �������� planes ���� ��ȯ�ϴ� ���� �޼ҵ�
	
	public Plane() {			// �ʵ带 �ʱ�ȭ ���� �ʴ� ������
		++planes;
	}
	public Plane(String man) {	// ���ۻ� �ʵ带 �ʱ�ȭ �ϴ� ������
		manufacsture = man;
		++planes;
	}
	public Plane(String man, String mod) {	// ���ۻ�, ���� �ʱ�ȭ �ϴ� ������
		manufacsture = man;
		model = mod;
		++planes;
	}
	public Plane(String man, String mod, int pas) {	// ��� �ʵ带 �ʱ�ȭ �ϴ� ������
		manufacsture = man;
		model = mod;
		maxPassanger = pas;
		++planes;
	}
	public void print() {	// ��� �޼ҵ�
		System.out.printf("������ : %s, �� : %s, �ִ�°��� : %d\n", manufacsture, model, maxPassanger);
	}
}
public class Ch09_Pro02 {
	public static void main(String[] args) {	// ����� Ŭ���� �׽�Ʈ
		System.out.println("����� �� : " + Plane.getPlanes());		// ����� �� ���
		// ��ü ����
		Plane p1 = new Plane();		
		Plane p2 = new Plane("Air Bus");
		Plane p3 = new Plane("Air Taxi", "A380");
		Plane p4 = new Plane("Air train", "A381", 500);
		System.out.println("����� �� : " + Plane.getPlanes());		// ����� �� ���
		// �����ڸ� �̿��Ͽ� p1 ��ü ����
		p1.setManufacsture("Air Plane");
		p1.setModel("A382");
		p1.setMaxPassanger(300);
		// ��ü ���
		p1.print();
		p2.print();
		p3.print();
		p4.print();
	}
}
