#include <iostream>

using namespace std;

class Triangle {//�ﰢ��
private :
	double base;//�ﰢ���� �غ�
	double height;//�ﰢ���� ����
	double area;//�ﰢ���� ����

public :
	double getBase();//�غ� ������
	double getHeight();//���� ������
	void setBase(double);//�غ� ������
	void setHeight(double);//���� ������
	void getArea();//������ ���ϴ� �Լ�
	void print();//�ﰢ���� ���¸� ���
};

double Triangle::getBase() {//�غ� ������
	return base;
}
double Triangle::getHeight() {//���� ������
	return height;
}
void Triangle::setBase(double lenth) {//�غ� ������
	base = lenth;
}
void Triangle::setHeight(double lenth) {//���� ������
	height = lenth;
}
void Triangle::getArea() {//������ ���ϴ� �Լ�
	area = base * height / 2;//�ﰢ���� ����
}
void Triangle::print() {//�ﰢ���� ���� ���
	cout << "�ﰢ���� �غ� : " << base << "\n�ﰢ���� ���� : " << height << "\n�ﰢ���� ���� : " << area << endl;
}

void main() {
	Triangle t1;//Triangle Ŭ���� Ÿ���� t1��ü�� ����

	t1.setBase(10);//t1�� �غ� �����ڸ� �̿��Ͽ� �غ� �ɹ������� 10����
	t1.setHeight(20);//t1�� ���� �����ڸ� �̿��Ͽ� ���� ��������� 20����
	t1.getArea();//t1 �ﰢ���� ������ ���ϴ� �Լ��� ȣ���Ͽ� �ﰢ���� ���̸� ����

	t1.print();//t1 �ﰢ���� ���� ���
}