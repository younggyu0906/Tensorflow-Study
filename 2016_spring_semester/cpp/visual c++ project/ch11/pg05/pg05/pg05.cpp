#include <iostream>
#include <ctime>

using namespace std;

class Time {//�ð��� ��Ÿ���� Ŭ����
	int hour, minute, second;//�ð�, ��, �ʸ� ���� �� �������
public :
	Time() {//����Ʈ ������
		hour = 0;
		minute = 0;
		second = 0;
	}
	Time (int h, int m, int s) {//�Ű������� ���� ������
		hour = h;
		minute = m;
		second = s;
	}
	~Time() {//�Ҹ���
	}
	void setHour(int h) {//������� hour setter
		hour = h;
	}
	int getHour() {//�������hour getter
		return hour;
	}
	void setMinute(int m) {//�������minute setter
		minute = m;
	}
	int getMinute() {//�������minute getter
		return minute;
	}
	void setSecond(int s) {//�������second setter
		second = s;
	}
	int getSecond() {//�������second getter
		return second;
	}
	void print() {//��� ��� �Լ�
		cout << hour << "�� " << minute << "�� " << second << "��\n";
	}
};

//bool isEqual(Time, Time);//���۷����� �Ű������� �޴� �Լ��� ȣ���� ���� ������ ���°� ���� ������ ����
bool isEqual(Time &, Time &);//���۷����� �Ű������� �޴� �� �Լ�
bool isEqual(Time *, Time *);//�����͸� �Ű������� �޴� �� �Լ�

void main() {//���� �Լ�
	int hour, min, sec;

	cout << "������ �ð�, ��, �ʸ� �Է��ϼ���.\n";
	cin >> hour >> min >> sec;

	//�ð��� ��Ÿ���� ��ü�� �����ϰ� �Է¹��� �ð�, ��, �� ���� ���ڷ� �Ѱ� ��
	Time t1(hour, min, sec);
	t1.print();//��� ���
	
	time_t timer;
	struct tm *t;
	
	timer = time(NULL);//���� �ð��� �� ������ ���

	t = localtime(&timer);//�� ������ �ð��� �и��Ͽ� ����ü�� ����

	//�ð��� ��Ÿ���� ��ü�� �����ϰ� ���� �ð��� ���ڷ� �Ѱ� ��
	Time t2(t->tm_hour, t->tm_min, t->tm_sec);
	
	t2.print();//��� ���

	isEqual(t1, t2);
	isEqual(&t1, &t2);
}

/*bool isEqual(Time t1, Time t2) {//������ ���� �ּ� ó��
	int hour = t1.getHour();
	int min = t1.getMinute();
	int sec = t1.getSecond();

	if(hour == t2.getHour() && min == t2.getMinute() && sec == t2.getSecond()) {
		cout << "�Է��� �ð��� ���� �ð��� �����ϴ�.\n";
		return true;
	}
	else {
		cout << "�Է��� �ð��� ���� �ð��� ���� �ʽ��ϴ�.\n";
		return false;
	}
}*/
bool isEqual(Time &t1, Time &t2){//���۷����� �Ű������� �޴� �� �Լ�
	int hour = t1.getHour();
	int min = t1.getMinute();
	int sec = t1.getSecond();

	if(hour == t2.getHour() && min == t2.getMinute() && sec == t2.getSecond()) {
		cout << "�Է��� �ð��� ���� �ð��� �����ϴ�.\n";
		return true;
	}
	else {
		cout << "�Է��� �ð��� ���� �ð��� ���� �ʽ��ϴ�.\n";
		return false;
	}
}
bool isEqual(Time *t1, Time *t2) {//�����͸� �Ű������� �޴� �� �Լ�
	int hour = t1->getHour();
	int min = t1->getMinute();
	int sec = t1->getSecond();

	if(hour == t2->getHour() && min == t2->getMinute() && sec == t2->getSecond()) {
		cout << "�Է��� �ð��� ���� �ð��� �����ϴ�.\n";
		return true;
	}
	else {
		cout << "�Է��� �ð��� ���� �ð��� ���� �ʽ��ϴ�.\n";
		return false;
	}
}