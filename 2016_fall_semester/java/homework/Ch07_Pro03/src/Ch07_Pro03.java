class Complex {				// ���Ҽ�
	private	double realNum;	// �Ǽ�
	private double imagNum;	// ���
	
	public double getRealNum()				{ return realNum; }			// realNum getter
	public void setRealNum(double realNum)	{ this.realNum = realNum; }	// realNum setter
	public double getImagNum()				{ return imagNum; }			// imagNum getter
	public void setImagNum(double imagNum)	{ this.imagNum = imagNum; }	// imagNum getter

	public void print() {		// ��� �Լ�
		System.out.println(realNum + " + " + imagNum + "i");
	}
}

public class Ch07_Pro03 {
	public static void main(String[] args) {
		Complex c1 = new Complex();	// ��ü ����
		c1.setRealNum(2.5);			// �Ǽ� ����
		c1.setImagNum(3.6);			// ��� ����
		c1.print();					// ���
	}
}