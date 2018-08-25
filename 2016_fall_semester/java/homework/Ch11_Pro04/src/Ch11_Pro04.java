class Book {
	protected String title, writer;	// å ����� ���ڸ� ������ �ʵ�
	protected int page;	// ������ �� �� ������ �ʵ�
	
	public Book() {	// ����Ʈ ������
		title = null;
		page = 0;
		writer = null;
	}
	public Book(String t, int p, String w) {	// ��� �ʵ带 �ʱ�ȭ�ϴ� ������
		title = t;
		page = p;
		writer = w;
	}
	// �� �ʵ��� �����ڿ� ������
	public String getTitle() { return title; }
	public void setTitle(String title) { this.title = title; }
	public int getPage() { return page; }
	public void setPage(int page) { this.page = page; }
	public String getWriter() { return writer; }
	public void setWriter(String writer) { this.writer = writer; }
	
	public String toString() {	// toString �޼ҵ� 
		return "title : " + title + ", page : " + page + ", writer : " + writer;
	}
	
	public boolean equals(Object obj) {	// equals �޼ҵ�
		if (obj instanceof Book) {		// ���� Ŭ������ ��ü�ΰ�?
			Book other = (Book)obj;		// Object�� Book���� ����ȯ
			if (title == other.title && page == other.page && writer == other.writer)
				return true;	// ��� �ʵ� ���Ͽ� ���� ������ true ��ȯ
			else
				return false;
		}
		else return false;
	}
}

class Magazine extends Book {
	private String issueDate;	// �߸���
	
	public Magazine() {	// ����Ʈ ������
		super(null, 0, null);
		issueDate = null;
	}
	public Magazine(String t, int p, String w, String i) {	// ��� �ʵ带 �ʱ�ȭ�ϴ� ������
		super(t, p, w);
		issueDate = i;
	}
	// �� �ʵ��� �����ڿ� ������
	public String getIssueDate() { return issueDate; }
	public void setIssueDate(String issueDate) { this.issueDate = issueDate; }
	
	public String toString() {	// toString �޼ҵ� ������
		return super.toString() + ", issueDate : " + issueDate;
	}
	public boolean equals(Object obj) {	// equals �޼ҵ� ������
		if(obj instanceof Book) {
			if (super.equals(obj)) {	// ��� Ŭ������ equals ȣ���ؼ� ��
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
		Book b[] = new Book[3];	// Book��ü �迭 3�� ����
		b[0] = new Book("book1", 10, "writer1");
		// ��� Ŭ���� Book�� �Ļ� Ŭ���� Magazine ����
		b[1] = new Magazine();
		b[2] = new Magazine("m1", 50, "w2", "2016-10-25");
		
		for(int i = 0; i < b.length; i++)		// toString �޼ҵ带 �̿��Ͽ� ��ü ���
			System.out.println(b[i].toString());
		System.out.println(b[1].equals(b[2]));	// p[1]��ü�� [2] ��ü ��
		
		// b[1] ��ü ����
		b[1].setTitle("m1");
		b[1].setPage(50);
		b[1].setWriter("w2");
		((Magazine)b[1]).setIssueDate("2016-10-25");
		
		for(int i = 0; i < b.length; i++)		// toString �޼ҵ带 �̿��Ͽ� ��ü ���
			System.out.println(b[i].toString());
		System.out.println(b[1].equals(b[2]));	// b[1]��ü�� b[2] ��ü ��
	}
}
