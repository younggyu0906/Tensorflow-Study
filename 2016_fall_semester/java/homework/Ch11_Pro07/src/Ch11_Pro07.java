class Student {
	protected String name;		// �̸�
	protected int studentNum;	// �й�
	protected String belongTo;	// �Ҽ�
	protected String major;		// �а�
	protected int grade;		// �г�
	protected int credit;		// ����
	
	Student() {		// �Ű����� ���� ������
		name = null;
		studentNum = 0;
		belongTo = null;
		major = null;
		grade = 0;
		credit = 0;
	}
	Student(String n, int s, String b, String m, int g, int c) {	// ��� �ʵ带 �ʱ�ȭ�ϴ� ������
		name = n;
		studentNum = s;
		belongTo = b;
		major = m;
		grade = g;
		credit = c;
	}
	// �� �ʵ��� �����ڿ� ������
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
	
	public String toString() {	// toString �޼ҵ�
		return name + ", " + studentNum + ", " + belongTo + ", " + major + ", " + grade + ", " + credit;
	}
	public boolean equals(Object obj) {	// equals �޼ҵ� �� ����
		if (obj instanceof Student) {
			Student other = (Student)obj;
			if (name == other.name && studentNum == other.studentNum && belongTo == other.belongTo && major == other.major && grade == other.grade && credit == other.credit)
				return true;	// ��� �ʵ� ���Ͽ� ���� ������ true ��ȯ
			else 
				return false;
		}
		else
			return false;
	}	
}

class UnderGraduate extends Student {	// �кλ�
	private String club;	// ���Ƹ�
	
	UnderGraduate() {	// �Ű����� ���� ������
		super(null, 0, null, null, 0, 0);
		club = null;
	}
	// ��� �ʵ带 �ʱ�ȭ�ϴ� ������
	UnderGraduate(String n, int s, String b, String m, int g, int c, String cl) {
		super(n, s, b, m, g, c);
		club = cl;
	}
	// club �����ڿ� ������
	public String getClub() { return club; }
	public void setClub(String club) { this.club = club; }
	
	public String toString() {	// toString �޼ҵ� ������
		return super.toString() + ", " + club;
	}
	public boolean equals(Object obj) {	// equals �޼ҵ� ������
		if(obj instanceof Student) {
			if (super.equals(obj)) {	// ��� Ŭ������ equals ȣ���ؼ� ��
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

class Graduate extends Student {	// ����
	private String assistantType;	// ���� ����
	private double scholarshipRate;	// ���б� ����
	
	Graduate() {	// �Ű����� ���� ������
		super(null, 0, null, null, 0, 0);
		assistantType = null;
		scholarshipRate = 0;
	}
	// ��� �ʵ带 �ʱ�ȭ�ϴ� ������
	Graduate(String n, int s, String b, String m, int g, int c, String at, double sr) {
		super(n, s, b, m, g, c);
		if(at == "��������" || at == "��������")	// ���� ������ ���������� ���������� ��� �ʱ�ȭ
			assistantType = at;
		else {	// �ƴҰ�� �ȳ� �޼��� ��� �� null�� �ʱ�ȭ
			System.out.println(this.getName() + " : ���� ����(�������� or ��������), null�� �ʱ�ȭ�մϴ�.");
			assistantType = null;
		}
		if(sr >= 0 && sr <= 1)	// ���б� ������ 0�̻� 1������ ��� �ʱ�ȭ
			scholarshipRate = sr;
		else {	// �ƴ� ��� �ȳ� �޼��� ��� �� 0���� �ʱ�ȭ
			System.out.println(this.getName() + " : ���б� ����(0�̻� 1����), 0���� �ʱ�ȭ�մϴ�.");
			scholarshipRate = 0;
		}
	}
	// �� �ʵ��� �����ڿ� ������
	public String getAssistantType() { return assistantType; }
	public void setAssistantType(String assistantType)	{ 
		if(assistantType == "��������" || assistantType == "��������")	// ���� ������ ���������� ���������� ��� ����
			this.assistantType = assistantType;
		else {	// �ƴҰ�� �ȳ� �޼��� ��� �� null�� �ʱ�ȭ
			System.out.println(this.getName() + " : ���� ����(�������� or ��������), null�� �ʱ�ȭ�մϴ�.");
			this.assistantType = null;
		}
	}
	public double getScholarshipRate() { return scholarshipRate; }
	public void setScholarshipRate(double scholarshipRate) { 
		if(scholarshipRate >= 0 && scholarshipRate <= 1)	// ���б� ������ 0�̻� 1������ ��� ����
			this.scholarshipRate = scholarshipRate;
		else {	// �ƴ� ��� �ȳ� �޼��� ��� �� 0���� �ʱ�ȭ
			System.out.println(this.getName() + " : ���б� ����(0�̻� 1����), 0���� �ʱ�ȭ�մϴ�.");
			this.scholarshipRate = 0;
		}
	}
	
	public String toString() {	// toString �޼ҵ� ������
		return super.toString() + ", " + assistantType + ", " + scholarshipRate;
	}
	public boolean equals(Object obj) {	// equals �޼ҵ� ������
		if(obj instanceof Student) {
			if (super.equals(obj)) {	// ��� Ŭ������ equals ȣ���ؼ� ��
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
		Student s[] = new Student[5];	// Student��ü �迭 4�� ����
		s[0] = new Student("lee", 2013136000, "koreaTech", "Computer", 2, 90);
		// ��� Ŭ���� Student�� �Ļ� Ŭ���� UnderGraduate ����
		s[1] = new UnderGraduate("kim", 2013136021, "koreaTech", "Computer", 2, 60, "club1");
		s[2] = new UnderGraduate("kim", 2013136021, "koreaTech", "Computer", 2, 60, "club1");
		// ��� Ŭ���� Student�� �Ļ� Ŭ���� Graduate ����
		s[3] = new Graduate("park", 2010136000, "koreaTech", "Computer", 5, 150, "��������", 0.5);
		s[4] = new Graduate("choi", 2009136000, "koreaTech", "Computer", 6, 150, "1", 2);
		
		for(int i = 0; i < s.length; i++)		// toString �޼ҵ带 �̿��Ͽ� ��ü ���
			System.out.println(s[i].toString());
		System.out.println(s[1].equals(s[2]));	// s[1]��ü�� s[2] ��ü ��
	}
}
