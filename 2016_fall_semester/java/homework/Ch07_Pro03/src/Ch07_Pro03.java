class Complex {				// 복소수
	private	double realNum;	// 실수
	private double imagNum;	// 허수
	
	public double getRealNum()				{ return realNum; }			// realNum getter
	public void setRealNum(double realNum)	{ this.realNum = realNum; }	// realNum setter
	public double getImagNum()				{ return imagNum; }			// imagNum getter
	public void setImagNum(double imagNum)	{ this.imagNum = imagNum; }	// imagNum getter

	public void print() {		// 출력 함수
		System.out.println(realNum + " + " + imagNum + "i");
	}
}

public class Ch07_Pro03 {
	public static void main(String[] args) {
		Complex c1 = new Complex();	// 객체 생성
		c1.setRealNum(2.5);			// 실수 설정
		c1.setImagNum(3.6);			// 허수 설정
		c1.print();					// 출력
	}
}