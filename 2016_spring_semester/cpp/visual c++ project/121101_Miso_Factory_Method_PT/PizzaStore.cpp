#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

using namespace std;

// 피자 가게
// 피자 생성
Pizza*		PizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;
	return pizza;
}
// 피자 주문
Pizza*		PizzaStore::OrderPizza(char* pType)
{
	Pizza* pizza = NULL;
	// 피자 주문하는 곳에서 피자를 생성하게 한다.
	pizza = CreatePizza(pType);

	// 준비
	pizza->Prepare();
	// 굽기
	pizza->Bake();
	// 커팅
	pizza->Cut();
	// 포장
	pizza->Package();

	return pizza;
}

// 뉴욕 피자 가게
Pizza*	NYPizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;

	if(!strcmp(pType,"치즈"))
	{
		pizza = new NYStyleCheesePizza;
	}
	else if(!strcmp(pType,"햄"))
	{
		pizza = new NYStyleHamPizza;
	}
	else if(!strcmp(pType,"조개"))
	{
		pizza = new NYStyleClamPizza;
	}
	else if(!strcmp(pType,"파인애플"))
	{
		pizza = new NYStylePinePizza;
	}
	else
	{
		cout <<"* 메뉴가 없습니다."<< endl;
	}

	return pizza;
}

// 시카고 피자 가게
Pizza*	ChicagoPizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;

	if(!strcmp(pType,"치즈"))
	{
		pizza = new ChicagoStyleCheesePizza;
	}
	else if(!strcmp(pType,"햄"))
	{
		pizza = new ChicagoStyleHamPizza;
	}
	else if(!strcmp(pType,"조개"))
	{
		pizza = new ChicagoStyleClamPizza;
	}
	else if(!strcmp(pType,"파인애플"))
	{
		pizza = new ChicagoStylePinePizza;
	}
	else
	{
		cout <<"* 메뉴가 없습니다."<< endl;
	}

	return pizza;
}
