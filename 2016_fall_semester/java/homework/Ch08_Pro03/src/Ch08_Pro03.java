class Dice {
	private int face;		// �ֻ����� ������ ���� ���� �� ����
	
	public void roll() {	// �ֻ����� ������ �޼ҵ�
		face = (int)(Math.random() * 6) + 1; // 1-6�� ������ ��� face�� ����
		System.out.println(face);
	}
}

public class Ch08_Pro03 {
	public static void main(String[] args) {
		Dice d1 = new Dice();		// ��ü ����
		
		for(int i = 0; i < 10; i++) { // �ֻ����� 10ȸ ����
			d1.roll();
		}
	}
}