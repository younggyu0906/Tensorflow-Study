#include <iostream>
#include <string>
using namespace std;
class Car {
	char *color;
public :
	Car(char *c) {
		cout << "������ ȣ��\n";
		color = new char[strlen(c) + 1];
		strcpy(color, c);
	}
	Car(const Car &obj) {
		cout << "���������\n";
		color = new char[strlen(obj.color) + 1];
		strcpy(color, obj.color);
	}
	~Car() {
		cout << "�Ҹ��� ȣ��\n";
		delete [] color;
	}
	Car getCar() {
		Car newCar("blue");
		return newCar;
	}
	void print(Car c) {
		cout << c.color << endl;
	}
};
void main() {
	Car c1("yellow");
	Car c2(c1);
	c1.print(c1);
	Car myCar = c1.getCar();
}
