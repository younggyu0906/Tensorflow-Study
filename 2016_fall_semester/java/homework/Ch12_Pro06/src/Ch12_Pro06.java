class Book {
	private int number;
	private String title, author;
	// �� �ʵ��� �����ڿ� ������
	public int getNumber() { return number; }
	public void setNumber(int number) { this.number = number; }
	public String getTitle() { return title; }
	public void setTitle(String title) { this.title = title; }
	public String getAuthor() { return author; }
	public void setAuthor(String author) { this.author = author; }
	// ������ �����ڿ� ��� �ʵ带 �ʱ�ȭ�ϴ� ������
	Book() {
		number = 0;
		title = null;
		author = null;
	}
	Book(int n, String t, String a) {
		number = n;
		title = t;
		author = a;
	}
	
	public boolean equals(Object obj) {	// equals method ������
		if (obj instanceof Book) {		// ������ȣ�� ������ ����å���� ����
			Book other = (Book)obj;		
			if (number == other.number)
				return true;
			else
				return false;
		}
		else return false;
	}
	
	public int getLateFees(int lDate) {	// ��ü�� ��ȯ �޼ҵ�
		return 0;
	}
}

class Novel extends Book{
	private int lateDate;
	private int lateFee;
	
	Novel(int n, String t, String a) {
		super(n, t, a);
	}
	public int getLateFees(int lDate) { // ��ü�� ��ȯ �޼ҵ� ������
		lateDate = lDate;
		return lateFee = lateDate * 300;
	}
}

class Poet extends Book{
	private int lateDate;
	private int lateFee;
	
	Poet(int n, String t, String a) {
		super(n, t, a);
	}
	public int getLateFees(int lDate) { // ��ü�� ��ȯ �޼ҵ� ������
		lateDate = lDate;
		return lateFee = lateDate * 200;
	}
}

class ScienceFiction extends Book{
	private int lateDate;
	private int lateFee;
	
	ScienceFiction(int n, String t, String a) {
		super(n, t, a);
	}
	public int getLateFees(int lDate) { // ��ü�� ��ȯ �޼ҵ� ������
		lateDate = lDate;
		return lateFee = lateDate * 600;
	}
}

public class Ch12_Pro06 {
	public static void main(String[] args) {
		Book b[] = new Book[3];
		b[0] = new Novel(1, "n1", "a1");
		b[1] = new Poet(1, "n3", "a3");
		b[2] = new Novel(15, "n1", "a1");
		
		System.out.println("b[0] == b[1] ? " + b[0].equals(b[1]));
		System.out.println("b[0] == b[2] ? " + b[0].equals(b[2]));
		System.out.println("b[0]�� ��ü�� : " + b[0].getLateFees(5));
	}
}
