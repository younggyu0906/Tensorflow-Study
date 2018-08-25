#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

using namespace std;

int main(void)
{
	cout <<"121101_Miso_Factory_Method_Patten"<< endl;

	// 뉴욕 피자 스토어 생성
	PizzaStore* NyPizza = new NYPizzaStore;
	// 주문
	Pizza*		pizza	= NyPizza->OrderPizza("파인애플");
	// 피자 이름 출력
	pizza->PizzaName();

	return 0;
}