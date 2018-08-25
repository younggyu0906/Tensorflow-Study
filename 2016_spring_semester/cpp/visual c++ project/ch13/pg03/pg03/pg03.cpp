#include <iostream>
#include <string>

using namespace std;

class Book {//�Ϲ����� å�� ��Ÿ���� Book Ŭ����
	string title, writer;//����, ���ڸ� ���� �� �������
	int page;//������ ���� ���� �� �������
public :
	Book(string t = " ", int p = 0, string w = " ") : title(t), page(p), writer(w) {//Book ������
	}
	~Book() {//Book �Ҹ���
	}
	void setTitle(string t) {//title ������
		title = t;
	}
	string getTitle() {//title ������
		return title;
	}
		void setPage(int p) {//page ������
		page = p;
	}
	int getPage() {//page ������
		return page;
	}
	void setWriter(string w) {//writer ������
		writer = w;
	}
	string getWriter() {//writer ������
		return writer;
	}
	void print() {//��� �Լ�
		cout << "���� : " << title << ", ������ �� : " << page << ", ���� : " << writer << endl;
	}
};

class Magazine : public Book {//Book Ŭ������ ��ӹ޾Ƽ� ������ ��Ÿ���� Magerzine Ŭ����
	string saleDate;//�߸����� ���� �� ����
public :
	Magazine(string t = " ", int p = 0, string w = " ", string s = 0000-00-00) : Book(t, p, w), saleDate(s) {//Magazine ������
	}
	~Magazine() {//Magazine �Ҹ���
	}
	void setSaleDate(string s) {//saleDate ������
		saleDate = s;
	}
	string getSaleDate() {//saleDate ������
		return saleDate;
	}
	void print() {//��� �Լ�
		Book::print();
		cout << "�߸��� : " << saleDate << endl;
	}
};
void main() {
	Book b1("power C++", 769, "õ�α�");//Book Ŭ������ �׽�Ʈ�ϱ� ���Ͽ� ��ü b1 ����
	b1.print();//��ü b1 ���

	Magazine m1("�̻����", 1121, "Kenneth H. Rosen", "2012-08-30");//Magazine Ŭ������ �׽�Ʈ �ϱ� ���Ͽ� ��ü m1 ����
	m1.print();//��ü m1 ���
}