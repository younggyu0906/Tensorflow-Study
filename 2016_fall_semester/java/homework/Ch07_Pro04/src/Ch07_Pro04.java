class Movie {
	private String title;		// ����
	private int grade;			// ����
	private String director;	// ����
	private String playdate;	// ������
	
	public String getTitle()				 { return title; } // title getter
	public void setTitle(String title)		 { this.title = title; } // title setter
	public int getGrade()					 { return grade; } // grade getter
	public void setGrade(int grade)			 { this.grade = grade; } // grade setter
	public String getDirector()				 { return director; } // director getter
	public void setDirector(String director) { this.director = director; } // director setter
	public String getPlaydate()				 { return playdate; } // playdate getter
	public void setPlaydate(String playdate) { this.playdate = playdate; } // playdate setter
	
	public void print() {	// ��ȭ�� ��� ������ ����ϴ� �Լ�
		System.out.println("��  �� : " + title);
		System.out.println("��  �� : " + grade);
		System.out.println("��  �� : " + director);
		System.out.println("������ : " + playdate);
	}	
}
public class Ch07_Pro04 {
	public static void main(String[] args) {
		Movie movie1 = new Movie(); // Movie ��ü ����
		movie1.setTitle("Asura");
		movie1.setGrade(6);
		movie1.setDirector("Kim");
		movie1.setPlaydate("2016.09.28");
		movie1.print(); // ��ȭ�� ���� ���
	}
}