#include <iostream>

using namespace std;
	
class BankAcct {//������ ���¸� ��Ÿ���� Ŭ����
protected :
	int money, interest;//�ܾװ� ���ڸ� ��Ÿ���� ��� ����
public :
	BankAcct (int m = 0, int i = 0) {//BankAcct ������
		money = m;
		interest = i;
	}
	virtual int getInterest() = 0;//���� ������ �������� ��ȯ�ϴ� ���������Լ�

	void deposit(int d) {//���� �Լ�
		money += d;
	}
	void withdraw(int w) {//��� �Լ�
		money -= w;
	}
	virtual void appInterest() = 0;//���� ���� ���������Լ�

	virtual void printMoney() = 0;//�ܾ��� ����ϴ� ���������Լ�
};

class SavingAcct : public BankAcct {//�������� 9%�� ���� ���� ����, BankAcct�� ��� �޴´�
public :
	SavingAcct(int m = 0) : BankAcct(m,9) {//SavingAcct������
	}
	virtual int getInterest() {//���� ������ �������� ��ȯ�ϴ� �Լ� ������
		return interest;
	}
	virtual void appInterest() {//���� ���� �Լ� ������
		money += money * interest / 100;
	}
	virtual void printMoney() {//�ܾ� ��� �Լ� ������
		cout << "�ܾ� : " << money << endl;
	}
};

class CheckingAcct : public BankAcct {//�������� 5%�� ���� ���� ����, BankAcct�� ��� �޴´�
public :
	CheckingAcct(int m = 0) : BankAcct(m,5) {//CheckingAcct������
	}
	virtual int getInterest() {//���� ������ �������� ��ȯ�ϴ� �Լ� ������
		return interest;
	}
	virtual void appInterest() {//���� ���� �Լ� ������
		money += money * interest / 100;
	}
	virtual void printMoney() {//�ܾ� ��� �Լ� ������
		cout << "�ܾ� : " << money << endl;
	}
};

void main() {
	BankAcct * ba[2];//��ü ������ �迭 ����

	ba[0] = new SavingAcct(15000);//ba[0] ��ü�� SavingAcct ��ü�� �������� �����Ͽ� ����
	ba[1] = new CheckingAcct(25000);//ba[1] ��ü�� CheckingAcct ��ü�� �������� �����Ͽ� ����

	for(int i = 0; i < 2; i++) {
		cout << "���� ";
		ba[i]->printMoney();//���� �ܾ� ���

		ba[i]->deposit(5000);//�Ա�
		cout << "�Ա� �� ";
		ba[i]->printMoney();//�Ա� �� �ܾ� ���
		
		ba[i]->withdraw(10000);//���
		cout << "��� �� ";
		ba[i]->printMoney();//��� �� �ܾ� ���

		ba[i]->appInterest();//���� ����
		cout << "���� ���� �� ";
		ba[i]->printMoney();//�������� �� �ܾ� ���

		cout << "���� : " << ba[i]->getInterest() << "%" << endl << endl;//������ ���
	}
};