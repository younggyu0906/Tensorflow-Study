#include <iostream>
#include <string>

using namespace std;

class BankAccnt //���¸� ��Ÿ���� �θ� Ŭ����
{
protected:
    int input; //�Աݾ�
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

class SavingAccnt : public BankAccnt //������ ��9%�� ���� ���� ����
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

class CheckingAccnt : public BankAccnt //������ �� 5%�� ���� ���� ����
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
        cout << "�Ա�: " << deposit << endl;
        cout << "���: " << withdraw << endl;
        cout << "�ܾ�: " << deposit-withdraw;
    }
};


int main()
{
    Account a;

	a.account->getInterest();
}