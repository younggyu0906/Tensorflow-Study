class Book {
	private String title, author;	// 제목, 저자를 저장 할 변수

	public String getTitle()			 { return title; }			// title getter
	public void setTitle(String title)	 { this.title = title; }	// title setter
	public String getAuthor()			 { return author; }			// author getter
	public void setAuthor(String author) { this.author = author; }	// author setter
}

public class Ch08_Pro02 {
	public static void main(String[] args) {
		Book b1 = new Book();		// 객체 생성
		b1.setTitle("Power JAVA");	// 제목 설정
		b1.setAuthor("천인국");		// 저자 설정
	
		System.out.println("제목 : " + b1.getTitle());
		System.out.println("저자 : " + b1.getAuthor());
	}
}