#include <iostream>

using namespace std;

class Complex {//���Ҽ�
private :
	double realNum;//�Ǽ�
	double imaginaryNum;//���

public :
	double getRealNum();//�Ǽ� ������
	double getImaginaryNum();//��� ������
	void setRealNum(double);//�Ǽ� ������
	void setImaginaryNum(double);//��� ������
	void add(Complex, Complex);//���Ҽ� ���� �Լ�
	void sub(Complex, Complex);//���Ҽ� ���� �Լ�
	void printNum();//��� �Լ�
};

double Complex::getRealNum() {//�Ǽ� ������
	return realNum;
}
double Complex::getImaginaryNum() {//��� ������
	return imaginaryNum;
}
void Complex::setRealNum(double num) {//�Ǽ� ������
	realNum = num;
}
void Complex::setImaginaryNum(double num) {//��� ������
	imaginaryNum = num;
}
void Complex::add(Complex comp1, Complex comp2) {//���Ҽ� ���� �Լ�
	realNum = comp1.realNum + comp2.realNum;//�� ���Ҽ��� �Ǽ��� ����
	imaginaryNum = comp1.imaginaryNum + comp2.imaginaryNum;//�� ���Ҽ��� ����� ����
}
void Complex::sub(Complex comp1, Complex comp2) {//���Ҽ� ���� �Լ�
	realNum = comp1.realNum - comp2.realNum; //�� ���Ҽ��� �Ǽ��� ����
	imaginaryNum = comp1.imaginaryNum - comp2.imaginaryNum;//�� ���Ҽ��� ����� ����
}
void Complex::printNum() {//��� �Լ�
	cout << realNum << " + " << imaginaryNum << "i\n";
}

void main() {
	Complex complex1; //Complex Ŭ���� Ÿ���� complex1 ��ü ����
	Complex complex2; //Complex Ŭ���� Ÿ���� complex2 ��ü ����
	Complex result; //Complex Ŭ���� Ÿ���� result ��ü ����

	complex1.setRealNum(2.1); //�Ǽ� �����ڸ� �̿��Ͽ� complex1 ��ü�� �Ǽ��ο� 2.1 ����
	complex1.setImaginaryNum(2.5);//��� �����ڸ� �̿��Ͽ� complex1 ��ü�� ����ο� 2.5 ����
	complex1.printNum();//complex1�� ���� ���� ���

	complex2.setRealNum(3.5);//�Ǽ� �����ڸ� �̿��Ͽ� complex2 ��ü�� �Ǽ��ο� 3.5 ����
	complex2.setImaginaryNum(1.9);//��� �����ڸ� �̿��Ͽ� complex1 ��ü�� ����ο� 1.9 ����
	complex2.printNum();//complex2�� ���� ���� ���

	result.add(complex1, complex2);//result ��ü�� ���Ҽ� �����Լ� (�� ���Ҽ��� ���� ��)
	cout << "�� ���Ҽ��� ���� = ";
	result.printNum();//result�� ���� ���� ���

	result.sub(complex1, complex2);//result ��ü�� ���Ҽ� �����Լ� (�� ���Ҽ��� ���� ��)
	cout << "�� ���Ҽ��� ���� = ";
	result.printNum();//result�� ���� ���� ���
}