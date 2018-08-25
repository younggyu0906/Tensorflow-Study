#include <iostream>
#include <string>

using namespace std;

class BankAccount {//���� ����
private :
	int accountNumber;//���� ��ȣ
	string owner;//������
	int balance;//�ܾ��� ǥ���ϴ� ����

public :
	void setBalance(int);//balance�� ���� ������
	int getBalance();//balance�� ���� ������
	void deposit(int);//���� �Լ�
	void withdraw(int);//���� �Լ�
	void transfer(int, BankAccount &);//"���� 8�� �۱� �Լ�"
	void print();//���� ���� ���
};

void BankAccount::setBalance(int amount) {
	balance = amount;
}
int BankAccount::getBalance() {
	return balance;
}
void BankAccount::deposit(int amount) {
	balance += amount;
}
void BankAccount::withdraw(int amount) {
	balance -= amount;
}
//"transfer�Լ� = ���� 8�� �۱� �Լ�", (��ü otherAccount�� ���۷����� ����Ͽ� ������ ��ü���� ���� ���� �� �� �ֵ��� ��)
void BankAccount::transfer(int amount, BankAccount &otherAccount) {//"���� 8�� �۱� �Լ�"
	balance -= amount;//������ �ܾ׿��� amount��ŭ �۱��Ͽ� amount��ŭ ����
	otherAccount.deposit(amount);//otherAccount������ ���忡���� amount��ŭ �Ա�(����)�� ���̹Ƿ� �����Լ� ���
}
void BankAccount::print() {
	cout << "�ܾ��� " << balance << "�Դϴ�." << endl;
}

void main() {
	BankAccount account;

	account.setBalance(0);
	account.deposit(10000);
	account.print();
	account.withdraw(8000);
	account.print();

	//�۱� �Լ� transfer�� ���� �׽�Ʈ
	BankAccount acc2;//�۱� ���� �ٸ� ���� acc2 ����
	acc2.setBalance(800);//�ܾ��� 800���� �ʱ�ȭ
	cout << "�۱� ��account, acc2 �ܾ�\n";
	account.print();//���
	acc2.print();//���
	account.transfer(1000, acc2);//account���¿��� 1000��ŭ acc2�� ���·� �۱�
	cout << "�۱� ��account, acc2 �ܾ�\n";
	account.print();//���
	acc2.print();//���
}