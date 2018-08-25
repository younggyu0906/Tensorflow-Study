#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

using namespace std;

// ���� ����
// ���� ����
Pizza*		PizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;
	return pizza;
}
// ���� �ֹ�
Pizza*		PizzaStore::OrderPizza(char* pType)
{
	Pizza* pizza = NULL;
	// ���� �ֹ��ϴ� ������ ���ڸ� �����ϰ� �Ѵ�.
	pizza = CreatePizza(pType);

	// �غ�
	pizza->Prepare();
	// ����
	pizza->Bake();
	// Ŀ��
	pizza->Cut();
	// ����
	pizza->Package();

	return pizza;
}

// ���� ���� ����
Pizza*	NYPizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;

	if(!strcmp(pType,"ġ��"))
	{
		pizza = new NYStyleCheesePizza;
	}
	else if(!strcmp(pType,"��"))
	{
		pizza = new NYStyleHamPizza;
	}
	else if(!strcmp(pType,"����"))
	{
		pizza = new NYStyleClamPizza;
	}
	else if(!strcmp(pType,"���ξ���"))
	{
		pizza = new NYStylePinePizza;
	}
	else
	{
		cout <<"* �޴��� �����ϴ�."<< endl;
	}

	return pizza;
}

// ��ī�� ���� ����
Pizza*	ChicagoPizzaStore::CreatePizza(char* pType)
{
	Pizza* pizza = NULL;

	if(!strcmp(pType,"ġ��"))
	{
		pizza = new ChicagoStyleCheesePizza;
	}
	else if(!strcmp(pType,"��"))
	{
		pizza = new ChicagoStyleHamPizza;
	}
	else if(!strcmp(pType,"����"))
	{
		pizza = new ChicagoStyleClamPizza;
	}
	else if(!strcmp(pType,"���ξ���"))
	{
		pizza = new ChicagoStylePinePizza;
	}
	else
	{
		cout <<"* �޴��� �����ϴ�."<< endl;
	}

	return pizza;
}
