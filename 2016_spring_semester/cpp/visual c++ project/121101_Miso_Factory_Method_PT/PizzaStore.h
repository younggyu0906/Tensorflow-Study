#pragma once

class Pizza;

// 피자 가게
class PizzaStore
{
private:
	// 피자 생성
	virtual Pizza*	CreatePizza(char* pType);
public:
	// 피자 주문
	Pizza*			OrderPizza(char* pType);
};

// 뉴욕 피자 가게
class NYPizzaStore : public PizzaStore
{
private:
	Pizza*	CreatePizza(char* pType);
};

// 시카고 피자 가게
class ChicagoPizzaStore : public PizzaStore
{
private:
	Pizza*	CreatePizza(char* pType);
};
