#pragma once

#include <iostream>
using namespace std;

class Pizza
{
public:
	virtual void PizzaName(void)	{}
	// ���� �غ�
	void			Prepare(void)	{	cout <<"=====> �غ�"<< endl;	}

	// ����
	void			Bake(void)		{	cout <<"=====> ����"<< endl;	}

	// �ڸ���
	void			Cut(void)		{	cout <<"=====> Ŀ��"<< endl;	}

	// ����
	void			Package(void)	{	cout <<"=====> ����"<< endl;	}
};

// ���� ����
class NYStyleCheesePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "����_ġ��_����" << endl;		}
};

class NYStyleHamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "����_��_����"<< endl;			}
};

class NYStyleClamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "����_����_����"<< endl;			}
};

class NYStylePinePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "����_���ξ���_����"<< endl;		}
};

// ��ī�� ����
class ChicagoStyleCheesePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "��ī��_ġ��_����"<< endl;		}
};

class ChicagoStyleHamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "��ī��_��_����"<< endl;			}
};

class ChicagoStyleClamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "��ī��_����_����"<< endl;		}
};

class ChicagoStylePinePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "��ī��_���ξ���_����"<< endl;	}
};
