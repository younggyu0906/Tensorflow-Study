#include <iostream>
#include <string>

using namespace std;

class HomeAppliance {//������ǰ�� ��Ÿ���� Ŭ����
protected :
	int price;//������ǰ�� ������ ��Ÿ���� �������
public :
	HomeAppliance(int p) {//HomeAppliance ������
		price = p;
	}
	void setPrice(int p) {//price ������
		price = p;
	}
	virtual int getPrice() {//price ������ �����Լ�
		return price;
	}
};

class Television : public HomeAppliance {//�ڷ������� ��Ÿ���� Ŭ����, HomeAppliance�� ��ӹ���
	string model, maker;//�𵨸�� ����Ŀ�� ��Ÿ���� �������
public :
	Television(int p = 0, string mdl = " ", string mkr = " ") : HomeAppliance(p) {//Television ������
		model = mdl;
		maker = mkr;
	}
	void setModel(string m) {//model ������
		model = m;
	}
	string getModel() {//model ������
		return model;
	}
	void setMaker(string m) {//maker ������
		maker = m;
	}
	string getMaker() {//maker ������
		return maker;
	}
	virtual int getPrice() {//price������ ������
		return price;
	}
};

class Refrigerator : public HomeAppliance {//����� ��Ÿ���� Ŭ����,  HomeAppliance�� ��ӹ���
	string model, maker;
public :
	Refrigerator(int p = 0, string mdl = " ", string mkr = " ") : HomeAppliance(p) {//Refrigerator ������
		model = mdl;
		maker = mkr;
	}
	void setModel(int m) {//model ������
		model = m;
	}
	string getModel() {//model ������
		return model;
	}
	void setMaker(int m) {//maker ������
		maker = m;
	}
	string getMaker() {//maker ������
		return maker;
	}
	virtual int getPrice() {//price������ ������
		return price;
	}
};

void main() {
	HomeAppliance *ha[2];//HomeAppliance ��ü ������ �迭 ����

	ha[0] = new Television(250000, "���� ���� �ƻ�", "����");//ha[0]��ü�� Television��ü�� �������� �����Ͽ� ����
	ha[1] = new Refrigerator(300000, "����Ʈ FULL HD TV", "IG");//ha[1]��ü�� Refrigerator��ü�� �������� �����Ͽ� ����

	for(int i = 0; i < 2; i++) {
		cout << "���� : " << ha[i]->getPrice() << endl;
		if(typeid(ha[i]) == typeid(Television)) {
			cout << "�𵨸� : " << ((Television *) ha[i])->getModel() << endl;//�𵨸� ���, ���� ����ȯ
			cout << "����Ŀ : " << ((Television *) ha[i])->getMaker() << endl;//����Ŀ ���, ���� ����ȯ
		}
		else {
			cout << "�𵨸� : " << ((Refrigerator *) ha[i])->getModel() << endl;//�𵨸� ���, ���� ����ȯ
			cout << "����Ŀ : " << ((Refrigerator *) ha[i])->getMaker() << endl;//����Ŀ ���, ���� ����ȯ
		}
		cout << endl;
	}
}