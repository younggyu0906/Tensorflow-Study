#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

using namespace std;

int main(void)
{
	cout <<"121101_Miso_Factory_Method_Patten"<< endl;

	// ���� ���� ����� ����
	PizzaStore* NyPizza = new NYPizzaStore;
	// �ֹ�
	Pizza*		pizza	= NyPizza->OrderPizza("���ξ���");
	// ���� �̸� ���
	pizza->PizzaName();

	return 0;
}