class Book {
	protected String title, writer;	// 책 제목과 저자를 저장할 필드
	protected int page;	// 페이지 수 를 저장할 필드
	
	public Book() {	// 디폴트 생성자
		title = null;
		page = 0;
		writer = null;
	}
	public Book(String t, int p, String w) {	// 모든 필드를 초기화하는 생성자
		title = t;
		page = p;
		writer = w;
	}
	// 각 필드의 접근자와 설정자
	public String getTitle() { return title; }
	public void setTitle(String title) { this.title = title; }
	public int getPage() { return page; }
	public void setPage(int page) { this.page = page; }
	public String getWriter() { return writer; }
	public void setWriter(String writer) { this.writer = writer; }
	
	public String toString() {	// toString 메소드 
		return "title : " + title + ", page : " + page + ", writer : " + writer;
	}
	
	public boolean equals(Object obj) {	// equals 메소드
		if (obj instanceof Book) {		// 동일 클래스의 객체인가?
			Book other = (Book)obj;		// Object를 Book으로 형변환
			if (title == other.title && page == other.page && writer == other.writer)
				return true;	// 모든 필드 비교하여 전부 같으면 true 반환
			else
				return false;
		}
		else return false;
	}
}

class Magazine extends Book {
	private String issueDate;	// 발매일
	
	public Magazine() {	// 디폴트 생성자
		super(null, 0, null);
		issueDate = null;
	}
	public Magazine(String t, int p, String w, String i) {	// 모든 필드를 초기화하는 생성자
		super(t, p, w);
		issueDate = i;
	}
	// 각 필드의 접근자와 설정자
	public String getIssueDate() { return issueDate; }
	public void setIssueDate(String issueDate) { this.issueDate = issueDate; }
	
	public String toString() {	// toString 메소드 재정의
		return super.toString() + ", issueDate : " + issueDate;
	}
	public boolean equals(Object obj) {	// equals 메소드 재정의
		if(obj instanceof Book) {
			if (super.equals(obj)) {	// 기반 클래스의 equals 호출해서 비교
				Magazine other = (Magazine)obj;
				if (issueDate == other.issueDate)
					return true;
				else
					return false;
			}
			return
					false;
		}
		return
				false;
	}
}

public class Ch11_Pro04 {
	public static void main(String[] args) {
		Book b[] = new Book[3];	// Book객체 배열 3개 생성
		b[0] = new Book("book1", 10, "writer1");
		// 기반 클래스 Book에 파생 클래스 Magazine 저장
		b[1] = new Magazine();
		b[2] = new Magazine("m1", 50, "w2", "2016-10-25");
		
		for(int i = 0; i < b.length; i++)		// toString 메소드를 이용하여 객체 출력
			System.out.println(b[i].toString());
		System.out.println(b[1].equals(b[2]));	// p[1]객체와 [2] 객체 비교
		
		// b[1] 객체 설정
		b[1].setTitle("m1");
		b[1].setPage(50);
		b[1].setWriter("w2");
		((Magazine)b[1]).setIssueDate("2016-10-25");
		
		for(int i = 0; i < b.length; i++)		// toString 메소드를 이용하여 객체 출력
			System.out.println(b[i].toString());
		System.out.println(b[1].equals(b[2]));	// b[1]객체와 b[2] 객체 비교
	}
}
