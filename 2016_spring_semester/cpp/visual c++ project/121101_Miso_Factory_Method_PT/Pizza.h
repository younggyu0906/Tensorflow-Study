#pragma once

#include <iostream>
using namespace std;

class Pizza
{
public:
	virtual void PizzaName(void)	{}
	// 피자 준비
	void			Prepare(void)	{	cout <<"=====> 준비"<< endl;	}

	// 굽기
	void			Bake(void)		{	cout <<"=====> 굽기"<< endl;	}

	// 자르기
	void			Cut(void)		{	cout <<"=====> 커팅"<< endl;	}

	// 포장
	void			Package(void)	{	cout <<"=====> 포장"<< endl;	}
};

// 뉴욕 피자
class NYStyleCheesePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "뉴욕_치즈_피자" << endl;		}
};

class NYStyleHamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "뉴욕_햄_피자"<< endl;			}
};

class NYStyleClamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "뉴욕_조개_피자"<< endl;			}
};

class NYStylePinePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "뉴욕_파인애플_피자"<< endl;		}
};

// 시카고 피자
class ChicagoStyleCheesePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "시카고_치즈_피자"<< endl;		}
};

class ChicagoStyleHamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "시카고_햄_피자"<< endl;			}
};

class ChicagoStyleClamPizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "시카고_조개_피자"<< endl;		}
};

class ChicagoStylePinePizza : public Pizza
{
public:
	void PizzaName(void)	{	cout<< "시카고_파인애플_피자"<< endl;	}
};
