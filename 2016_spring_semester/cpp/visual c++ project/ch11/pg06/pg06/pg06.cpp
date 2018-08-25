#include <iostream>
#include <string>

using namespace std;

class Date {//��¥�� ��Ÿ���� Ŭ����
	int year, month, day;//��, ��, ���� ������ �������
public :
	Date() { //����Ʈ ������
		year = 1;
		month = 1;
		day = 1;
	}
	Date(int y, int m, int d) {//�Ű������� ���� ������
		year = y;
		month = m;
		day = d;
	}
	~Date() {//�Ҹ���
	}
	void print() {//��� �Լ�
		cout << year << "�� " << month << "�� " << day << "��\n";
	}
};

class Employee {//������ ��Ÿ���� Ŭ����
	string name;//�̸�
	Date birthDate;//����
	Date hireDate;//�Ի���
public :
	Employee () : name("a"), birthDate(1, 1, 1), hireDate(1, 1, 1) {//����Ʈ ������
	}
	Employee (string n, Date &b, Date &h) { //�Ű������� ���� ������
		name = n;
		birthDate = b;
		hireDate = h;
	}
	~Employee () {//�Ҹ���
	}
	void print() {//��� �Լ�
		cout << "�̸� : " << name << endl;
		cout << "���� : ";
		birthDate.print();
		cout << "�Ի��� : ";
		hireDate.print();
	}
};

void main() {//�����Լ�
	Date birthday(1994, 9, 6);//��¥ ��ü ����
	Date hireday(2016, 5, 15);//��¥ ��ü ����

	Employee e1("Kim young-gyu", birthday, hireday);//���� ��ü
	e1.print();//���
}