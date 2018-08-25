#include <iostream>

using namespace std;
	
class BankAcct {//ÀºÇàÀÇ °èÁÂ¸¦ ³ªÅ¸³»´Â Å¬·¡½º
protected :
	int money, interest;//ÀÜ¾×°ú ÀÌÀÚ¸¦ ³ªÅ¸³»´Â ¸â¹ö º¯¼ö
public :
	BankAcct (int m = 0, int i = 0) {//BankAcct »ı¼ºÀÚ
		money = m;
		interest = i;
	}
	virtual int getInterest() = 0;//ÇöÀç °èÁÂÀÇ ÀÌÀÚÀ²À» ¹İÈ¯ÇÏ´Â ¼ø¼ö°¡»óÇÔ¼ö

	void deposit(int d) {//¿¹±İ ÇÔ¼ö
		money += d;
	}
	void withdraw(int w) {//Ãâ±İ ÇÔ¼ö
		money -= w;
	}
	virtual void appInterest() = 0;//ÀÌÀÚ Àû¿ë ¼ø¼ö°¡»óÇÔ¼ö

	virtual void printMoney() = 0;//ÀÜ¾×À» Ãâ·ÂÇÏ´Â ¼ø¼ö°¡»óÇÔ¼ö
};

class SavingAcct : public BankAcct {//ÀÌÀÚÀ²ÀÌ 9%ÀÎ Àú®‚ ¿¹±İ °èÁÂ, BankAcct¸¦ »ó¼Ó ¹Ş´Â´Ù
public :
	SavingAcct(int m = 0) : BankAcct(m,9) {//SavingAcct»ı¼ºÀÚ
	}
	virtual int getInterest() {//ÇöÀç °èÁÂÀÇ ÀÌÀÚÀ²À» ¹İÈ¯ÇÏ´Â ÇÔ¼ö ÀçÁ¤ÀÇ
		return interest;
	}
	virtual void appInterest() {//ÀÌÀÚ Àû¿ë ÇÔ¼ö ÀçÁ¤ÀÇ
		money += money * interest / 100;
	}
	virtual void printMoney() {//ÀÜ¾× Ãâ·Â ÇÔ¼ö ÀçÁ¤ÀÇ
		cout << "ÀÜ¾× : " << money << endl;
	}
};

class CheckingAcct : public BankAcct {//ÀÌÀÚÀ²ÀÌ 5%ÀÎ ´çÁÂ ¿¹±İ °èÁÂ, BankAcct¸¦ »ó¼Ó ¹Ş´Â´Ù
public :
	CheckingAcct(int m = 0) : BankAcct(m,5) {//CheckingAcct»ı¼ºÀÚ
	}
	virtual int getInterest() {//ÇöÀç °èÁÂÀÇ ÀÌÀÚÀ²À» ¹İÈ¯ÇÏ´Â ÇÔ¼ö ÀçÁ¤ÀÇ
		return interest;
	}
	virtual void appInterest() {//ÀÌÀÚ Àû¿ë ÇÔ¼ö ÀçÁ¤ÀÇ
		money += money * interest / 100;
	}
	virtual void printMoney() {//ÀÜ¾× Ãâ·Â ÇÔ¼ö ÀçÁ¤ÀÇ
		cout << "ÀÜ¾× : " << money << endl;
	}
};

void main() {
	BankAcct * ba[2];//°´Ã¼ Æ÷ÀÎÅÍ ¹è¿­ »ı¼º

	ba[0] = new SavingAcct(15000);//ba[0] °´Ã¼¿¡ SavingAcct °´Ã¼¸¦ µ¿ÀûÀ¸·Î »ı¼ºÇÏ¿© ÀúÀå
	ba[1] = new CheckingAcct(25000);//ba[1] °´Ã¼¿¡ CheckingAcct °´Ã¼¸¦ µ¿ÀûÀ¸·Î »ı¼ºÇÏ¿© ÀúÀå

	for(int i = 0; i < 2; i++) {
		cout << "ÇöÀç ";
		ba[i]->printMoney();//ÇöÀç ÀÜ¾× Ãâ·Â

		ba[i]->deposit(5000);//ÀÔ±İ
		cout << "ÀÔ±İ ÈÄ ";
		ba[i]->printMoney();//ÀÔ±İ ÈÄ ÀÜ¾× Ãâ·Â
		
		ba[i]->withdraw(10000);//Ãâ±İ
		cout << "Ãâ±İ ÈÄ ";
		ba[i]->printMoney();//Ãâ±İ ÈÄ ÀÜ¾× Ãâ·Â

		ba[i]->appInterest();//ÀÌÀÚ Àû¿ë
		cout << "ÀÌÀÚ Àû¿ë ÈÄ ";
		ba[i]->printMoney();//ÀÌÀÚÀû¿ë ÈÄ ÀÜ¾× Ãâ·Â

		cout << "ÀÌÀÚ : " << ba[i]->getInterest() << "%" << endl << endl;//ÀÌÀÚÀ² Ãâ·Â
	}
};