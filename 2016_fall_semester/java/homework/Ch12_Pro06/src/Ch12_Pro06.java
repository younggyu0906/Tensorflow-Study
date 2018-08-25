class Book {
	private int number;
	private String title, author;
	// 각 필드의 접근자와 설정자
	public int getNumber() { return number; }
	public void setNumber(int number) { this.number = number; }
	public String getTitle() { return title; }
	public void setTitle(String title) { this.title = title; }
	public String getAuthor() { return author; }
	public void setAuthor(String author) { this.author = author; }
	// 디폴드 생성자와 모든 필드를 초기화하는 생성자
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
	
	public boolean equals(Object obj) {	// equals method 재정의
		if (obj instanceof Book) {		// 관리번호가 같으면 같은책으로 간주
			Book other = (Book)obj;		
			if (number == other.number)
				return true;
			else
				return false;
		}
		else return false;
	}
	
	public int getLateFees(int lDate) {	// 연체료 반환 메소드
		return 0;
	}
}

class Novel extends Book{
	private int lateDate;
	private int lateFee;
	
	Novel(int n, String t, String a) {
		super(n, t, a);
	}
	public int getLateFees(int lDate) { // 연체료 반환 메소드 재정의
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
	public int getLateFees(int lDate) { // 연체료 반환 메소드 재정의
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
	public int getLateFees(int lDate) { // 연체료 반환 메소드 재정의
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
		System.out.println("b[0]의 연체료 : " + b[0].getLateFees(5));
	}
}
