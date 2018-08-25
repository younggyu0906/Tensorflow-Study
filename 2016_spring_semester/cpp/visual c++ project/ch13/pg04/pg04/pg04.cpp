#include <iostream>
#include <string>

using namespace std;

class Food {//�Ϲ����� ������ ��Ÿ���� Food Ŭ����
	int calorie, price, weight;//Į�θ�, ����, �߷��� ���� �� �������
public :
	Food(int c, int p, int w) : calorie(c), price(p), weight(w) {//Food ������
	}
	~Food() {//Food �Ҹ���
	}
	void setCalorie(int c) {//calorie ������
		calorie = c;
	}
	int getCalorie() {//calorie ������
		return calorie;
	}
	void setPrice(int p) {//price ������
		price = p;
	}
	int getPrice() {//price ������
		return price;
	}
	void setWeight(int w) {//weight ������
		weight = w;
	}
	int getWeight() {//weight ������
		return weight;
	}
	void print() {//��� �Լ�
		cout << "Į�θ� : " << calorie << ", ���� : " << price << ", �߷� : " << weight << endl;
	}
};

class Melon : public Food {//Food Ŭ������ ��ӹ޾Ƽ� ��� ��Ÿ���� Melon Ŭ����
	string farm;//���� ����� ���� �� ����
public :
	Melon(int c, int p, int w, string f) : Food(c, p, w), farm(f) {//Melon ������
	}
	~Melon() {//Melon �Ҹ���
	}
	void setFarm(string f) {//farm ������
		farm = f;
	}
	string getFarm() {//farm ������
		return farm;
	}
	void print() {//��� �Լ�
		Food::print();
		cout << "���� ��� : " << farm << endl;
	}
};
void main() {
	Food f1(300, 10000, 205);//Food Ŭ������ �׽�Ʈ �ϱ� ���Ͽ� f1 ��ü ����
	f1.print();

	Melon m1(200, 5300, 124, "��̳��");//Melon Ŭ������ �׽�Ʈ �ϱ� ���Ͽ� m1 ��ü ����
	m1.print();
}