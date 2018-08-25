class Student {
	protected String name;		// 이름
	protected int studentNum;	// 학번
	protected String belongTo;	// 소속
	protected String major;		// 학과
	protected int grade;		// 학년
	protected int credit;		// 학점
	
	Student() {		// 매개변수 없는 생성자
		name = null;
		studentNum = 0;
		belongTo = null;
		major = null;
		grade = 0;
		credit = 0;
	}
	Student(String n, int s, String b, String m, int g, int c) {	// 모든 필드를 초기화하는 생성자
		name = n;
		studentNum = s;
		belongTo = b;
		major = m;
		grade = g;
		credit = c;
	}
	// 각 필드의 접근자와 설정자
	public String getName()						{ return name; }
	public void setName(String name)			{ this.name = name; }
	public int getStudentNum()					{ return studentNum; }
	public void setStudentNum(int studentNum)	{ this.studentNum = studentNum; }
	public String getBelongTo()					{ return belongTo; }
	public void setBelongTo(String belongTo)	{ this.belongTo = belongTo; }
	public String getMajor()					{ return major; }
	public void setMajor(String major) 			{ this.major = major; }
	public int getGrade()						{ return grade; }
	public void setGrade(int grade) 			{ this.grade = grade; }
	public int getCredit() 						{ return credit; }
	public void setCredit(int credit)			{ this.credit = credit; }
	
	public String toString() {	// toString 메소드
		return name + ", " + studentNum + ", " + belongTo + ", " + major + ", " + grade + ", " + credit;
	}
	public boolean equals(Object obj) {	// equals 메소드 재 정의
		if (obj instanceof Student) {
			Student other = (Student)obj;
			if (name == other.name && studentNum == other.studentNum && belongTo == other.belongTo && major == other.major && grade == other.grade && credit == other.credit)
				return true;	// 모든 필드 비교하여 전부 같으면 true 반환
			else 
				return false;
		}
		else
			return false;
	}	
}

class UnderGraduate extends Student {	// 학부생
	private String club;	// 동아리
	
	UnderGraduate() {	// 매개변수 없는 생성자
		super(null, 0, null, null, 0, 0);
		club = null;
	}
	// 모든 필드를 초기화하는 생성자
	UnderGraduate(String n, int s, String b, String m, int g, int c, String cl) {
		super(n, s, b, m, g, c);
		club = cl;
	}
	// club 접근자와 설정자
	public String getClub() { return club; }
	public void setClub(String club) { this.club = club; }
	
	public String toString() {	// toString 메소드 재정의
		return super.toString() + ", " + club;
	}
	public boolean equals(Object obj) {	// equals 메소드 재정의
		if(obj instanceof Student) {
			if (super.equals(obj)) {	// 기반 클래스의 equals 호출해서 비교
				UnderGraduate other = (UnderGraduate)obj;
				if (club == other.club)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
}

class Graduate extends Student {	// 조교
	private String assistantType;	// 조교 유형
	private double scholarshipRate;	// 장학금 비율
	
	Graduate() {	// 매개변수 없는 생성자
		super(null, 0, null, null, 0, 0);
		assistantType = null;
		scholarshipRate = 0;
	}
	// 모든 필드를 초기화하는 생성자
	Graduate(String n, int s, String b, String m, int g, int c, String at, double sr) {
		super(n, s, b, m, g, c);
		if(at == "교육조교" || at == "연구조교")	// 조교 유형이 교육조교나 연구조교일 경우 초기화
			assistantType = at;
		else {	// 아닐경우 안내 메세지 출력 후 null로 초기화
			System.out.println(this.getName() + " : 조교 유형(교육조교 or 연구조교), null로 초기화합니다.");
			assistantType = null;
		}
		if(sr >= 0 && sr <= 1)	// 장학금 비율이 0이상 1이하일 경우 초기화
			scholarshipRate = sr;
		else {	// 아닐 경우 안내 메세지 출력 후 0으로 초기화
			System.out.println(this.getName() + " : 장학금 비율(0이상 1이하), 0으로 초기화합니다.");
			scholarshipRate = 0;
		}
	}
	// 각 필드의 접근자와 설정자
	public String getAssistantType() { return assistantType; }
	public void setAssistantType(String assistantType)	{ 
		if(assistantType == "교육조교" || assistantType == "연구조교")	// 조교 유형이 교육조교나 연구조교일 경우 설정
			this.assistantType = assistantType;
		else {	// 아닐경우 안내 메세지 출력 후 null로 초기화
			System.out.println(this.getName() + " : 조교 유형(교육조교 or 연구조교), null로 초기화합니다.");
			this.assistantType = null;
		}
	}
	public double getScholarshipRate() { return scholarshipRate; }
	public void setScholarshipRate(double scholarshipRate) { 
		if(scholarshipRate >= 0 && scholarshipRate <= 1)	// 장학금 비율이 0이상 1이하일 경우 설정
			this.scholarshipRate = scholarshipRate;
		else {	// 아닐 경우 안내 메세지 출력 후 0으로 초기화
			System.out.println(this.getName() + " : 장학금 비율(0이상 1이하), 0으로 초기화합니다.");
			this.scholarshipRate = 0;
		}
	}
	
	public String toString() {	// toString 메소드 재정의
		return super.toString() + ", " + assistantType + ", " + scholarshipRate;
	}
	public boolean equals(Object obj) {	// equals 메소드 재정의
		if(obj instanceof Student) {
			if (super.equals(obj)) {	// 기반 클래스의 equals 호출해서 비교
				Graduate other = (Graduate)obj;
				if (assistantType == other.assistantType && scholarshipRate == other.scholarshipRate )
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
}

public class Ch11_Pro07 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s[] = new Student[5];	// Student객체 배열 4개 생성
		s[0] = new Student("lee", 2013136000, "koreaTech", "Computer", 2, 90);
		// 기반 클래스 Student에 파생 클래스 UnderGraduate 저장
		s[1] = new UnderGraduate("kim", 2013136021, "koreaTech", "Computer", 2, 60, "club1");
		s[2] = new UnderGraduate("kim", 2013136021, "koreaTech", "Computer", 2, 60, "club1");
		// 기반 클래스 Student에 파생 클래스 Graduate 저장
		s[3] = new Graduate("park", 2010136000, "koreaTech", "Computer", 5, 150, "연구조교", 0.5);
		s[4] = new Graduate("choi", 2009136000, "koreaTech", "Computer", 6, 150, "1", 2);
		
		for(int i = 0; i < s.length; i++)		// toString 메소드를 이용하여 객체 출력
			System.out.println(s[i].toString());
		System.out.println(s[1].equals(s[2]));	// s[1]객체와 s[2] 객체 비교
	}
}
