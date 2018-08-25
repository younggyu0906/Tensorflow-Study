#include <iostream>

using namespace std;

class Complex {//복소수
private :
	double realNum;//실수
	double imaginaryNum;//허수

public :
	double getRealNum();//실수 접근자
	double getImaginaryNum();//허수 접근자
	void setRealNum(double);//실수 설정자
	void setImaginaryNum(double);//허수 설정자
	void add(Complex, Complex);//복소수 덧셈 함수
	void sub(Complex, Complex);//복소수 뺄셈 함수
	void printNum();//출력 함수
};

double Complex::getRealNum() {//실수 접근자
	return realNum;
}
double Complex::getImaginaryNum() {//허수 접근자
	return imaginaryNum;
}
void Complex::setRealNum(double num) {//실수 설정자
	realNum = num;
}
void Complex::setImaginaryNum(double num) {//허수 설정자
	imaginaryNum = num;
}
void Complex::add(Complex comp1, Complex comp2) {//복소수 덧셈 함수
	realNum = comp1.realNum + comp2.realNum;//두 복소수의 실수부 덧셈
	imaginaryNum = comp1.imaginaryNum + comp2.imaginaryNum;//두 복소수의 허수부 덧셈
}
void Complex::sub(Complex comp1, Complex comp2) {//복소수 뺄셈 함수
	realNum = comp1.realNum - comp2.realNum; //두 복소수의 실수부 뺄셈
	imaginaryNum = comp1.imaginaryNum - comp2.imaginaryNum;//두 복소수의 허수부 뺄셈
}
void Complex::printNum() {//출력 함수
	cout << realNum << " + " << imaginaryNum << "i\n";
}

void main() {
	Complex complex1; //Complex 클래스 타입의 complex1 객체 생성
	Complex complex2; //Complex 클래스 타입의 complex2 객체 생성
	Complex result; //Complex 클래스 타입의 result 객체 생성

	complex1.setRealNum(2.1); //실수 설정자를 이용하여 complex1 객체의 실수부에 2.1 저장
	complex1.setImaginaryNum(2.5);//허수 설정자를 이용하여 complex1 객체의 허수부에 2.5 저장
	complex1.printNum();//complex1의 현재 상태 출력

	complex2.setRealNum(3.5);//실수 설정자를 이용하여 complex2 객체의 실수부에 3.5 저장
	complex2.setImaginaryNum(1.9);//허수 설정자를 이용하여 complex1 객체의 허수부에 1.9 저장
	complex2.printNum();//complex2의 현재 상태 출력

	result.add(complex1, complex2);//result 객체의 복소수 덧셈함수 (두 복소수의 덧셈 값)
	cout << "두 복소수의 덧셈 = ";
	result.printNum();//result의 현재 상태 출력

	result.sub(complex1, complex2);//result 객체의 복소수 뺄셈함수 (두 복소수의 뺄셈 값)
	cout << "두 복소수의 뺄셈 = ";
	result.printNum();//result의 현재 상태 출력
}