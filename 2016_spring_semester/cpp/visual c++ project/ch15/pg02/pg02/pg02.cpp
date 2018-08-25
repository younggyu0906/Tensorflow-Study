#include <iostream>
#include <string>

using namespace std;

class HomeAppliance {//전자제품을 나타내는 클래스
protected :
	int price;//전자제품의 가격을 나타내는 멤버변수
public :
	HomeAppliance(int p) {//HomeAppliance 생성자
		price = p;
	}
	void setPrice(int p) {//price 설정자
		price = p;
	}
	virtual int getPrice() {//price 접근자 가상함수
		return price;
	}
};

class Television : public HomeAppliance {//텔레비전을 나타내는 클래스, HomeAppliance을 상속받음
	string model, maker;//모델명과 메이커를 나타내는 멤버변수
public :
	Television(int p = 0, string mdl = " ", string mkr = " ") : HomeAppliance(p) {//Television 생성자
		model = mdl;
		maker = mkr;
	}
	void setModel(string m) {//model 설정자
		model = m;
	}
	string getModel() {//model 접근자
		return model;
	}
	void setMaker(string m) {//maker 설정자
		maker = m;
	}
	string getMaker() {//maker 접근자
		return maker;
	}
	virtual int getPrice() {//price설정자 재정의
		return price;
	}
};

class Refrigerator : public HomeAppliance {//냉장고를 나타내는 클래스,  HomeAppliance을 상속받음
	string model, maker;
public :
	Refrigerator(int p = 0, string mdl = " ", string mkr = " ") : HomeAppliance(p) {//Refrigerator 생성자
		model = mdl;
		maker = mkr;
	}
	void setModel(int m) {//model 설정자
		model = m;
	}
	string getModel() {//model 접근자
		return model;
	}
	void setMaker(int m) {//maker 설정자
		maker = m;
	}
	string getMaker() {//maker 접근자
		return maker;
	}
	virtual int getPrice() {//price설정자 재정의
		return price;
	}
};

void main() {
	HomeAppliance *ha[2];//HomeAppliance 객체 포인터 배열 생성

	ha[0] = new Television(250000, "샘숭 지팔 아삭", "샘숭");//ha[0]객체에 Television객체를 동적으로 생성하여 저장
	ha[1] = new Refrigerator(300000, "스마트 FULL HD TV", "IG");//ha[1]객체에 Refrigerator객체를 동적으로 생성하여 저장

	for(int i = 0; i < 2; i++) {
		cout << "가격 : " << ha[i]->getPrice() << endl;
		if(typeid(ha[i]) == typeid(Television)) {
			cout << "모델명 : " << ((Television *) ha[i])->getModel() << endl;//모델명 출력, 하향 형변환
			cout << "메이커 : " << ((Television *) ha[i])->getMaker() << endl;//메이커 출력, 하향 형변환
		}
		else {
			cout << "모델명 : " << ((Refrigerator *) ha[i])->getModel() << endl;//모델명 출력, 하향 형변환
			cout << "메이커 : " << ((Refrigerator *) ha[i])->getMaker() << endl;//메이커 출력, 하향 형변환
		}
		cout << endl;
	}
}