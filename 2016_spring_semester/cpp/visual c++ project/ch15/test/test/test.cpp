#include <iostream>
#include <string>

using namespace std;

class BankAccnt //계좌를 나타내는 부모 클래스
{
protected:
    int input; //입금액
public:
    BankAccnt(int i) : input(i)
    {
    }
    
    void setInput(int i)
    {
        input = i;
    }
    
    int getInput()
    {
        return input;
    }
    
    virtual double getInterest() = 0;
};

class SavingAccnt : public BankAccnt //이자율 연9%인 저축 예금 계좌
{
public:
    SavingAccnt(int i) : BankAccnt(i)
    {
    }
    
    virtual double getInterest()
    {
        return input * 0.09;
    }
};

class CheckingAccnt : public BankAccnt //이자율 연 5%인 당좌 예금 계좌
{
public:
    CheckingAccnt(int i) : BankAccnt(i)
    {
    }
    
    virtual double getInterest()
    {
        return input * 0.05;
    }
};

class Account
{
    
public:
	BankAccnt *account;
    int deposit;
    int withdraw;
    
    int getdeposit()
    {
        return deposit;
    }
    
    int getwithdraw()
    {
        return withdraw;
    }
    
    void setdeposit(int d)
    {
        deposit = d;
    }
    
    void setwithdraw(int w)
    {
        withdraw = w;
    }
    
    void print()
    {
        cout << "입금: " << deposit << endl;
        cout << "출금: " << withdraw << endl;
        cout << "잔액: " << deposit-withdraw;
    }
};


int main()
{
    Account a;

	a.account->getInterest();
}