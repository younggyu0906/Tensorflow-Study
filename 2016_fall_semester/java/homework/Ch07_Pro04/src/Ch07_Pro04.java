class Movie {
	private String title;		// 제목
	private int grade;			// 평점
	private String director;	// 감독
	private String playdate;	// 개봉일
	
	public String getTitle()				 { return title; } // title getter
	public void setTitle(String title)		 { this.title = title; } // title setter
	public int getGrade()					 { return grade; } // grade getter
	public void setGrade(int grade)			 { this.grade = grade; } // grade setter
	public String getDirector()				 { return director; } // director getter
	public void setDirector(String director) { this.director = director; } // director setter
	public String getPlaydate()				 { return playdate; } // playdate getter
	public void setPlaydate(String playdate) { this.playdate = playdate; } // playdate setter
	
	public void print() {	// 영화의 모든 정보를 출력하는 함수
		System.out.println("제  목 : " + title);
		System.out.println("평  점 : " + grade);
		System.out.println("감  독 : " + director);
		System.out.println("개봉일 : " + playdate);
	}	
}
public class Ch07_Pro04 {
	public static void main(String[] args) {
		Movie movie1 = new Movie(); // Movie 객체 생성
		movie1.setTitle("Asura");
		movie1.setGrade(6);
		movie1.setDirector("Kim");
		movie1.setPlaydate("2016.09.28");
		movie1.print(); // 영화의 정보 출력
	}
}