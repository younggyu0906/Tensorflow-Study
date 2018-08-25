#include <iostream>
#include <string>

using namespace std;

class BankAccount {//은행 계좌
private :
	int accountNumber;//계좌 번호
	string owner;//예금주
	int balance;//잔액을 표시하는 변수

public :
	void setBalance(int);//balance에 대한 설정자
	int getBalance();//balance에 대한 접근자
	void deposit(int);//저금 함수
	void withdraw(int);//인출 함수
	void transfer(int, BankAccount &);//"문제 8번 송금 함수"
	void print();//현재 상태 출력
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
//"transfer함수 = 문제 8번 송금 함수", (객체 otherAccount를 레퍼런스를 사용하여 원래의 객체에서 값이 변경 될 수 있도록 함)
void BankAccount::transfer(int amount, BankAccount &otherAccount) {//"문제 8번 송금 함수"
	balance -= amount;//현재의 잔액에서 amount만큼 송금하여 amount만큼 뺄셈
	otherAccount.deposit(amount);//otherAccount계좌의 입장에서는 amount만큼 입금(저금)된 것이므로 저금함수 사용
}
void BankAccount::print() {
	cout << "잔액은 " << balance << "입니다." << endl;
}

void main() {
	BankAccount account;

	account.setBalance(0);
	account.deposit(10000);
	account.print();
	account.withdraw(8000);
	account.print();

	//송금 함수 transfer를 위한 테스트
	BankAccount acc2;//송금 받을 다른 계좌 acc2 생성
	acc2.setBalance(800);//잔액을 800으로 초기화
	cout << "송금 전account, acc2 잔액\n";
	account.print();//출력
	acc2.print();//출력
	account.transfer(1000, acc2);//account계좌에서 1000만큼 acc2의 계좌로 송금
	cout << "송금 후account, acc2 잔액\n";
	account.print();//출려
	acc2.print();//출력
}