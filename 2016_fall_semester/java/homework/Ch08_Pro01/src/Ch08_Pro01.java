class Circle {
	private double cx, cy, r;
	
	public double getCx()			{ return cx; }		// cx getter
	public void setCx(double cx)	{ this.cx = cx; }	// cx setter
	public double getCy()			{ return cy; }		// cy getter
	public void setCy(double cy)	{ this.cy = cy; }	// cy setter
	public double getR()			{ return r; }		// r getter
	public void setR(double r)		{ this.r = r; }		// r setter
	
	public double area() {	// ���� ���̸� ���ϴ� �޼ҵ�
		return r * r * 3.141592;
	}
}

public class Ch08_Pro01 {
	public static void main(String[] args) {
		Circle c1 = new Circle();	// Circle ��ü ����
		c1.setCx(0);
		c1.setCy(0);
		c1.setR(4);
		
		System.out.println("c1�� ���� : " + c1.area());	// ���� ���
	}
}