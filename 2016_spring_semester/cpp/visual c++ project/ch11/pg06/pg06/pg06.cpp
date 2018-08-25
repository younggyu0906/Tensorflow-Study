#include <iostream>
#include <string>

using namespace std;

class Date {//날짜를 나타내는 클래스
	int year, month, day;//년, 월, 일을 저장할 멤버변수
public :
	Date() { //디폴트 생성자
		year = 1;
		month = 1;
		day = 1;
	}
	Date(int y, int m, int d) {//매개변수를 갖는 생성자
		year = y;
		month = m;
		day = d;
	}
	~Date() {//소멸자
	}
	void print() {//출력 함수
		cout << year << "년 " << month << "월 " << day << "일\n";
	}
};

class Employee {//직원을 나타내는 클래스
	string name;//이름
	Date birthDate;//생일
	Date hireDate;//입사일
public :
	Employee () : name("a"), birthDate(1, 1, 1), hireDate(1, 1, 1) {//디폴트 생성자
	}
	Employee (string n, Date &b, Date &h) { //매개변수를 갖는 생성자
		name = n;
		birthDate = b;
		hireDate = h;
	}
	~Employee () {//소멸자
	}
	void print() {//출력 함수
		cout << "이름 : " << name << endl;
		cout << "생일 : ";
		birthDate.print();
		cout << "입사일 : ";
		hireDate.print();
	}
};

void main() {//메인함수
	Date birthday(1994, 9, 6);//날짜 객체 생성
	Date hireday(2016, 5, 15);//날짜 객체 생성

	Employee e1("Kim young-gyu", birthday, hireday);//직원 객체
	e1.print();//출력
}