#include <iostream>
#include <string>

using namespace std;

class Food {//일반적인 음식을 나타내는 Food 클래스
	int calorie, price, weight;//칼로리, 가격, 중량을 저장 할 멤버변수
public :
	Food(int c, int p, int w) : calorie(c), price(p), weight(w) {//Food 생성자
	}
	~Food() {//Food 소멸자
	}
	void setCalorie(int c) {//calorie 설정자
		calorie = c;
	}
	int getCalorie() {//calorie 접근자
		return calorie;
	}
	void setPrice(int p) {//price 설정자
		price = p;
	}
	int getPrice() {//price 접근자
		return price;
	}
	void setWeight(int w) {//weight 설정자
		weight = w;
	}
	int getWeight() {//weight 접근자
		return weight;
	}
	void print() {//출력 함수
		cout << "칼로리 : " << calorie << ", 가격 : " << price << ", 중량 : " << weight << endl;
	}
};

class Melon : public Food {//Food 클래스를 상속받아서 멜론 나타내는 Melon 클래스
	string farm;//경작 농원을 저장 할 변수
public :
	Melon(int c, int p, int w, string f) : Food(c, p, w), farm(f) {//Melon 생성자
	}
	~Melon() {//Melon 소멸자
	}
	void setFarm(string f) {//farm 설정자
		farm = f;
	}
	string getFarm() {//farm 접근자
		return farm;
	}
	void print() {//출력 함수
		Food::print();
		cout << "경작 농원 : " << farm << endl;
	}
};
void main() {
	Food f1(300, 10000, 205);//Food 클래스를 테스트 하기 위하여 f1 객체 생성
	f1.print();

	Melon m1(200, 5300, 124, "장미농원");//Melon 클래스를 테스트 하기 위하여 m1 객체 생성
	m1.print();
}