#include <iostream>

using namespace std;

class Shape {//������ ����� ��Ÿ���� Shape Ŭ����
protected :
	int x, y;//������ �������� ���� �� ������� x, y
public :
	Shape(int x = 0, int y = 0) {//Shape ������
		this->x = x;
		this->y = y;
	}
	virtual void draw() {//������ �׸��� Draw ���� �Լ� ����
		cout << "Shape Draw" << endl;
	}
	void setOrigin(int x, int y) {//������(x, y)���� �����ϴ� ����Լ�
		this->x = x;
		this->y = y;
	}
	virtual void move(int mx, int my) {//�������� �̵���Ű�� ����Լ�
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//������ ���̸� ���Ͽ� �����ϴ� ���� �Լ� ����
		cout << "Shape ����?" << endl;
		return 0;
	}
	virtual void printOrigin() {//�������� ����ϴ� ����Լ�
		cout << "��ġ : (" << x << ", " << y << ")\n";
	}
};

class Rectangle : public Shape {//�簢���� ��Ÿ���� Ŭ����, Shape�� ���
private :
	int width, height;//�簢���� �غ��� ���̸� ������ ������� 
public :
	Rectangle (int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y) {//Rectangle ������
		width = w;
		height = h;
	}
	void setWidth(int w) {//width ������
		width = w;
	}
	void setHeight(int h) {//height ������
		height = h;
	}
	virtual void draw() {//������ �׸��� Draw�Լ� ������
		cout << "Rectangle Draw" << endl;
	}
	virtual void move(int mx, int my) {//�������� �̵���Ű�� move�Լ� ������
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//������ ���̸� ���ϴ� getArea ������
		return width * height;
	}
	virtual void printOrigin() {//������ ����Լ� printOrigin ������
		cout << "��ġ : (" << x << ", " << y << ")\n";
	}
};
class Circle : public Shape {//���� ��Ÿ���� Circle Ŭ����, Shape ���
private:
	int radius;//�������� ������ ��� ����
public :
	Circle (int x = 0, int y = 0, int r = 0) : Shape(x, y) {//Circle ������
		radius = r;
	}
	void setRadius(int r) {//radius ������
		radius = r;
	}
	virtual void draw() {//������ �׸��� Draw�Լ� ������
		cout << "Circle Draw" << endl;
	}
	virtual void move(int mx, int my) {//�������� �̵���Ű�� move�Լ� ������
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//������ ���̸� ���ϴ� getArea ������
		return radius * radius * 3.141592;
	}
	virtual void printOrigin() {//������ ����Լ� printOrigin ������
		cout << "��ġ : (" << x << ", " << y << ")\n";
	}
};
class Triangle : public Shape {//�ﰢ���� ��Ÿ���� Triangle Ŭ����, Shape ���
private :
	int base, height;//�غ��� ���̸� ������ �������
public:
	Triangle (int x = 0, int y = 0, int b = 0, int h = 0) : Shape(x, y) {//Triangle ������
		base = b;
		height = h;
	}
	virtual void draw() {//������ �׸��� Draw�Լ� ������
		cout << "Triangle Draw" << endl;
	}
	virtual void move(int mx, int my) {//�������� �̵���Ű�� move�Լ� ������
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//������ ���̸� ���ϴ� getArea ������
		return base * height / 2;
	}
	virtual void printOrigin() {//������ ����Լ� printOrigin ������
		cout << "��ġ : (" << x << ", " << y << ")\n";
	}
};
class Ellipse : public Shape {//Ÿ���� ��Ÿ���� Ellipse Ŭ����, Shape ���
private :
	int majorAxis, minorAxis;//Ÿ���� �� ������, ª�� �������� ���� ������ �������
public :
	Ellipse (int x = 0, int y = 0, int major = 0, int minor = 0) : Shape(x, y) {//Ellipse ������
		majorAxis = major;
		minorAxis = minor;
	}
	virtual void draw() {//������ �׸��� Draw�Լ� ������
		cout << "Ellipse Draw" << endl;
	}
	virtual void move(int mx, int my) {//�������� �̵���Ű�� move�Լ� ������
		x = x + mx;
		y = y + my;
	}
	virtual double getArea() {//������ ���̸� ���ϴ� getArea ������
		return majorAxis * minorAxis * 3.141592;
	}
	virtual void printOrigin() {//������ ����Լ� printOrigin ������
		cout << "��ġ : (" << x << ", " << y << ")\n";
	}
};

int main() {
	Shape *arrayOfShapes[4];//Shape ������ �迭

	arrayOfShapes[0] = new Rectangle(0, 0, 8, 6);//Rectangle ��ü ����
	arrayOfShapes[1] = new Triangle(0, 0, 8, 6);//Triangle ��ü ����
	arrayOfShapes[2] = new Circle(0, 0, 8);//Circle ��ü ����
	arrayOfShapes[3] = new Ellipse(0, 0, 8, 6);//Ellipse ��ü ����

	for (int i = 0; i < 4; i++) {
		arrayOfShapes[i]->draw();//Draw�Լ� ȣ��
		cout << "���� : " << arrayOfShapes[i]->getArea() << endl;//������ ���� ���
		arrayOfShapes[i]->printOrigin();//������ ���
		arrayOfShapes[i]->move(9, 6);//������ �̵�
		arrayOfShapes[i]->printOrigin();//������ ���
		cout << endl;
	}
}