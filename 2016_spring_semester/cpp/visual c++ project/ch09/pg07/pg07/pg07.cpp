#include <iostream>

using namespace std;

class Triangle {//삼각형
private :
	double base;//삼각형의 밑변
	double height;//삼각형의 높이
	double area;//삼각형의 면적

public :
	double getBase();//밑변 접근자
	double getHeight();//높이 접근자
	void setBase(double);//밑변 설정자
	void setHeight(double);//높이 설정자
	void getArea();//면적을 구하는 함수
	void print();//삼각형의 상태를 출력
};

double Triangle::getBase() {//밑변 접근자
	return base;
}
double Triangle::getHeight() {//높이 접근자
	return height;
}
void Triangle::setBase(double lenth) {//밑변 설정자
	base = lenth;
}
void Triangle::setHeight(double lenth) {//높이 설정자
	height = lenth;
}
void Triangle::getArea() {//면적을 구하는 함수
	area = base * height / 2;//삼각형의 면적
}
void Triangle::print() {//삼각형의 상태 출력
	cout << "삼각형의 밑변 : " << base << "\n삼각형의 높이 : " << height << "\n삼각형의 넓이 : " << area << endl;
}

void main() {
	Triangle t1;//Triangle 클래스 타입의 t1객체를 생성

	t1.setBase(10);//t1의 밑변 접근자를 이용하여 밑변 맴버변수에 10저장
	t1.setHeight(20);//t1의 높이 접근자를 이용하여 높이 멤버변수에 20저장
	t1.getArea();//t1 삼각형의 면적를 구하는 함수를 호출하여 삼각형의 넓이를 구함

	t1.print();//t1 삼각형의 상태 출력
}