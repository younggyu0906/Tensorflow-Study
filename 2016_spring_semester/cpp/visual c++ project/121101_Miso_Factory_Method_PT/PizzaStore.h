#pragma once

class Pizza;

// ���� ����
class PizzaStore
{
private:
	// ���� ����
	virtual Pizza*	CreatePizza(char* pType);
public:
	// ���� �ֹ�
	Pizza*			OrderPizza(char* pType);
};

// ���� ���� ����
class NYPizzaStore : public PizzaStore
{
private:
	Pizza*	CreatePizza(char* pType);
};

// ��ī�� ���� ����
class ChicagoPizzaStore : public PizzaStore
{
private:
	Pizza*	CreatePizza(char* pType);
};
