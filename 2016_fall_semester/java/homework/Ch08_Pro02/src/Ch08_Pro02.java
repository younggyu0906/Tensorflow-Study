class Book {
	private String title, author;	// ����, ���ڸ� ���� �� ����

	public String getTitle()			 { return title; }			// title getter
	public void setTitle(String title)	 { this.title = title; }	// title setter
	public String getAuthor()			 { return author; }			// author getter
	public void setAuthor(String author) { this.author = author; }	// author setter
}

public class Ch08_Pro02 {
	public static void main(String[] args) {
		Book b1 = new Book();		// ��ü ����
		b1.setTitle("Power JAVA");	// ���� ����
		b1.setAuthor("õ�α�");		// ���� ����
	
		System.out.println("���� : " + b1.getTitle());
		System.out.println("���� : " + b1.getAuthor());
	}
}