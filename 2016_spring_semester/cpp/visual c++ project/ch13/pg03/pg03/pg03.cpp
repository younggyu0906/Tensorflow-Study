#include <iostream>
#include <string>

using namespace std;

class Book {//일반적인 책을 나타내는 Book 클래스
	string title, writer;//제목, 저자를 저장 할 멤버변수
	int page;//페이지 수를 저장 할 멤버변수
public :
	Book(string t = " ", int p = 0, string w = " ") : title(t), page(p), writer(w) {//Book 생성자
	}
	~Book() {//Book 소멸자
	}
	void setTitle(string t) {//title 설정자
		title = t;
	}
	string getTitle() {//title 접근자
		return title;
	}
		void setPage(int p) {//page 설정자
		page = p;
	}
	int getPage() {//page 접근자
		return page;
	}
	void setWriter(string w) {//writer 설정자
		writer = w;
	}
	string getWriter() {//writer 접근자
		return writer;
	}
	void print() {//출력 함수
		cout << "제목 : " << title << ", 페이지 수 : " << page << ", 저자 : " << writer << endl;
	}
};

class Magazine : public Book {//Book 클래스를 상속받아서 잡지를 나타내는 Magerzine 클래스
	string saleDate;//발매일을 저장 할 변수
public :
	Magazine(string t = " ", int p = 0, string w = " ", string s = 0000-00-00) : Book(t, p, w), saleDate(s) {//Magazine 생성자
	}
	~Magazine() {//Magazine 소멸자
	}
	void setSaleDate(string s) {//saleDate 설정자
		saleDate = s;
	}
	string getSaleDate() {//saleDate 접근자
		return saleDate;
	}
	void print() {//출력 함수
		Book::print();
		cout << "발매일 : " << saleDate << endl;
	}
};
void main() {
	Book b1("power C++", 769, "천인국");//Book 클래스를 테스트하기 위하여 객체 b1 선언
	b1.print();//객체 b1 출력

	Magazine m1("이산수학", 1121, "Kenneth H. Rosen", "2012-08-30");//Magazine 클래스를 테스트 하기 위하여 객체 m1 선언
	m1.print();//객체 m1 출력
}