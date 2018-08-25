#include <iostream>

using namespace std;

class Shape {//도형의 모양을 나타내는 Shape 클래스
protected :
	int x, y;//도형의 기준점을 저장 할 멤버변수 x, y
public :
	Shape(int x = 0, int y = 0) {//Shape 생성자
		this->x = x;
		this->y = y;
	}
	virtual void draw() {//도형을 그리는 Draw 가상 함수 정의
		cout << "Shape Draw" << endl;
	}
	void setOrigin(int x, int y) {//기준점(x, y)값을 설정하는 멤버함수
		this->x = x;
		this->y = y;
	}
	virtual void move(int mx, int my) {//기준점을 이동시키는 멤버함수
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//도형의 넓이를 구하여 리턴하는 가상 함수 정의
		cout << "Shape 넓이?" << endl;
		return 0;
	}
	virtual void printOrigin() {//기준점을 출력하는 멤버함수
		cout << "위치 : (" << x << ", " << y << ")\n";
	}
};

class Rectangle : public Shape {//사각형을 나타내는 클래스, Shape를 상속
private :
	int width, height;//사각형의 밑변과 높이를 저장할 멤버변수 
public :
	Rectangle (int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y) {//Rectangle 생성자
		width = w;
		height = h;
	}
	void setWidth(int w) {//width 설정자
		width = w;
	}
	void setHeight(int h) {//height 설정자
		height = h;
	}
	virtual void draw() {//도형을 그리는 Draw함수 재정의
		cout << "Rectangle Draw" << endl;
	}
	virtual void move(int mx, int my) {//기준점을 이동시키는 move함수 재정의
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//도형의 넓이를 구하는 getArea 재정의
		return width * height;
	}
	virtual void printOrigin() {//기준점 출력함수 printOrigin 재정의
		cout << "위치 : (" << x << ", " << y << ")\n";
	}
};
class Circle : public Shape {//원을 나타내는 Circle 클래스, Shape 상속
private:
	int radius;//반지름을 저장할 멤버 변수
public :
	Circle (int x = 0, int y = 0, int r = 0) : Shape(x, y) {//Circle 생성자
		radius = r;
	}
	void setRadius(int r) {//radius 설정자
		radius = r;
	}
	virtual void draw() {//도형을 그리는 Draw함수 재정의
		cout << "Circle Draw" << endl;
	}
	virtual void move(int mx, int my) {//기준점을 이동시키는 move함수 재정의
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//도형의 넓이를 구하는 getArea 재정의
		return radius * radius * 3.141592;
	}
	virtual void printOrigin() {//기준점 출력함수 printOrigin 재정의
		cout << "위치 : (" << x << ", " << y << ")\n";
	}
};
class Triangle : public Shape {//삼각형을 나타내는 Triangle 클래스, Shape 상속
private :
	int base, height;//밑변과 높이를 저장할 멤버변수
public:
	Triangle (int x = 0, int y = 0, int b = 0, int h = 0) : Shape(x, y) {//Triangle 생성자
		base = b;
		height = h;
	}
	virtual void draw() {//도형을 그리는 Draw함수 재정의
		cout << "Triangle Draw" << endl;
	}
	virtual void move(int mx, int my) {//기준점을 이동시키는 move함수 재정의
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//도형의 넓이를 구하는 getArea 재정의
		return base * height / 2;
	}
	virtual void printOrigin() {//기준점 출력함수 printOrigin 재정의
		cout << "위치 : (" << x << ", " << y << ")\n";
	}
};
class Ellipse : public Shape {//타원을 나타내는 Ellipse 클래스, Shape 상속
private :
	int majorAxis, minorAxis;//타원의 긴 반지름, 짧은 반지름이 값을 저장할 멤버변수
public :
	Ellipse (int x = 0, int y = 0, int major = 0, int minor = 0) : Shape(x, y) {//Ellipse 생성자
		majorAxis = major;
		minorAxis = minor;
	}
	virtual void draw() {//도형을 그리는 Draw함수 재정의
		cout << "Ellipse Draw" << endl;
	}
	virtual void move(int mx, int my) {//기준점을 이동시키는 move함수 재정의
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//도형의 넓이를 구하는 getArea 재정의
		return majorAxis * minorAxis * 3.141592;
	}
	virtual void printOrigin() {//기준점 출력함수 printOrigin 재정의
		cout << "위치 : (" << x << ", " << y << ")\n";
	}
};

int main() {
	Shape *arrayOfShapes[4];//Shape 포인터 배열

	arrayOfShapes[0] = new Rectangle(0, 0, 8, 6);//Rectangle 객체 생성
	arrayOfShapes[1] = new Triangle(0, 0, 8, 6);//Triangle 객체 생성
	arrayOfShapes[2] = new Circle(0, 0, 8);//Circle 객체 생성
	arrayOfShapes[3] = new Ellipse(0, 0, 8, 6);//Ellipse 객체 생성

	for (int i = 0; i < 4; i++) {
		arrayOfShapes[i]->draw();//Draw함수 호출
		cout << "넓이 : " << arrayOfShapes[i]->getArea() << endl;//도형의 넓이 출력
		arrayOfShapes[i]->printOrigin();//기준점 출력
		arrayOfShapes[i]->move(9, 6);//기준점 이동
		arrayOfShapes[i]->printOrigin();//기준점 출력
		cout << endl;
	}
}